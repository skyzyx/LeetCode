public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s == null || t == null || s.length() != t.length())
            return false;
            
        Map<Character, Character> smap = new HashMap<Character, Character>();
        Map<Character, Character> tmap = new HashMap<Character, Character>();
        
        for (int i = 0; i < s.length(); i++) {
            if (smap.containsKey(s.charAt(i)))
                if (smap.get(s.charAt(i)) != t.charAt(i))
                    return false;
            if (tmap.containsKey(t.charAt(i)))
                if (tmap.get(t.charAt(i)) != s.charAt(i))
                    return false;
                
            smap.put(s.charAt(i), t.charAt(i));
            tmap.put(t.charAt(i), s.charAt(i));
        }
        return true;
    }
}