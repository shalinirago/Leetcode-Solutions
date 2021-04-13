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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned int>> q;
        unsigned int left = 0, right = 0, result = 0;

        q.push({root, 0});
        while (!q.empty()){
            left = q.front().second;
            
            int q_len = q.size();
            for (int i = 0; i < q_len; i++){
                pair<TreeNode*, unsigned int> out = q.front();
                q.pop();
                right = out.second;
                
                if (out.first->left){
                    q.push({out.first->left, (2*right)});
                }
                if (out.first->right){
                    q.push({out.first->right, (2*right)+1});
                }
            }
            
            result = max(result, right-left+1);
        }
        
        return result;
    }
};


/*

width of a level = length between end nodes - rightmost and leftmost non null nodes

          1
         / \
        3   2
       /\  / \  
      5  n n  9                 q: 5,null,null,9
     / \     /  \
    6  n    n    7                             



*/