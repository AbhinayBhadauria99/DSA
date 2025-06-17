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
    void helper(TreeNode* root, int val){
        if(val>root->val){
            if(root->right==NULL){
                root->right=new TreeNode(val);
            }
            helper(root->right,val);
        }
        if(val<root->val){
            if(root->left==NULL){
                root->left=new TreeNode(val);
            }
            helper(root->left,val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root == NULL) {
            return new TreeNode(val);  //agar kuchh nhi to vahi val ka node bna dete hai
        }
        helper(root,val);
        return root;
    }
};