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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = new ListNode();
        root->next = head;
        ListNode* p1 = root;
        ListNode* p2 = root;
        
        for (int i = 1; i <= n+1; i++){
            p2 = p2->next;
        }
        
        while (p2 != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p1->next = p1->next->next;
        
        return root->next;
    }
};