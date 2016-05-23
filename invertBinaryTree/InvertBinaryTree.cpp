

class Solution {
public:

    TreeNode* invertTree_recursive(TreeNode* root) {
        if (root==NULL) return root;
        TreeNode* node = invertTree_recursive(root->left);
        root->left = invertTree_recursive(root->right);
        root->right = node;
        return root;
    }
    
    TreeNode* invertTree_non_recursive(TreeNode* root) {
        if (root==NULL) return root;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();
            swap(node->left, node->right);
            if (node->left) stack.push_back(node->left);
            if (node->right) stack.push_back(node->right);
        }
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (rand()%2){
            return invertTree_non_recursive(root);
        }
        return invertTree_recursive(root);    
    }
};

