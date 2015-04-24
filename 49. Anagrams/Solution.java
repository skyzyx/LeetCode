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