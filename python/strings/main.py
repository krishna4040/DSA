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
