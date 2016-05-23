



#define zeros(i) (i ^ (i - 1)) & i
class Solution {
public:
    vector <int> sorted, sol, fenwick;
    int n;
    int search(int t)
    {
        int step = 0;
        for(; (1 << step) <= n; step++);
        int i = 0;
        for(int k = step; k >= 0; k--)
            if(i + (1 << k) < n && sorted[i + (1 << k)] <= t)
                i += (1 << k);
        return i;
    }
    int compute(int t)
    {
        int s = 0;
        for(int i = t; i > 0; i -= zeros(i))
            s += fenwick[i];
        return s;
    }
    void add(int t)
    {
        for(int i = t; i <= n; i += zeros(i))
            fenwick[i]++;
    }
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size())
        {
            sorted = nums;
            n = nums.size();
            sort(sorted.begin(), sorted.end());
            vector <int> f(sorted.size());
            fenwick = f;
            for(int i = nums.size() - 1; i >= 0; i--)
            {
                int pos = search(nums[i]) + 1;
                sol.push_back(compute(pos - 1));
                add(pos);
            }
            reverse(sol.begin(), sol.end());
        }
        return sol;
    }
};




class BinarySearchTreeNode
{
    public:
        int val;     
        int less;      // count of members less than val
        int count;     // count of members equal val
        BinarySearchTreeNode *left, *right;
        BinarySearchTreeNode(int value) : val(value), less(0),count(1),left(NULL), right(NULL) {}
};

class BinarySearchTree
{
    private:
        BinarySearchTreeNode* root;
    public:
        BinarySearchTree(const int value):root(new BinarySearchTreeNode(value)){ }
        ~BinarySearchTree() {
            freeTree(root);
        }
        void insert(const int value, int &numLessThan) {
            insert(root, value, numLessThan);
        }
    private:
        void freeTree(BinarySearchTreeNode* root){
            if (root == NULL) return;
            if (root->left) freeTree(root->left);
            if (root->right) freeTree(root->right);
            delete root;
        }

        void insert(BinarySearchTreeNode* root, const int value, int &numLessThan) {

            if(value < root->val) {  // left
                root->less++;
                if(root->left == NULL) {
                    root->left = new BinarySearchTreeNode(value);
                }else{
                    this->insert(root->left, value, numLessThan);
                }
            } else if(value > root->val) { // right
                numLessThan += root->less + root->count;
                if(!root->right) {
                    root->right = new BinarySearchTreeNode(value);
                }else{
                    this->insert(root->right, value, numLessThan);
                }
            } else {
                numLessThan += root->less;
                root->count++;
                return;
            }
        }
};

class Solution {
    public:
        vector<int> countSmaller(vector<int>& nums) {
            vector<int> counts(nums.size());
            if(nums.size() == 0) return counts;

            BinarySearchTree tree(nums[nums.size()-1]);

            for(int i = nums.size() - 2; i >= 0; i--) {
                int numLessThan = 0;
                tree.insert( nums[i], numLessThan);
                counts[i] = numLessThan;
            }
            return counts; 
        }
};
