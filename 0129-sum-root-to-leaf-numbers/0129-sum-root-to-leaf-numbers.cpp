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
   void helper(TreeNode* root,string temp,vector<string>& res){
    if(root==NULL)return;
   temp+=(to_string(root->val));
   if(root->left==NULL && root->right==NULL){
    res.push_back(temp);
    return;
   }
    helper(root->left,temp,res);
    helper(root->right,temp,res);
   }
public:
    int sumNumbers(TreeNode* root) {
        string temp="";
        vector<string> res;
        helper(root,temp,res);
        int result=0;
        for(auto it:res){
           result+=stoi(it);
        }
        return result;
    }
};