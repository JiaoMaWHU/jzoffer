/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
//很朴素的写法
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > vSum;
        if(pRoot==nullptr) return vSum;
        queue<TreeNode *> q;
        q.push(pRoot);
        TreeNode * n = nullptr;
        int remain=1;
        int nextNum=0;
        vector<int> v;
        stack<int> s;
        bool odd=true;
        while(!q.empty()){
            n=q.front();
            q.pop();
            if(odd){
                v.push_back(n->val);
            }else{
                s.push(n->val);
            }
            if(n->left!=nullptr){
                q.push(n->left);
                nextNum++;
            }
            if(n->right!=nullptr){
                q.push(n->right);
                nextNum++;
            }
            remain--;
            if(remain==0){
                if(!odd){
                    while(!s.empty()){
                        v.push_back(s.top());
                        s.pop();
                    }
                }
                vSum.push_back(v);
                v.clear();
                remain=nextNum;
                nextNum=0;
                odd=!odd;
            }
        }
        return vSum;
    }
};
//两个栈的写法
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        stack<TreeNode *> stack1,stack2;
        bool direction = true;//向右打印为true，向左打印为false
        if(pRoot!=NULL)
            stack1.push(pRoot);
        TreeNode *node;
        while(!stack1.empty() || !stack2.empty()){
            vector<int> data;
            if(!stack1.empty()){
                while(!stack1.empty()){
                    node = stack1.top();
                    stack1.pop();
                    data.push_back(node->val);
                    if(node->left!=NULL)
                        stack2.push(node->left);
                    if(node->right!=NULL)
                        stack2.push(node->right);
                }
                result.push_back(data);
            }
            else if(!stack2.empty()){
                while(!stack2.empty()){
                    node = stack2.top();
                    stack2.pop();
                    data.push_back(node->val);
                    if(node->right!=NULL)
                        stack1.push(node->right);
                    if(node->left!=NULL)
                        stack1.push(node->left);
                }
                result.push_back(data);
            }
        }
        return result;
    }
};