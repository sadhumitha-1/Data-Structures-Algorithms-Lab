# Lab 4 - List ADT - Singly Linked List

## Part A

Write a C++ **menu-driven program** to implement **List ADT** using a **singly linked list**.  
Maintain proper boundary conditions and follow good coding practices.

### Operations to Implement:

1. Insert Beginning  
2. Insert End  
3. Insert Position  
4. Delete Beginning  
5. Delete End  
6. Delete Position  
7. Search  
8. Display  
9. Display Reverse  
10. Reverse Link  
11. Exit  

- **Option 9**: Does **not** change the structure of the list. It only prints the contents of the list in reverse order.  
- **Option 10**: Actually reverses the links in the list.  

### Reverse Linked List (Option 10):

The visual logic is shown below:

![Reverse Linked List](https://github.com/sadhumitha-1/Data-Structures-Algorithms-Lab/blob/main/lab4/images/Linked%20list%20reversal.png?raw=true)

### Question:

What is the **time complexity** of each of the above operations?

---

## Part B

Write a C++ **menu-driven program** to implement List ADT using a **singly linked list** with the following feature:

- You have a `gethead()` **private member function** that returns the address of the head of the list.

### Operations:

1. Insert Ascending  
2. Merge  
3. Display  
4. Exit  

- **Insert Ascending**: Inserts a node so that the list is always in **ascending order**  
- **Merge**: Takes two lists as input and merges them into a third list in **ascending order**  

### Additional Requirement:

Convert the implementation into a **header file** and include it in a separate C++ file.  
The second file should maintain **3 lists** and provide the following operations:

1. Insert List1  
2. Insert List2  
3. Merge into List3  
4. Display  
5. Exit  

### Time Complexity:

- Operation 1 (Insert List1/2): **O(n)**  
- Operation 2 (Insert List2): **O(m)**  
- Operation 3 (Merge): **O(n + m)**
