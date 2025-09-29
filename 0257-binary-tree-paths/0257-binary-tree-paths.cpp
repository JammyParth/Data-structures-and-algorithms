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
    

    void paths(vector<string> &ans ,string res, TreeNode* &node){
        
        if(!node){
            return;
        }

        if(!res.empty()){
            res += "->";
        }
        res += to_string(node -> val);


        //base case = leaf node
        if(!node -> left && !node -> right){
            ans.push_back(res);
            return;
            
        }

        if(node -> left) paths(ans, res, node -> left);
        if(node -> right) paths(ans, res , node -> right);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        paths(ans , "" , root);

        return ans;
        
    }
};