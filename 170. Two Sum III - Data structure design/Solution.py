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
        self.mydict = dict()

    # @return nothing
    def add(self, number):
        if not self.mydict.has_key(number):
            self.mydict[number] = 1
        else:
            self.mydict[number] = self.mydict[number] + 1

    # @param value, an integer
    # @return a Boolean
    def find(self, value):
        for key in self.mydict.keys():
            target = value - key
            if self.mydict.has_key(target) and target != value:
                return True
            elif self.mydict.has_key(target) and target == value and self.mydict[target] >= 2:
                return True
        
        return False