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
    int treeLevel (TreeNode* root){
        if (root== NULL) return 0;
        return 1 + max (treeLevel(root->left), treeLevel(root->right));
    }
    void helper(TreeNode* root, int currentLevel, int targetLevel, vector<int> & ans){
        if (root==NULL) return;
        if (currentLevel==targetLevel) ans[targetLevel]=root->val;
        helper(root->left, currentLevel + 1, targetLevel, ans);
        helper(root->right, currentLevel + 1, targetLevel, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int n= treeLevel(root);
        vector<int> ans (n);
        for(int i=0; i<n; i++){
            helper(root,0,i,ans);
        }
        return ans;
    }
};