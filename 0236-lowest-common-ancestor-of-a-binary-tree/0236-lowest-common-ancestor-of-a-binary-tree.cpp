/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
 TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL || root==p || root==q) return root; //agar node null toh it will return null
      TreeNode* left = helper(root->left,p,q);
      TreeNode* right=helper(root->right,p,q);

      if(left && right) return root;
      return left?left:right;   //agar left null hai toh right
 }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return helper(root,p,q);
    }
};