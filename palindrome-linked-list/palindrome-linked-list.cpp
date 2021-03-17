/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* front;
    
    bool isPalindrome(ListNode* head) {
        front = head;
        
        return check(head);
    }
    
    bool check(ListNode* head){
        
        if (head != nullptr){
            if (!check(head->next)){
                return false;
            }
            if (front->val != head->val){
                return false;
            }
            
            front = front->next;
        }
        
        return true;
    }
};