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
   void helper(TreeNode* root,vector<string>& res,string st){//st is passed by value because it get refreshed in each new path from root to leaf by  ""
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
          st+=to_string(root->val);
          res.push_back(st);
          return;
    }
    else{
        st+=to_string(root->val);
        st+=("->");
    }
    helper(root->left,res,st);
    helper(root->right,res,st);
   }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string st="";
        helper(root,res,st);
        return res;
    }
};