# LeetCode #170: Two Sum III

'''
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
'''

class TwoSum:
    # initialize your data structure here
    def __init__(self):
        self.mydict = dict() # OR self.mydict = {}

    # @return nothing
    def add(self, number):
        if number in self.mydict: # OR if self.mydict.has_key(number):
            self.mydict[number] += 1
        else:
            self.mydict[number] = 1

    # @param value, an integer
    # @return a Boolean
    def find(self, value):
        for key in self.mydict:
        # for key in self.mydict.keys(): Time Limit Exceeded
            target = value - key
            if target in self.mydict and (target != key or self.mydict[target] > 1):
                return True
        
        return False
