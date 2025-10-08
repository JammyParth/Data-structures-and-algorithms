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

    void traversal(TreeNode* node, vector<TreeNode*> &order){

        if(!node){
            return;
        }
        order.push_back(node);
        traversal(node->left, order);
        traversal(node->right, order);

    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> order;

        traversal(root , order);

        int n = order.size();

        
        for(int i = 0; i < n - 1; i++){
            order[i] -> left = NULL;
            order[i] -> right = order[i + 1];
        }
        // curr -> left = NULL;
        // curr -> right = NULL;
    }
};