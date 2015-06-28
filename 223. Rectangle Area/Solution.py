# LeetCode #223: Rectangle Area

'''
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
'''

class Solution:
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        area1 = (C-A) * (D-B)
        area2 = (G-E) * (H-F)
        common = max(min(C, G) - max(A, E), 0) * max(min(D, H) - max(B, F), 0)
        return area1 + area2 - common
        