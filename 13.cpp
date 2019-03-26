class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool matrix[rows*cols];
        memset(matrix,0,rows*cols);
        bool* m=matrix;
        dfs(threshold,0,0,m,rows,cols);
        int n=0;
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(m[i*cols+j]){n++;}
        return n;
    }
    
    void dfs(int t, int r, int c, bool* m, int rows, int cols){
        if(getNum(r)+getNum(c)<=t&&r>=0&&r<rows&&c>=0&&c<cols&&m[r*cols+c]!=true){
                m[r*cols+c]=true;
                dfs(t,r,c+1,m,rows,cols);
                dfs(t,r,c-1,m,rows,cols);
                dfs(t,r+1,c,m,rows,cols);
                dfs(t,r-1,c,m,rows,cols);
        }
    }
    
    int getNum(int n){
        int num=0;
        while(n>0){
            num+=(n%10);
            n/=10;
        }
        return num;
    }
};