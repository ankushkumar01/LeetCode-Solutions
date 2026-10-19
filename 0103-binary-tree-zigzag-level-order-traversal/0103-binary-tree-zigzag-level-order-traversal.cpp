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
        currentLevel++;
        if (targetLevel%2==1){
            helper(root->left,currentLevel, targetLevel, result);
            helper(root->right, currentLevel, targetLevel, result);
        }
        else{
            helper(root->right, currentLevel, targetLevel, result);
            helper(root->left,currentLevel, targetLevel, result);
        }  
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int maxLevel=treeLevel(root);
        for (int i=1; i<=maxLevel ; i++){
            vector<int> result;
            helper(root, 1, i, result);
            ans.push_back(result);
        }
        return ans;
    }
};