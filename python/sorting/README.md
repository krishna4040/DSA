## ✅ **1. Built-in Sorting Functions (Most Pythonic)**

### 🔹 `sorted()` — returns a new sorted list

```python
nums = [5, 3, 9, 1]
sorted_nums = sorted(nums)  # [1, 3, 5, 9]
```

### 🔹 `.sort()` — sorts in-place

```python
nums.sort()
```

### 🔹 Reverse sort

```python
sorted(nums, reverse=True)
```

### 🔹 Sort by key (e.g. length, absolute value, etc.)

```python
words = ['banana', 'pie', 'Washington', 'book']
sorted(words, key=len)
sorted(nums, key=abs)
```

---

## ✅ **2. Pythonic Tricks**

### 🔹 Sort tuples by second item

```python
pairs = [(1, 3), (2, 2), (3, 1)]
sorted(pairs, key=lambda x: x[1])
```

### 🔹 Sort by multiple keys

```python
data = [('Alice', 25), ('Bob', 30), ('Alice', 22)]
sorted(data, key=lambda x: (x[0], x[1]))  # sort by name, then age
```

### 🔹 Sort ignoring case

```python
names = ['bob', 'Alice', 'jane', 'David']
sorted(names, key=str.lower)
```

---

## ✅ **3. Custom Sorts with `functools.cmp_to_key`**

Use when you need full control (e.g. comparator logic like C++ `sort()`):

```python
from functools import cmp_to_key

def custom_cmp(a, b):
    return a - b  # ascending

sorted_list = sorted([5, 2, 9], key=cmp_to_key(custom_cmp))
```

---

## ✅ **4. Useful Modules with Sorting Algorithms**

| Module             | Use Case                                         |
| ------------------ | ------------------------------------------------ |
| `heapq`            | Efficient heap-based sorting, priority queues    |
| `bisect`           | Insert into sorted lists efficiently             |
| `numpy`            | Fast sorting on large arrays                     |
| `pandas`           | DataFrame sorting                                |
| `sortedcontainers` | Sorted list, dict, set that auto-maintains order |

---

## ✅ **5. `heapq` – Heap Sort / Priority Queue**

```python
import heapq

nums = [5, 1, 9, 3]
heapq.heapify(nums)  # in-place min-heap

heapq.heappop(nums)  # 1
heapq.heappush(nums, 2)
```

For getting k largest/smallest:

```python
heapq.nlargest(2, nums)
heapq.nsmallest(2, nums)
```

---

## ✅ **6. `bisect` – Maintain Sorted Lists**

```python
import bisect

arr = [1, 3, 4, 6]
bisect.insort(arr, 5)  # [1, 3, 4, 5, 6]
```

---

## ✅ **7. Sorting with `numpy`**

```python
import numpy as np

arr = np.array([5, 3, 1])
np.sort(arr)  # returns a new sorted array
```

---

## ✅ **8. Sorting in `pandas`**

```python
import pandas as pd

df = pd.DataFrame({'name': ['Alice', 'Bob'], 'age': [25, 20]})
df.sort_values(by='age')
```

---

## ✅ **9. `sortedcontainers` (3rd-party)**

Install:

```bash
pip install sortedcontainers
```

Use:

```python
from sortedcontainers import SortedList

sl = SortedList([3, 1, 2])
sl.add(0)  # maintains sorted order
print(sl)  # SortedList([0, 1, 2, 3])
```

---

## ✅ **10. Stable Sort (default in Python)**

Python’s sort is **stable**, meaning it maintains relative order for equal elements. You can exploit this:

```python
data = [('a', 3), ('b', 1), ('a', 2)]
# First sort by second item
data = sorted(data, key=lambda x: x[1])
# Then stable sort by first item
data = sorted(data, key=lambda x: x[0])
```

---

## ⚡ Quick Sorting Recipes

| Task               | One-liner                               |
| ------------------ | --------------------------------------- |
| Descending sort    | `sorted(arr, reverse=True)`             |
| Sort by last char  | `sorted(words, key=lambda w: w[-1])`    |
| Sort dict by value | `sorted(d.items(), key=lambda x: x[1])` |
| Top K largest      | `heapq.nlargest(k, arr)`                |
| Insert in sorted   | `bisect.insort(arr, val)`               |

---

## 🧠 Bonus: Timing Sort Performance

```python
import timeit

timeit.timeit('sorted([5,3,1,2,4])', number=100000)
```

---

Python's built-in `sort()` and `sorted()` functions use a highly optimized sorting algorithm called **Timsort**.

---

## 🧠 **Timsort Explained**

- **Full Name:** Tim Peters' Sort (after the Python core developer who created it)
- **Used in:** `list.sort()` and `sorted()`
- **Time Complexity:**
  - **Best case:** $$O(n)$$ (when list is already sorted or nearly sorted)
  - **Average case:** $$O(n \log n)$$
  - **Worst case:** $$O(n \log n)$$
- **Space Complexity:** $$O(n)$$

---

## ✅ **Why Timsort?**

Timsort is a hybrid algorithm that combines:

- **Merge Sort** (for guaranteed $$O(n \log n)$$ performance)
- **Insertion Sort** (for small or nearly sorted segments)

It works in **three main steps**:

1. **Divide into Runs**:
   - It scans the list to find ascending or descending sequences (called _runs_).
   - Descending runs are reversed to become ascending.

2. **Insertion Sort on Small Runs**:
   - If runs are too small, it extends them using insertion sort (efficient for small sizes).

3. **Merge Runs**:
   - Then, like merge sort, it merges the runs together using a stack and specific merging criteria to maintain performance guarantees.

---

## 🔍 Real-world Benefits

- Stable: keeps order of equal elements.
- Fast on real-world data (which often has partial order).
- Adaptive: takes advantage of existing order in the list.
- Used in other languages too: Java, Android, etc.

---

## ✅ In Summary

```python
sorted(my_list)
my_list.sort()
```

Both use **Timsort**, which is:

> 🧠 “A hybrid stable sorting algorithm derived from merge sort and insertion sort, optimized for real-world data.”

---

Let me know if you'd like a visualization or to implement Timsort from scratch in Python.
