

class Solution {
public:
    void rightSideViewHelper(TreeNode* root, int level, vector<int>& result) {
        if (root == NULL) return;
        if ( result.size() < level ) result.push_back(root->val);
        rightSideViewHelper(root->right, level+1, result);
        rightSideViewHelper(root->left, level+1, result);
    }
    
    void rightSideViewHelper(TreeNode* root, vector<int>& result) {
        if (root==NULL) return;

        vector<TreeNode*> stack;
        vector<int> level;
        stack.push_back(root);
        level.push_back(1);
        
        while (stack.size()>0) {
            TreeNode* r = stack.back(); stack.pop_back();
            int l = level.back(); level.pop_back();
            if ( result.size() < l ) {
                result.push_back(r->val);
            }
            if (r->left) {
                stack.push_back(r->left);
                level.push_back(l+1);
            }
            if (r->right) {
                stack.push_back(r->right);
                level.push_back(l+1);
            }
        }
    }
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (rand()%2){
            rightSideViewHelper(root, 1, result);
        }else{
            rightSideViewHelper(root, result);
        }
        return result;
    }
};
