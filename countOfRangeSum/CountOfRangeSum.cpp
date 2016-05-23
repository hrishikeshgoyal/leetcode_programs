



class Node{
    public:
        long long val;
        int cnt; //amount of the nodes
        Node *left, *right;
        Node(long long v):val(v), cnt(1), left(NULL), right(NULL) {}
};

class Tree{
    public:
        Tree():root(NULL){ }
        ~Tree() { freeTree(root); }
        
        void Insert(long long val) {
            Insert(root, val);
        }
        int LessThan(long long sum, int val) {
            return LessThan(root, sum, val, 0);
        }
        
    private:
        Node* root;
        
        //general binary search tree insert algorithm
        void Insert(Node* &root, long long val) {
            if (!root) {
                root = new Node(val);
                return;
            }
            
            root->cnt++;
            
            if (val < root->val ) {
                Insert(root->left, val);
            }else if (val > root->val) {
                Insert(root->right, val);
            }
        }
        //return how many of the sums less than `val`
        //  -  `sum` is the new sums which hasn't been inserted
        //  -  `val` is the `lower` or `upper+1`
        int LessThan(Node* root, long long sum, int val, int res) {
            
            if (!root) return res;

            if ( sum - root->val < val) {
                //if (sum[j, i] < val), which means all of the right branch must be less than `val` 
                //so we add the amounts of sums in right branch, and keep going the left branch.
                res += (root->cnt - (root->left ? root->left->cnt : 0) );
                return LessThan(root->left, sum, val, res);
            }else if ( sum - root->val > val) {
                //if (sum[j, i] > val), which means all of left brach must be greater than `val`
                //so we just keep going the right branch.
                return LessThan(root->right, sum, val, res);
            }else {
                //if (sum[j,i] == val), which means we find the correct place, 
                //so we just return the the amounts of right branch.]
                return res + (root->right ? root->right->cnt : 0);
            }
        }
        void freeTree(Node* root){
            if (!root) return;
            if (root->left) freeTree(root->left);
            if (root->right) freeTree(root->right);
            delete root;
        }
        
};



class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        Tree tree;
        tree.Insert(0);
        long long sum = 0;
        int res = 0;
        
        for (int n : nums) {
            sum += n;
            int lcnt = tree.LessThan(sum, lower);
            int hcnt = tree.LessThan(sum, upper + 1);
            res += (hcnt - lcnt);
            tree.Insert(sum);
        }

        return res;
    }
};
