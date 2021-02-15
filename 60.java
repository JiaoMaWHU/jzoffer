class Solution {
    public double[] dicesProbability(int n) {
        int maxv = n * 6;
        int[][] count = new int[2][maxv+1];
        for(int j=0; j<maxv+1; j++)
            count[1][j] = 0;
        count[1][0] = 1;
        for(int i = 0; i<n; i++) {
            for(int j=0; j<maxv+1; j++)
                count[i%2][j] = 0;
            for(int j=1; j<maxv+1; j++) {
                for(int k=1; k<7; k++) {
                    if(j-k<0) {
                        break;
                    }
                    count[i%2][j] += count[(i+1)%2][j-k];
                }
            }
        }
        int non0 = 0;
        int sum = 0;
        int v;
        for(int i=0; i<maxv+1; i++) {
            v = count[(n-1)%2][i];
            if (v != 0) {
                non0++;
                sum += v;
            }
        }
        double[] res = new double[non0];
        int id = 0;
        for(int i=0; i<maxv+1; i++) {
            v = count[(n-1)%2][i];
            if(v != 0) {
                res[id++] = (double)v/(double)sum;
            }
        }
        return res;
    }
}