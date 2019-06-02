/*
Given a binary tree, determine if it is a valid binary search tree (BST).

--------------------------------
Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
--------------------------------
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
private:
    bool isValidBST(TreeNode* root, TreeNode* left, TreeNode* right) {
        if(root == nullptr) return true;
        if(left && root->val <= left->val) return false;
        if(right && root->val >= right->val) return false;
        
        return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
    }
    
};
