class Solution {
    public int missingNumber(int[] nums) {
        int s = 0;
        for (int i=0; i<nums.length; i++) {
            if(nums[i] != s) {
                break;
            }
            s++;
        }
        return s;
    }
}