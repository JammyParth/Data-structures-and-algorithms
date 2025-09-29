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

    bool check(TreeNode* node){
        

        if(node == NULL){
            return true;
        }

        int lefth = 0;
        int righth = 0;

        TreeNode* leftn = node;

        while(leftn){
            lefth++;
            leftn = leftn -> left;
        }

        TreeNode* rightn = node;

        while(rightn){
            righth++;
            rightn = rightn -> right;
        }

        if(abs(righth - lefth) > 1){
            return false;
        }


        return check(node -> left) && check(node -> right);

    }

    bool isBalanced(TreeNode* root) {
       return check(root);
    }
};