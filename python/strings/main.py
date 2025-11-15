import string
from collections import Counter
from itertools import combinations, permutations, product


def is_palindrome(s):
    return s == s[::-1]


def is_anagram(a, b):
    return Counter(a) == Counter(b)


def is_pangram(s):
    """Contains all characters"""
    return set(string.ascii_lowercase) <= set(s.lower())


def is_rotated(a):
    return a in a + a


def is_binary_palindrome(n):
    return is_palindrome(bin(n)[:2])


def sum_of_digits(n):
    return sum(int(d) for d in str(n))


def rev_num(n):
    return int(str(n)[::-1])


def rev_words(sentence):
    return " ".join(reversed(sentence.split()))


def rev_chars_words(sentence):
    return " ".join(w[::-1] for w in sentence.split())


def longest_shortest_word(s):
    return (max(s.split(), key=len), min(s.split(), key=len))


def most_common_word(sentence):
    return Counter(sentence.split()).most_common(1)


def count_palindrome_sub_strings(s):
    if len(s) < 2:
        return 1
    count = 0
    for i in range(len(s)):
        count += expand_around_center(s, i, i)
        count += expand_around_center(s, i, i + 1)
    return count


def expand_around_center(s, i, j):
    count = 0
    while i >= 0 and j < len(s) and s[i] == s[j]:
        count += 1
        i -= 1
        j += 1
    return count


def rabin_karp(text, pattern):
    n, m = len(text), len(pattern)
    base, mod = 256, 101  # rolling hash params
    pat_hash = 0
    txt_hash = 0
    h = pow(base, m - 1, mod)  # base^(m-1) % mod

    # initial hash
    for i in range(m):
        pat_hash = (pat_hash * base + ord(pattern[i])) % mod
        txt_hash = (txt_hash * base + ord(text[i])) % mod

    # slide over text
    for i in range(n - m + 1):
        if pat_hash == txt_hash:
            if text[i : i + m] == pattern:
                return i
        if i < n - m:
            txt_hash = (txt_hash - ord(text[i]) * h) * base + ord(text[i + m])
            txt_hash %= mod
    return -1


def number_to_words(num):
    if num == 0:
        return "zero"

    # Words for basic numbers
    ones = [
        "",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    ]
    tens = [
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety",
    ]

    # Helper for numbers < 1000
    def three_digit_words(n):
        word = ""
        if n >= 100:
            word += ones[n // 100] + " hundred"
            n %= 100
            if n > 0:
                word += " "
        if n >= 20:
            word += tens[n // 10]
            n %= 10
            if n > 0:
                word += " " + ones[n]
        elif n > 0:
            word += ones[n]
        return word

    parts = [(10**6, "million"), (10**3, "thousand"), (1, "")]

    words = []
    for value, name in parts:
        if num >= value:
            chunk = num // value
            num %= value
            words.append(three_digit_words(chunk))
            if name:
                words.append(name)

    return " ".join(words).strip()


def next_permutation(s):
    i = len(s) - 2
    while i >= 0 and s[i] >= s[i + 1]:
        i -= 1
    if i == -1:
        return False

    j = len(s) - 1
    while s[i] <= s[j]:
        j -= 1

    s[i], s[j] = s[j], s[i]
    s[i + 1 :] = reversed(s[i + 1 :])
    return True


def int_to_roman(num):
    # Roman numeral mapping in descending order
    val = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    syms = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

    roman_num = ""
    for i in range(len(val)):
        count = num // val[i]  # How many times this value fits
        roman_num += syms[i] * count
        num %= val[i]  # Reduce the number
    return roman_num


def roman_to_int(s):
    roman = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    res = 0
    for i in range(len(s)):
        if i + 1 < len(s) and roman[s[i]] < roman[s[i + 1]]:
            res -= roman[s[i]]
        else:
            res += roman[s[i]]
    print(res)
