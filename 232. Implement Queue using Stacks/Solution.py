# LeetCode #232: Implement Queue using Stacks

'''
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
'''

class Queue:
    # initialize your data structure here.
    def __init__(self):
        self.s1 = []
        self.s2 = []

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.s1.append(x)

    # @return nothing
    def pop(self):
        while len(self.s1) > 0:
            self.s2.append(self.s1.pop())
            
        self.s2.pop()
        
        while len(self.s2) > 0:
            self.s1.append(self.s2.pop())

    # @return an integer
    def peek(self):
        return self.s1[0]

    # @return an boolean
    def empty(self):
        return len(self.s1) == 0