public class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new ArrayList<String>();
        if (s == null || s.length() < 11)
            return res;
            
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        map.put('A', 0);
        map.put('C', 1);
        map.put('G', 2);
        map.put('T', 3);
        
        Set<Integer> first = new HashSet<Integer>();
        Set<Integer> second = new HashSet<Integer>();
        
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < 9) {
                index = (index << 2) + map.get(s.charAt(i));
            } else {
                index = (index << 2) + map.get(s.charAt(i));
                index = index & ((1 << 20) - 1);
                if (first.contains(index) && !second.contains(index)) {
                    res.add(s.substring(i-9, i+1));
                    second.add(index);
                } else {
                    first.add(index);
                }
            }
        }
        return res;
    }
}