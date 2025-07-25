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

    TreeNode* search(TreeNode* node , int val){
        if(!node || node -> val == val){
            return node;
        }

        if(node -> val < val){
            return search(node -> right, val);
        }

        else{
            return search(node -> left , val);
        }

    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        return search(root , val);
    }
};