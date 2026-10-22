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
    void insertTreeNode(TreeNode* root, int val){
        // if (root==NULL){
        //     TreeNode* temp= new TreeNode (val);
        //     root= temp;
        //     return;
        // }
        if (val > root->val && root->right==NULL) {
            TreeNode* temp= new TreeNode (val);
            root->right= temp;
            return;
        }
        if (val < root->val && root->left==NULL) {
            TreeNode* temp= new TreeNode (val);
            root->left= temp;
            return;
        }
        if (val< root->val && root->left != NULL) insertTreeNode(root->left, val);
        else insertTreeNode(root->right, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }

        insertTreeNode(root, val);
        return root;
    }
};