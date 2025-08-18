import random


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swap = False
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swap = True
        if not swap:
            break


def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[min_idx], arr[i] = arr[i], arr[min_idx]


def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key, j = arr[i], i - 1
        while j > 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


def merge(a, b):
    result = []
    i = j = 0

    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            result.append(a[i])
            i += 1
        else:
            result.append(b[j])
            j += 1

    result.extend(a[i:])
    result.extend(b[j:])
    return result


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    return merge(left, right)


def intersection(a, b):
    # return list(set(a) & set(b))
    set_b = set(b)
    return [x for x in a if x in set_b]


def union(a, b):
    return list(set(a) | set(b))


def count_inversions(arr):
    def merge_sort(arr):
        if len(arr) <= 1:
            return arr, 0

        mid = len(arr) // 2
        left, inv_left = merge_sort(arr[:mid])
        right, inv_right = merge_sort(arr[mid:])
        merged, inv_split = merge(left, right)
        return merged, inv_left + inv_right + inv_split

    def merge(left, right):
        result = []
        i = j = inv_count = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                inv_count += len(left) - i  # All remaining left are inversions
                j += 1
        result += left[i:]
        result += right[j:]
        return result, inv_count

    _, total_inversions = merge_sort(arr)
    return total_inversions


def hoare(arr, l, h):
    pivot = arr[l]
    i, j = l, h
    while i < j:
        while arr[i] < pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    arr[l], arr[j] = arr[j] + arr[l]
    return j


def qs(arr, l, h):
    while l < h:
        p = hoare(arr, l, h)
        if p - l < h - p:
            qs(arr, l, p)
            l = p + 1
        else:
            qs(arr, p + 1, h)
            h = p


def quickselect(arr, k):
    """It is an efficient selection algoritm"""
    lo, hi = 0, len(arr) - 1
    while lo <= hi:
        p = hoare(arr, lo, hi)
        if p == k - 1:
            return arr[p]
        elif p < k - 1:
            hi = p - 1
        else:
            lo = p + 1
    return -1


def segregate(arr):
    i, j = -1, len(arr)
    while True:
        while True:
            i += 1
            if arr[i] < 0:
                break
        while True:
            j -= 1
            if arr[j] > 0:
                break
        if i >= j:
            return
        arr[i], arr[j] = arr[j], arr[i]


def dnf(arr):
    l, m, h = 0, 0, len(arr) - 1
    while m <= h:
        if arr[m] == 0:
            arr[m], arr[l] = arr[l], arr[m]
            m += 1
            l += 1
        elif arr[m] == 1:
            m += 1
        else:
            arr[m], arr[h] = arr[h], arr[m]
            h -= 1


def cycle_sort(arr):
    """the idea is to find the sorted index of an element find how manyy elements are smaller than the current element"""
    n = len(arr)

    for cycle_start in range(n - 1):
        item = arr[cycle_start]
        pos = cycle_start

        # Find position where we put the element
        for i in range(cycle_start + 1, n):
            if arr[i] < item:
                pos += 1

        # If the item is already in the correct position
        if pos == cycle_start:
            continue

        # Skip duplicates
        while item == arr[pos]:
            pos += 1

        # Put the item to its right position
        arr[pos], item = item, arr[pos]

        # Rotate the rest of the cycle
        while pos != cycle_start:
            pos = cycle_start
            for i in range(cycle_start + 1, n):
                if arr[i] < item:
                    pos += 1

            while item == arr[pos]:
                pos += 1

            arr[pos], item = item, arr[pos]


def count_sort(arr):
    max_ele = max(arr)
    count = [0] * (max_ele + 1)  # +1 to include max_ele index

    # Count occurrences
    for val in arr:
        count[val] += 1

    # Reconstruct sorted array
    i = 0
    for j in range(len(count)):
        while count[j] > 0:
            arr[i] = j
            i += 1
            count[j] -= 1


def radix_sort(arr):
    max_ele = max(arr)
    place = 1
    while place <= max_ele / place:
        count_sort(arr, place)
