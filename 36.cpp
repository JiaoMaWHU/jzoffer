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
  TreeNode* Convert(TreeNode* pRootOfTree) {
    CreateList(pRootOfTree);
    TreeNode* ret = last;
    while (ret->left != nullptr && ret != nullptr) {
      ret = ret->left;
    }
    return ret;
  }

  void CreateList(TreeNode* pNode) {
    if (pNode == nullptr) {
      return;
    }
    if (pNode->left != nullptr) {
      CreateList(pNode->left);
    }
    pNode->left = last;
    if (last != nullptr) {
      last->right = pNode;
    }
    last = pNode;
    if (pNode->right != nullptr) {
      CreateList(pNode->right);
    }
  }

  TreeNode* last = nullptr;
};