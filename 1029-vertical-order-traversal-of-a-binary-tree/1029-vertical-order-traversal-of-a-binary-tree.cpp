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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        map<int , map<int , multiset<int>>> mp; //matrix for row and col. 

        queue<pair<TreeNode* , pair<int , int>>> q; //{Node , {col , row}}

        q.push({root , {0 , 0}});

        while(!q.empty()){

            auto it  = q.front();
            q.pop();

            TreeNode* node = it.first;
            int row = it.second.second;
            int col = it.second.first;

            mp[col][row].insert(node -> val);

            if(node -> left){
                q.push({node -> left , {col - 1 , row + 1}});
            }

            if(node -> right){
                q.push({node -> right , {col + 1, row + 1}});
            }

        }



        for(auto col : mp){

            vector<int> temp;
            for(auto row : col.second){
                temp.insert(temp.end() , row.second.begin() , row.second.end());
            }

            ans.push_back(temp);
        }

        return ans;

    }
};