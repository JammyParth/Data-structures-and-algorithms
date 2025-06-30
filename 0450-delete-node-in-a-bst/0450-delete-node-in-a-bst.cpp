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
    
    TreeNode* rightmostchild(TreeNode* node){
        if(node -> right == NULL){
            return node;
        }

        while(node -> right){
            node = node -> right;
        }
        return node;
    }

    TreeNode* helper(TreeNode* node){
        if(node -> left == NULL){
            return node -> right;
        }

        if(node -> right == NULL){
            return node -> left;
        }

        //3rd condition
        else{
            TreeNode* rightchild = rightmostchild(node -> left);
            rightchild -> right = node -> right;
            return node -> left;
        }

        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //1st condition
        if(!root) return NULL;

        TreeNode* dummy = root;
        //2nd condition
        if(root -> val == key){
            return helper(root);
        }
        

        while(root != NULL){
        //3rd condition
        if(root -> val > key){

        if(root -> left != NULL && root -> left -> val == key){
            root -> left = helper(root -> left);
            break;
        }
        else{
            root = root -> left;
        } 
        }

        else{
        //4th condition
        if(root -> right != NULL && root -> right -> val == key){
            root -> right = helper(root -> right);
            break;
        }
        else{
            root = root -> right;
        }
        }
        }

    return dummy;
    }
};