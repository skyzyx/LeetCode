public class Solution {
    public void sortColors(int[] A) {
        if (A == null || A.length <= 1)
            return;
            
        int i = 0;
        int j = A.length - 1;
        int zeroIndex = 0;
        
        while (i <= j) {
            if (A[i] == 0) {
                swap(A, i, zeroIndex);
                i++;
                zeroIndex++;
            } else if (A[i] == 2) {
                swap(A, i, j);
                j--;
            } else {
                i++;
            }
        }
        return;
    }
    
    private void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}