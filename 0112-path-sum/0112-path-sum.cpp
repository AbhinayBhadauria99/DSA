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
   void helper(TreeNode* root, int& targetSum,int res,bool& temp){ //temp passed by reference
    if(root==NULL) return;
    res+= root->val;

    helper(root->left,targetSum,res,temp);

    if(res==targetSum && root->left==NULL && root->right==NULL){
    temp=true;
    return;
    } 

    helper(root->right,targetSum,res,temp);
   }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool temp=false;
        int res=0;
        helper(root,targetSum,res,temp);
        return temp;
    }
};