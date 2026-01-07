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
    long long prod = 1;
    long long maxprod = 1;
    long long sum = 0;
    long long totalsum = 0;
    int MOD = 1e9 + 7;

    long long getsum(TreeNode* root){
        if(!root) return 0;
        return root->val + getsum(root->left) + getsum(root->right);
    }


    long long helper(TreeNode* root){

        if(!root) return 0;

        long long left = helper(root->left);
        long long right = helper(root->right);

        long long subsum = root->val + left + right;
        maxprod = max(maxprod, subsum * (totalsum - subsum));

        return subsum;

    }
    int maxProduct(TreeNode* root) {

        if(!root){
            return 0;
        }
        totalsum = getsum(root);
        helper(root);

        return maxprod % MOD;
        
    }
};