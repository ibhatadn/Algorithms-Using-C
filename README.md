# 🖥️ Algorithms in C

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

This repository contains my personal implementations of various algorithms written in **C** during my B.Tech CSE program.  
Each program is implemented from scratch, focusing on clarity, efficiency, and a deep understanding of the underlying concepts.


The aim of this repo is to serve as:
- A reference for students & learners
- A personal archive of my DSA journey

---


## 📂 Contents

- **Sorting Algorithms**
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort


- **Searching Algorithms**
  - Linear Search
  - Binary Search

- **Graph Algorithms**
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Dijkstra's Algorithm
  - Floyd-Warshall Algorithm
  - Kruskal’s Algorithm
  - Prim’s Algorithm

- **Other Algorithms**
  - Tower of Hanoi
  - Matrix Multiplication
  - String Matching (Longest Common Sub Squence)

---

## 🚀 Example

```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
