/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> p, v;
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        p=pre;
        v=vin;
        return construct(0, pre.size()-1, 0, v.size()-1);
    }
    
    TreeNode* construct(int px, int py, int vx, int vy){
        int value=p[px];
        TreeNode *node = new TreeNode(value);
        if(px==py) return node;
        int root;
        for(int i=vx; i<=vy; i++){
            if(v[i]==value){
                root=i; break;
            }
        }
        int len = root - vx;
        if(len>0){
            node->left = construct(px+1,px+len,vx,root-1);
        }
        if(len<vy-vx)
        node->right = construct(px+len+1,py,root+1,vy);
        return node;
    }
};