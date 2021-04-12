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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr){
            return head;
        }
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* nextNode = dummy->next;
        
        while (nextNode != nullptr){
            if (nextNode->val == val){
                prev->next = nextNode->next;
                nextNode = nextNode->next;
            }
            else{
                nextNode = nextNode->next;
                prev = prev->next;
            }
        }
        
        return dummy->next;
    }
};