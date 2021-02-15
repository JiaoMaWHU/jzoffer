class Solution {
    public int[] singleNumbers(int[] nums) {
        int[] twon = new int[2];
        twon[0] = 0;
        twon[1] = 0;
        int res = 0;
        for (int n: nums) {
            res ^= n;
        }
        int id = 0;
        while( (res & (int)Math.pow(2, id)) == 0) {
            id++;
        }
        int target = (int)Math.pow(2, id);
        int i = 0, j = 0;
        while(j < nums.length) {
            if ( ((nums[j] & target) == 0) ) {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                i++;
            }
            j++;
        }
        for (int s = 0; s<i; s++) {
            twon[0] ^= nums[s];
        }
        for (int s = i; s<nums.length; s++) {
            twon[1] ^= nums[s];
        }
        return twon;
    }
}