// LeetCode #158: Read N Characters Given Read4 II - Call multiple times

/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.
*/

/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     
    private Queue<Character> que = new LinkedList<Character>(); 
     
    public int read(char[] buf, int n) {
        char[] tmpbuf = new char[4];
        int ans = 0;
        // Queue<Character> que = new LinkedList<Character>();
        
        while (true) {
            int num = read4(tmpbuf);
            for (int i = 0; i < num; i++)
                que.offer(tmpbuf[i]);
                
            num = Math.min(n - ans, que.size());
            if (num == 0)
                break;
            
            for (int i = 0; i < num; i++)
                buf[ans++] = que.poll();
        }
        return ans;
        
    }
}