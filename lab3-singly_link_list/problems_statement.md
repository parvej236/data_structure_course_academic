====================================
Link List: Operatioins
====================================

1. Traversing
2. Searching (unsorted)
3. Searching (sorted)
4. Insertion (beginning)
5. Insertion (at loc, at position)
6. Insertion (ending)
7. Insertion (sorted)
8. Deletion (at loc)
9. Deletion (for ITEM)

====================================
PROBLEM 1 : CRITICAL POINTS IN LINKED LIST
====================================

Given the head of a linked list, find the number of critical points.
The first and last nodes are NOT considered critical points.

Definitions:
- A node is a LOCAL MINIMA if:
  - Both the previous node and the next node have values greater than the current node
- A node is a LOCAL MAXIMA if:
  - Both the previous node and the next node have values smaller than the current node

Local minima and local maxima are collectively called critical points.

--------------------
Input Format
--------------------
- First line contains integer N (number of elements in the linked list)
- Second line contains N space-separated integers representing node values

--------------------
Output Format
--------------------
- Print the number of critical points in the linked list

--------------------
Constraints
--------------------
- 1 ≤ N ≤ 10^5
- 1 ≤ Node.data ≤ 10^9

--------------------
Sample 1
--------------------
Input:
8
1 2 3 3 3 5 1 3 2

Output:
2

Explanation:
- Node with value 1 is a local minima
- Node with value 5 is a local maxima
- Total critical points = 2

--------------------
Sample 2
--------------------
Input:
7
1 2 3 2 1 3 2 3

Output:
3

Explanation:
- 3rd node is a critical point
- 5th node is a critical point
- 6th node is a critical point
- Total critical points = 3


====================================
PROBLEM 2 : MIDDLE ELEMENT OF LINKED LIST
====================================

You are given the head of a singly linked list A of length N.
The values in the list are:
A1, A2, A3, ..., AN

The middle element of a linked list of length N is defined as:
- The (floor(N / 2) + 1)-th element from the head

--------------------
Input Format
--------------------
- First line contains integer T (number of test cases)
- For each test case:
  - First line contains integer N
  - Second line contains N space-separated integers A1, A2, ..., AN

--------------------
Output Format
--------------------
- For each test case, print the value of the middle element of the linked list

--------------------
Sample Input and Output
--------------------

Input:
3
5
1 2 3 4 5
6
1 2 3 4 5 6
4
10 1 6 12

Output:
3
4
6
