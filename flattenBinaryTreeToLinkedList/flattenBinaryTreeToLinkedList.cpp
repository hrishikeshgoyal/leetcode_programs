

class Solution {
public:
    void flatten(TreeNode *root) {
        
        vector<TreeNode*> v, stack;
        stack.push_back(root);
        while(stack.size()>0){
            TreeNode* node = stack.back();
            stack.pop_back();
            v.push_back(node);
            
            if (node && node->right){
                stack.push_back(node->right);
            }
            if (node && node->left){
                stack.push_back(node->left);
            }
        }
        
        v.push_back(NULL);
        for(int i=0; i<v.size(); i++){
            if (v[i]){
                v[i]->left = NULL;
                v[i]->right = v[i+1];
            }
        }
        
    }
};
