class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str==nullptr||pattern==nullptr) 
            if(str==nullptr&&pattern==nullptr) return true;
            else return false;
        
        return matching(str, pattern);
    }
    
    bool matching(char* str, char* pattern){
        if(*str=='\0'&&*pattern=='\0') return true;
        if(*str!='\0'&&*pattern=='\0') return false;
        if(*(pattern+1)=='*'){
            if(*str==*pattern||(*pattern=='.'&&*str!='\0')){
                return matching(str, pattern+2) ||
                    matching(str+1, pattern) ||
                    matching(str+1, pattern+2);
            }
            else return matching(str, pattern+2);
        }else if(*str==*pattern||(*pattern=='.'&&*str!='\0')) return matching(str+1,pattern+1);
        else return false;
    }
};