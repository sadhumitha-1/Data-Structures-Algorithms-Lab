# Lab 9 - Tree ADT – Binary Search Tree

## A. Utilize C++ STL to solve the following (K5)

Nene invented a new game based on an increasing sequence of integers a₁, a₂, ..., aₖ.  
In this game, initially **n** players are lined up in a row. In each of the rounds of this game, the following happens:

- Nene finds the a₁-th, a₂-th, ..., aₖ-th players in a row. They are kicked out of the game simultaneously.  
- If the *i*-th player in a row should be kicked out, but there are fewer than *i* players in a row, they are skipped.

Once no one is kicked out of the game in some round, all the players that are still in the game are declared as winners.

**Example**:  
Consider the game with `a = [3, 5]` and `n = 5` players. Let the players be named A, B, ..., E:

- **Round 1**: Line = ABCDE → kick players C (3rd) and E (5th) → Result: ABD  
- **Round 2**: Line = ABD → kick D (3rd) only → Result: AB  
- **Round 3**: No valid aᵢ positions → Game ends.  
- Winners: Players A and B.

Nene has not yet decided how many people would join the game initially.  
You are given **g** integers n₁, n₂, ..., n_q and must answer the following for each 1 ≤ *i* ≤ *q*:

- How many people would be declared as winners if there are nᵢ players in the game initially?

### **Input**
- First line: Integer `t` (1 ≤ t ≤ 1000) — number of test cases  
- For each test case:
  - First line: Two integers `k` and `q` (1 < k, q < 100) — elimination sequence length and number of simulations  
  - Second line: `k` integers a₁, a₂, …, aₖ (1 ≤ a₁ < a₂ < … < aₖ < 100)  
  - Third line: `q` integers n₁, n₂, …, n_q (1 ≤ nᵢ < 100)

### **Output**
- For each nᵢ, output the number of winners (remaining players) after all elimination rounds.

![Testacases](https://github.com/sadhumitha-1/Data-Structures-Algorithms-Lab/blob/main/lab%209/images/1.png?raw=true)

---

## B. Utilize C++ STL to solve the following (K5)

There are **n** participants in a competition, participant *i* having a strength of sᵢ.  
Every participant wonders how much of an advantage they have over the next strongest participant.  
Each participant *i* wants to know the difference between sᵢ and sⱼ, where *j* is the strongest participant other than *i* (may be negative).

### **Input**
- First line: Integer `t` (1 ≤ t ≤ 1000) — number of test cases  
- For each test case:
  - First line: Integer `n` (2 ≤ n ≤ 2×10⁵) — number of participants  
  - Second line: `n` integers s₁, s₂, ..., sₙ (1 ≤ sᵢ ≤ 10⁹)

### **Output**
- For each test case, output `n` space-separated integers.  
  For each 1 ≤ *i* ≤ *n*, output the difference between sᵢ and the maximum strength of any other participant.

![Testacases](https://github.com/sadhumitha-1/Data-Structures-Algorithms-Lab/blob/main/lab%209/images/2.png?raw=true)

---

## C. Write a separate C++ menu-driven program to implement Tree ADT using a binary search tree

Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations:

1. Insert  
2. Preorder  
3. Inorder  
4. Postorder  
5. Search  
6. Exit  

**What is the time complexity of each of the operations? (K4)**

---

## D. Add a "construct expression tree" method to the binary tree data structure

- Import `stack` from STL to construct the expression tree  
- Import Tree ADT program into another program that:
  - Gets a valid postfix expression
  - Constructs and prints the expression tree

### The program has the following operations:

1. Postfix Expression  
2. Construct Expression Tree  
3. Preorder  
4. Inorder  
5. Postorder  
6. Exit  

**What is the time complexity of each of the operations? (K4)**
