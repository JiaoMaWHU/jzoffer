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
  vector<vector<int> > result;
  vector<int> v;
  vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
    if (root == nullptr) return result;
    findPath(root, expectNumber);
    return result;
  }

  void findPath(TreeNode* root, int leftV) {
    if (leftV == root->val) {
      if (root->left == nullptr && root->right == nullptr) {
        v.push_back(root->val);
        result.push_back(v);
        v.erase(v.end() - 1);
      }
    } else if (leftV > root->val) {
      v.push_back(root->val);
      if (root->left != nullptr) {
        findPath(root->left, leftV - root->val);
      }
      if (root->right != nullptr) {
        findPath(root->right, leftV - root->val);
      }
      v.erase(v.end() - 1);
    }
  }
};