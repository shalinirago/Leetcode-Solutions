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
   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        
        if (root == nullptr)
            return result;
        
        TreeNode* node = root;
        st.push(node);
        
        while (!st.empty()){
            node = st.top();
            st.pop();
            result.push_back(node->val);
            
            if (node->right){
                st.push(node->right);
            }
            
            if (node->left){
                st.push(node->left);
            }
        }
        return result;
    }
    
    /*void traverse(TreeNode* root, vector<int>& result) 
    {
        if (root != NULL)
        {
            result.push_back(root->val);
            traverse(root->left, result);
            traverse(root->right, result);
            
        }
    }
    stack  = 1      result = 1, 2
             2
             3
                
    
    
    
    
    */
        
   
    
};