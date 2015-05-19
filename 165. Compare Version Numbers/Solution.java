public class Solution {
    public int compareVersion(String version1, String version2) {
        for (int i = 0, j = 0; i < version1.length() || j < version2.length(); i++, j++) {
            int data1 = 0, data2 = 0;
            while (i < version1.length() && version1.charAt(i) != '.') {
                data1 = data1 * 10 + (version1.charAt(i) - '0');
                i++;
            }
            
            while (j < version2.length() && version2.charAt(j) != '.') {
                data2 = data2 * 10 + (version2.charAt(j) - '0');
                j++;
            }
            
            if (data1 > data2)
                return 1;
            if (data1 < data2)
                return -1;
        }
        return 0;
    }
}