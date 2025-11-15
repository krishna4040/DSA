# Linked List — Complete Learning Sheet

**Goal:** ultra‑concise, practical cheat–sheet for singly, doubly, circular & XOR linked lists + advanced topics and Python code.

---

# 1. Concept Overview & Recognition

**Definition (1‑line):** A linked list is a linear collection of nodes where each node stores a value and a reference (pointer) to the next (and/or previous) node.

**Analogy:** train carriages: each carriage (node) holds cargo (value) and a coupling (pointer) to the next carriage.

**When to use:**

- frequent inserts/deletes in middle or head (O(1) with pointer) vs arrays (O(n)).
- you need stable iterators/pointers to elements while mutating the list.
- streaming or unbounded sequences where you don't need random access.
- when memory locality isn't critical (cache unfriendly).

---

# 2. Core DSA Concepts Related

| Concept                            | Why it matters                                                              |
| ---------------------------------- | --------------------------------------------------------------------------- |
| Pointers/References                | Fundamental to node linking.                                                |
| Two‑pointer techniques (slow/fast) | Find middle, detect cycles, nth-from-end.                                   |
| Recursion                          | Natural for recursive traversal and reversal.                               |
| Merge sort on lists                | Best sorting algorithm for linked lists (O(n log n) without random access). |
| Memory management                  | Sentinel/dummy nodes, **slots**, object pools in contests.                  |

**Important algorithms:** reverse (iterative/recursive), find middle, detect/remove cycle (Floyd), merge two sorted lists, merge‑sort for linked list, nth-from-end, intersection, clone (random pointer), reorder list, flatten multilevel lists, XOR linked list traversal.

---

# 3. Python Implementations (patterns & snippets)

## 3.1 Minimal singly linked list (idiomatic)

```python
class Node:
    __slots__ = ("val","next")
    def __init__(self, val, nxt=None):
        self.val = val
        self.next = nxt

class SLL:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, val):
        node = Node(val)
        if not self.head:
            self.head = self.tail = node
        else:
            self.tail.next = node
            self.tail = node

    def prepend(self, val):
        node = Node(val, self.head)
        self.head = node
        if not self.tail:
            self.tail = node

    def __iter__(self):
        cur = self.head
        while cur:
            yield cur.val
            cur = cur.next

    def __repr__(self):
        return 'SLL([' + ', '.join(map(str, self)) + '])'
```

## 3.2 Doubly linked list (dataclass)

```python
from dataclasses import dataclass

@dataclass
class DNode:
    val: int
    prev: 'DNode' = None
    next: 'DNode' = None

class DLL:
    def __init__(self):
        self.head = None
        self.tail = None
    # append/prepend/remove similar but update prev links
```

## 3.3 Circular linked list (single node points to itself)

```python
class CircularLL:
    def __init__(self):
        self.head = None

    def append(self, val):
        node = Node(val)
        if not self.head:
            node.next = node
            self.head = node
        else:
            node.next = self.head.next
            self.head.next = node
            self.head.val, node.val = node.val, self.head.val  # rotate trick
```

(there are multiple insertion conventions for circular lists)

## 3.4 XOR linked list (safe pure‑Python simulation)

- In low‑level languages XOR lists store `prev ^ next` pointer. Python can't directly xor addresses safely; simulate using a dict mapping ids.

```python
class XNode:
    def __init__(self, val):
        self.val = val
        self.npx = 0  # xor of ids

class XORList:
    def __init__(self):
        self.head_id = 0
        self.nodes = {}  # id -> node

    def _id(self, obj):
        return id(obj) if obj is not None else 0

    def add(self, val):
        node = XNode(val)
        nid = id(node)
        self.nodes[nid] = node
        if self.head_id == 0:
            self.head_id = nid
            return
        # append at front (update pointers)
        head = self.nodes[self.head_id]
        head.npx ^= nid
        node.npx = self.head_id
        self.head_id = nid

    def traverse(self):
        prev_id = 0
        cur_id = self.head_id
        while cur_id:
            cur = self.nodes[cur_id]
            yield cur.val
            next_id = prev_id ^ cur.npx
            prev_id, cur_id = cur_id, next_id
```

> Note: realistic XOR lists in Python are rare — prefer this only for learning/CS‑theory.

## 3.5 Contest / static memory pool style (arrays for speed)

```python
MAX = 100000
val = [0]*MAX
nxt = [-1]*MAX
head = -1
unused = 0

def new_node(x):
    global unused
    val[unused] = x
    nxt[unused] = -1
    unused += 1
    return unused - 1

# link using indices (fast, avoids object overhead)
```

## 3.6 Use `collections.deque` as a practical alternative

- `deque` supports O(1) append/pop at both ends and is often the correct Pythonic choice when you need list-like queue/deque semantics.

---

# 4. All Methods & Operations (cheat table + mini examples)

**Complexities (typical):**

| Operation                 |                    SLL |  DLL | Circular |                  XOR |
| ------------------------- | ---------------------: | ---: | -------: | -------------------: |
| Insert head               |                   O(1) | O(1) |     O(1) |                 O(1) |
| Insert tail               | O(n) (unless tail ref) | O(1) |     O(1) | O(1) w/ tracked tail |
| Delete head               |                   O(1) | O(1) |     O(1) |                 O(1) |
| Delete arbitrary by value |                   O(n) | O(n) |     O(n) |                 O(n) |
| Search                    |                   O(n) | O(n) |     O(n) |                 O(n) |
| Random access (indexing)  |                   O(n) | O(n) |     O(n) |                 O(n) |
| Reverse (in‑place)        |                   O(n) | O(n) |     O(n) |                 O(n) |

Below are _standard operations_ with syntax, tiny example and complexity. For brevity `ll` refers to an instance of `SLL`/`DLL`.

- **Create**
  - Syntax: `ll = SLL()`
  - Example: `ll = SLL()` — empty list. Complexity: O(1)

- **Insert / Append**
  - Syntax: `ll.append(x)` or `ll.prepend(x)`
  - Example: `ll.append(5)` → adds 5 at tail.
  - Complexity: append O(1) with tail, prepend O(1)

- **Insert after node**
  - Syntax: `ll.insert_after(node, x)`
  - Example: `ll.insert_after(node_ref, 7)`
  - Complexity: O(1) (given node reference)

- **Delete by value**
  - Syntax: `ll.remove(val)`
  - Example: `ll.remove(5)` — removes first 5 found.
  - Complexity: O(n)

- **Delete by position**
  - Syntax: `ll.remove_at(i)`
  - Example: `ll.remove_at(0)` removes head.
  - Complexity: O(n)

- **Search**
  - Syntax: `ll.find(val)`
  - Example: `node = ll.find(3)`
  - Complexity: O(n)

- **Traverse / iterate**
  - Syntax: `for v in ll: ...`
  - Example: `list(ll)` -> snapshot list of values.
  - Complexity: O(n)

- **Reverse (iterative)**
  - Syntax: `ll.reverse()`
  - Example: `ll.reverse()`
  - Complexity: O(n)

- **Reverse (recursive)**
  - Syntax: `ll.reverse_recursive()`
  - Complexity: O(n) time, O(n) stack

- **Find middle**
  - Technique: slow/fast pointers
  - Example snippet:

    ```python
    slow = fast = ll.head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    # slow is middle
    ```

  - Complexity: O(n)

- **Detect cycle & find cycle start**
  - Detect: Floyd's cycle detection (tortoise & hare)
  - Find start: after detection, reset one pointer to head and move both by 1 until equal.
  - Complexity: O(n)

- **Nth from end**
  - Two pointers: advance fast by n, then move both until fast hits end; slow is answer.
  - Complexity: O(n)

- **Merge two sorted lists**
  - Iterative merge using dummy head. Complexity: O(n+m)

- **Merge sort (list)**
  - Split by middle, recursively sort halves, merge. Complexity: O(n log n), O(log n) stack

- **Intersection of two lists**
  - Align lengths, walk together; or use two-pointer trick with switching heads. Complexity: O(n+m)

- **Clone list with random pointer**
  - Standard 3‑pass algorithm (weave nodes, fix randoms, unweave). Complexity: O(n)

- **Rotate, Partition, Reorder**
  - Common LeetCode operations; all O(n).

---

# 5. Operator Overloading (useful dunder methods)

| Overload             | Behavior       | Example                                     |
| -------------------- | -------------- | ------------------------------------------- |
| `__iter__`           | iterate values | `for v in ll:`                              |
| `__len__`            | `len(ll)`      | implement counting (cache if needed)        |
| `__contains__`       | `x in ll`      | linear search                               |
| `__getitem__`        | `ll[i]`        | O(i) traversal, can return slice too (O(n)) |
| `__setitem__`        | `ll[i] = v`    | O(i)                                        |
| `__add__`            | `ll1 + ll2`    | concatenation (O(n) to copy)                |
| `__repr__`/`__str__` | printable form | `repr(ll)`                                  |

**Example: implement `__len__` and `__contains__`**

```python
class SLL:
    ...
    def __len__(self):
        i = 0
        cur = self.head
        while cur:
            i += 1
            cur = cur.next
        return i

    def __contains__(self, x):
        return any(v == x for v in self)
```

> Note: indexing `ll[i]` is allowed but O(n); prefer converting to list if you need many random accesses.

---

# 6. Tips, Tricks & Pitfalls

**Tips**

- Use a **dummy/sentinel head** to simplify insert/delete edge cases.
- Keep `tail` reference to make append O(1).
- Use `__slots__` or `dataclass(frozen=True)` for memory/perf improvements.
- Use `deque` when you only need O(1) ends, not middle operations.
- For contest code, use array pools (index‑based) to avoid object overhead.

**Pitfalls**

- Forgetting to update `tail` when deleting last node.
- Off‑by‑one in loops (head / tail handling).
- Recursion depth on very long lists (prefer iterative reversal).
- Relying on object identity vs value equality when searching.
- XOR lists: hard to debug and rarely worth it in Python.

---

# 7. Applications

**Real world**: memory allocator free lists, undo/redo stacks, LRU caches (DLL + hashmap), adjacency lists for sparse graphs (conceptual), OS job queues.

**Algorithmic**: building blocks for stacks & queues, LRU, merging streams, implementing ordered sets with limited operations, solving common interview problems (reverse, detect cycle, merge sorted lists).

---

# 8. Examples

## Example 1 — Basic operations (create, append, remove, traverse)

```python
ll = SLL()
ll.append(1)
ll.append(2)
ll.prepend(0)
print(list(ll))        # [0,1,2]
ll.remove(1)
print(list(ll))        # [0,2]
ll.reverse()
print(list(ll))        # [2,0]
```

**Explanation (1‑line each):** append adds to tail; prepend adds to head; remove scans and unlinks; reverse rewires pointers in one pass.

## Example 2 — LeetCode style: Remove Nth node from end (step‑by‑step)

**Problem:** remove nth node from end and return head.

**Idea:** use two pointers `fast` and `slow`. Move `fast` n steps, then move both until `fast` reaches end. `slow.next` is node to remove.

```python
def remove_nth_from_end(head, n):
    dummy = Node(0, head)
    fast = slow = dummy
    for _ in range(n):
        fast = fast.next
    while fast.next:
        fast = fast.next
        slow = slow.next
    # slow.next is node to delete
    slow.next = slow.next.next
    return dummy.next
```

**Step by step:**

1. `dummy` avoids deleting head special case.
2. Move `fast` n steps ahead.
3. Walk both until `fast.next` is None; `slow.next` is target.
4. Bypass `slow.next`.

**Complexity:** O(n) time, O(1) extra space.

---

# Quick Cheat — one‑page commands

- Create: `ll = SLL()`
- Append: `ll.append(x)` O(1)
- Prepend: `ll.prepend(x)` O(1)
- Search: `node = ll.find(x)` O(n)
- Remove: `ll.remove(x)` O(n)
- Reverse: `ll.reverse()` O(n)
- Middle: slow/fast pointers O(n)
- Cycle detect: Floyd's algorithm O(n)
- Use `deque` if only ends are needed.

---

If you want, I can:

- produce a one‑page printable PDF version,
- add more solved problems (merge sort, reorder list, clone random pointer) with step‑by‑step traces, or
- give a minimal 40–line cheat file for contests (index pool implementation).

Tell me which (if any) and I will add it to the sheet.
