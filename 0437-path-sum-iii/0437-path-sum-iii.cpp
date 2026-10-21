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
    void traverseTree(TreeNode* root, int targetSum, int & pathCount){
        if (root==NULL) return;
        helper(root, targetSum, pathCount);
        traverseTree(root->left, targetSum, pathCount);
        traverseTree(root->right, targetSum, pathCount);
    }
    void helper(TreeNode* root, long long targetSum, int & pathCount){
        if (root==NULL) return;
        if (root->val==targetSum){
            pathCount=pathCount + 1;
        }
        helper(root->left, targetSum-(root->val), pathCount);
        helper(root->right, targetSum-(root->val), pathCount);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int pathCount=0;
        traverseTree(root, targetSum, pathCount);
        return pathCount;
    }
};