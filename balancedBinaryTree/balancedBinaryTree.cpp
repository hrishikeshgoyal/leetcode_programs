

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int height=0;
        return isBalancedUtil(root, height);
    }

    bool isBalancedUtil(TreeNode* root, int& height){
       if(root==NULL){
          height=0;
          return true;
       }
       int lh=0, rh=0;
       bool isLeft = isBalancedUtil(root->left, lh);
       bool isRight = isBalancedUtil(root->right, rh);
       height = (lh > rh ? lh : rh) + 1;
       return (abs(lh-rh)<=1 && isLeft && isRight);
    }

};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root==NULL) return true;
        
        int left = treeDepth(root->left); 
        int right = treeDepth(root->right);
        
        if (left-right>1 || left-right < -1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int treeDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }

        int left=1, right=1;
        
        left += treeDepth(root->left);
        right += treeDepth(root->right);
        
        return left>right?left:right;
    }

};
