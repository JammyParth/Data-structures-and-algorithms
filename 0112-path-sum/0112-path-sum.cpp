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

    bool check(TreeNode* node , int targetSum, int currSum){

        if(!node){
            return false;
        }

        if(!node -> left && !node -> right){
            if(targetSum == currSum + node -> val){
                return true;
            }

            else{
                return false;
            }
        }
        return check(node -> left ,targetSum , currSum + node -> val) ||
        check(node -> right , targetSum , currSum + node -> val);
        
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root , targetSum, 0);
    }
};