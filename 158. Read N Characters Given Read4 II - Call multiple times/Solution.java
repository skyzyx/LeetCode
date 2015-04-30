/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     
    Queue<Character> que = new LinkedList<Character>(); 
     
    public int read(char[] buf, int n) {
        char[] tmpbuf = new char[4];
        int ans = 0;
        // Queue<Character> que = new LinkedList<Character>();
        
        while (true) {
            int num = read4(tmpbuf);
            for (int i = 0; i < num; i++)
                que.offer(tmpbuf[i]);
                
            num = Math.min(n - ans, que.size());
            for (int i = 0; i < num; i++)
                buf[ans++] = que.poll();
                
            if (num == 0)
                break;
        }
        return ans;
        
    }
}