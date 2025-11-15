Application

- Fucntion Calls
- Balanced Parenthesis
- Reversing Items
- Infix to Postfix/ Prefix
- Evaluation of Postfix/ Prefix
- Stock span problem
- Undo/Redo, Forward/Backward, Cut/Copy/Paste

# Two Stack in single list

At first, it may look a bit artificial to put **two stacks in a single list**, but there are some real motivations behind it. Let me break it down:

### ✅ Why implement two stacks in one array?

1. **Efficient memory usage**
   - If you keep **two separate arrays** for two stacks, you must pre-allocate space for each.
   - What if one stack fills up while the other stays nearly empty? → wasted memory.
   - By putting them **in the same array growing from opposite ends**, they dynamically share unused space.

2. **Classic interview/DSA problem**
   - This is a standard data structure interview question that tests understanding of space optimization and pointer manipulation.

3. **Foundation for advanced DS**
   - Helps understand how **multiple stacks/queues can be implemented in shared memory**.
   - Useful when you have memory constraints (like in embedded systems).

### 📌 Applications

1. **Memory-constrained systems**
   - In low-level programming (firmware, embedded systems, compilers), memory is scarce. Efficient data structure designs like this matter.

2. **Expression evaluation**
   - Some compilers/interpreters use **multiple stacks** (e.g., one for operators, one for operands). Having them in a shared structure avoids waste.

3. **Undo/Redo operations**
   - Many applications (editors, spreadsheets) implement **undo/redo** as two stacks. Keeping them in the same array saves memory and keeps cache locality better.

4. **Simulating recursion & function calls**
   - System runtime often uses a **call stack**. In some designs, multiple stacks (e.g., for threads/coroutines) share a region of memory, similar to this idea.

5. **Algorithm problems**
   - Some competitive programming and OS-level problems use this technique when implementing **multiple data structures in a limited buffer**.

# Monotonic stack

when we start storing element in a specific order then it is called monotonic stack

# Stock Span problem

span_day = (idx of current day/element) - (idx of closest greaer element/day) if there is greater element on left else it is (index + 1)
we can find the prev_greater of elements of array in linear time using stacks
we can also find the next_greater just by reverse_traversing

# Infix, Prefix, Postfix

`Infix`: x+y
`Prefix`: +xy
`Postfix`: xy+

## Advantages of prefix and postfix

- Do not require paranthesis, procedure rules, and associativity rules
- can be evaluated by a program that traverse the given expression exactly once

## Infix to Postfix/Prefix (Naive)

- paranthesis the given infix based on precedence
- start from innermost brackets and move outwards converting accordingly

## Infix to Postfix Stack Algorithm

- traverse the infix from L to R
- for every ch in infix expression
  - if ch is operand: append to answer
  - if ch is (: psuh to stack
  - if ch is ): pop from stack until ( found
  - if ch is operator:
    - if stack is empty: push the operator
    - else
      - higher precedence: push to stack
      - lower precendece: pop until higher found then push
- at end pop out everything from stack

Time complexity is: O(N)

## Postfix to Infix Stack Algorithm

- traverse the postifx expression from L to R
- if the ch is operand: push to stack
- if the ch is operator:
  - pop two times to get the operands
  - perform the corrosponding action
  - push the res back in stack for further evaluation

Time complexity is: O(N)

## Infix to Prefix Stack Algorithm

- traverse the infix from R to L
- for every ch in infix expression
  - if ch is operand: append to answer
  - if ch is ): psuh to stack
  - if ch is (: pop from stack until ( found
  - if ch is operator:
    - if stack is empty: push the operator
    - else
      - higher precedence: push to stack
      - lower precendece: pop until higher found then push
- at end pop out everything from stack
- return reverse of answer

Time complexity is: O(N)

## Postfix to Infix Stack Algorithm

(same just reverse traversal)

- traverse the postifx expression from R to L
- if the ch is operand: push to stack
- if the ch is operator:
  - pop two times to get the operands
  - perform the corrosponding action
  - push the res back in stack for further evaluation

Time complexity is: O(N)
