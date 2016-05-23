

#include <iostream>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode *root, int& maxSum ) {

    if (NULL == root) return 0;

    //get the maxPathSum for both left and right branch
    int left  = maxPathSum(root->left,  maxSum);
    int right = maxPathSum(root->right, maxSum);

    // The max sum could be one of the following situations:
    //    1) root + left
    //    2) root + right
    //    3) root
    //    4) root + left + right   
    //
    // And the whole function need to return the the max of 1) 2) 3) 
    int val = root->val;
    int maxBranch = left > right ? max(left + val, val) : max(right + val, val);
    int m = max(left + right + val, maxBranch);

    maxSum = max(maxSum, m);

    return maxBranch;
}

int maxPathSum(TreeNode *root) {
    #define INT_MIN     (-2147483647 - 1)
    int maxSum = INT_MIN;
    maxPathSum(root, maxSum);
    return maxSum;
}

int main()
{
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    cout << maxPathSum(&root) << endl; 
    return 0;
}
