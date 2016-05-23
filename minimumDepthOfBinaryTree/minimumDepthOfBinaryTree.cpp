

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }
        if (root->left==NULL && root->right==NULL){
            return 1;
        }
        int left=INT_MAX;
        if (root->left){
            left = minDepth(root->left) + 1 ;
        }
        int right=INT_MAX;
        if (root->right){
            right = minDepth(root->right) + 1;
        }
        
        return left<right ? left : right;
        
    }
};
