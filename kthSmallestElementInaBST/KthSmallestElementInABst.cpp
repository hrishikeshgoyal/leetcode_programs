


class Solution {
public:
    // in-order travel - recursive way
    int kthSmallestHelper_recursive(TreeNode* root, int& k) {
        if (root==NULL) return 0; //this behavior is undefined!
        
        //in-order travel
        int result = kthSmallestHelper_recursive(root->left, k);
        if (k==0) return result;
        
        k--;
        if (k==0) return root->val;
        
        
        return kthSmallestHelper_recursive(root->right, k);
    }
    // in-order travel - non-recursive way
    int kthSmallestHelper_nonRecursive(TreeNode* root, int k){
        stack<TreeNode*> s;
        
        while(!s.empty() || root){
            
            while (root) { 
                s.push(root);
                root = root->left;
            }
            
            k--;
            root = s.top()->right;

            if (k==0) return s.top()->val;
            
            s.pop();
        }
        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        //return kthSmallestHelper_nonRecursive(root, k);
        return kthSmallestHelper_recursive(root, k);
    }
};
