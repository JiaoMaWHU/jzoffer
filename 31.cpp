class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()||popV.empty()){
            if(pushV.empty()&&popV.empty()){
                return true;
            }else return false;
        }else{
            if(pushV.size()!=popV.size()) return false;
            map<int,int> mapV;
            vector<bool> isV(pushV.size());
            vector<int> popSeq(pushV.size());
            for(int i=0; i<pushV.size(); i++){
                mapV.insert(std::pair<int,int>(pushV[i],i));
            }
            for(int i=0; i<popV.size(); i++){
                auto it = mapV.find(popV[i]);
                if(it==mapV.end()) return false;
                if(isV[it->second]!=0) return false;
                isV[it->second] = 1;
                popSeq[i] = it->second;
            }
            isV.assign(pushV.size(),0);
            int next=-1;
            for(auto &item : popSeq){
                if(item>=next){
                    next=-1;
                    isV[item] = 1;
                    for(int i =0; i<item; i++){
                        if(isV[i]!=1) next= i;
                    }
                }else return false;
            }
            return true;
        }
    }
};