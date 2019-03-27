class Solution {
public:
     int  NumberOf1(int n) {
         int num=0;
         while(n){
             num++;
             n=n&(n-1);
         }
         return num;
     }
};