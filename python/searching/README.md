Excellent question — binary search is **not limited to sorted arrays**, but to **“monotonicity” or “directional decision-making”**.

---

### ✅ **Key Rule: When to Use Binary Search**

You can use Binary Search if:

> You can determine which side (left or right) to move **based on a condition** that guarantees the target lies there.

---

### 🧠 **Think of Binary Search as a Decision Space Reduction**

- It's not about sorted arrays.
- It’s about reducing the **search space** using some **predictable condition**.
- That condition must allow you to **confidently discard one half** at every step.

---

### 🔍 Examples of Where Binary Search Works (even if array is unsorted)

| Problem Type                                        | Description                                       | Binary Search On                         |
| --------------------------------------------------- | ------------------------------------------------- | ---------------------------------------- |
| 🔄 Rotated Sorted Array                             | One part is sorted, decide direction based on mid | Index                                    |
| 🔼 Peak Element                                     | Check if mid is greater/smaller than neighbors    | Index                                    |
| 📦 Allocate Minimum Pages / Split Array Largest Sum | Divide workload across partitions                 | Value range (e.g., max(arr) to sum(arr)) |
| ⏳ Koko Eating Bananas / Min Time to Paint Boards   | Binary search on answer: how fast / how many      | Time / Rate                              |
| 🎯 Find First/Last Occurrence                       | In sorted array, find leftmost/rightmost index    | Index                                    |
| 📉 Find Square Root / N-th Root                     | Check mid\*mid vs target                          | Value                                    |
| 📈 Aggressive Cows / Placing WiFi Routers           | Maximize min distance                             | Distance (value range)                   |

---

### 🤔 How to Know if You Can Use Binary Search

Ask yourself:

✅ Is the search space **monotonic** (e.g., increasing/decreasing)?
✅ Can I write a condition like:

> “If I choose `mid`, I can decide to go left or right”?

✅ Does the **answer lie in a range** (like time, distance, number of workers)?
✅ Can I define a **function `f(mid)`** that tells me if `mid` is a **valid answer**?

---

### 🧩 Mental Model: Two Binary Search Styles

| Style               | Search Space                 | Example                                   |
| ------------------- | ---------------------------- | ----------------------------------------- |
| 1. **Index-based**  | Binary search on array index | Sorted array, rotated array, peak element |
| 2. **Answer-based** | Binary search on value range | Min max load, capacity, rate, time        |

---

### 🔑 Tip to Master It

Whenever you can't use a hash map, two-pointers, or greedy easily, and you need to **minimize or maximize something** or **search for a feasible condition**, think:

> “Can I binary search the answer instead of the array?”

---

Would you like a visual mindmap of this or a table of binary search patterns categorized by problem type?
