// LeetCode #149: Max Points on a Line

// Given n points on a 2D plane, find the maximum number of points that 
// lie on the same straight line.

/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    public int maxPoints(Point[] points) {
        if (points == null || points.length == 0) return 0;
        
        int res = 0;
        Map<Double, Integer> map = new HashMap<Double, Integer>();
        
        for (int i = 0; i < points.length; i++) {
            int duplicate = 1;
            int vertical = 0;
            for (int j = i+1; j < points.length; j++) {
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) duplicate++;
                    else vertical++;
                } else {
                    double slope = points[j]. y == points[i].y? 0.0: 
                    1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
                    
                    if (map.containsKey(slope))
                        map.put(slope, map.get(slope) + 1);
                    else
                        map.put(slope, 1);
                }
            }
            
            for (Integer num: map.values()) {
                if (num + duplicate > res) 
                    res = num + duplicate; 
            }
            
            res = Math.max(res, duplicate + vertical);
            map.clear();
        }
        return res;
    }
}