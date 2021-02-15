class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) {
            return new int[]{};
        }
        int[] res = new int[nums.length - k +1];
        LinkedList<Integer> ll = new LinkedList<Integer>();
        int l = 0;
        for(int r = 0; r<nums.length; r++) {
            while( ll.size()>0 && ll.getLast() < nums[r]) {
                ll.removeLast();
            }
            ll.add(nums[r]);
            if(r-l == k-1) {
                res[l] = ll.getFirst();
                if(ll.getFirst() == nums[l++]) {
                    ll.removeFirst();
                }
            }
        }
        return res;
    }
}