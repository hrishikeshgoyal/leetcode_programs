

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> v;
        generatePathSum(root, sum, v, result);
        return result;
    }
    
    void generatePathSum(TreeNode *root, int sum, vector<int> v, vector<vector<int> >& result) {
        
        if (root==NULL) {
            return;
        }
        
        if (root->left==NULL && root->right==NULL) {
            if (root->val == sum){
                v.push_back(root->val);
                result.push_back(v);
            }
            return;
        }
        
        v.push_back(root->val);
        
        if (root->left) {
            generatePathSum(root->left, sum - root->val, v, result);
        }
        
        if (root->right) {
            generatePathSum(root->right, sum - root->val, v, result);
        }
    }
};
