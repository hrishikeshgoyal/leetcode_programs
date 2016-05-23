

class BSTIterator {
    private:
        vector<int> v; 
        int pos;
    public:
        //Travse the Tree in-order and covert it to an array
        BSTIterator(TreeNode *root) {
            pos = 0;
            vector<TreeNode*> stack;
            while(stack.size()>0 || root !=NULL) {
                if (root){
                    stack.push_back(root);
                    root = root->left;
                }else{
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }

        int next() {
            return v[pos++];
        }
};
