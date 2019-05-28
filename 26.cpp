/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==nullptr || pRoot2==nullptr)
            return false;
        bool ret = false;
        rollnode1(pRoot1,pRoot2,ret);
        return ret;
    }
    
    void rollnode1(TreeNode* pRoot1, TreeNode* pRoot2, bool &isSub){
        if(isSub) return;
        if(pRoot1->val==pRoot2->val){
            if(match(pRoot1,pRoot2))
                isSub = true;
        }else{
            if(pRoot1->left!=nullptr)
                rollnode1(pRoot1->left,pRoot2,isSub);
            if(pRoot1->right!=nullptr)
                rollnode1(pRoot1->right,pRoot2,isSub);
        }
        return;
    }
    
    bool match(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1==nullptr&&pRoot2==nullptr){
            return true;
        }else if(pRoot1!=nullptr&&pRoot2!=nullptr){
            if(pRoot1->val!=pRoot2->val)
                return false;
            return match(pRoot1->left,pRoot2->left)&&match(pRoot1->right,pRoot2->right);
        }else{
            return false;
        }
    }
};



