class Solution {
    public int strToInt(String str) {
        String newstr = str.trim();
        if(newstr.length()==0) {
            return 0;
        }
        int sign = 1;
        long res = 0;
        int i = 0;
        if(newstr.charAt(i) == '-') {
            sign = -1;
            i++;
        }else if(newstr.charAt(i) == '+') {
            sign = 1;
            i++;
        }
        int valid = 0;
        while(i<newstr.length()) {
            if(newstr.charAt(i) < '0' || newstr.charAt(i) > '9') {
                break;
            }else{
                valid = 1;
                res *= 10;
                res += (newstr.charAt(i) - '0');
                if(res * sign > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                }else if(res * sign < Integer.MIN_VALUE) {
                    return Integer.MIN_VALUE;
                }
            }
            i++;
        }
        if(valid == 0){
            return 0;
        }
        res *= sign;
        return (int)res;
    }
}