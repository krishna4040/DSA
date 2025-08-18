from collections import Counter


def unique(arr):
    return len(set(arr))


def frequency(arr):
    return Counter(arr)


def intersection(a, b):
    return list(set(a) & set(b))


def union(a, b):
    return list(set(a) | set(b))


def is_pair(arr, target):
    seen = set()
    for num in arr:
        if target - num in seen:
            return True
        seen.add(num)
    return False
