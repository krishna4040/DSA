# Number Theory & Mathematical Concepts for DSA - Complete Guide

## 1. Concept Overview & Recognition

### Number Theory

**Definition**: Study of integers and their properties, relationships, and patterns.
**Intuition**: Like detective work with numbers - finding hidden patterns, divisibility rules, and mathematical relationships.

### Modular Arithmetic

**Definition**: Arithmetic operations on remainders after division.
**Intuition**: Clock arithmetic - after 12 comes 1, after 59 minutes comes 0.

**Recognition Patterns**:

- "Result modulo 10^9+7" or any modulo operations
- Armstrong numbers, palindromes, digit manipulation
- Prime checking, factorization problems
- Fibonacci, factorial calculations with large numbers
- GCD/LCM problems, coprime calculations
- Cycle detection, period finding
- Cryptography, hashing problems

## 2. Core DSA Concepts Related

| Concept                       | Key Property                               | Mathematical Foundation           |
| ----------------------------- | ------------------------------------------ | --------------------------------- |
| **Modular Arithmetic**        | `(a ± b) % m = ((a % m) ± (b % m)) % m`    | Ring theory, congruences          |
| **Prime Numbers**             | Only divisible by 1 and itself             | Fundamental theorem of arithmetic |
| **GCD/LCM**                   | `gcd(a,b) × lcm(a,b) = a × b`              | Euclidean algorithm               |
| **Euler's Totient**           | `φ(n)` = count of numbers ≤ n coprime to n | Multiplicative functions          |
| **Fermat's Little Theorem**   | `a^(p-1) ≡ 1 (mod p)` for prime p          | Modular exponentiation            |
| **Chinese Remainder Theorem** | Solving system of congruences              | Ring isomorphism                  |

## 3. Important Algorithms

### Core Number Theory Algorithms

1. **Sieve of Eratosthenes** - Generate all primes up to n
2. **Euclidean Algorithm** - Find GCD efficiently
3. **Extended Euclidean Algorithm** - Find modular inverse
4. **Fast Exponentiation** - Calculate a^b mod m
5. **Prime Factorization** - Break number into prime factors
6. **Euler's Totient Function** - Count coprimes
7. **Segmented Sieve** - Primes in range [L, R]

## 4. Python Implementations

### Basic Number Theory Operations

```python
import math
from functools import lru_cache
from collections import defaultdict, Counter

MOD = 10**9 + 7

# Built-in functions
gcd_val = math.gcd(a, b)
factorial = math.factorial(n)
sqrt_val = math.isqrt(n)  # Integer square root
```

### Prime Number Functions

```python
# Simple primality test
def is_prime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0: return False
    return True

# Sieve of Eratosthenes
def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, n + 1, i):
                is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

# Prime factorization
def prime_factors(n):
    factors = []
    d = 2
    while d * d <= n:
        while n % d == 0:
            factors.append(d)
            n /= d
        d += 1
    if n > 1:
        factors.append(n)
    return factors
```

## 5. All Methods & Operations

### Modular Arithmetic Methods

| Method             | Syntax                           | Example                      | Time Complexity |
| ------------------ | -------------------------------- | ---------------------------- | --------------- |
| **Addition**       | `(a + b) % MOD`                  | `(15 + 25) % 7 = 5`          | O(1)            |
| **Subtraction**    | `(a - b + MOD) % MOD`            | `(5 - 8 + 7) % 7 = 4`        | O(1)            |
| **Multiplication** | `(a * b) % MOD`                  | `(6 * 7) % 5 = 2`            | O(1)            |
| **Division**       | `(a * pow(b, MOD-2, MOD)) % MOD` | `(6 * pow(2, 5, 7)) % 7 = 4` | O(log MOD)      |
| **Power**          | `pow(a, b, MOD)`                 | `pow(2, 10, 7) = 2`          | O(log b)        |
| **Inverse**        | `pow(a, MOD-2, MOD)`             | `pow(3, 5, 7) = 5`           | O(log MOD)      |

### Number Theory Specific Methods

```python
# GCD and LCM
def gcd(a, b):
    while b: a, b = b, a % b
    return a  # O(log min(a,b))

def lcm(a, b):
    return (a * b) // gcd(a, b)  # O(log min(a,b))

# Euler's totient function
def euler_totient(n):
    result = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0: n //= p
            result -= result // p
        p += 1
    if n > 1: result -= result // n
    return result  # O(√n)

# Count divisors
def count_divisors(n):
    count = 0
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            count += 1 if i * i == n else 2
    return count  # O(√n)
```

### Sequence Operations

```python
# Fibonacci with memoization
@lru_cache(maxsize=None)
def fibonacci(n):
    if n <= 1: return n
    return (fibonacci(n-1) + fibonacci(n-2)) % MOD

# Matrix exponentiation for Fibonacci
def fib_matrix(n):
    def matrix_mult(A, B, mod):
        return [[(A[0][0]*B[0][0] + A[0][1]*B[1][0]) % mod,
                 (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % mod],
                [(A[1][0]*B[0][0] + A[1][1]*B[1][0]) % mod,
                 (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % mod]]

    def matrix_power(matrix, n, mod):
        if n == 1: return matrix
        if n % 2 == 0:
            half = matrix_power(matrix, n//2, mod)
            return matrix_mult(half, half, mod)
        return matrix_mult(matrix, matrix_power(matrix, n-1, mod), mod)

    if n <= 1: return n
    base = [[1, 1], [1, 0]]
    result = matrix_power(base, n, MOD)
    return result[0][1]  # O(log n)
```

## 6. Operator Overloading

### Built-in Operators for Numbers

```python
# Arithmetic operators
a + b, a - b, a * b, a // b, a % b, a ** b

# Comparison operators
a == b, a != b, a < b, a <= b, a > b, a >= b

# Bitwise operators (useful for number theory)
a & b   # AND - check if bit is set
a | b   # OR - set bits
a ^ b   # XOR - toggle bits
a << 1  # Left shift (multiply by 2)
a >> 1  # Right shift (divide by 2)
~a      # NOT - flip all bits

# Examples
def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0

def count_set_bits(n):
    return bin(n).count('1')
```

## 7. Tips, Tricks & Pitfalls

### Common Mistakes

```python
# ❌ Wrong: Negative modulo
result = (a - b) % MOD  # Can be negative!

# ✅ Correct: Handle negative modulo
result = (a - b + MOD) % MOD

# ❌ Wrong: Division in modular arithmetic
result = (a / b) % MOD  # Wrong!

# ✅ Correct: Use modular inverse
result = (a * pow(b, MOD-2, MOD)) % MOD

# ❌ Wrong: Forgetting to apply modulo
def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i  # Overflow!
    return result % MOD

# ✅ Correct: Apply modulo at each step
def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result = (result * i) % MOD
    return result
```

### Efficiency Tips

```python
# Use __slots__ for memory efficiency in custom classes
class ModInt:
    __slots__ = ['val', 'mod']

# Pre-compute powers for repeated use
powers_of_2 = [1]
for i in range(1, 31):
    powers_of_2.append(powers_of_2[-1] * 2)

# Use bit operations for powers of 2
def multiply_by_power_of_2(n, k):
    return n << k  # n * (2^k)

def divide_by_power_of_2(n, k):
    return n >> k  # n // (2^k)
```

## 8. Applications

### Real-world Usage

- **Cryptography**: RSA, elliptic curve cryptography
- **Computer Graphics**: Transformations, fractals
- **Database Systems**: Hash functions, consistent hashing
- **Networking**: Checksums, error detection
- **Machine Learning**: Hash-based algorithms

### DSA Problem Categories

- **Digit Manipulation**: Armstrong numbers, palindromes, sum of digits
- **Prime Problems**: Prime checking, prime factorization, twin primes
- **Sequence Problems**: Fibonacci, Catalan numbers, arithmetic progressions
- **Modular Problems**: Large factorial, combinations, power calculations
- **GCD/LCM Problems**: Coprime arrays, simplifying fractions

## 9. Classic DSA Examples

### Example 1: Armstrong Number (Narcissistic Number)

```python
def is_armstrong(n):
    """
    Armstrong number: sum of digits raised to power of number of digits
    equals the number itself (153 = 1³ + 5³ + 3³)
    """
    str_n = str(n)
    num_digits = len(str_n)
    digit_sum = sum(int(digit) ** num_digits for digit in str_n)
    return digit_sum == n

def find_armstrong_in_range(start, end):
    """Find all Armstrong numbers in given range"""
    return [n for n in range(start, end + 1) if is_armstrong(n)]

# Advanced: Handle large numbers with modular arithmetic
def is_armstrong_mod(n, mod):
    str_n = str(n)
    num_digits = len(str_n)
    digit_sum = 0
    for digit in str_n:
        digit_sum = (digit_sum + pow(int(digit), num_digits, mod)) % mod
    return digit_sum == n % mod

print(find_armstrong_in_range(1, 1000))  # [1, 153, 371, 407]
```

### Example 2: Advanced Prime Problem - Goldbach's Conjecture

```python
def goldbach_conjecture(n):
    """
    Every even integer > 2 can be expressed as sum of two primes
    Find all such pairs for given even number
    """
    if n <= 2 or n % 2 != 0:
        return []

    # Generate primes up to n
    primes = set(sieve(n))
    pairs = []

    for p in primes:
        if p > n // 2:
            break
        if (n - p) in primes:
            pairs.append((p, n - p))

    return pairs

def verify_goldbach_range(start, end):
    """Verify Goldbach's conjecture for range of even numbers"""
    results = {}
    for n in range(start, end + 1, 2):
        if n > 2:
            pairs = goldbach_conjecture(n)
            results[n] = len(pairs)
    return results

print(goldbach_conjecture(20))  # [(3, 17), (7, 13)]
```

### Example 3: Perfect Numbers and Number Classifications

```python
def classify_number(n):
    """
    Classify numbers as:
    - Perfect: sum of proper divisors = n (e.g., 6 = 1+2+3)
    - Abundant: sum of proper divisors > n
    - Deficient: sum of proper divisors < n
    """
    if n <= 1:
        return "Invalid"

    divisor_sum = 1  # 1 is always a proper divisor
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            divisor_sum += i
            if i != n // i:  # Avoid counting square root twice
                divisor_sum += n // i

    if divisor_sum == n:
        return "Perfect"
    elif divisor_sum > n:
        return "Abundant"
    else:
        return "Deficient"

# Related: Amicable numbers
def are_amicable(a, b):
    """Two numbers are amicable if sum of proper divisors of each equals the other"""
    def sum_proper_divisors(n):
        if n <= 1: return 0
        div_sum = 1
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                div_sum += i
                if i != n // i:
                    div_sum += n // i
        return div_sum

    return sum_proper_divisors(a) == b and sum_proper_divisors(b) == a

print(classify_number(6))    # Perfect
print(are_amicable(220, 284))  # True
```

### Example 4: Digit Manipulation & Special Numbers

```python
class DigitOperations:
    """Collection of digit-based number theory operations"""

    @staticmethod
    def digit_sum(n):
        """Sum of digits"""
        return sum(int(d) for d in str(abs(n)))

    @staticmethod
    def digit_product(n):
        """Product of digits"""
        result = 1
        for d in str(abs(n)):
            result *= int(d)
        return result

    @staticmethod
    def reverse_number(n):
        """Reverse digits of number"""
        sign = -1 if n < 0 else 1
        return sign * int(str(abs(n))[::-1])

    @staticmethod
    def is_palindrome(n):
        """Check if number reads same forwards and backwards"""
        s = str(abs(n))
        return s == s[::-1]

    @staticmethod
    def is_happy_number(n):
        """Happy number: repeatedly sum squares of digits until 1 or cycle"""
        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = sum(int(d)**2 for d in str(n))
        return n == 1

    @staticmethod
    def is_harshad(n):
        """Harshad number: divisible by sum of its digits"""
        return n % DigitOperations.digit_sum(n) == 0

    @staticmethod
    def is_armstrong(n):
        """Armstrong/Narcissistic number"""
        str_n = str(n)
        power = len(str_n)
        return sum(int(d)**power for d in str_n) == n

    @staticmethod
    def is_kaprekar(n):
        """Kaprekar number: n² split into two parts that sum to n"""
        if n == 1: return True
        sq = str(n * n)
        for i in range(1, len(sq)):
            left = int(sq[:i])
            right = int(sq[i:])
            if right > 0 and left + right == n:
                return True
        return False

# Usage examples
ops = DigitOperations()
print(ops.is_armstrong(153))    # True
print(ops.is_happy_number(19))  # True
print(ops.is_harshad(12))       # True (12 % (1+2) == 0)
print(ops.is_kaprekar(45))      # True (45² = 2025, 20+25 = 45)
```

### Example 5: Sequences and Series

```python
class MathSequences:
    """Mathematical sequences commonly used in DSA"""

    @staticmethod
    @lru_cache(maxsize=None)
    def fibonacci(n, mod=MOD):
        """Fibonacci sequence with memoization"""
        if n <= 1: return n
        return (MathSequences.fibonacci(n-1, mod) +
                MathSequences.fibonacci(n-2, mod)) % mod

    @staticmethod
    def fibonacci_matrix(n, mod=MOD):
        """Fast Fibonacci using matrix exponentiation"""
        def matrix_mult(A, B, mod):
            return [[(A[0][0]*B[0][0] + A[0][1]*B[1][0]) % mod,
                     (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % mod],
                    [(A[1][0]*B[0][0] + A[1][1]*B[1][0]) % mod,
                     (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % mod]]

        def matrix_power(matrix, n, mod):
            if n == 1: return matrix
            if n % 2 == 0:
                half = matrix_power(matrix, n//2, mod)
                return matrix_mult(half, half, mod)
            return matrix_mult(matrix, matrix_power(matrix, n-1, mod), mod)

        if n <= 1: return n
        base = [[1, 1], [1, 0]]
        result = matrix_power(base, n, mod)
        return result[0][1]  # O(log n)

    @staticmethod
    def catalan(n, mod=MOD):
        """nth Catalan number: C(n) = (2n)! / ((n+1)! * n!)"""
        if n <= 1: return 1

        # Using formula: C(n) = C(2n,n) / (n+1)
        numerator = 1
        for i in range(n + 1):
            numerator = (numerator * (n + 1 + i)) % mod
            numerator = (numerator * pow(i + 1, mod - 2, mod)) % mod

        return (numerator * pow(n + 1, mod - 2, mod)) % mod

    @staticmethod
    def factorial_mod(n, mod=MOD):
        """Factorial with modular arithmetic"""
        result = 1
        for i in range(1, n + 1):
            result = (result * i) % mod
        return result

    @staticmethod
    def tribonacci(n, mod=MOD):
        """Tribonacci: T(n) = T(n-1) + T(n-2) + T(n-3)"""
        if n <= 0: return 0
        if n <= 2: return 1

        a, b, c = 0, 1, 1
        for i in range(3, n + 1):
            a, b, c = b, c, (a + b + c) % mod
        return c

# Usage
seq = MathSequences()
print(seq.fibonacci(50))        # Large Fibonacci number
print(seq.catalan(10))          # 10th Catalan number
print(seq.tribonacci(20))       # 20th Tribonacci number
```

## 8. Advanced Number Theory Concepts

### Primality and Factorization

```python
# Miller-Rabin primality test (probabilistic)
def miller_rabin(n, k=5):
    """Miller-Rabin primality test"""
    if n < 2: return False
    if n == 2 or n == 3: return True
    if n % 2 == 0: return False

    # Write n-1 as d * 2^r
    r = 0
    d = n - 1
    while d % 2 == 0:
        d //= 2
        r += 1

    # Witness loop
    import random
    for _ in range(k):
        a = random.randrange(2, n - 1)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

# Pollard's rho algorithm for factorization
def pollard_rho(n):
    """Fast integer factorization"""
    if n % 2 == 0: return 2

    x, y, c = 2, 2, 1
    d = 1

    f = lambda x: (x * x + c) % n

    while d == 1:
        x = f(x)
        y = f(f(y))
        d = math.gcd(abs(x - y), n)

    return d if d != n else None
```

### Combinatorics with Modular Arithmetic

```python
class ModularCombinatorics:
    """Combinatorics operations with modular arithmetic"""

    def __init__(self, max_n, mod=MOD):
        self.mod = mod
        self.max_n = max_n

        # Pre-compute factorials and inverse factorials
        self.fact = [1] * (max_n + 1)
        for i in range(1, max_n + 1):
            self.fact[i] = (self.fact[i-1] * i) % mod

        self.inv_fact = [1] * (max_n + 1)
        self.inv_fact[max_n] = pow(self.fact[max_n], mod - 2, mod)
        for i in range(max_n - 1, -1, -1):
            self.inv_fact[i] = (self.inv_fact[i + 1] * (i + 1)) % mod

    def nCr(self, n, r):
        """Combination: C(n,r) = n! / (r! * (n-r)!)"""
        if r > n or r < 0: return 0
        return (self.fact[n] * self.inv_fact[r] % self.mod *
                self.inv_fact[n - r]) % self.mod

    def nPr(self, n, r):
        """Permutation: P(n,r) = n! / (n-r)!"""
        if r > n or r < 0: return 0
        return (self.fact[n] * self.inv_fact[n - r]) % self.mod

# Usage
comb = ModularCombinatorics(1000)
print(comb.nCr(50, 25))  # C(50,25) % MOD
```

### Example 6: Complex Number Theory Problem

```python
def solve_euler_totient_sum(n):
    """
    Calculate sum of φ(i) for i from 1 to n
    where φ(i) is Euler's totient function
    """
    phi = list(range(n + 1))  # Initialize φ(i) = i

    # Sieve-like approach to calculate φ for all numbers
    for i in range(2, n + 1):
        if phi[i] == i:  # i is prime
            for j in range(i, n + 1, i):
                phi[j] -= phi[j] // i

    return sum(phi[1:n + 1])

def count_coprime_pairs(n):
    """Count pairs (i,j) where 1 ≤ i < j ≤ n and gcd(i,j) = 1"""
    phi = list(range(n + 1))

    for i in range(2, n + 1):
        if phi[i] == i:  # Prime
            for j in range(i, n + 1, i):
                phi[j] -= phi[j] // i

    # Sum of φ(i) for i from 2 to n, then add 1 for pair (1,1)
    return sum(phi[2:n + 1]) + 1

print(solve_euler_totient_sum(10))  # Sum of φ(1) to φ(10)
print(count_coprime_pairs(10))      # Count of coprime pairs
```

## Quick Reference Cheat Sheet

```python
import math
from functools import lru_cache

MOD = 10**9 + 7

# Essential number theory operations
def gcd(a, b): return math.gcd(a, b)
def lcm(a, b): return a * b // math.gcd(a, b)
def is_prime(n): return n > 1 and all(n % i for i in range(2, int(n**0.5) + 1))
def power_mod(a, b, m): return pow(a, b, m)
def mod_inverse(a, m): return pow(a, m-2, m)  # When m is prime

# Digit operations
def digit_sum(n): return sum(int(d) for d in str(abs(n)))
def reverse_num(n): return int(str(abs(n))[::-1]) * (1 if n >= 0 else -1)
def is_palindrome(n): return str(n) == str(n)[::-1]

# Sequences
@lru_cache(maxsize=None)
def fib(n): return n if n <= 1 else (fib(n-1) + fib(n-2)) % MOD

# Special numbers check
def is_armstrong(n):
    s = str(n); p = len(s)
    return sum(int(d)**p for d in s) == n

def is_perfect(n):
    return n > 1 and sum(i for i in range(1, n) if n % i == 0) == n
```

## Common DSA Number Theory Problems

1. **Armstrong Numbers**: Check if sum of digits^(number of digits) equals number
2. **Happy Numbers**: Sum of squares of digits eventually reaches 1
3. **Perfect Numbers**: Sum of proper divisors equals the number
4. **Palindromic Numbers**: Number reads same forwards and backwards
5. **Harshad Numbers**: Divisible by sum of digits
6. **Kaprekar Numbers**: n² can be split into parts that sum to n
7. **Prime Gaps**: Distance between consecutive primes
8. **Twin Primes**: Prime pairs differing by 2
9. **Goldbach Conjecture**: Even numbers as sum of two primes
10. **Collatz Sequence**: 3n+1 problem
