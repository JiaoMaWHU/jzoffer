class Solution {
    public int nthUglyNumber(int n) {
        int[] arr = new int[n];
        Arrays.fill(arr, 0);
        arr[0] = 1;
        int nextUNid = 1;
        int biggestUNid = 0;
        int un2Id = 0;
        int un3Id = 0;
        int un5Id = 0;
        int minimum;
        while(nextUNid < n) {
            minimum = Math.min(arr[un2Id] * 2, arr[un3Id] * 3);
            minimum = Math.min(minimum, arr[un5Id] * 5);
            arr[nextUNid] = minimum;
            nextUNid++;
            
            biggestUNid = Math.max(biggestUNid, minimum);
            while(arr[un2Id] * 2 <= biggestUNid && un2Id < nextUNid) 
                un2Id++;
            while(arr[un3Id] * 3 <= biggestUNid && un3Id < nextUNid) 
                un3Id++;
            while(arr[un5Id] * 5 <= biggestUNid && un5Id < nextUNid) 
                un5Id++;
        }
        
        return arr[n-1];
    }
}