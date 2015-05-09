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