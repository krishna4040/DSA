def reverse(x: int) -> int:
    """
    Given a signed 32-bit integer x, return x with its digits reversed.
    If reversing x causes the value to go outside the signed 32-bit integer
    range [-231, 231 - 1], then return 0.
    """
    int_min, int_max = -(2**31), 2**31 - 1
    sign = -1 if x < 0 else 1
    s = str(abs(x))
    rev = sign * int(s[::-1])
    return rev if int_min <= rev <= int_max else 0
