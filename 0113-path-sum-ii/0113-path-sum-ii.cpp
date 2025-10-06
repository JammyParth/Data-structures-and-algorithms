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
    vector<vector<int>> ans;

    void solve(TreeNode* node, int targetSum ,int currSum, vector<int> level){
        
        //base cases
        if(!node){
            return;
        }
        level.push_back(node -> val);

        if(!node -> left && !node -> right){
            if(targetSum == currSum + node -> val){
                ans.push_back(level);
                return;
            }
        }
        solve(node -> left , targetSum , currSum + node -> val , level);
        solve(node -> right , targetSum , currSum + node -> val , level);

        level.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //backtracking.
        solve(root , targetSum , 0 , {});

        return ans;
    }
};