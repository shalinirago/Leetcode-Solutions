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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        height(root, ans);
        
        return ans;
        
    }
    
    
    int height(TreeNode* root, bool& ans)
    {
        if (root == NULL)
        {
            return 0;
        }
        
        int leftDepth = height(root->left, ans);
        int rightDepth = height(root->right, ans);
        
        if (abs(leftDepth - rightDepth) > 1)
        {
            ans = false;
            return -1;
        }
        
        return max(leftDepth, rightDepth) + 1;
    }

};