class Solution {
    
    public int translateNum(int num) {
        if (num<10) {
            return 1;
        }
        String s = Integer.toString(num);
        Integer[] dp = new Integer[s.length()+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i<dp.length; i++) {
            dp[i] = dp[i-1] * 1;
            int v = (s.charAt(i-2) - '0') * 10 + (s.charAt(i-1) - '0');
            if ((v >= 10) && (v <= 25)){
                dp[i] += dp[i-2] * 1;
            }
        }
        return dp[dp.length-1];
    }
}