// LeetCode #146: LRU Cache

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

import java.util.LinkedHashMap;

public class LRUCache {
    LinkedHashMap<Integer, Integer> map;
    int capacity;
    
    public LRUCache(int capacity) {
        map = new LinkedHashMap<Integer, Integer>();
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (!map.containsKey(key))
            return -1;
            
        int value = map.get(key);
        map.remove(key);
        map.put(key, value);
        return value;
    }
    
    public void set(int key, int value) {
        if (!map.containsKey(key)) {
            map.put(key,value);
            if (map.size() > capacity)
                map.remove(map.keySet().iterator().next()); // Remove the first key.
        } else {
            map.remove(key);
            map.put(key,value);
        }
    }
}