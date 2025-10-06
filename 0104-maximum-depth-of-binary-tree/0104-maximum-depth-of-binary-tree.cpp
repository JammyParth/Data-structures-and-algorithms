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
    int depth = 0;
    int maxdepth =  INT_MIN;


    void solve(TreeNode* node){

        if(!node){
            return;
        }

        depth++;
        if(!node -> left && !node -> right){
            maxdepth = max(depth , maxdepth);
            depth--;
            return;
        }

        solve(node -> left);
        solve(node -> right);

        depth--;
    }
    int maxDepth(TreeNode* root) {
        solve(root);
        return maxdepth == INT_MIN ? 0 : maxdepth;
    }
};