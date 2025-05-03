# Lab 3 - List ADT - Array Implementation

## Description

Write a C++ **menu-driven program** to implement **List ADT** using an **array of size 5**.  
Maintain proper boundary conditions and follow good coding practices.

The List ADT should support the following operations:

1. Insert Beginning  
2. Insert End  
3. Insert Position  
4. Delete Beginning  
5. Delete End  
6. Delete Position  
7. Search  
8. Display  
9. Rotate  
10. Exit  

---

## Rotate Operation

The **Rotate** option takes an input `k`, which rotates the entire array to the **right** by `k` times.  
You should implement **at least 3 solutions**, including one that uses **O(1) extra space**.

### Example:

Input: nums = [1, 2, 3, 4, 5], k = 2
Output: [4, 5, 1, 2, 3]


**Explanation:**

- Rotate 1 step to the right → [5, 1, 2, 3, 4]  
- Rotate 2 steps to the right → [4, 5, 1, 2, 3]

---
