====================================
PROBLEM 1 : ARRAY OPERATIONS
====================================

Given an array and some operations on the array, print the final state of the array.

The array is a[] of size n, indexed from 0 to n-1.

Operations:
S D  : Add integer D to all elements of the array
M D  : Multiply all elements of the array by integer D
D K  : Divide all elements of the array by integer K (integer division, K ≠ 0)
P Y Z: Swap elements a[Y] and a[Z]
R    : Reverse the array
       Example: [1, 2, 4, 3] becomes [3, 4, 2, 1]

--------------------
Input Format
--------------------
- First line contains integer T (number of test cases)
- For each test case:
  - One line contains two integers n and m
    - n : size of array (1 ≤ n ≤ 100)
    - m : number of operations (0 ≤ m ≤ 101)
  - Next line contains n space-separated integers (array elements)
  - Next m lines contain one operation per line

You may assume:
- No overflow or underflow of 32-bit signed integers
- No invalid array index access

--------------------
Output Format
--------------------
- For each test case:
  - Print the case number
  - In the next line, print the final array elements separated by a single space
  - No trailing space after the last element


====================================
PROBLEM 2 : HAPPY RUNNERS (ALICE AND BOB)
====================================

Alice and Bob ran for N days.

On the i-th day:
- Alice ran Ai meters
- Bob ran Bi meters

Rules:
- Alice is unhappy if Bob ran strictly more than twice Alice's distance
- Bob is unhappy if Alice ran strictly more than twice Bob's distance
- Otherwise, they are happy

Examples:
- Alice = 200, Bob = 500
  Alice unhappy, Bob happy
- Alice = 500, Bob = 240
  Alice happy, Bob unhappy
- Alice = 300, Bob = 500
  Both happy

Task:
Count how many days both Alice and Bob were happy.

--------------------
Input Format
--------------------
- First line contains integer T (number of test cases)
- For each test case:
  - First line contains integer N (number of days)
  - Second line contains N space-separated integers A1, A2, ..., AN
  - Third line contains N space-separated integers B1, B2, ..., BN

--------------------
Output Format
--------------------
- For each test case, print the number of days when both Alice and Bob were happy

--------------------
Constraints
--------------------
- 1 ≤ T ≤ 1000
- 1 ≤ N ≤ 100
- 1 ≤ Ai, Bi ≤ 10^5


====================================
PROBLEM 3 : DIVIDING ARRAY INTO THREE SETS
====================================

Vitaly has an array of n distinct integers.
He wants to divide the array into three non-empty sets such that:

1. Product of elements in the first set is negative (< 0)
2. Product of elements in the second set is positive (> 0)
3. Product of elements in the third set is zero (= 0)
4. Each number appears in exactly one set

--------------------
Input Format
--------------------
- First line contains integer n (3 ≤ n ≤ 100)
- Second line contains n space-separated distinct integers
  a1, a2, ..., an (|ai| ≤ 1000)

--------------------
Output Format
--------------------
- First line:
  - Integer n1 (n1 > 0)
  - Followed by n1 integers of the first set
- Second line:
  - Integer n2 (n2 > 0)
  - Followed by n2 integers of the second set
- Third line:
  - Integer n3 (n3 > 0)
  - Followed by n3 integers of the third set

Notes:
- The solution is guaranteed to exist
- Any valid solution may be printed


====================================
PROBLEM 4 : TWO SUM
====================================

Given an array of integers nums[] and an integer target.

Task:
- Return YES if there exist two different elements such that:
  nums[i] + nums[j] = target
- Also return the indices of those two elements
- Otherwise, return NULL

Rules:
- The same element cannot be used twice
- Example:
  If target = 10 and nums[0] = 10
  nums[0] + nums[0] is NOT allowed


====================================
PROBLEM 5 : JUMP GAME
====================================

You are given an integer array nums[].

- You start at the first index (index 0)
- Each element represents the maximum jump length from that position

Task:
- Return true if you can reach the last index
- Otherwise, return false

--------------------
Examples
--------------------

Example 1:
Input:  nums = [2, 3, 1, 1, 4]
Output: true
Explanation:
- Jump from index 0 to 1
- Then jump 3 steps to reach the last index

Example 2:
Input:  nums = [3, 2, 1, 0, 4]
Output: false
Explanation:
- You always reach index 3
- Jump length at index 3 is 0, so you cannot move further

--------------------
Constraints
--------------------
- 1 ≤ nums.length ≤ 10^4
- 0 ≤ nums[i] ≤ 10^5
