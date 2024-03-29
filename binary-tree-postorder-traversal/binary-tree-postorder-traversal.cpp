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
   
    vector<int> postorderTraversal(TreeNode* root) {
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
            
            if (node->left){
                st.push(node->left);
            }
            
            if (node->right){
                st.push(node->right);
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};