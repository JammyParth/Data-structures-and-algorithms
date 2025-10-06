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
    int mindepth = INT_MAX;

    void solve(TreeNode* node){
        if(!node){
            return;
        }
        depth++;
        if(!node -> left && !node -> right){
            mindepth = min(mindepth , depth);
            depth--;
            return;
        }

        solve(node -> left);
        solve(node -> right);

        depth--;

    }
    
    int minDepth(TreeNode* root) {
        solve(root);

        
        return mindepth == INT_MAX ? 0 : mindepth;
    }
};