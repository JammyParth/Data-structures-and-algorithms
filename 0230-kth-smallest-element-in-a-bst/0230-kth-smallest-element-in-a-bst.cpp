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

    int count = 0;
    int result = -1;

    void helper(TreeNode* node , int k){

        if(!node || count >= k){
            return;
        }
        if(node -> left) helper(node -> left , k);
        count++;
        if(count == k){
            result = node -> val;
            return; 
        }
        if(node -> right) helper(node -> right , k);

    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root , k);
        return result;
    }
};