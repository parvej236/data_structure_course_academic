# Data Structures Implementation in C++

This repository contains comprehensive implementations of various data structures and algorithms in C++ for the Data Structures course (Level 2, Term 1) at Chittagong University of Engineering & Technology (CUET). These implementations serve both as course assignments and learning resources.

## Course Information

- **Institution**: Chittagong University of Engineering & Technology (CUET)
- **Course**: Data Structures (CSE-241)
- **Level**: 2
- **Term**: 1

## Course Instructors

**Course Teachers:**
- **Animesh Chandra Roy** - Assistant Professor, Dept. of CSE, CUET
- **Md. Atiqul Islam Rizvi** - Assistant Professor, Dept. of CSE, CUET

## Textbook

**Data Structures with C** by Seymour Lipschutz

[Download PDF](https://gnindia.dronacharya.info/IT/3rdSem/Downloads/DataStructure/Books/DATA-STRUCTURE-BOOK-3.pdf)

## Requirements

- C++ compiler (GCC/G++ recommended)
- Basic knowledge of C++ programming
- Understanding of data structure concepts

## How to Compile and Run

To compile any of the programs, use the following command:
```bash
g++ -o output_name source_file.cpp
```

For example:
```bash
g++ -o array_operations lab1-array/1_array_operatoins.cpp
./array_operations
```

## Lab Overview

### Lab 1: Array Operations
**Location**: `lab1-array/`

This lab covers fundamental array operations and algorithmic problems:

1. **Array Operations** (`1_array_operatoins.cpp`)
   - Add integer to all elements
   - Multiply all elements by integer
   - Divide all elements by integer
   - Swap specific elements
   - Reverse array

2. **Happy Runners** (`2_happy_runners.cpp`)
   - Determine happiness criteria for two runners (Alice and Bob)
   - Count days when both are happy
   - Alice unhappy if Bob ran > 2× her distance
   - Bob unhappy if Alice ran > 2× his distance

3. **Dividing Array Into Three Sets** (`3_diving_array_into_three_sets.cpp`)
   - Divide array into three non-empty sets
   - First set: product is negative
   - Second set: product is positive
   - Third set: product is zero

4. **Two Sum** (`4_two_sum.cpp`)
   - Find two different elements that sum to target
   - Return indices of found elements or NULL if not found

5. **Jump Game** (`5_jump_game.cpp`)
   - Determine if you can reach the last array index
   - Each element represents maximum jump length from that position

---

### Lab 2: String Operations
**Location**: `lab2-string/`

This lab focuses on string manipulation and pattern matching:

1. **World Chess Championship** (`1_world_chess_championship.cpp`)
   - Calculate prize money based on game results
   - Scoring: Win = 2 pts, Draw = 1 pt each, Loss = 0 pts
   - Champion gets 60% or 55% (if tied) of prize pool
   - Input: String of 14 characters (C=Carlsen win, N=Chef win, D=Draw)

2. **Happy String** (`2_happy_string.cpp`)
   - Generate k-th lexicographically ordered "happy string" of length n
   - Happy string: contains only a, b, c with no adjacent characters being same
   - Returns empty string if fewer than k happy strings exist

3. **Shortest Palindrome** (`3_shortest_palindrome.cpp`)
   - Find shortest palindrome by adding characters to the right of string
   - Calculate minimum length of resulting palindrome
   - Handles very large strings efficiently

4. **Add One to Large Number** (`4_add_one_to_large_number.cpp`)
   - Add 1 to extremely large numbers (up to 10^200000)
   - Handle as string since numbers exceed standard integer limits
   - Efficiently manage carry-over logic

---

### Lab 3: Linked List Fundamentals
**Location**: `lab3-link_list/`

This lab covers basic singly linked list operations:

1. **Link List Operations** (`link_list_perations.cpp`)
   - Traversing linked list
   - Searching (unsorted and sorted lists)
   - Insertion (beginning, middle, end, and sorted)
   - Deletion (at location and for specific item)

2. **Problem 1: Critical Points** (`problem1.cpp`)
   - Find local minima and local maxima in linked list
   - Local minima: both adjacent nodes have greater values
   - Local maxima: both adjacent nodes have smaller values
   - First and last nodes are not considered critical

3. **Problem 2: Middle Element** (`problem2.cpp`)
   - Find middle element of singly linked list
   - Middle position = floor(N/2) + 1 from head

---

### Lab 4: Advanced Linked List Operations
**Location**: `lab4-link_list_more/`

This lab implements specialized linked list variants:

1. **Grounded Header Linked List** (`grounded_header_linked_list.cpp`)
   - Linked list with header node at beginning
   - Operations: traversing, searching, insertion, deletion

2. **Circular Header Linked List** (`circular_header_linked_list.cpp`)
   - Circular linked list with header node
   - Last node points back to header node
   - Operations: traversing, searching, insertion, deletion

3. **Doubly Linked List** (`doubly_linked_list.cpp`)
   - Two-way circular linked list (doubly linked)
   - Each node has pointers to both next and previous nodes
   - Operations: traversing, insertion, deletion

---

### Lab 5: Queue, Stack, and Recursion
**Location**: `lab5-queue_stack_recursion/`

This lab explores stack, queue, and recursive applications:

1. **Stack Performance** (`stack_perfomance.cpp`)
   - Stack operations: push, pop, peek
   - LIFO (Last-In-First-Out) behavior
   - Performance analysis

2. **Queue Performance** (`queue_performance.cpp`)
   - Queue operations: enqueue, dequeue, peek
   - FIFO (First-In-First-Out) behavior
   - Performance metrics

3. **Deque Performance** (`deque_performance.cpp`)
   - Double-ended queue operations
   - Insert/delete from both ends
   - Performance benchmarking

4. **Priority Queue Performance** (`priority_queue_performance.cpp`)
   - Elements ordered by priority
   - High priority elements dequeued first
   - Performance analysis

5. **Infix to Postfix** (`infixToPostfix.cpp`)
   - Convert infix expressions to postfix notation
   - Evaluate postfix expressions
   - Use stack-based approach

6. **Tower of Hanoi** (`tower_of_hanoi_performance.cpp`)
   - Classic recursive puzzle solution
   - Move disks from source to destination peg
   - Minimum moves calculation: 2^n - 1

---

### Lab 6: Binary Trees
**Location**: `lab6-binary_tree/`

This lab covers tree creation and traversal algorithms:

1. **Binary Tree** (`bt.cpp`)
   - Binary tree creation and traversal
   - Preorder, Inorder, Postorder traversal (recursive and iterative)
   - Uses stack for iterative approaches

2. **Binary Search Tree (BST)** (`BST.cpp`)
   - BST creation with ordered insertion
   - Searching elements in BST
   - Deletion from BST
   - Maintains sorted property

---

### Lab 7: M-Way Trees
**Location**: `lab7-m_way_tree/`

This lab explores multi-way trees:

1. **M-Way Tree Performance** (`m_way_performance.cpp`)
   - Trees with more than 2 children per node
   - Operations and performance analysis
   - Useful for databases and file systems

---

### Lab 8: Reserved
**Location**: `lab8/`

Contains: `READIT.txt` (placeholder for future content)

---

### Lab 9: Heaps and Graphs
**Location**: `lab9-heap_graph/`

This lab covers heap structures and graph algorithms:

1. **Huffman Min Heap** (`huffman_min_heap.cpp`)
   - Min heap creation and operations
   - Insertion in min heap
   - Searching in min heap
   - Deletion from min heap
   - Huffman coding algorithm using min heap

2. **Graph BFS/DFS** (`graph_bfs_dfs.cpp`)
   - Graph creation and representation
   - Breadth-First Search (BFS) traversal
   - Depth-First Search (DFS) traversal
   - Applications in connectivity and pathfinding

---

## File Structure

```
.
├── README.md
├── lab1-array/
│   ├── 1_array_operatoins.cpp
│   ├── 2_happy_runners.cpp
│   ├── 3_diving_array_into_three_sets.cpp
│   ├── 4_two_sum.cpp
│   ├── 5_jump_game.cpp
│   └── problem_statement.md
├── lab2-string/
│   ├── 1_world_chess_championship.cpp
│   ├── 2_happy_string.cpp
│   ├── 3_shortest_palindrome.cpp
│   ├── 4_add_one_to_large_number.cpp
│   └── problem_statement.md
├── lab3-link_list/
│   ├── link_list_perations.cpp
│   ├── problem1.cpp
│   ├── problem2.cpp
│   └── problems_statement.md
├── lab4-link_list_more/
│   ├── circular_header_linked_list.cpp
│   ├── doubly_linked_list.cpp
│   ├── grounded_header_linked_list.cpp
│   └── problem_statement.md
├── lab5-queue_stack_recursion/
│   ├── deque_performance.cpp
│   ├── infixToPostfix.cpp
│   ├── priority_queue_performance.cpp
│   ├── queue_performance.cpp
│   ├── stack_perfomance.cpp
│   ├── tower_of_hanoi_performance.cpp
│   └── problems_statement.md
├── lab6-binary_tree/
│   ├── BST.cpp
│   ├── bt.cpp
│   └── problem_statement.md
├── lab7-m_way_tree/
│   └── m_way_performance.cpp
├── lab8/
│   └── READIT.txt
└── lab9-heap_graph/
    ├── graph_bfs_dfs.cpp
    ├── huffman_min_heap.cpp
    └── problems_statement.md
```

## Key Concepts Covered

### Data Structures
- Arrays
- Strings
- Singly Linked Lists
- Grounded Header Linked Lists
- Circular Linked Lists
- Doubly Linked Lists
- Stacks
- Queues
- Deques
- Priority Queues
- Binary Trees
- Binary Search Trees
- M-Way Trees
- Heaps (Min Heap)
- Graphs

### Algorithms
- Array manipulation and searching
- String processing
- Tree traversal (preorder, inorder, postorder)
- Graph traversal (BFS, DFS)
- Huffman coding
- Tower of Hanoi
- Expression conversion (Infix to Postfix)

## Compilation and Execution Tips

- Each file is independent and can be compiled separately
- Default build task: `C/C++: g++ build active file`
- Ensure g++ is installed: `which g++`
- Debug compilation with: `g++ -g -o program program.cpp`

## Contributing

Feel free to contribute by:
1. Forking the repository
2. Creating a new branch for your feature
3. Submitting a pull request

## License

This project is open source and available for educational purposes.

## Contact

- GitHub: [@parvej236](https://github.com/parvej236)
