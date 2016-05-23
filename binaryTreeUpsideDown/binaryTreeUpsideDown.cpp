


class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        //using a dummy node to help to store the new tree      
        TreeNode dummy(0);
        TreeNode *head =  &dummy, *left=NULL, *right=NULL;

        while ( root!=NULL ) {
            //find the right & left
            left = root->right;
            right = root;
            
            //move root the next
            root = root->left;
            
            //replace the right with current root
            right->left = head->left;
            right->right = head->right;
            
            //move the dummy to the root
            dummy.right = right;
            dummy.left = left;
            
            //reset the head to the root
            head = &dummy;
    
        }
        
        return head->right;
    }
};
