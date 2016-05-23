


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
                continue;
            }
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
                continue;
            }
            return root;
            
        }
        return NULL;
    }
};
