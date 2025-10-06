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

    string res = "";
    vector<string> ans;

    void solve(TreeNode* node){

        if(!node){
            return;
        }  

        res += char('a' + node -> val);

        //leaf node
        if(!node -> left && !node -> right){
            
            string temp = res;
            reverse(temp.begin()  , temp.end());
            ans.push_back(temp);
            res.pop_back();
            return;
        }

        solve(node -> left);
        solve(node -> right);

        res.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root);
        sort(ans.begin() , ans.end());

        return ans[0];
    }
};