/*
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
 
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
    pair<int,int> p ;

    void getAvg(TreeNode* root){
     if(root == NULL){
         return ;
     }
     p.first += root->val ;
     p.second++ ;
     getAvg(root->left);
     getAvg(root->right);
    }



public:
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL){
            return 0 ;
        }
        p.first = 0 ;
        p.second = 0 ;
        getAvg(root); 
        int count = (root->val == (p.first/p.second)) ;
       
        return count + averageOfSubtree(root->left) + averageOfSubtree(root->right) ;
    }
};