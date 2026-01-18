====================================
PROBLEM 1 : WORLD CHESS CHAMPIONSHIP
====================================

The World Chess Championship is about to start.

14 Classical games will be played between Chef and Carlsen in the championship.
Each game has one of three outcomes:
- Carlsen wins
- Chef wins
- Draw

Scoring Rules:
- Winner of a game gets 2 points
- Loser gets 0 points
- In case of a draw, both players get 1 point each

The total prize pool of the championship is 100 * X.

After all 14 games:
- If one player has strictly more points, he is declared champion.
  - Winner gets 60 * X
  - Loser gets 40 * X
- If the total points are tied:
  - Defending champion Carlsen is declared the winner
  - Winner gets 55 * X
  - Loser gets 45 * X

You are given the results of all 14 games.
Output the prize money that Carlsen receives.

The results are given as a string of length 14 consisting of:
- 'C' : victory by Carlsen
- 'N' : victory by Chef
- 'D' : draw

--------------------
Input Format
--------------------
- First line contains an integer T, the number of test cases
- For each test case:
  - First line contains integer X
  - Second line contains a string of length 14 with characters C, N, D

--------------------
Output Format
--------------------
- For each test case, print the total prize money won by Carlsen

--------------------
Constraints
--------------------
- 1 ≤ T ≤ 1000
- 1 ≤ X ≤ 10^6
- Length of string = 14
- String contains only C, N, D


====================================
PROBLEM 2 : HAPPY STRING
====================================

A happy string:
- Consists only of characters: a, b, c
- No two adjacent characters are the same

Examples of happy strings:
- "abc", "ac", "b", "abcbabcbcb"

Not happy strings:
- "aa", "baa", "ababbc"

Given two integers n and k:
- Consider all happy strings of length n
- Sort them in lexicographical order
- Return the k-th string
- If there are fewer than k happy strings, return an empty string

--------------------
Input / Output Examples
--------------------

Example 1:
Input:  n = 1, k = 3
Output: "c"

Example 2:
Input:  n = 1, k = 4
Output: ""

Example 3:
Input:  n = 3, k = 9
Output: "cab"

--------------------
Constraints
--------------------
- 1 ≤ n ≤ 10
- 1 ≤ k ≤ 100


====================================
PROBLEM 3 : SHORTEST PALINDROME
====================================

A string is a palindrome if it reads the same forwards and backwards.

Examples:
- Palindromes: "abba", "madam"
- Not palindrome: "adam"

You are given a non-empty string S containing only lowercase English letters.
The string may or may not be a palindrome.

Rules:
- You are allowed to add characters only to the RIGHT side of the string
- You can add any characters
- The final string must be a palindrome
- The palindrome length must be minimum possible

Example:
Input string: "bababa"
Possible palindromes:
- "bababababab"
- "babababab"
- "bababab"

Shortest palindrome is "bababab"

--------------------
Input Format
--------------------
- First line contains integer T (number of test cases)
- For each test case:
  - One line containing string S

--------------------
Output Format
--------------------
- For each test case, print:
  Case X: Y
  where X is case number and Y is length of shortest palindrome

--------------------
Constraints
--------------------
- 1 ≤ T ≤ 10
- 1 ≤ length(S) ≤ 10^6
- Dataset is large, use fast I/O

--------------------
Examples
--------------------

Input:  bababababa
Output: Case 1: 11

Input:  pqrs
Output: Case 2: 7

Input:  anncbaaababaaa
Output: Case 3: 19


====================================
PROBLEM 4 : ADD ONE TO LARGE NUMBER
====================================

You are given a very large number N.
You need to print N + 1.

The number is too large to fit in standard integer data types.
You must take the input as a string and manipulate its digits.

--------------------
Input Format
--------------------
- First line contains integer T (number of test cases)
- For each test case:
  - One line containing a string N

--------------------
Output Format
--------------------
- For each test case, print the string representing N + 1

--------------------
Constraints
--------------------
- 1 ≤ T ≤ 100
- 1 ≤ N ≤ 10^200000 - 1
- Total number of digits across all test cases ≤ 4 * 10^5
