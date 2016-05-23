


class Solution {
public:
    //return -1 if it is not.
    int isCompleteTree(TreeNode* root) {
        if (!root) return 0;

        int cnt = 1;
        TreeNode *left = root, *right = root;
        for(; left && right; left=left->left, right=right->right) {
            cnt *= 2;
        }
      
        if (left!=NULL || right!=NULL) {
            return -1;
        }
        return cnt-1;
    }

    int countNodes(TreeNode* root) {
        int cnt = isCompleteTree(root);
        if (cnt != -1) return cnt;
        int leftCnt = countNodes(root->left);
        int rightCnt = countNodes(root->right);
        return leftCnt + rightCnt + 1;
    }
};
