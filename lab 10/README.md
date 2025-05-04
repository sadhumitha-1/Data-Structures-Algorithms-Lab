# Lab 10 - Priority Queue ADT – Heap

## A. Utilize C++ STL if needed. Write a C++ program to solve the following

Polycarp was presented with some sequence of integers *a* of length *n* (1 ≤ aᵢ ≤ *n*). A sequence can make Polycarp happy only if it consists of different numbers (i.e. distinct numbers).  
In order to make his sequence like this, Polycarp is going to make some (possibly zero) number of moves.  
In one move, he can:  
1. remove the first (leftmost) element of the sequence.

For example, in one move, the sequence [3,1,4,3] will produce the sequence [1,4,3], which consists of different numbers.  

Determine the minimum number of moves he needs to make so that in the remaining sequence all elements are different.  
In other words, find the length of the smallest prefix of the given sequence *a*, after removing which all values in the sequence will be unique.

### Input  
The first line of the input contains a single integer *t* (1 ≤ *t* ≤ 10⁴) — the number of test cases.  
Each test case consists of two lines.  
The first line contains an integer *n* (1 ≤ *n* ≤ 2⋅10⁵) — the length of the given sequence *a*.  
The second line contains *n* integers a₁, a₂, …, aₙ (1 ≤ aᵢ ≤ *n*) — elements of the given sequence *a*.  
It is guaranteed that the sum of *n* values over all test cases does not exceed 2⋅10⁵.

### Output  
For each test case print your answer on a separate line — the minimum number of elements that must be removed from the beginning of the sequence so that all remaining elements are different.

### Note  
It is easy to see that all the remaining sequences contain only distinct elements.  
In each test case, the shortest matching prefix was removed.  

![Testacases](https://github.com/sadhumitha-1/Data-Structures-Algorithms-Lab/blob/main/lab%2010/images/1.png?raw=true)

---

## B. Utilize C++ STL if needed. Write a C++ program to solve the following

Three guys play a game: first, each person writes down *n* distinct words of length 3.  
Then, they total up the number of points as follows:  
2. if a word was written by one person — that person gets 3 points,  
3. if a word was written by two people — each of the two gets 1 point,  
4. if a word was written by all — nobody gets any points.

In the end, how many points does each player have?

### Input  
The input consists of multiple test cases.  
The first line contains an integer *t* (1 ≤ *t* ≤ 100) — the number of test cases. The description of the test cases follows.  
The first line of each test case contains an integer *n* (1 ≤ *n* ≤ 1000) — the number of words written by each person.  
The following three lines each contain *n* distinct strings — the words written by each person. Each string consists of 3 lowercase English characters.

### Output  
For each test case, output three space-separated integers — the number of points each of the three guys earned.  
You should output the answers in the same order as the input; the *i*-th integer should be the number of points earned by the *i*-th guy.

### Note  
In the first test case:  
1. The word `abc` was written by the first and third guys — they each get 1 point.  
2. The word `def` was written by the second guy only — he gets 3 points.  

![Testacases](https://github.com/sadhumitha-1/Data-Structures-Algorithms-Lab/blob/main/lab%2010/images/1.png?raw=true)

---

## C. Write a separate C++ menu-driven program to implement Priority Queue ADT using a max heap.  
Maintain proper boundary conditions and follow good coding practices.  
The Priority Queue ADT has the following operations:

1. Insert  
2. Delete  
3. Display  
4. Search  
5. Sort (Heap Sort)  
6. Exit  

What is the time complexity of each of the operations? (K4)
