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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()){
            return nullptr;
        }
        
        int maxval = INT_MIN;
        int max_idx = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > maxval){
                maxval = nums[i];
                max_idx = i;
            }
        }
        
        vector<int> left_subtree;
        vector<int> right_subtree;
        
        for (int i = 0; i < nums.size(); i++){
            if (i < max_idx){
                left_subtree.push_back(nums[i]);
            }
            
            else if (i > max_idx){
                right_subtree.push_back(nums[i]);
            }
        }
        
        TreeNode* node = new TreeNode();
        node->val = maxval;
        
        node->left = constructMaximumBinaryTree(left_subtree);
        node->right = constructMaximumBinaryTree(right_subtree);
        
        return node;
    }
};


/*

nums = [3, 2, 1, 6, 0 5]

int maxval = int_min

* traverse the nums array to get max value, index_max:
* traverse till max index - save in left subtree array and post maxindex, save in right subtree array

left_tree = [3, 2, 1]
right_tree = [0, 5]

create root with root->val = maxval
root->left = constructMaximumBinaryTree(left_tree)
root->right = constructMaximumBinaryTree(right_tree)

return root

maxval = 3
left_tree = []                  left_tree = [0]
right_tree [ 2, 1]



*/