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
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int start, int end,int& idx){
        if(start>end) return NULL;
        int rootVal= preorder[idx];
        int temp=start;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==rootVal){
                temp=i;
                break;
            }
        }
        idx++;
        TreeNode* root=new TreeNode(rootVal);
        root->left=helper(preorder,inorder,start,temp-1,idx);
        root->right=helper(preorder,inorder,temp+1,end,idx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        int n= preorder.size();
        return helper(preorder,inorder,0,n-1,idx);
    }
};