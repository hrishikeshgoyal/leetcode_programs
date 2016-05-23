


class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (root==NULL) return false;
        if (root == p) {
            path.push_back(p);
            return true;
        }
        
        path.push_back(root);
        if (findPath(root->left, p, path)) return true;
        if (findPath(root->right, p, path)) return true;
        path.pop_back();
        
        return false;
    }

    //Ordinary way, find the path and comapre the path.
    TreeNode* lowestCommonAncestor01(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> path1, path2;
        
        if (!findPath(root, p, path1)) return NULL;
        if (!findPath(root, q, path2)) return NULL;
        
        int len = path1.size() < path2.size() ? path1.size() : path2.size();
        TreeNode* result = root;
        for(int i=0; i<len; i++) {
            if (path1[i] != path2[i]) {
                return result;
            }
            result = path1[i];
        }
        return result;
    }
    
    //Actually, we can do the recursive search in one time
    TreeNode* lowestCommonAncestor02(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //return if found or not found, return NULL if not found
        if (root==NULL || root == p || root == q) return root;
        
        //find the LCA in left tree
        TreeNode* left = lowestCommonAncestor02(root->left, p, q);
        //find the LCA in right tree
        TreeNode* right = lowestCommonAncestor02(root->right, p, q);
        
        //left==NULL means both `p` and `q` are not found in left tree.
        if (left==NULL) return right;
        //right==NULL means both `p` and `q` are not found in right tree.
        if (right==NULL) return left;
        // left!=NULL && right !=NULL, which means `p` & `q` are seperated in left and right tree.
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        srand(time(0));
        if (random()%2) {
            return lowestCommonAncestor02(root, p, q);
        }
        return lowestCommonAncestor01(root, p, q);
    }
};
