class Solution {
    int row, col, len;
    bool* boolm;
    
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    { 
        boolm=new bool[rows*cols];
        row=rows;col=cols;len=strlen(str);
        for(int i=0; i<rows; i++) 
            for(int j=0; j<cols; j++) boolm[i*cols+j]=false;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(dfs(i,j,0,matrix,str)){
                    delete boolm;
                    return true;
                }
            }
        }
        delete boolm;
        return false;
    }
    
    bool dfs(int r, int c, int n, char* ma, char* s){
        if(s[n]==ma[r*col+c]){
            std::cout<<r<<c<<s[n]<<std::endl;
            boolm[r*col+c]=true;
            if(n==len-1) return true;
            bool re=false;
            if(r>0) 
                if(boolm[(r-1)*col+c]!=true) re=re||dfs(r-1,c,n+1,ma,s);
            if(r<row-1&&re!=true) 
                if(boolm[(r+1)*col+c]!=true) re=re||dfs(r+1,c,n+1,ma,s);
            if(c>0&&re!=true) 
                if(boolm[(r)*col+c-1]!=true) re=re||dfs(r,c-1,n+1,ma,s);
            if(c<col-1&&re!=true) 
                if(boolm[r*col+c+1]!=true) re=re||dfs(r,c+1,n+1,ma,s);
            if(!re) boolm[r*col+c]=false;
            return re;
        }
        return false;
    }
};