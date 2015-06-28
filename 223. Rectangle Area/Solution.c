// LeetCode #223: Rectangle Area

/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
*/

int max(int a, int b) {
    return a > b? a: b;
}

int min(int a, int b) {
    return a < b? a: b;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1 = (C-A) * (D-B);
    int area2 = (G-E) * (H-F);
        
    if (E > C || A > G || B > H || F > D)
        return area1 + area2;
        
    int common = max((min(C, G) - max(A, E)), 0) * max((min(D, H) - max(B, F)), 0);
    return area1 + area2 - common;
}