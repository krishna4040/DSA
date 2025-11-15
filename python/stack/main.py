class Stack:
    def __init__(self, stack=None):
        self.stack = stack if stack is not None else []
        self.ast = []

    def push(self, item):
        self.stack.append(item)
        if self.peek() and self.ast[-1] >= self.peek():
            self.ast.append(item)
        if not self.peek():
            self.ast.append(item)

    def pop(self):
        if self.peek() == self.ast[-1]:
            self.ast.pop()
        return self.stack.pop() if self.stack else None

    def peek(self):
        return self.stack[-1] if self.stack else None

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)

    def get_min(self):
        return self.ast[-1]


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LStack:
    def __init__(self):
        self.top = None
        self._size = 0  # to track number of elements

    def is_empty(self):
        return self.top is None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top  # new node points to old top
        self.top = new_node  # update top
        self._size += 1

    def pop(self):
        if self.is_empty():
            raise IndexError("Pop from empty stack")
        popped = self.top.data
        self.top = self.top.next  # move top pointer down
        self._size -= 1
        return popped

    def peek(self):
        if self.is_empty():
            raise IndexError("Peek from empty stack")
        return self.top.data

    def size(self):
        return self._size

    def __repr__(self):
        # For visualization
        elems, curr = [], self.top
        while curr:
            elems.append(str(curr.data))
            curr = curr.next
        return "Top -> " + " -> ".join(elems)


def check_balanced(s: str):
    opening = {"(": ")", "{": "}", "[": "]"}
    st = Stack()

    for ch in s:
        if ch in opening:  # if it's an opening bracket
            st.push(ch)
        else:
            if st.is_empty():  # no matching opening bracket
                return False
            top = st.pop()
            if opening[top] != ch:  # mismatch
                return False

    return st.is_empty()  # must be empty at the end


"""
Naive solution: divide array from middle
problem: there is space wastage if second stack is not utilising all space
and first stack requires more
"""


class TwoStacks:
    """Cache friendliness, single point of reference"""

    def __init__(self, capacity):
        self.arr = [None] * capacity
        self.capacity = capacity
        self.top1 = -1
        self.top2 = capacity

    def push1(self, item):
        if self.top1 + 1 < self.top2:
            self.top1 += 1
            self.arr[self.top1] = item
        else:
            raise OverflowError("Stack1 overflow")

    def push2(self, item):
        if self.top1 + 1 < self.top2:
            self.top2 -= 1
            self.arr[self.top2] = item
        else:
            raise OverflowError("Stack2 overflow")

    def pop1(self):
        if self.top1 >= 0:
            val = self.arr[self.top1]
            self.arr[self.top1] = None
            self.top1 -= 1
            return val
        raise IndexError("Stack1 underflow")

    def pop2(self):
        if self.top2 < self.capacity:
            val = self.arr[self.top2]
            self.arr[self.top2] = None
            self.top2 += 1
            return val
        raise IndexError("Stack2 underflow")

    def peek1(self):
        if self.top1 >= 0:
            return self.arr[self.top1]
        raise IndexError("Stack1 is empty")

    def peek2(self):
        if self.top2 < self.capacity:
            return self.arr[self.top2]
        raise IndexError("Stack2 is empty")

    def is_empty1(self):
        return self.top1 == -1

    def is_empty2(self):
        return self.top2 == self.capacity


class KStacks:
    """This is the extension of above problem"""

    def __init__(self, k, n):
        """
        Initialize k stacks in a single array of size n.
        k: number of stacks
        n: size of array
        """
        self.k = k
        self.n = n
        self.arr = [None] * n  # array to store actual values
        self.top = [-1] * k  # top[i] is the index of top element of i-th stack
        self.next = list(range(1, n)) + [
            -1
        ]  # next[i] is the next free index or next element in stack
        self.free = 0  # beginning index of free list

    def is_full(self):
        return self.free == -1

    def is_empty(self, sn):
        return self.top[sn] == -1

    def push(self, value, sn):
        """
        Push value into stack number sn (0-based index)
        """
        if self.is_full():
            raise OverflowError("Stack Overflow")

        # Get first free index
        i = self.free
        # Update free to next free slot
        self.free = self.next[i]

        # Insert value
        self.arr[i] = value
        # Link new element to previous top
        self.next[i] = self.top[sn]
        # Update top
        self.top[sn] = i

    def pop(self, sn):
        """
        Pop element from stack number sn (0-based index)
        """
        if self.is_empty(sn):
            raise IndexError(f"Stack {sn} Underflow")

        # Get index of top element
        i = self.top[sn]
        # Update top to previous element
        self.top[sn] = self.next[i]
        # Add this index to free list
        self.next[i] = self.free
        self.free = i

        return self.arr[i]

    def peek(self, sn):
        if self.is_empty(sn):
            raise IndexError(f"Stack {sn} is empty")
        return self.arr[self.top[sn]]


class StackNode:
    def __init__(self, index=None, next_node=None):
        self.index = index
        self.next = next_node


class NStack:
    def __init__(self, N, s):
        """
        Initialize N stacks in an array of size s
        N: number of stacks
        s: size of the array
        """
        # Original array to store data
        self.arr = [0] * s

        # Array to store top pointers for each stack
        self.top = [None] * N

        # Stack to store free indices
        self.free_indices = []

        # Initialize free indices stack with all available indices
        for i in range(s):
            self.free_indices.append(i)

    def push(self, x, m):
        """
        Push element x to stack m (1-indexed)
        Returns True if successful, False if array is full
        """
        if not self.free_indices:
            return False  # Array is full

        # Get a free index
        free_index = self.free_indices.pop()

        # Store the data in the array
        self.arr[free_index] = x

        # Create new node and update stack top
        new_node = StackNode(free_index, self.top[m - 1])
        self.top[m - 1] = new_node

        return True

    def pop(self, m):
        """
        Pop element from stack m (1-indexed)
        Returns popped element or -1 if stack is empty
        """
        if self.top[m - 1] is None:
            return -1  # Stack is empty

        # Get the index of top element
        top_index = self.top[m - 1].index

        # Get the element from array
        element = self.arr[top_index]

        # Add the index back to free indices
        self.free_indices.append(top_index)

        # Update stack top
        self.top[m - 1] = self.top[m - 1].next

        return element

    def is_empty(self, m):
        """Check if stack m is empty"""
        return self.top[m - 1] is None

    def print_stack(self, m):
        """Print stack m for debugging"""
        if self.is_empty(m):
            print(f"Stack {m} is empty")
            return

        current = self.top[m - 1]
        elements = []
        while current:
            elements.append(self.arr[current.index])
            current = current.next

        print(f"Stack {m}: {elements[::-1]}")  # Reverse to show from bottom to top

    def print_free_indices(self):
        """Print available free indices"""
        print(f"Free indices: {self.free_indices}")


class StockSpanner:
    def __init__(self):
        self.prices = []

    def next(self, val) -> int:
        self.prices.append(val)
        n = len(self.prices)
        count = 1
        for i in range(n-2, -1, -1):
            if self.prices[i] <= val:
                count += 1
            else:
                break
        return count

    def next_v2(self, val) -> int:
        pass

def stock_span(prices):
    n = len(prices)
    span = [0] * n
    stack = []

    for i in range(n):
        # Pop smaller or equal prices
        while stack and prices[i] >= prices[stack[-1]]:
            stack.pop()

        # If stack empty, all previous are smaller
        span[i] = i + 1 if not stack else i - stack[-1]
        stack.append(i)

    return span


def prev_greater_element(arr):
    n = len(arr)
    pge = [-1] * len(arr)
    stack = []
    for i in range(n):
        while stack and arr[i] >= stack[-1]:
            stack.pop()
        pge[i] = stack[-1] if stack else -1
        stack.append(arr[i])
    return pge


def next_greater_element(arr):
    n = len(arr)
    nge = [-1] * n
    stack = []
    for i in range(n - 1, -1, -1):
        while stack and arr[i] >= arr[stack[-1]]:
            stack.pop()
        nge[i] = stack[-1] if stack else -1
        stack.append(arr[i])

    return nge.reverse()

def nge_v2(arr):
    N = len(arr)
    n = N * 2
    nge = [-1] * n
    stack = []
    for i in range(n-1, -1, -1):
        idx = i % N
        while stack and arr[idx] >= stack[-1]:
            stack.pop()
        nge[idx] = stack[-1] if stack else -1
        stack.append(arr[idx])

    return nge


def prev_smaller_element(arr):
    n = len(arr)
    st = []
    pse = [-1] * n
    for i in range(n):
        while st and arr[i] <= st[-1]:
            st.pop()
        pse[i] = st[-1] if st else -1
        st.append(arr[i])
    return pse


def next_smaller_element(arr):
    n = len(arr)
    st = []
    nse = [-1] * n
    for i in range(n-1, -1, -1):
        while st and arr[i] <= st[-1]:
            st.pop()
        nse[i] = st[-1] if st else -1
        st.append(arr[i])
    return nse.reverse()


def largest_histogram_area_v1(height: list[int]) -> int:
    if not height:
        return 0
    if len(height) == 1:
        return height[0]
    min_ele_idx = height.index(min(height))
    curr_area = height[min_ele_idx] * len(height)
    left_area = largest_histogram_area_v1(height[:min_ele_idx])
    right_area = largest_histogram_area_v1(height[min_ele_idx + 1 :])

    return max(curr_area, left_area, right_area)


def largest_histogram_area_v2(height: list[int]) -> int:
    ps = prev_smaller_element(height)
    ns = next_smaller_element(height)
    res = 0

    for i, h in enumerate(height):
        curr = h
        curr += (i - ps[i] - 1) * h
        curr += (ns[i] - i - 1) * h
        res = max(res, curr)

    return res


def largest_histogram_area_v3(height):
    pass


def largest_submatrix(matrix: list[list[int]]) -> int:
    R = len(matrix)
    C = len(matrix[0])
    res = -1
    heights = []
    for r in range(R):
        if r == 0:
            heights = matrix[r][:]
        else:
            heights = [heights[c] + 1 if matrix[r][c] != 0 else 0 for c in range(C)]
        res = max(res, largest_histogram_area_v1(heights))
    return res


def infix_to_postfix(infix: str) -> str:
    precedence = {'^': 4, '*': 3, '/': 3, '+': 2, '-': 2, '(': 1}
    stack = []
    postfix = ""

    for ch in infix:
        if ch.isalnum():
            postfix += ch
        elif ch == '(':
            stack.append(ch)
        elif ch == ')':
            while stack and stack[-1] != '(':
                postfix += stack.pop()
            stack.pop()
        else:
            while stack and precedence.get(stack[-1], 0) >= precedence[ch]:
                postfix += stack.pop()
            stack.append(ch)

    while stack:
        postfix += stack.pop()

    return postfix


def infix_to_prefix(infix: str) -> str:
    infix = infix[::-1]
    infix = ''.join(['(' if ch == ')' else ')' if ch == '(' else ch for ch in infix])

    precedence = {'^': 4, '*': 3, '/': 3, '+': 2, '-': 2, '(': 1}
    stack = []
    prefix = ""

    for ch in infix:
        if ch.isalnum():
            prefix += ch
        elif ch == '(':
            stack.append(ch)
        elif ch == ')':
            while stack and stack[-1] != '(':
                prefix += stack.pop()
            stack.pop()
        else:
            while stack and precedence.get(stack[-1], 0) > precedence[ch]:
                prefix += stack.pop()
            stack.append(ch)

    while stack:
        prefix += stack.pop()

    return prefix[::-1]


def evaluate_postfix(postfix: str) -> int:
    stack = []
    tokens = postfix.split()

    for token in tokens:
        if token.isdigit():
            stack.append(int(token))
        else:
            b = stack.pop()
            a = stack.pop()

            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(int(a / b))
            elif token == '^':
                stack.append(a ** b)

    return stack.pop()


def evaluate_prefix(postfix: str) -> int:
    stack = []
    tokens = postfix.split()

    for token in tokens.reverse():
        if token.isdigit():
            stack.append(int(token))
        else:
            b = stack.pop()
            a = stack.pop()

            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(int(a / b))
            elif token == '^':
                stack.append(a ** b)

    return stack.pop()
