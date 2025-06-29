/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxSum(TreeNode* node, int &sum){

        if(node == NULL) return 0;

        //now we'll check for left subtree and rightsubtree, and avoid taking negative values if theyare making our sum negative.

        int leftsum = max(maxSum(node -> left , sum) , 0);
        int rightsum = max(maxSum(node -> right , sum) , 0);

        sum = max(sum , leftsum + rightsum + node -> val);

        return max(leftsum , rightsum) + node -> val;
    }
    int maxPathSum(TreeNode* root) {

        // if(root == NULL) return root;
        int sum = INT_MIN;
        maxSum(root , sum);
        if(root -> val < 0 && root -> left == NULL && root -> right == NULL) return root -> val;
        return sum;
    }
};