/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.
*/
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
private:
    void helper(vector<int>& nodes , TreeNode* root){
        if(root == NULL){
            return ;
        }
        nodes.push_back(root->val);
        helper(nodes , root->left) ;
        helper(nodes , root->right) ;
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans ;
      helper(ans , root) ;
      return ans ;
    }
};