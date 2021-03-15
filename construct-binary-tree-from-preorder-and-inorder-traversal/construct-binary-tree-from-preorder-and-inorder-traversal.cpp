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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return findNodes(preorder, inorder);
    }
    
    TreeNode* findNodes(vector<int>& preorder, vector<int>& inorder){
        if (preorder.empty())
            return nullptr;
        
        
        TreeNode* node = new TreeNode();
        node->val = preorder[0];
        
        
        vector<int> pre_nodes;
        vector<int> in_nodes;
        int root_idx = 0;
        
        for (int i = 0; i < inorder.size(); i++){
            if (inorder[i] != node->val){
                in_nodes.push_back(inorder[i]);
            }
            else{
                root_idx = i;
                break;
            }
        }
        
        for (int i = 1; i <= in_nodes.size(); i++){
            pre_nodes.push_back(preorder[i]);
        }
        
        node->left = findNodes(pre_nodes, in_nodes);
        in_nodes.clear();
        pre_nodes.clear();
        
        for (int i = root_idx+1; i < inorder.size(); i++){
            in_nodes.push_back(inorder[i]);
        }
        
        for (int i = root_idx+1; i < preorder.size(); i++){
            pre_nodes.push_back(preorder[i]);
        }
        node->right = findNodes(pre_nodes, in_nodes);
        
        return node;
    }
    
    
};