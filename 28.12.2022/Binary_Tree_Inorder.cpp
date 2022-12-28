/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
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
    private: vector<int> ans ;
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
            return ans;
        vector<int> ans1 = inorderTraversal(root->left) ;
        // cout<<root->val<<endl ;
        ans.push_back(root->val) ;
       vector<int> ans2 = inorderTraversal(root->right) ;
        return ans ;
    }
};