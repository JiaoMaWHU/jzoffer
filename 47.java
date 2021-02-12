class Solution {
    
    public int maxValue(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int left, upper;
                left = j-1>=0 ? grid[i][j-1]: 0;
                upper = i-1>=0 ? grid[i-1][j]: 0;
                grid[i][j] += Math.max(left, upper); 
            }
        }
        return grid[m-1][n-1];
    }
}