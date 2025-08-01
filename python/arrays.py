import math


def search(arr, x):
    for ele in arr:
        if ele == x:
            return True
    return False


def insert(arr, x, pos):
    n = len(arr)
    idx = pos - 1
    for i in range(n - 1, idx + 1, -1):
        arr[i + 1] = arr[i]
    arr[idx] = x
    return n + 1


def delete(arr, x):
    n = len(arr)
    for i in range(0, n):
        if arr[i] == x:
            break
    if i == n:
        return n
    for j in range(0, n):
        arr[j] = arr[j + 1]
        return n - 1


def max_element(arr):
    res = -math.inf
    for i in range(len(arr)):
        res = max(arr[i], res)
    return res


def second_largest(arr):
    res1 = -math.inf
    res2 = -math.inf

    for i in range(len(arr)):
        if arr[i] > res1:
            res2 = res1
            res1 = arr[i]

    return res2


def check_sorted(arr):
    res = True
    for i in range(len(arr)):
        if arr[i] > arr[i + 1]:
            res = False
    return res


def rev(arr):
    i, j = 0, len(arr) - 1
    while i <= j:
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
        i += 1
        j -= 1


def remove_duplicates(nums):
    if not nums:
        return 0
    i = 0
    for j in range(1, len(nums)):
        if nums[j] != nums[i]:
            i += 1
            nums[i] = nums[j]  # Overwrite duplicate

    return i + 1  # Length of array with unique elements


def move_zeroes_end(arr):
    count = 0
    for i in range(len(arr)):
        if arr[i] == 0:
            arr[count] = arr[i]
            count += 1
    for i in range(count, len(arr)):
        arr[i] = 0


def rotate_arr(arr, d):
    n = len(arr)
    d = d % n
    arr[:] = arr[d:] + arr[:d]


def find_leader(arr):
    """Moore Voting Alogrithm"""
    res = []
    for i in range(len(arr)):
        is_leader = True
        for j in range(i + 1, len(arr)):
            if arr[i] < arr[j]:
                is_leader = False
        if is_leader:
            res.append(arr[i])
    return res


def find_leader_v2(arr):
    res = []
    curr_leader = arr[-1]
    res.append(curr_leader)
    for i in range(len(arr) - 2, -1, -1):
        if arr[i] > curr_leader:
            res.append(curr_leader)
            curr_leader = arr[i]
    return res


def max_diff(arr):
    min_so_far = arr[0]
    max_diff = -math.inf
    for i in range(1, len(arr)):
        max_diff = max(max_diff, arr[i] - min_so_far)
        min_so_far = min(min_so_far, arr[i])
    return max_diff


def print_frequencies_sorted(arr):
    if not arr:
        return
    count = 1
    for i in range(1, len(arr)):
        if arr[i] == arr[i - 1]:
            count += 1
        else:
            print(f"{arr[i - 1]} → {count}")
            count = 1
    print(f"{arr[-1]} → {count}")  # print last group


def max_profit_multi(arr):
    profit = 0
    for i in range(1, len(arr)):
        if arr[i] > arr[i - 1]:
            profit += arr[i] - arr[i - 1]
    return profit


def trapping_rain_water(arr):
    res = 0
    for i in range(len(arr)):
        lmax, rmax = -math.inf, -math.inf
        for j in range(1, i):
            lmax = max(lmax, arr[j])
        for j in range(i + 1, len(arr) - 1):
            rmax = max(rmax, arr[j])
        res += min(lmax, rmax) - arr[i]
    return res


def find_water(arr):
    n = len(arr)
    if n < 3:
        return 0

    # Arrays to store the max height to the left and right of each bar
    left = [0] * n
    right = [0] * n

    # Fill left array
    left[0] = arr[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], arr[i])

    # Fill right array
    right[n - 1] = arr[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], arr[i])

    # Calculate trapped water
    water = 0
    for i in range(1, n - 1):
        var = min(left[i - 1], right[i + 1])
        if var > arr[i]:
            water += var - arr[i]

    return water


def max_subarray_sum_naive(arr):
    n = len(arr)
    max_sum = float("-inf")

    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += arr[j]
            max_sum = max(max_sum, current_sum)

    return max_sum


def max_subarray_sum(arr):
    max_sum = float("-inf")  # or use arr[0] if arr is non-empty
    max_ending = 0

    for num in arr:
        max_ending = max(max_ending + num, num)
        max_sum = max(max_sum, max_ending)

    return max_sum


def max_circular_subarr_sum(arr):
    kadane_sum = max_subarray_sum(arr)

    total = sum(arr)
    curr_min = global_min = arr[0]

    for i in range(1, len(arr)):
        curr_min = min(arr[i], curr_min + arr[i])
        global_min = min(global_min, curr_min)

    circular_sum = total - global_min

    if kadane_sum < 0:
        return kadane_sum

    return max(kadane_sum, circular_sum)


def longest_even_odd(arr):
    n = len(arr)
    max_len = 1
    curr_len = 1

    for i in range(1, n):
        if arr[i] % 2 != arr[i - 1] % 2:
            curr_len += 1
            max_len = max(max_len, curr_len)
        else:
            curr_len = 1  # Reset

    return max_len


def majority_element(arr):
    ele, count = arr[0], 1

    for i in range(len(arr)):
        if count == 0:
            ele = arr[i]
            count = 1
        count += 1 if arr[i] == ele else -1

    final_count = sum(1 for num in arr if num == ele)

    if final_count > len(arr) // 2:
        return ele
    return -1


def group_flips(arr):
    n = len(arr)
    if n == 0:
        return

    zero_groups = []
    one_groups = []

    i = 0
    while i < n:
        start = i
        while i < n and arr[i] == arr[start]:
            i += 1
        end = i - 1

        if arr[start] == 0:
            zero_groups.append((start, end))
        else:
            one_groups.append((start, end))

    # Choose the smaller group to flip
    flip_groups = zero_groups if len(zero_groups) < len(one_groups) else one_groups

    # Print flips
    for start, end in flip_groups:
        print(f"Flip from index {start} to {end}")


def group_flips_v2(arr):
    n = len(arr)
    for i in range(1, n):
        if arr[i] != arr[i - 1]:
            if arr[i] != arr[0]:
                print(f"from {i} to")
            else:
                print(i - 1)
        if arr[n - 1] != arr[0]:
            print(n - 1)


def max_k_subarr_sum(arr, k):
    n = len(arr)
    curr_sum = 0
    for i in range(k):
        curr_sum += arr[i]
    res = curr_sum
    for i in range(k, n):
        curr_sum += arr[i] - arr[i - k]
        res = max(res, curr_sum)
    return res
