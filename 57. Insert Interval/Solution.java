// LeetCode #57: Insert Interval

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

/*
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> res = new ArrayList<Interval>();
        
        for (Interval item: intervals) {
            if (item.end < newInterval.start) 
                res.add(item);
            else if (item.start > newInterval.end) {
                res.add(newInterval);
                newInterval = item;
            } else {
                // newInterval = new Interval(Math.min(item.start, newInterval.start), Math.max(item.end, newInterval.end));
                newInterval.start = Math.min(item.start, newInterval.start);
                newInterval.end = Math.max(item.end, newInterval.end);
            }
        }
        res.add(newInterval);
        return res;
    }
}
*/

public class Solution { // Using ListIterator
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> res = new ArrayList<Interval>();
        
        ListIterator<Interval> it = intervals.listIterator();
        // ListIterator it = intervals.listIterator();
        // error: incompatible types: Object cannot be converted to Interval
        
        // Iterator<Interval> it = intervals.iterator();
        // Besides ListIterator, Iterator works as well.
        
        while (it.hasNext()) {
            Interval item = it.next();
            
            if (item.end < newInterval.start) 
                res.add(item);
            else if (item.start > newInterval.end) {
                res.add(newInterval);
                newInterval = item;
            } else {
                // newInterval = new Interval(Math.min(item.start, newInterval.start), Math.max(item.end, newInterval.end));
                newInterval.start = Math.min(item.start, newInterval.start);
                newInterval.end = Math.max(item.end, newInterval.end);
            }
        }
        res.add(newInterval);
        return res;
    }
}