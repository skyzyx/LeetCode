// LeetCode #223: Rectangle Area

/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
*/

public class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A) * (D-B);
        int area2 = (G-E) * (H-F);
        
        if (E > C || A > G || B > H || F > D)
            return area1 + area2;
        
        int common = Math.max((Math.min(C, G) - Math.max(A, E)), 0) * Math.max((Math.min(D, H) - Math.max(B, F)), 0);
        return area1 + area2 - common;
    }
}