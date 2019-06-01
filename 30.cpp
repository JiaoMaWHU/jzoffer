class Solution {
public:
    void push(int value) {
        if(value<=min_){
            min_ = value;
            s2.push(value);
        }
        s1.push(value);
    }
    void pop() {
        if(s1.top()==min_){
            s2.pop();
            min_ = s2.top();
        }
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return min_;
    }
    int min_ = 1000000;
    stack<int> s1;
    stack<int> s2;
};