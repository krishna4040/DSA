class Node:
    """This is a basic unit of Linked List"""

    __slots__ = ("data", "next")

    def __init__(self, data, nxt=None):
        self.data = data
        self.next = nxt


class SLL:
    """This is a singly Linked List"""

    def __init__(self):
        self.head = None

    def __iter__(self):
        curr = self.head
        while curr:
            yield curr.data
            curr = curr.next

    def __repr__(self):
        return "SLL([" + ", ".join(map(str, self)) + "])"

    def __str__(self):
        return "->".join(map(str, self))

    def __len__(self):
        count = 0
        curr = self.head
        while curr:
            count += 1
            curr = curr.next
        return count

    def __bool__(self):
        return len(self) > 0

    def __contains__(self, data):
        curr = self.head
        while curr:
            if curr.data == data:
                return True
            curr = curr.next
        return False

    def __getitem__(self, index):
        if index < 0:
            index = len(self) + index
        if not self.head:
            raise IndexError("List is empty")
        if index == 0:
            return self.head.data

        current = self.head
        i = 0
        while current:
            if i == index:
                return current.data
            current = current.next
            i += 1

        raise IndexError("Index out of range")

    def __setitem__(self, value, index):
        if index < 0:
            index = len(self) + index
        current = self.head
        i = 0
        while current:
            if i == index:
                current.data = value
                return
            current = current.next
            i += 1

        raise IndentationError("Index out of range")

    def __delitem__(self, index):
        if index < 0:
            index = len(self) + index
        curr = self.head
        i = 0
        while curr and curr.next:
            if i == index - 1:
                curr.next = curr.next.next
                return
            curr = curr.next
            i += 1

        raise IndexError("Index out of range")

    def __reverse__(self):
        values = []
        curr = self.head
        while curr:
            values.append(curr.data)
            curr = curr.next
        yield from reversed(values)

    def insert(self, data, pos):
        temp = Node(data)
        if pos == 1:
            temp.next = self.head
            self.head = temp
            return
        curr = self.head
        while pos - 1 and curr:
            curr = curr.next
            pos -= 1
        if not curr:
            raise IndexError("Indext out of range")
        temp.next = curr.next
        curr.next = temp

    def push(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = new_node

    def get_middle(self):
        slow, fast = self.head, self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow.data

    def reverse(self):
        prev = None
        curr = self.head
        while not curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        self.head = prev


ll = SLL()
ll.push(1)
ll.push(2)
ll.push(3)
print(f"list is: {ll}")
print(f"is 1 in ll? {1 in ll}")
print(f"lenght of list is {len(ll)}")
print("iterating over linked list")
for val in ll:
    print(f"val is {val}")
print(f"Middle element is {ll.get_middle()}")
