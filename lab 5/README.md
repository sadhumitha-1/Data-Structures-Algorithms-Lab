# Lab 5 - List ADT – Circular and Doubly Linked List

## Part A – Doubly Linked List

Write a C++ **menu-driven program** to implement List ADT using a **doubly linked list with a tail**.  
Maintain proper boundary conditions and follow good coding practices.

### Operations:

1. Insert Beginning  
2. Insert End  
3. Insert Position  
4. Delete Beginning  
5. Delete End  
6. Delete Position  
7. Search  
8. Display  
9. Exit  

> ❓ **Question:** What is the time complexity of each of the above operations? (K4)

---

## Part B – Circular Linked List

Write a C++ **menu-driven program** to implement List ADT using a **circular linked list**.  
Maintain proper boundary conditions and follow good coding practices.

### Operations:

1. Insert Beginning  
2. Insert End  
3. Insert Position  
4. Delete Beginning  
5. Delete End  
6. Delete Position  
7. Search  
8. Display  
9. Exit  

> ❓ **Question:** What is the time complexity of each of the above operations? (K4)

---

## Part C – Round-Robin Scheduling Simulation

An operating system allocates a **fixed CPU time slot** for processes using the **round-robin scheduling algorithm**.  
The fixed time slot is initialized before the start of the program.  
Implement this scheduling using a **circular linked list**.

Include the logic in a **header file** and write a **menu-driven** C++ program to perform the following operations:

### Operations:

1. Insert Process  
2. Execute  
3. Exit  

### Operation Details:

- **Insert Process**:  
  - Prompts the user for an integer (processing time)  
  - Adds the process to the end of the circular linked list  

- **Execute**:  
  - Removes the process at the beginning  
  - Subtracts the fixed time slice from its remaining time  
  - If time ≤ 0, the process is complete  
  - Else, insert the remaining time at the end of the list  

> ❓ **Question:** What is the time complexity of each of the above operations? (K4)

---
