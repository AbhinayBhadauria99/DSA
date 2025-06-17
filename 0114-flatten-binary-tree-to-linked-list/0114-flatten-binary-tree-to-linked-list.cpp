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
   void helper(TreeNode* root){
    if (!root) return;
    if(root->left){
        TreeNode* temp= root->left;
        root->left=NULL;
        TreeNode* temp2 =root->right;
        root->right=temp;
        TreeNode* curr= root->right;
        while(curr->right){
            curr= curr->right;
        }
        curr->right=temp2;
    }
    if(root->right) helper(root->right);
   }
public:
    void flatten(TreeNode* root) {
         helper(root);
    }
};