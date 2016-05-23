

class Solution {
public:
    int sumNumbers(TreeNode *root) {
    
        if (!root) return 0;
        
        int sum = 0;       
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0){
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left){
                node->left->val += (10*node->val); 
                v.push_back(node->left);
            }
            if (node->right){
                node->right->val += (10*node->val); 
                v.push_back(node->right);
            }
            if(!node->right && !node->left){
                sum += node->val;
            }
        }
        
        return sum;
    }
};
