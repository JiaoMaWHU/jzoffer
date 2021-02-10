class Solution {
    
    public int numDigits(int n) {
        if (n == 0) 
            return 1;
        return (int)(Math.log10(n)) + 1;
    }
    
    class SortByDigits implements Comparator<Integer> {
        public int compare(Integer a, Integer b) {
            Double dg1 = Math.pow(10, numDigits(a));
            Double dg2 = Math.pow(10, numDigits(b));
            return (a * dg2.intValue() + b) - (b * dg1.intValue() + a);
        }
    }
    
    public String minNumber(int[] nums) {
        Integer[] Nums = new Integer[nums.length];
        for (int i=0; i<nums.length; i++) {
            Nums[i] = nums[i];
        }
        Arrays.sort(Nums, new SortByDigits());
        StringBuilder sb = new StringBuilder();
        for(Integer n: Nums) {
            sb.append(n.toString());
        }
        return sb.toString();
    }
}