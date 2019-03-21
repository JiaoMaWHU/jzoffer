class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row=array.size();
        int column=array[0].size();
        int min_col=0;
        for(int i=row-1; i>=0;i--){
            for(int j=min_col; j<column; j++){
                if(array[i][j]>target){
                    break;   
                }else if(array[i][j]==target){
                    return true;
                }else{
                    min_col=j;
                }
            }
        }
        return false;
    }
};