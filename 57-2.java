class Solution {
    public int[][] findContinuousSequence(int target) {
        LinkedList<int[]> ll = new LinkedList<int[]>();
        int i = 1, j = 2;
        int sum = 0;
        while(i<j) {
            sum = (i+j)*(j-i+1)/2;
            if(sum == target) {
                int[] arr = new int[j-i+1];
                for(int k=0; k<j-i+1; k++)
                    arr[k] = k+i;
                ll.add(arr);
                i++;
            }else if(sum < target) {
                j++;
            }else{
                i++;
            }
        }
        return ll.toArray(new int[ll.size()][]);
    }
}