# Bit Manipulation & Number Systems - Complete Learning Guide

## 1. Concept Overview & Recognition

### Definition & Intuition

**Bit manipulation** is the process of algorithmically manipulating bits or other pieces of data shorter than a word. Think of it like **flipping switches** on a control panel - each bit is a switch that can be ON (1) or OFF (0).

**Real-life analogy**: Imagine a row of light switches. You can turn individual lights on/off, check if a light is on, or control multiple lights at once with master switches.

### When to Recognize This Approach

- Problems involving **powers of 2** (1, 2, 4, 8, 16, ...)
- **Set operations** (union, intersection, subset checks)
- **Optimization** problems requiring O(1) space for boolean flags
- **Counting** problems (number of 1s, unique numbers)
- Keywords: "binary", "toggle", "flip", "XOR", "even/odd", "powers of 2"
- **Memory-efficient** solutions needed

---

## 2. Core DSA Concepts Related

| Concept                   | Description                                    | Application                       |
| ------------------------- | ---------------------------------------------- | --------------------------------- |
| **Binary Representation** | Numbers stored as sequences of 0s and 1s       | Foundation for all bit operations |
| **Two's Complement**      | Method to represent negative numbers           | Understanding signed integers     |
| **Bitwise Operations**    | AND, OR, XOR, NOT, shifts                      | Core manipulation tools           |
| **Bit Masking**           | Using patterns to isolate/modify specific bits | Selective bit operations          |
| **Binary Logarithms**     | log₂(n) - position of highest set bit          | Finding bit positions             |

---

## 3. Important Algorithms

| Algorithm             | Purpose                         | Time Complexity       |
| --------------------- | ------------------------------- | --------------------- |
| **Brian Kernighan's** | Count set bits efficiently      | O(number of set bits) |
| **Bit Reversal**      | Reverse bits in a number        | O(log n)              |
| **Power of 2 Check**  | Check if number is power of 2   | O(1)                  |
| **Single Number**     | Find unique element using XOR   | O(n)                  |
| **Subset Generation** | Generate all subsets using bits | O(2ⁿ)                 |

---

## 4. Python Implementations & Number Systems

### Binary Representation

```python
# Convert to binary
bin(10)        # '0b1010'
format(10, 'b') # '1010'
f"{10:b}"      # '1010'

# Convert from binary
int('1010', 2)  # 10
int('0b1010', 2)  # 10

# Other number systems
oct(10)        # '0o12' (octal)
hex(10)        # '0xa' (hexadecimal)
int('12', 8)   # 10 (from octal)
int('a', 16)   # 10 (from hex)
```

### Pythonic Bit Manipulation

```python
# Get bit length
(10).bit_length()  # 4
(10).bit_count()   # 2 (Python 3.10+)

# Work with large numbers
import math
math.log2(1024)    # 10.0
```

---

## 5. All Bitwise Operations & Methods

| Operation       | Symbol | Python Syntax | Example  | Result | Time |
| --------------- | ------ | ------------- | -------- | ------ | ---- |
| **AND**         | &      | `a & b`       | `5 & 3`  | `1`    | O(1) |
| **OR**          | \|     | `a \| b`      | `5 \| 3` | `7`    | O(1) |
| **XOR**         | ^      | `a ^ b`       | `5 ^ 3`  | `6`    | O(1) |
| **NOT**         | ~      | `~a`          | `~5`     | `-6`   | O(1) |
| **Left Shift**  | <<     | `a << n`      | `5 << 1` | `10`   | O(1) |
| **Right Shift** | >>     | `a >> n`      | `5 >> 1` | `2`    | O(1) |

### Essential Bit Operations

```python
# Check if bit is set
def is_bit_set(num, pos):
    return (num & (1 << pos)) != 0

# Set a bit
def set_bit(num, pos):
    return num | (1 << pos)

# Clear a bit
def clear_bit(num, pos):
    return num & ~(1 << pos)

# Toggle a bit
def toggle_bit(num, pos):
    return num ^ (1 << pos)

# Get rightmost set bit
def rightmost_set_bit(num):
    return num & -num

# Clear rightmost set bit
def clear_rightmost_set_bit(num):
    return num & (num - 1)
```

---

## 6. Operator Overloading

| Operator | Usage        | Example      | Result     |
| -------- | ------------ | ------------ | ---------- |
| `&`      | Bitwise AND  | `5 & 3`      | `1`        |
| `\|`     | Bitwise OR   | `5 \| 3`     | `7`        |
| `^`      | Bitwise XOR  | `5 ^ 3`      | `6`        |
| `~`      | Bitwise NOT  | `~5`         | `-6`       |
| `<<`     | Left shift   | `5 << 2`     | `20`       |
| `>>`     | Right shift  | `20 >> 2`    | `5`        |
| `&=`     | In-place AND | `x &= mask`  | Modifies x |
| `\|=`    | In-place OR  | `x \|= mask` | Modifies x |

---

## 7. Tips, Tricks & Pitfalls

### Common Mistakes

- **Negative numbers**: `~0` is `-1`, not maximum positive integer
- **Operator precedence**: Use parentheses `(x & mask) == 0` not `x & mask == 0`
- **Shift overflow**: Shifting by >= bit width is undefined behavior

### Efficiency Tips

```python
# ✅ Fast power of 2 check
def is_power_of_2(n):
    return n > 0 and (n & (n - 1)) == 0

# ✅ Fast multiplication/division by powers of 2
x << 3  # x * 8
x >> 2  # x // 4

# ✅ Fast absolute value (for positive numbers)
def fast_abs(x):
    mask = x >> 31  # Get sign bit
    return (x + mask) ^ mask

# ✅ Swap without temporary variable
def swap(a, b):
    a ^= b
    b ^= a
    a ^= b
    return a, b
```

### Magic Numbers & Patterns

```python
# Common bit masks
EVEN_BITS = 0xAAAAAAAA  # 1010...
ODD_BITS = 0x55555555   # 0101...
ALL_ONES = 0xFFFFFFFF   # 1111...

# Brian Kernighan's algorithm
def count_set_bits(n):
    count = 0
    while n:
        n &= n - 1  # Clear rightmost set bit
        count += 1
    return count
```

---

## 8. Applications

### Real-world Usage

- **Compression algorithms** (Huffman coding)
- **Cryptography** (encryption keys, hashing)
- **Graphics** (pixel manipulation, color channels)
- **Database indexing** (bloom filters)
- **Network protocols** (IP addressing, subnetting)

### Algorithmic Usage

- **Dynamic Programming** (bitmask DP for subsets)
- **Graph Algorithms** (representing visited nodes)
- **String Algorithms** (pattern matching optimizations)
- **Mathematical Computations** (fast arithmetic)

---

## 9. Example 1: Basic Operations Demo

```python
def bit_manipulation_demo():
    """Demonstrate basic bit manipulation operations"""
    num = 12  # Binary: 1100

    print(f"Original: {num} = {bin(num)}")

    # Check specific bits
    print(f"Bit 2 set? {bool(num & (1 << 2))}")  # True
    print(f"Bit 0 set? {bool(num & (1 << 0))}")  # False

    # Set bit 1
    num_with_bit1 = num | (1 << 1)  # 1110 = 14
    print(f"After setting bit 1: {num_with_bit1} = {bin(num_with_bit1)}")

    # Clear bit 3
    num_clear_bit3 = num & ~(1 << 3)  # 0100 = 4
    print(f"After clearing bit 3: {num_clear_bit3} = {bin(num_clear_bit3)}")

    # Toggle bit 0
    num_toggle_bit0 = num ^ (1 << 0)  # 1101 = 13
    print(f"After toggling bit 0: {num_toggle_bit0} = {bin(num_toggle_bit0)}")

bit_manipulation_demo()
```

---

## 10. Example 2: Advanced Problem - Single Number

**Problem**: Given an array where every element appears twice except one, find the single number.

```python
def find_single_number(nums):
    """
    Use XOR properties: a ^ a = 0, a ^ 0 = a
    All paired numbers cancel out, leaving only the single number.

    Time: O(n), Space: O(1)
    """
    result = 0
    for num in nums:
        result ^= num
    return result

# Test
test_array = [4, 1, 2, 1, 2]
print(f"Single number: {find_single_number(test_array)}")  # Output: 4

# One-liner version (Pythonic)
def find_single_number_oneliner(nums):
    from functools import reduce
    import operator
    return reduce(operator.xor, nums, 0)

# Even more Pythonic (if you have functools)
from functools import reduce
single = reduce(lambda x, y: x ^ y, nums, 0)
```

---

## 11. Advanced Example: Subset Generation

```python
def generate_subsets(arr):
    """
    Generate all subsets using bit manipulation.
    Each bit position represents whether element is included.

    Time: O(n * 2^n), Space: O(1) auxiliary
    """
    n = len(arr)
    subsets = []

    # Iterate through all possible bit patterns
    for mask in range(1 << n):  # 0 to 2^n - 1
        subset = []
        for i in range(n):
            if mask & (1 << i):  # Check if i-th bit is set
                subset.append(arr[i])
        subsets.append(subset)

    return subsets

# Test
arr = [1, 2, 3]
subsets = generate_subsets(arr)
print(f"All subsets: {subsets}")
# Output: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
```

---

## 12. Quick Reference Cheat Sheet

| Task                          | Code                         | Complexity |
| ----------------------------- | ---------------------------- | ---------- |
| Check if power of 2           | `n > 0 and (n & (n-1)) == 0` | O(1)       |
| Get lowest set bit            | `n & -n`                     | O(1)       |
| Count set bits                | `bin(n).count('1')`          | O(log n)   |
| Check if even                 | `n & 1 == 0`                 | O(1)       |
| Multiply by 2^k               | `n << k`                     | O(1)       |
| Divide by 2^k                 | `n >> k`                     | O(1)       |
| Clear rightmost set bit       | `n & (n-1)`                  | O(1)       |
| Isolate rightmost set bit     | `n & -n`                     | O(1)       |
| Set all bits after position i | `n \| ((1 << (i+1)) - 1)`    | O(1)       |
| Check if bits i and j differ  | `((n >> i) ^ (n >> j)) & 1`  | O(1)       |

### Memory Optimization Patterns

```python
# Use integers as boolean arrays (32/64 flags in one int)
flags = 0
flags |= (1 << 5)   # Set flag 5
flags &= ~(1 << 3)  # Clear flag 3
is_set = bool(flags & (1 << 7))  # Check flag 7

# Compact representation of sets
def list_to_bitmask(lst, max_val):
    mask = 0
    for x in lst:
        mask |= (1 << x)
    return mask

def bitmask_to_list(mask):
    result = []
    pos = 0
    while mask:
        if mask & 1:
            result.append(pos)
        mask >>= 1
        pos += 1
    return result
```

---

## Key Takeaways

1. **XOR is powerful** - use for finding unique elements, swapping, toggling
2. **Powers of 2** have exactly one bit set - use `n & (n-1) == 0` to check
3. **Right shift** = integer division by 2, **left shift** = multiplication by 2
4. **Negative numbers** use two's complement - be careful with signed operations
5. **Bitmasks** can replace boolean arrays for space efficiency
6. **Think in binary** - visualize the bit patterns when solving problems
