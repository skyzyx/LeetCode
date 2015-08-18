// LeetCode #49: Anagrams

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

Update (2015-08-09):
The signature of the function had been updated to return list<list<string>> instead of 
list<string>, as suggested here. If you still see your function signature return a 
list<string>, please click the reload button  to reset your code definition.
*/

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List res = new ArrayList();
        if (strs == null || strs.length == 0) return res;
        
        Map<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
        
        for (String word: strs) {
            char[] wordarr = word.toCharArray();
            Arrays.sort(wordarr);
            String s = String.valueOf(wordarr);
            
            if (map.containsKey(s)) {
                map.get(s).add(word);
            } else{
                ArrayList<String> tmp = new ArrayList<String>();
                tmp.add(word);
                map.put(s, tmp);
            }
        }
        
        for (ArrayList<String> item: map.values()) {
            if (item.size() > 2);
                Collections.sort(item);
            res.add(item);
        }
        
        return res;
    }
}

/*
public class Solution {
    public List<String> anagrams(String[] strs) {
        List<String> res = new ArrayList<String>();
        if (strs.length < 2)
            return res;
        
        Map<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
        
        for (String word: strs) {
            char[] tmp = word.toCharArray();
            Arrays.sort(tmp);
            // String foo = tmp.toString(); Do NOT work.
            String foo = String.valueOf(tmp);
            
            if (map.containsKey(foo)) {
                map.get(foo).add(word);
            } else {
                ArrayList<String> bar = new ArrayList<String>();
                bar.add(word);
                map.put(foo, bar);
                // map.put(foo, bar.add(word)); error: incompatible types: boolean cannot be converted to ArrayList<String>
            }
        }
        
        for (ArrayList<String> list: map.values()) {
            if (list.size() > 1)
                res.addAll(list);
        }
        return res;
        
    }
}
*/