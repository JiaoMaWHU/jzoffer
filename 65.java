class Solution {
    public int add(int a, int b) {
        int res = 0;
        int add = 0;
        int tmp = 0;
        for(int i=0; i<32; i++) {
            tmp = (a & 1) ^ (b & 1);
            int cp_add = add;
            if((a & 1) == 1 && (b&1) == 1) {
                add = 1;
            }else if((tmp & 1) == 1 && (add & 1) == 1){
                add = 1;
            }else{
                add = 0;
            }
            tmp ^= cp_add;
            res |= (tmp&1) << i;
            a >>= 1;
            b >>= 1;
        }
        return res;
    }
}