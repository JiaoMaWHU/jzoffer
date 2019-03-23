class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int x=0, y=rotateArray.size()-1, m;
        while(x<=y){
            m=x+((y-x)>>2);
            if(rotateArray[m]>rotateArray[y]){
                x=m+1;
            }else if(rotateArray[m]<rotateArray[x]){
                x=x+1;
            }else y=m-1;
        }
        return rotateArray[x];
    }
};