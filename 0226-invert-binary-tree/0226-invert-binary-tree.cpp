/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
  void helper(TreeNode* temp){
    if(temp==NULL) return; 
    TreeNode* temp2= temp->left;
    temp->left=temp->right;
    temp->right=temp2;
    helper(temp->left);
    helper(temp->right);
  }
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};