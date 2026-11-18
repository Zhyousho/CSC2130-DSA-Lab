#include <stdio.h>
#include <string.h>

#define MAX 100
#define PAGE_LEN 80

typedef struct {
    char item[MAX][PAGE_LEN];
    int top;
} Stack;

static void init(Stack *s) { s->top = -1; }
static int empty(const Stack *s) { return s->top == -1; }

static void push(Stack *s, const char *page) {
    if (s->top < MAX - 1) {
        strncpy(s->item[++s->top], page, PAGE_LEN - 1);
        s->item[s->top][PAGE_LEN - 1] = '\0';
    }
}

static int pop(Stack *s, char *page) {
    if (empty(s)) return 0;
    strcpy(page, s->item[s->top--]);
    return 1;
}

static void clear(Stack *s) { s->top = -1; }

int main(void) {
    Stack back, forward;
    char current[PAGE_LEN] = "Home", page[PAGE_LEN];
    int choice;
    init(&back);
    init(&forward);

    do {
        printf("\nCurrent page: %s\n1. Visit  2. Back  3. Forward  0. Exit\nChoice: ",
               current);
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            printf("Page name (no spaces): ");
            if (scanf("%79s", page) != 1) break;
            push(&back, current);
            strcpy(current, page);
            clear(&forward);
        } else if (choice == 2) {
            if (pop(&back, page)) {
                push(&forward, current);
                strcpy(current, page);
            } else puts("No previous page.");
        } else if (choice == 3) {
            if (pop(&forward, page)) {
                push(&back, current);
                strcpy(current, page);
            } else puts("No forward page.");
        } else if (choice != 0) {
            puts("Invalid choice.");
        }
    } while (choice != 0);

    return 0;
}
