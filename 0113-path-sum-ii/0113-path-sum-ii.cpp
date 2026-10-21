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
    void helper(TreeNode* root, int targetSum, vector<int>ans, vector<vector<int>>& finalAns){
        if (root==NULL) return;
        ans.push_back(root->val);
        if (root->left==NULL && root->right==NULL){
            int sum=0;
            for(int i: ans){
                sum+=i;
            }
            if (sum==targetSum) finalAns.push_back(ans);
            return;
        }
        helper(root->left, targetSum, ans, finalAns);
        helper(root->right, targetSum, ans, finalAns);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> finalAns;
        vector<int>ans;
        helper(root, targetSum, ans, finalAns);
        return finalAns;
    }
};