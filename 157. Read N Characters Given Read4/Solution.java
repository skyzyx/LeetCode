/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    public int read(char[] buf, int n) {
        char[] tempBuf = new char[4];
        int ans = 0;
        
        while (true) {
            int num = read4(tempBuf);
            if (num == 0)
                break;
                
            /*
            Input:	"a", 0
            Output:	"a"
            Expected:	""
            */
            num = Math.min(num, n - ans);
                
            for (int i = 0; i < num; i++)
                buf[ans++] = tempBuf[i];
        }
        return ans;
    }
}