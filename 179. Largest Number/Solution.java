public class Solution {
    public String largestNumber(int[] num) {
        if (num == null || num.length == 0)
            return "";
            
        String[] s = new String[num.length];
        for (int i = 0; i < num.length; i++)
            s[i] = String.valueOf(num[i]);
            
        Arrays.sort(s, new MyComp());
        
        StringBuilder res = new StringBuilder();
        for (int i = s.length - 1; i >= 0; i--)
            res.append(s[i]);
            
        int i = 0; // Deal with one corner case: input "0", "0", the output should be "0" instead of "00".
        while (i < res.length() - 1) {
            if (res.charAt(i) != '0')
                break;
            i++;
        }
            
        return res.toString().substring(i); // Not subString(i)
        
    }
    
    public class MyComp implements Comparator<String> {
        @Override
        public int compare(String s1, String s2) {
            return (s1 + s2).compareTo(s2 + s1);
        }
    }
    
    /*
    public Comparator<String> comparator = new Comparator<String>() {
        public int compare(String s1, String s2) {
            String comb1 = s1 + s2;
            String comb2 = s2 + s1;
            return comb1.compareTo(comb2);
        }
    };
    */
}