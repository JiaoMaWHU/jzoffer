class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> sq;
    priority_queue<int> gq;
    
    void Insert(int num)
    {
        if(gq.size()>sq.size()){
            gq.push(num);
            sq.push(gq.top());
            gq.pop();
        }else{
            if(!sq.empty()&&num>sq.top()){
                sq.push(num);
                gq.push(sq.top());
                sq.pop();
            }else gq.push(num);
        }
    }

    double GetMedian()
    { 
        if(gq.size()==sq.size())
            return (gq.top()+sq.top())/2.000;
        else
            return gq.top();
    }

};
