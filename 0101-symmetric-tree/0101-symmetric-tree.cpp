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
    bool helper(TreeNode * leftsub, TreeNode* rightsub){
        if (leftsub==NULL && rightsub==NULL) return true;
        if (leftsub== NULL && rightsub!=NULL || leftsub!=NULL && rightsub== NULL) return false;

        if (leftsub->val != rightsub->val) return false;

        bool leftans= helper (leftsub->left, rightsub->left);
        if (leftans== false) return false;

        bool rightans= helper (leftsub->right, rightsub->right);
        if (rightans== false) return false;
        
        return true;
    }
    void inverse(TreeNode* root){
        if (root == NULL) return;
        TreeNode* temp= root->left;
        root->left= root->right;
        root->right=temp;
        inverse(root->left);
        inverse(root->right);
    }
    bool isSymmetric(TreeNode* root) {
        inverse (root->right);
        return helper(root->left, root->right); 
    }
};