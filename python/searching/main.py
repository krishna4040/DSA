import bisect


def ls(arr, x):
    for i, _ in enumerate(arr):
        if arr[i] == x:
            return i
    return -1


def bsr(arr, l, h, x):
    if l > h:
        return -1

    m = (l + h) // 2  # use integer division
    if arr[m] == x:
        return m
    if arr[m] > x:
        return bsr(arr, l, m - 1, x)
    return bsr(arr, m + 1, h, x)


def bsi(arr, x):
    l, h = 0, len(arr) - 1
    while l <= h:
        m = (l + h) // 2
        if arr[m] == x:
            return m
        if arr[m] > x:
            h = m - 1
        else:
            l = m + 1
    return -1


def first_occurence(arr, x):
    return bisect.bisect_left(arr, x)


def last_occurence(arr, x):
    return bisect.bisect_right(arr, x) - 1


def count_occurence(arr, x):
    return last_occurence(arr, x) - first_occurence(arr, x)


def count_ones(arr):
    if arr == sorted(arr):
        return len(arr) - first_occurence(arr, 1)
    else:
        return len(arr) - last_occurence(arr, 1)


def search_infinite(arr, x):
    idx = 1
    while arr[idx] < x:
        idx *= idx

    low, high = idx / 2 + 1, idx - 1
    while low < high:
        mid = (low + high) // 2
        if x < arr[mid]:
            high = mid - 1
        elif x > arr[mid]:
            low = mid + 1
        else:
            return mid


def search_sorted_rotated(arr, x):
    l, h = 0, len(arr) - 1
    while l < h:
        m = (l + h) // 2
        if arr[m] == x:
            return m

        if arr[m] >= arr[l]:
            if x > arr[l] and x < arr[m]:
                h = m - 1
            else:
                l = m + 1
        else:
            if x < arr[h] and x > arr[m]:
                l = m + 1
            else:
                h = m - 1
    return -1
