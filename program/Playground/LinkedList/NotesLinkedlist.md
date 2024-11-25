# Linked List Notes

## Introduction
A linked list is a linear data structure where elements are stored in nodes. Each node contains a reference (or link) to the next node in the sequence.

## Types of Linked Lists
1. **Singly Linked List**: Each node points to the next node.
2. **Doubly Linked List**: Each node points to both the next and the previous node.
3. **Circular Linked List**: The last node points back to the first node.

## Basic Operations
1. **Insertion**: Adding a new node to the list.
    - At the beginning
    - At the end
    - After a given node
2. **Deletion**: Removing a node from the list.
    - From the beginning
    - From the end
    - A specific node
3. **Traversal**: Accessing each node in the list.
4. **Searching**: Finding a node with a specific value.

## Advantages
- Dynamic size
- Ease of insertion/deletion

## Disadvantages
- No random access
- Extra memory for storing pointers

## Example Code (Singly Linked List in Python)
```python
class Node:
     def __init__(self, data):
          self.data = data
          self.next = None

class LinkedList:
     def __init__(self):
          self.head = None

     def insert_at_beginning(self, data):
          new_node = Node(data)
          new_node.next = self.head
          self.head = new_node

     def insert_at_end(self, data):
          new_node = Node(data)
          if not self.head:
                self.head = new_node
                return
          last = self.head
          while last.next:
                last = last.next
          last.next = new_node

     def delete_node(self, key):
          temp = self.head
          if temp and temp.data == key:
                self.head = temp.next
                temp = None
                return
          prev = None
          while temp and temp.data != key:
                prev = temp
                temp = temp.next
          if temp is None:
                return
          prev.next = temp.next
          temp = None

     def traverse(self):
          temp = self.head
          while temp:
                print(temp.data, end=" -> ")
                temp = temp.next
          print("None")

# Example usage
ll = LinkedList()
ll.insert_at_beginning(1)
ll.insert_at_end(2)
ll.insert_at_end(3)
ll.traverse()  # Output: 1 -> 2 -> 3 -> None
ll.delete_node(2)
ll.traverse()  # Output: 1 -> 3 -> None
```

## Conclusion
Linked lists are fundamental data structures that provide efficient insertion and deletion operations. They are widely used in various applications, including implementing other data structures like stacks, queues, and graphs.
