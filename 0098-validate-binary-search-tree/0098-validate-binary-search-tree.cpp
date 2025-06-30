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

    void solve(TreeNode* node , vector<int> &res){
        if(node -> left) solve(node -> left , res);
        res.push_back(node -> val);
        if(node -> right) solve(node -> right , res);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return false;
        vector<int> res;
        solve(root , res);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
        
    }
};