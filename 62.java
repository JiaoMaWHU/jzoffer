class Solution {
    public int lastRemaining(int n, int m) {
        
        int last = 0;
        for(int i=1; i<n; i++) {
            last = (last + m) % (i+1);
        }
        return last;
    }
}