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
        vector<vector<int> > vSum;
        if(pRoot==nullptr) return vSum;
        queue<TreeNode *> q;
        q.push(pRoot);
        TreeNode * n = nullptr;
        int remain=1;
        int nextNum=0;
        vector<int> v;
        while(!q.empty()){
            n=q.front();
            q.pop();
            v.push_back(n->val);
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
                vSum.push_back(v);//相当于插入空行
                v.clear();
                remain=nextNum;
                nextNum=0;
            }
        }
        return vSum;
    }
};