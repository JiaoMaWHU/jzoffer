class Solution {
public:
    int Fibonacci(int n) {
        int n2=0, n1=1, f;
        if(n==0) return n2;
        else if(n==1) return n1;
        else{
            for(int i=2; i<=n; i++){
                f=n2+n1;
                n2=n1;
                n1=f;
            }
        }
        return f;
    }
};