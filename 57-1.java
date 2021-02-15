class Solution {
    public int[] twoSum(int[] nums, int target) {
        int i = 0, j = nums.length-1;
        while(i<j) {
            int v = nums[i] + nums[j];
            if(v == target) {
                break;
            }else if(v > target) {
                j--;
            }else {
                i++;
            }
        }
        return new int[]{nums[i], nums[j]};
    }
}