class Solution {
    public int singleNumber(int[] nums) {
        int[] counts = new int[31];
        for(int n: nums) {
            int i = 0;
            while(n != 0) {
                counts[i++] += n % 2;
                n >>= 1;
            }
        }
        int res = 0;
        for(int i=0; i<31; i++) {
            if ( (counts[i] % 3) != 0) 
                res += Math.pow(2, i);
        }
        return res;
    }
}