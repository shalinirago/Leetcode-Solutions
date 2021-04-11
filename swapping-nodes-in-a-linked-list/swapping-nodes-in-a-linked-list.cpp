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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* first_k = dummy;
        ListNode* ptr = dummy;
        
        for (int i = 1; i <= k; i++){
            first_k = first_k->next;
        }
        ptr = first_k->next;
        ListNode* second_k = dummy;
        
        while (ptr != nullptr){
            ptr = ptr->next;
            second_k = second_k->next;
        }
        second_k = second_k->next;
        
        int temp = first_k->val;
        first_k->val = second_k->val;
        second_k->val = temp;
        
        return dummy->next;
        
    }
};