#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id, priority, done;
    char title[100];
    struct Task *next;
} Task;

static Task *head = NULL;
static int nextId = 1;

static void addTask(void) {
    Task *node = malloc(sizeof *node);
    if (!node) {
        puts("Memory allocation failed.");
        return;
    }
    node->id = nextId++;
    printf("Task title: ");
    scanf(" %99[^\n]", node->title);
    printf("Priority (1=High, 2=Medium, 3=Low): ");
    if (scanf("%d", &node->priority) != 1) {
        free(node);
        puts("Invalid priority.");
        return;
    }
    if (node->priority < 1 || node->priority > 3) node->priority = 3;
    node->done = 0;
    node->next = NULL;

    if (!head) head = node;
    else {
        Task *p = head;
        while (p->next) p = p->next;
        p->next = node;
    }
    printf("Added task ID %d\n", node->id);
}

static void displayTasks(void) {
    Task *p = head;
    if (!p) {
        puts("No tasks.");
        return;
    }
    puts("\nID | Title | Priority | Status");
    while (p) {
        const char *priority = p->priority == 1 ? "High" :
                               p->priority == 2 ? "Medium" : "Low";
        printf("%d | %s | %s | %s\n", p->id, p->title, priority,
               p->done ? "Completed" : "Pending");
        p = p->next;
    }
}

static Task *searchTask(int id) {
    Task *p = head;
    while (p) {
        if (p->id == id) return p;
        p = p->next;
    }
    return NULL;
}

static void completeTask(int id) {
    Task *p = searchTask(id);
    if (p) {
        p->done = 1;
        puts("Task marked completed.");
    } else puts("Task not found.");
}

static void deleteTask(int id) {
    Task *p = head, *prev = NULL;
    while (p && p->id != id) {
        prev = p;
        p = p->next;
    }
    if (!p) {
        puts("Task not found.");
        return;
    }
    if (!prev) head = p->next;
    else prev->next = p->next;
    free(p);
    puts("Task deleted.");
}

static void sortByPriority(void) {
    if (!head) return;
    int swapped;
    do {
        Task *p = head;
        swapped = 0;
        while (p->next) {
            if (p->priority > p->next->priority) {
                int id = p->id, priority = p->priority, done = p->done;
                char title[100];
                strcpy(title, p->title);

                p->id = p->next->id;
                p->priority = p->next->priority;
                p->done = p->next->done;
                strcpy(p->title, p->next->title);

                p->next->id = id;
                p->next->priority = priority;
                p->next->done = done;
                strcpy(p->next->title, title);
                swapped = 1;
            }
            p = p->next;
        }
    } while (swapped);
    puts("Tasks sorted by priority.");
}

int main(void) {
    int choice, id;
    do {
        printf("\n1. Add  2. Display  3. Search  4. Complete\n"
               "5. Delete  6. Sort by priority  0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: addTask(); break;
            case 2: displayTasks(); break;
            case 3:
                printf("Task ID: ");
                if (scanf("%d", &id) == 1) {
                    Task *p = searchTask(id);
                    if (p) printf("%s (priority %d)\n", p->title, p->priority);
                    else puts("Task not found.");
                }
                break;
            case 4:
                printf("Task ID: ");
                if (scanf("%d", &id) == 1) completeTask(id);
                break;
            case 5:
                printf("Task ID: ");
                if (scanf("%d", &id) == 1) deleteTask(id);
                break;
            case 6: sortByPriority(); break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (choice != 0);

    while (head) {
        Task *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
