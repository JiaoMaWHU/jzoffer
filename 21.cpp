class Solution {
public:
    void reOrderArray(vector<int> &array) {
         for(int i = 0;i < array.size()/2 +1;i++){
            for(int j = array.size()-1; j>i;j--){
                if(array[j]%2==1&&array[j-1]%2==0)
                    swap(array[j],array[j-1]);
            }
        }
    }
};