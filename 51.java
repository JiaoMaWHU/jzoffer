class Solution {
    public int reversePairs(int[] nums) {
        int leng = nums.length;
        int[] sorte_darr = new int[nums.length];
        return merge(nums, sorte_darr, 0, leng-1);
    }
    
    public int merge(int[] nums, int[] sorte_darr, int l, int r) {
        int v = 0;
        if (l >= r) {
            return v;
        }
        v += merge(nums, sorte_darr, l, (l+r)/2);
        v += merge(nums, sorte_darr, (l+r)/2+1, r);
        v += mergeTwo(nums, sorte_darr, l, (l+r)/2, (l+r)/2+1, r);
        return v;
    }
    
    public int mergeTwo(int[] nums, int[] sorte_darr, int l1, int r1, int l2, int r2) {
        for (int i = l1; i <= r2; i++) {
            sorte_darr[i] = nums[i];
        }
        int v = 0;
        int p1 = l1, p2 = l2;
        int s = l1;
        while(s <= r2) {
            if (p1 > r1) {
                nums[s++] = sorte_darr[p2++];
                continue;
            }
            if (p2 > r2) {
                nums[s++] = sorte_darr[p1++];
                v += (p2 - l2);
                continue;
            }
            if (sorte_darr[p1] > sorte_darr[p2]) {
                nums[s++] = sorte_darr[p2++];
            } else {
                nums[s++] = sorte_darr[p1++];
                v += (p2 - l2);
            }
        }
        return v;
    }
}