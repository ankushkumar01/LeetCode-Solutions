/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool findTreeNode(TreeNode* root, TreeNode* p){
        if (root== NULL) return false;
        if (p->val == root->val) return true;
        return (p->val < root->val)? findTreeNode (root->left, p): findTreeNode (root->right, p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp=NULL;
        if (root==NULL) return temp;
        if (root->val == p->val || root->val == q->val) {
            temp=root;
            return temp;
        }
        if (root->val >p->val && root->val < q->val || root->val >q->val && root->val < p->val){
            if (findTreeNode(root->left, p) && findTreeNode(root->right, q) || findTreeNode(root->left, q) && findTreeNode(root->right, p)){
                temp= root;
            }
        }
        else{
            if (findTreeNode(root->left, p) && findTreeNode(root->left, q)){
                return lowestCommonAncestor(root->left, p, q);
            }
            if (findTreeNode(root->right, p) && findTreeNode(root->right, q)){
                return lowestCommonAncestor(root->right, p, q);
            }
        }
        return temp;
    }
};