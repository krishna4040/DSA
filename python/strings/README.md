# 🧵 Strings in Python – The Ultimate Pythonic Guide

---

## 1. **String Basics**

- Strings are **immutable sequences of characters**.
- You can **index, slice, iterate**, but not modify in place.

```python
s = "python"
print(s[0])     # 'p'
print(s[-1])    # 'n'
print(s[1:4])   # 'yth' (slicing: end exclusive)
```

🔑 Pythonic: **Use slicing instead of loops** for substring extraction.

---

## 2. **String Creation & Concatenation**

```python
s1 = "hello"
s2 = "world"

# Bad: repeated concatenation
s = s1 + " " + s2

# Pythonic
s = f"{s1} {s2}"      # f-string
s = " ".join([s1, s2]) # best when combining many
```

🔑 `str.join` is faster & memory efficient than `+`.

---

## 3. **Common String Methods**

```python
s = "   Python3.9  "

print(s.strip())      # remove spaces → "Python3.9"
print(s.lower())      # "python3.9"
print(s.upper())      # "PYTHON3.9"
print(s.startswith("Py"))  # True
print(s.endswith("9"))     # True
print(s.replace("3.9", "rocks"))  # "   Pythonrocks  "
print(s.split())      # ["Python3.9"]
print(",".join(["a","b","c"]))  # "a,b,c"
```

🔑 Pythonic: **Chain methods** for clean transformations.

```python
s = "  DSA  "
print(s.strip().lower())  # 'dsa'
```

---

## 4. **Checking Characters**

```python
s = "abc123"

print(s.isalpha())  # False
print(s.isdigit())  # False
print(s.isalnum())  # True
print("abc".isalpha()) # True
print("123".isdigit()) # True
```

---

## 5. **Reversing Strings**

```python
s = "python"
print(s[::-1])   # "nohtyp"
```

🔑 One-liner reverse: `s[::-1]` instead of loops.

---

## 6. **Finding & Counting**

```python
s = "abracadabra"
print(s.find("ra"))      # 2
print(s.rfind("ra"))     # 9 (last occurrence)
print(s.count("a"))      # 5
```

---

## 7. **Character ↔ ASCII**

```python
print(ord('a'))  # 97
print(chr(97))   # 'a'
```

🔑 Useful for mapping `'a'..'z'` → `0..25`.

---

## 8. **Iterating Strings (Pythonic way)**

```python
s = "abc"

# With index
for i, c in enumerate(s):
    print(i, c)
```

---

## 9. **Collections for Strings**

### Counter (Frequency Map)

```python
from collections import Counter

s = "banana"
freq = Counter(s)
print(freq)     # {'a':3, 'b':1, 'n':2}

# Most common char
print(freq.most_common(1))  # [('a',3)]
```

### defaultdict

```python
from collections import defaultdict
d = defaultdict(int)
for c in "banana":
    d[c] += 1
print(d)  # {'b':1, 'a':3, 'n':2}
```

### deque (sliding window)

```python
from collections import deque
dq = deque("abcd")
dq.append("e")
dq.popleft()
print("".join(dq))  # "bcde"
```

---

## 10. **Regex (`re`)**

```python
import re
s = "abc123xyz456"

print(re.findall(r"\d+", s))   # ['123','456']
print(re.sub(r"\d+", "#", s))  # 'abc#xyz#'
```

🔑 Regex shines for **pattern extraction**.

---

## 11. **itertools for Strings**

```python
from itertools import permutations, combinations

print(["".join(p) for p in permutations("abc", 2)])
# ['ab','ac','ba','bc','ca','cb']

print(["".join(c) for c in combinations("abc", 2)])
# ['ab','ac','bc']
```

---

## 12. **string module**

```python
import string

print(string.ascii_lowercase)  # 'abcdefghijklmnopqrstuvwxyz'
print(string.digits)           # '0123456789'
```

---

## 13. **Problem Patterns & Pythonic Solutions**

### 🔹 Palindrome

```python
s = "racecar"
print(s == s[::-1])  # True
```

### 🔹 Anagram

```python
from collections import Counter
print(Counter("listen") == Counter("silent"))  # True
```

### 🔹 Rotation

```python
s1, s2 = "abcde", "cdeab"
print(s2 in s1+s1)  # True
```

### 🔹 Substrings (brute force)

```python
s = "abc"
subs = [s[i:j] for i in range(len(s)) for j in range(i+1, len(s)+1)]
print(subs)  # ['a','ab','abc','b','bc','c']
```

### 🔹 Longest substring without repeat (sliding window)

```python
s = "abcabcbb"
seen = {}
start = maxlen = 0
for i, c in enumerate(s):
    if c in seen and seen[c] >= start:
        start = seen[c] + 1
    seen[c] = i
    maxlen = max(maxlen, i - start + 1)
print(maxlen)  # 3
```

---

## 14. **Performance Tips**

- Use `list` + `"".join()` for building strings.
- Avoid nested loops if sliding window / hash map can work.
- For large parsing, regex may be faster than manual checks.

---

# 🌟 TL;DR — Pythonic String Idioms

- Reverse: `s[::-1]`
- Anagram: `Counter(s1) == Counter(s2)`
- Rotation: `s2 in s1+s1`
- Frequency map: `Counter(s)`
- Unique chars: `len(set(s)) == len(s)`
- Substrings: `[s[i:j] for i in range(n) for j in range(i+1, n+1)]`
- Clean transform: `s.strip().lower().replace(" ", "_")`

---

# 🔢 Int ↔ String in Python (DSA-focused)

## 1. **Integer → String**

### Basic

```python
x = 123
s = str(x)       # "123"
```

### With formatting

```python
x = 255
print(f"{x}")       # "255" (f-string)
print(bin(x))       # "0b11111111"
print(oct(x))       # "0o377"
print(hex(x))       # "0xff"
```

🔑 Use built-in `bin`, `oct`, `hex` for base conversions.

---

## 2. **String → Integer**

### Basic

```python
s = "123"
x = int(s)       # 123
```

### With different bases

```python
print(int("1010", 2))   # 10 (binary → decimal)
print(int("1f", 16))    # 31 (hex → decimal)
```

---

## 3. **Integer → List of Digits**

```python
x = 12345
digits = list(str(x))        # ['1','2','3','4','5']
digits_int = [int(d) for d in str(x)]  # [1,2,3,4,5]
```

---

## 4. **List of Digits → Integer**

```python
digits = [1, 2, 3, 4, 5]
x = int("".join(map(str, digits)))   # 12345
```

---

## 5. **Digit Problems (Common in DSA)**

### Sum of digits

```python
x = 12345
print(sum(int(d) for d in str(x)))  # 15
```

### Palindrome number

```python
x = 121
print(str(x) == str(x)[::-1])   # True
```

### Reverse integer

```python
x = 12345
rev = int(str(x)[::-1])   # 54321
```

---

## 6. **Character ↔ Integer (ord/chr)**

### Single char → ASCII

```python
print(ord('a'))   # 97
print(ord('A'))   # 65
```

### ASCII → char

```python
print(chr(97))   # 'a'
print(chr(65))   # 'A'
```

👉 Useful for `'a'..'z' → 0..25` mappings:

```python
index = ord('c') - ord('a')  # 2
```

---

## 7. **Special Cases**

### Roman numerals ↔ int

(common interview Q!)

```python
roman = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
s = "MCMIV"  # 1904
res = 0
for i in range(len(s)):
    if i+1 < len(s) and roman[s[i]] < roman[s[i+1]]:
        res -= roman[s[i]]
    else:
        res += roman[s[i]]
print(res)  # 1904
```

### Excel column ↔ number

```python
# Excel column: A=1, B=2 ... Z=26, AA=27 ...
s = "AB"
res = 0
for c in s:
    res = res*26 + (ord(c)-ord('A')+1)
print(res)  # 28
```

---

# ⚡ Pythonic Patterns (Int ↔ String)

| Problem             | Trick                                     |
| ------------------- | ----------------------------------------- |
| Int → Str           | `str(x)`                                  |
| Str → Int           | `int(s)`                                  |
| Binary/Hex convert  | `bin(x), oct(x), hex(x)` / `int(s, base)` |
| Digits of number    | `[int(d) for d in str(x)]`                |
| Rebuild from digits | `int("".join(map(str, digits)))`          |
| Palindrome number   | `str(x) == str(x)[::-1]`                  |
| Reverse number      | `int(str(x)[::-1])`                       |
| Char → index (a=0)  | `ord(c) - ord('a')`                       |
| Index → char        | `chr(i + ord('a'))`                       |

---

# 🧵 String Concepts in Python for DSA

## 1. **Splitting Sentences into Words**

```python
s = "hello world from python"
words = s.split()        # ['hello','world','from','python']
words = s.split("o")     # ['hell', ' w', 'rld fr', 'm pyth', 'n']
```

🔑 Pythonic: `s.split()` (no arg) automatically splits on **any whitespace**.

---

## 2. **Joining Words into Sentence**

```python
words = ["hello", "world"]
sentence = " ".join(words)   # "hello world"
```

🔑 Always use `" ".join()` (not `+` concatenation).

---

## 3. **Reverse Word Order**

```python
s = "I love Python"
print(" ".join(reversed(s.split())))  # "Python love I"
```

---

## 4. **Reverse Characters in Each Word**

```python
s = "I love Python"
print(" ".join(w[::-1] for w in s.split()))
# "I evol nohtyP"
```

---

## 5. **Count Words / Unique Words**

```python
s = "apple banana apple orange banana"
from collections import Counter
print(Counter(s.split()))
# {'apple':2, 'banana':2, 'orange':1}
```

---

## 6. **Find Longest / Shortest Word**

```python
s = "I love programming in Python"
words = s.split()
print(max(words, key=len))  # 'programming'
print(min(words, key=len))  # 'I'
```

---

## 7. **Sentence Normalization**

```python
s = "   Hello,   PYTHON!!   "
print(" ".join(s.strip().lower().split()))
# "hello, python!!"
```

🔑 Common in cleaning input strings before solving.

---

## 8. **Word Frequencies (Most Common Word)**

```python
s = "cat bat mat cat bat cat"
words = s.split()
from collections import Counter
print(Counter(words).most_common(1))
# [('cat', 3)]
```

---

## 9. **Check Word Pattern** (classic Leetcode)

```python
# "abba" vs "dog cat cat dog" → True
pattern, sentence = "abba", "dog cat cat dog"
words = sentence.split()
print(len(set(pattern)) == len(set(words)) == len(set(zip(pattern, words))))
# True
```

---

## 10. **Sentence as Substring Problem**

### Check if word exists

```python
s = "data structures and algorithms"
print("algorithms" in s)  # True
```

### Find index

```python
print(s.find("structures"))  # 5
```

---

## 11. **Sorting Words**

```python
s = "python java c cpp"
words = s.split()
print(sorted(words))        # ['c','cpp','java','python']
print(sorted(words, key=len)) # ['c','cpp','java','python']
```

---

## 12. **Sentence Palindrome (Ignore spaces & punctuation)**

```python
import re
s = "A man, a plan, a canal: Panama"
clean = re.sub(r"[^a-z0-9]", "", s.lower())
print(clean == clean[::-1])   # True
```

---

## 13. **Word Capitalization**

```python
s = "hello world"
print(s.title())     # "Hello World"
print(s.capitalize()) # "Hello world"
```

---

## 14. **Advanced Parsing (Regex)**

```python
import re
s = "email: test@mail.com, phone: 123-456"
print(re.findall(r"\w+@\w+\.\w+", s))   # ['test@mail.com']
print(re.findall(r"\d{3}-\d{3}", s))   # ['123-456']
```

---

# ⚡ Pythonic Sentence & Word Tricks

| Problem                  | Pythonic Trick                                   |
| ------------------------ | ------------------------------------------------ |
| Split into words         | `s.split()`                                      |
| Join words               | `" ".join(words)`                                |
| Reverse word order       | `" ".join(reversed(s.split()))`                  |
| Reverse each word        | `" ".join(w[::-1] for w in s.split())`           |
| Word count               | `Counter(s.split())`                             |
| Longest/shortest word    | `max(words, key=len)` / `min(words, key=len)`    |
| Most common word         | `Counter(words).most_common(1)`                  |
| Word pattern check       | `len(set(zip(pattern, words))) == ...`           |
| Clean spaces & normalize | `" ".join(s.split())`                            |
| Palindrome sentence      | `re.sub(r"[^a-z0-9]","",s.lower()) == ...[::-1]` |

---

## 🔑 Operator Overloading in Strings

### 1. **Concatenation (`+`)**

- Overloaded by `__add__`.
- Joins two strings into one.

```python
a = "Hello"
b = "World"
print(a + " " + b)   # "Hello World"
```

⚠️ Costly in loops (O(n)), because strings are immutable → creates new string each time.

---

### 2. **Repetition (`*`)**

- Overloaded by `__mul__` and `__rmul__`.
- Repeats the string multiple times.

```python
s = "ab"
print(s * 3)  # "ababab"
```

---

### 3. **Comparison (`<`, `>`, `<=`, `>=`, `==`, `!=`)**

- Overloaded by `__lt__`, `__gt__`, `__eq__`, etc.
- Lexicographical (dictionary order), not by length.

```python
print("apple" < "banana")   # True
print("10" < "2")           # True (since '1' < '2')
```

---

### 4. **Membership (`in`, `not in`)**

- Uses `__contains__`.

```python
s = "datastructures"
print("data" in s)       # True
print("algo" not in s)   # True
```

---

### 5. **Indexing & Slicing (`[]`)**

- Strings support `__getitem__`.
- Returns character(s).

```python
s = "python"
print(s[0])     # "p"
print(s[-1])    # "n"
print(s[1:4])   # "yth"
```

---

### 6. **Iteration (`for x in s`)**

- Uses `__iter__`.

```python
for ch in "AI":
    print(ch)   # 'A' then 'I'
```

---

### 7. **Length (`len`)**

- Uses `__len__`.

```python
print(len("hello"))  # 5
```

---

# Pattern Searching

| Algorithm      | Purpose                     | Time Complexity                  | Use Case                       |
| -------------- | --------------------------- | -------------------------------- | ------------------------------ |
| **Rabin–Karp** | Hash-based substring search | Avg: O(n+m), Worst: O(nm)        | Multiple pattern search        |
| **KMP**        | Efficient substring search  | Always O(n+m)                    | Deterministic, avoids rechecks |
| **Regex**      | Pattern matching language   | Depends on engine (often slower) | Complex rules like `[0-9]+`    |
