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
    int level (TreeNode* root){
        if (root== nullptr) return 0;
        return 1 + max(level (root->left), level (root->right));
    }
    void helper(TreeNode* root, int & d){
        if (root== nullptr) return;
        d=max(d, level(root->left)+ level(root->right));
        helper(root->left,d);
        helper(root->right,d);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int d=0;
       helper(root, d);
       return d;
    }
};