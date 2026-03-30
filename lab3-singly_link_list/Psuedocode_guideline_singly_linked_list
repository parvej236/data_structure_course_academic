# 📘 Linked List – Pseudocode Guide (Based on C++ Implementation)

## 📌 Node Structure

```
struct node
    info : integer
    link : pointer to node
```

---

## 🔗 1. Traversal (Display List)

```
Procedure showlist(start)
    ptr ← start

    WHILE ptr ≠ NULL DO
        PRINT ptr.info
        ptr ← ptr.link
    END WHILE

    PRINT newline
End Procedure
```

---

## 🔍 2. Searching

### (a) Search in Unsorted List

```
Procedure search_unsort(start, key)
    ptr ← start
    idx ← 0

    WHILE ptr ≠ NULL DO
        IF ptr.info = key THEN
            RETURN idx
        END IF
        ptr ← ptr.link
        idx ← idx + 1
    END WHILE

    RETURN -1
End Procedure
```

---

### (b) Search in Sorted List

```
Procedure search_sort(start, key)
    ptr ← start
    idx ← 0

    WHILE ptr ≠ NULL AND ptr.info ≤ key DO
        IF ptr.info = key THEN
            RETURN idx
        END IF
        ptr ← ptr.link
        idx ← idx + 1
    END WHILE

    RETURN -1
End Procedure
```

---

## ➕ 3. Insertion Operations

### (a) Insert at Beginning

```
Procedure insert_beg(start, data)
    CREATE newnode

    IF memory not available THEN
        PRINT "Overflow"
        RETURN
    END IF

    newnode.info ← data
    newnode.link ← start
    start ← newnode
End Procedure
```

---

### (b) Insert at End

```
Procedure insert_end(start, data)
    CREATE newnode
    newnode.info ← data
    newnode.link ← NULL

    IF start = NULL THEN
        start ← newnode
        RETURN
    END IF

    ptr ← start

    WHILE ptr.link ≠ NULL DO
        ptr ← ptr.link
    END WHILE

    ptr.link ← newnode
End Procedure
```

---

### (c) Insert at Position

```
Procedure insert_position(start, data, pos)
    IF pos < 1 THEN
        PRINT "Invalid position"
        RETURN
    END IF

    CREATE newnode
    newnode.info ← data

    IF pos = 1 THEN
        newnode.link ← start
        start ← newnode
        RETURN
    END IF

    ptr ← start

    FOR i ← 1 TO pos - 2 DO
        IF ptr = NULL THEN
            PRINT "Invalid position"
            RETURN
        END IF
        ptr ← ptr.link
    END FOR

    newnode.link ← ptr.link
    ptr.link ← newnode
End Procedure
```

---

### (d) Insert in Sorted List

```
Procedure insert_sorted(start, data)
    CREATE newnode
    newnode.info ← data

    IF start = NULL OR data < start.info THEN
        newnode.link ← start
        start ← newnode
        RETURN
    END IF

    ptr ← start

    WHILE ptr.link ≠ NULL AND ptr.link.info < data DO
        ptr ← ptr.link
    END WHILE

    newnode.link ← ptr.link
    ptr.link ← newnode
End Procedure
```

---

## 4. Deletion Operations

### (a) Delete by Position

```
Procedure delete_pos(start, pos)
    IF start = NULL THEN
        PRINT "Underflow: List is empty"
        RETURN
    END IF

    IF pos <= 0 THEN
        PRINT "Invalid position"
        RETURN
    END IF

    IF pos = 1 THEN
        temp ← start
        start ← start.link
        DELETE temp
        RETURN
    END IF

    ptr ← start

    FOR i ← 1 TO pos - 2 DO
        IF ptr = NULL THEN
            PRINT "Position does not exist"
            RETURN
        END IF
        ptr ← ptr.link
    END FOR

    IF ptr = NULL OR ptr.link = NULL THEN
        PRINT "Position does not exist"
        RETURN
    END IF

    temp ← ptr.link
    ptr.link ← temp.link
    DELETE temp
End Procedure
```

---

### (b) Delete by Value

```
Procedure delete_item(start, data)
    IF start = NULL THEN
        PRINT "Underflow: List is empty"
        RETURN
    END IF

    prev ← NULL
    curr ← start

    WHILE curr ≠ NULL AND curr.info ≠ data DO
        prev ← curr
        curr ← curr.link
    END WHILE

    IF curr = NULL THEN
        PRINT "Item not found"
        RETURN
    END IF

    IF prev = NULL THEN
        start ← curr.link
    ELSE
        prev.link ← curr.link
    END IF

    DELETE curr
    PRINT "Item deleted"
End Procedure
```

---

## ⚡ Summary

* Traversal → O(n)
* Search → O(n)
* Insert at beginning → O(1)
* Insert at end → O(n)
* Insert at position → O(n)
* Delete → O(n)

---

✨ This README is based on your corrected C++ implementation and is ready for exams or GitHub usage.
