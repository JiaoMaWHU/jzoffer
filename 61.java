class Solution {
    public boolean isStraight(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        while(nums[i] == 0) {
            i++;
        }
        int jokers = i++;
        int diff = 0;
        while(i<5) {
            if(nums[i] == nums[i-1]) {
                return false;
            }
            diff += (nums[i] - nums[i-1] -1);
            i++;
        }
        if(diff > jokers) {
            return false;
        }
        return true;
    }
}