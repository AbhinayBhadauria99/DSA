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
public:

    bool isMirrorTree(TreeNode* &p, TreeNode* &q) {
        // bc
        if (!p && !q) return true;
        if ((!p && q) || (p && !q)) return false;

        return (p->val == q->val) && isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
    }

    bool isSymmetric(TreeNode* &root) {
        // same as isSameTree - lc - 100
        if (!root) return true;

        return isMirrorTree(root->left, root->right);
    }
};