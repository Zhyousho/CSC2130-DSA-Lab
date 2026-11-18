# CSC2130 – Data Structures and Algorithms Lab

This repository contains three C mini-projects and a collection of C problem-solving exercises completed on LeetCode.

## Repository structure

```text
CSC2130-DSA-Lab/
├── Mini-Projects/
│   ├── Student-Task-Manager/
│   ├── Browser-History-Simulator/
│   └── Campus-Route-Finder/
├── Problem-Solving/
│   ├── Arrays/
│   ├── Two-Pointers/
│   ├── Binary-Search/
│   ├── Greedy/
│   ├── Dynamic-Programming/
│   └── Linked-Lists/
└── Report/
    └── CSC2130-DSA-Lab-Report.pdf
```

## Mini-projects

| Project | Main concepts |
|---|---|
| Student Task Manager | Singly linked list, traversal, linear search, bubble sort |
| Browser History Simulator | Stacks, LIFO |
| Campus Route Finder | Graph, adjacency matrix, queue, BFS |

Each project folder contains its own `main.c` and README with compilation instructions.

## Problem-solving exercises

The `Problem-Solving` directory contains C function submissions for 15 problems:

1. Two Sum
2. Trapping Rain Water
3. Plus One
4. Jump Game
5. Find First and Last Position of Element in Sorted Array
6. Remove Duplicates from Sorted Array
7. Remove Element
8. Search Insert Position
9. House Robber
10. 3Sum
11. Smallest Stable Index I
12. Container With Most Water
13. Swap Nodes in Pairs
14. Remove Nth Node From End of List
15. Add Two Numbers

Most files use the function signatures expected by LeetCode. Linked-list submissions rely on LeetCode's `struct ListNode` definition. Some array problems require standard headers such as `<stdlib.h>` for `malloc`, `realloc`, and `qsort`.

## Compiling a mini-project

For example:

```bash
gcc -std=c11 -Wall -Wextra Mini-Projects/Student-Task-Manager/main.c -o task-manager
./task-manager
```

Use the corresponding source path and executable name for the other projects.

## LeetCode profile

https://leetcode.com/u/sohammayank/

## Report

The `Report` folder contains the accompanying CSC2130 lab report PDF.

---
