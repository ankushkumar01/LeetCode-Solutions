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
    void insertTreeNode(TreeNode* root, int p){
        if (root==NULL) return;
        if (root->val < p){
            if (root->right== NULL) {
                root->right= new TreeNode(p);
                return;
            }
            insertTreeNode(root->right, p);
        }
        if (root->val > p){
            if (root->left == NULL) {
                root->left = new TreeNode(p);
                return;
            }
            insertTreeNode(root->left, p);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n= preorder.size();
        TreeNode* root;
        if (n==0) return NULL;
        else{
            root= new TreeNode(preorder[0]);
        }
        for (int i=1; i<n; i++){
            insertTreeNode(root, preorder[i]);
        }
        return root;
    }
};