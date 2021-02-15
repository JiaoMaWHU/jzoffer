class Solution {
    public int[] constructArr(int[] a) {
        if(a.length==0) {
            return new int[0];
        }
        if(a.length==1) {
            return a;
        }
        int[] front = new int[a.length];
        int[] back = new int[a.length];
        front[0] = a[0];
        back[a.length-1] = a[a.length-1];
        for(int i=1; i<front.length; i++) {
            front[i] = front[i-1] * a[i];
        }
        for(int i=back.length-2; i>0; i--){
            back[i] = back[i+1] * a[i];
        }
        int[] res = new int[a.length];
        int b, f;
        for(int i=0; i<a.length; i++){
            f = i-1 < 0? 1:front[i-1];
            b = i+1 > a.length-1? 1:back[i+1];
            res[i] = f * b;
        }
        return res;
    }
}