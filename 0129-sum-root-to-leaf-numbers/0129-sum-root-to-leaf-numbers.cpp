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
    int totalsum = 0;
    string num = "";

    void solve(TreeNode* node){
        if(!node){
            return;
        }

        num += to_string(node -> val);
        if(!node -> left && !node -> right){
            totalsum += stoi(num);
            num.pop_back();
            return;
        }

        solve(node -> left);
        solve(node -> right);

        num.pop_back();

    }
    int sumNumbers(TreeNode* root) {
        solve(root);
        return totalsum;
    }
};