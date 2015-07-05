// LeetCode #157: Read N Characters Given Read4

/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.
*/

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