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
    int treeLevel(TreeNode* root){
        if (root== NULL) return 0;
        return 1 + max( treeLevel(root->left), treeLevel(root->right));
    }
    
    void helper(TreeNode* root, int currentLevel, int targetLevel, vector<int> &result){
        if (root==NULL) return;
        if (currentLevel== targetLevel){
            result.push_back(root->val);
            return;
        }
        helper(root->left,currentLevel+1, targetLevel, result);
        helper(root->right, currentLevel+1, targetLevel, result);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> result;
        int maxLevel=treeLevel(root);
        for (int i=1; i<=maxLevel ; i++){
            helper(root, 1, i, result);
            ans.push_back(result);
            for (int i:result){
                result.pop_back();
            }
        }
        return ans;
    }
};