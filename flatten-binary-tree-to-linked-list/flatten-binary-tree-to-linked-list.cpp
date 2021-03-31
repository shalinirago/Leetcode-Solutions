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
    void flatten(TreeNode* root) {
        if (root == nullptr){
            return;
        }   
        
        if (root->left != nullptr){
        TreeNode* rightmostinleft = root->left;
        while (rightmostinleft->right != nullptr){
            rightmostinleft=rightmostinleft->right;
        }
        rightmostinleft->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        }
        
        flatten(root->right);
    }
};


/*

preorder: root, left, right

        1                                                       1
       / \                          2           2       =>      \
      2   5                        / \  =>       \              2
    /    / \                      3   4           3              \
   3    4   6                                     \               3..                  
       / \                                           4  
      5   7
      
      
* given node: extract and store right subtree = temp
* if node not null:
    node->left->right = temp
    node->right = node->left
    node->left = nullptr
* recursively call both subtrees



*/