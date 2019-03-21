class Solution {
public:
	void replaceSpace(char *str,int length) {
        std::vector<int> v;
        for(int i=0; i<length; i++){
            if(str[i]==' '){
                v.push_back(i);
            }
        }
        int size = v.size();
        int end = length-1;
        for(int i=size-1;i>=0;i--){
            int j;
            for(j=end;j>v[i];j--){
                str[j+2*(i+1)]=str[j];
            }
            j=j+2*(i);
            str[j]='%';str[j+1]='2';str[j+2]='0';
            end=v[i]-1;
        }
	}
};