# Hashing concept

## **1. What is Hashing?**

Hashing is a technique to **map data to fixed-size storage** (usually an array) using a **hash function**.

- Instead of searching linearly, you jump directly to the location where data should be stored.
- Used in **hash tables**, **sets**, **dictionaries**, caches, etc.

**Real-world analogy:**
Think of hashing as assigning lockers to students:

- Hash function → student’s roll number mod total lockers.
- Storage → locker.
- Lookup → you go directly to the locker instead of checking each one.

---

## **2. Direct Address Table**

- If keys are small integers within a **small fixed range**, you can use an **array** directly indexed by the key.
- No hash function needed — index = key.

Example:

```python
# Direct address table for keys 0..9
table = [None] * 10
table[3] = "Alice"   # store at index 3
print(table[3])      # O(1) retrieval
```

Drawback → Memory waste if keys are sparse or huge.

---

## **3. Concept of Hashing**

Instead of storing at index = key:

1. Use **hash function** `h(key)` to convert key into a valid index.
2. Store/retrieve from that index.

**Hash function requirements**:

- Deterministic (same key → same index)
- Uniform distribution (avoid clustering)
- Fast to compute

---

## **4. How Hash Function Works**

Example hash function:

```python
def hash_function(key, table_size):
    return key % table_size
```

For strings:

```python
def hash_function_str(key, table_size):
    return sum(ord(ch) for ch in key) % table_size
```

---

## **5. Example of Hash Table with Simple Hashing**

```python
class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        idx = self.hash(key)
        self.table[idx] = value

    def get(self, key):
        idx = self.hash(key)
        return self.table[idx]

ht = HashTable(5)
ht.insert("apple", 100)
print(ht.get("apple"))  # 100
```

---

## **6. Collision Handling**

When two keys hash to the same index, you have a **collision**.

Two main strategies:

1. **Chaining** → Use a list (or linked list) at each index to store multiple items.
2. **Open Addressing** → Find another open slot using a probing strategy.

---

### **6.1 Chaining**

```python
class ChainingHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        idx = self.hash(key)
        for i, (k, v) in enumerate(self.table[idx]):
            if k == key:  # update existing
                self.table[idx][i] = (key, value)
                return
        self.table[idx].append((key, value))

    def get(self, key):
        idx = self.hash(key)
        for k, v in self.table[idx]:
            if k == key:
                return v
        return None

ht = ChainingHashTable(5)
ht.insert("apple", 100)
ht.insert("banana", 200)
print(ht.get("banana"))
```

✅ Pros: Easy to implement, handles high load factor well.
❌ Cons: Needs extra memory for lists.

---

### **6.2 Open Addressing**

Instead of storing multiple items in a list, probe for another empty slot.

#### **a) Linear Probing**

- If `h(key)` is occupied, check `(h(key) + 1) % size`, `(h(key) + 2) % size`, etc.

```python
class LinearProbingHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        idx = self.hash(key)
        for i in range(self.size):
            probe_idx = (idx + i) % self.size
            if self.table[probe_idx] is None or self.table[probe_idx][0] == key:
                self.table[probe_idx] = (key, value)
                return
        raise Exception("Hash table full")

    def get(self, key):
        idx = self.hash(key)
        for i in range(self.size):
            probe_idx = (idx + i) % self.size
            if self.table[probe_idx] is None:
                return None
            if self.table[probe_idx][0] == key:
                return self.table[probe_idx][1]
        return None
```

---

#### **b) Quadratic Probing**

- Probe using `(h(key) + i²) % size`.

```python
probe_idx = (idx + i*i) % self.size
```

✅ Reduces **primary clustering** compared to linear probing.

---

#### **c) Double Hashing**

- Use a **second hash function** for step size:

```python
probe_idx = (h1(key) + i * h2(key)) % size
```

- Ensures better spread, reduces clustering.

---

## **7. Clustering**

- **Primary clustering**: Large contiguous blocks of filled slots in linear probing.
- **Secondary clustering**: In quadratic probing, keys with same initial hash follow same probe sequence.

**Mitigation**:

- Use double hashing.
- Keep load factor low (< 0.7).

---

## **8. Summary Table**

| Method            | Pros                          | Cons                              |
| ----------------- | ----------------------------- | --------------------------------- |
| Direct Address    | O(1) lookup                   | Wastes memory for large key space |
| Chaining          | Easy, works well at high load | Extra memory for chains           |
| Linear Probing    | Simple                        | Primary clustering                |
| Quadratic Probing | Reduces primary clustering    | Still has secondary clustering    |
| Double Hashing    | Best spread                   | Needs good second hash function   |

# Hasing in Python

## **1️⃣ SET in Python (Everything You Need for DSA)** |

A `set` is basically a **hash table for unique elements** with O(1) average time for add/remove/check.

---

### **Creation**

```python
s = {1, 2, 3}            # literal
s = set([1, 2, 3])       # from list
s = set()                # empty set
```

---

### **Add / Remove**

```python
s.add(4)                 # {1, 2, 3, 4}
s.remove(2)              # removes 2 (KeyError if missing)
s.discard(5)             # safe remove, does nothing if missing
s.pop()                  # removes & returns a random element
s.clear()                # remove all elements
```

---

### **Membership Check**

```python
if 3 in s:               # O(1) lookup
    print("Found")
```

---

### **Operator Overloads for Set Algebra**

Python lets you use **math-like operators** instead of verbose method calls:

| Operation            | Operator   | Method Equivalent             |     |
| -------------------- | ---------- | ----------------------------- | --- |
| Union                | `s1 \| s2` | `s1.union(s2)`                |     |
| Intersection         | `s1 & s2`  | `s1.intersection(s2)`         |     |
| Difference           | `s1 - s2`  | `s1.difference(s2)`           |     |
| Symmetric Difference | `s1 ^ s2`  | `s1.symmetric_difference(s2)` |     |
| Subset Check         | `s1 <= s2` | `s1.issubset(s2)`             |     |
| Strict Subset        | `s1 < s2`  | —                             |     |
| Superset Check       | `s1 >= s2` | `s1.issuperset(s2)`           |     |
| Strict Superset      | `s1 > s2`  | —                             |     |

**Example:**

```python
a = {1, 2, 3}
b = {3, 4, 5}

print(a | b)  # {1, 2, 3, 4, 5}
print(a & b)  # {3}
print(a - b)  # {1, 2}
print(a ^ b)  # {1, 2, 4, 5}
print(a <= b) # False
print({1, 2} <= a)  # True
```

---

### **In-place Operator Variants (Faster)**

- `|=` → `update()`
- `&=` → `intersection_update()`
- `-=` → `difference_update()`
- `^=` → `symmetric_difference_update()`

**Example:**

```python
a = {1, 2, 3}
b = {3, 4}
a |= b   # a = a ∪ b → {1, 2, 3, 4}
```

---

### **Other Useful Set Methods**

```python
s.copy()                  # shallow copy
s.isdisjoint(t)           # True if no common elements
```

---

## **2️⃣ DICT in Python (Everything for DSA)**

A `dict` is a **hash map** with O(1) average lookup and insertion.

---

### **Creation**

```python
d = {"a": 1, "b": 2}
d = dict(a=1, b=2)
d = dict([(1, 'one'), (2, 'two')])
```

---

### **Access / Insert**

```python
print(d["a"])             # KeyError if missing
print(d.get("c", 0))      # 0 if key not found

d["c"] = 3                # add new
d.update({"d": 4})        # merge another dict
```

---

### **Remove**

```python
d.pop("a", None)          # remove key safely
d.popitem()               # remove last inserted key-value
d.clear()                 # remove all items
```

---

### **Iteration**

```python
for k in d:               # iterate keys
    ...
for k, v in d.items():    # iterate pairs
    ...
```

---

### **Key Existence**

```python
if "x" in d:              # O(1)
    ...
```

---

### **Setdefault for Fast Init**

```python
adj = {}
adj.setdefault(1, []).append(2)  # if 1 not present, set to []
```

---

### **Dict Comprehension**

```python
squares = {x: x*x for x in range(5)}
```

---

### **Special Trick — Dict Views Behave Like Sets**

```python
d1 = {1: "a", 2: "b"}
d2 = {2: "x", 3: "y"}

print(d1.keys() & d2.keys())  # {2}
print(d1.keys() | d2.keys())  # {1, 2, 3}
print(d1.keys() - d2.keys())  # {1}
```

---

## **3️⃣ Contest-Style Pythonic Shortcuts**

- **Frequency count in 1 line**

```python
from collections import Counter
freq = Counter(arr)
```

- **Check duplicates quickly**

```python
if len(arr) != len(set(arr)):
    print("Duplicates exist")
```

- **Group by key in 1 line**

```python
from collections import defaultdict
groups = defaultdict(list)
for w in words:
    groups["".join(sorted(w))].append(w)
```

- **Two-sum with dict**

```python
seen = {}
for i, num in enumerate(nums):
    if target - num in seen:
        print(seen[target - num], i)
    seen[num] = i
```

- **Intersection in one line**

```python
common = set(list1) & set(list2)
```

---

## Some differences

| Type          | Mutable? | Ordered?  | Keyed Access? | Auto Defaults? | Named Fields? |
| ------------- | -------- | --------- | ------------- | -------------- | ------------- |
| `dict`        | ✅       | ✅ (3.7+) | ✅            | ❌             | ❌            |
| `defaultdict` | ✅       | ✅ (3.7+) | ✅            | ✅             | ❌            |
| `OrderedDict` | ✅       | ✅        | ✅            | ❌             | ❌            |
| `tuple`       | ❌       | ✅        | Index only    | ❌             | ❌            |
| `namedtuple`  | ❌       | ✅        | Index + Name  | ❌             | ✅            |

## Hashable and Non Hashable Types

| Type                      | Mutable? | Hashable? | Notes                                                       |
| ------------------------- | -------- | --------- | ----------------------------------------------------------- |
| `int`                     | ❌       | ✅        | All integers                                                |
| `float`                   | ❌       | ✅        | Includes `inf`, `nan` (though `nan` is special in equality) |
| `bool`                    | ❌       | ✅        | `True`, `False`                                             |
| `str`                     | ❌       | ✅        | Strings are immutable                                       |
| `tuple`                   | ❌       | ✅        | Only if all elements are hashable                           |
| `frozenset`               | ❌       | ✅        | Immutable version of set                                    |
| `bytes`                   | ❌       | ✅        | Immutable sequence of bytes                                 |
| `NoneType`                | ❌       | ✅        | `None`                                                      |
| `complex`                 | ❌       | ✅        | Complex numbers                                             |
| Type                      | Mutable? | Hashable? | Why Not                                                     |
| ------------------------- | -------- | --------- | ----------------------                                      |
| `list`                    | ✅       | ❌        | Mutable sequence                                            |
| `set`                     | ✅       | ❌        | Mutable membership                                          |
| `dict`                    | ✅       | ❌        | Keys/values can change                                      |
| `bytearray`               | ✅       | ❌        | Mutable bytes                                               |
| `collections.deque`       | ✅       | ❌        | Mutable queue                                               |
| `collections.defaultdict` | ✅       | ❌        | Mutable dict subclass                                       |
| `collections.OrderedDict` | ✅       | ❌        | Mutable dict subclass                                       |
| `collections.Counter`     | ✅       | ❌        | Mutable dict subclass                                       |

- A tuple is hashable only if all its elements are hashable.
