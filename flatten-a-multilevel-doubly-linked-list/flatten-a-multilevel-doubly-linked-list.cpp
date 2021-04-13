/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    
    3 2 1 4 3
               
    
    };
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr){
            return head;
        }
        Node* tail = head;
        
        Node* next1 = flatten(tail->child);
        Node* next2 = flatten(tail->next);
        
        if (next1){
            tail->next = next1;
            while (tail->next){
                tail->next->prev = tail;
                tail->child = nullptr;
                tail = tail->next;
            }
        }
        
        tail->next = next2;
        if (next2){
            next2->prev = tail;
        }
        
        return head;
       
    }
};



/*
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
             

* Node* curr = head, 
* traverse: 1---2---3 - (child != null?){ temp = curr->next}
            curr->next = curr->child; 1--2--3--7
-- recursive            traverse: 7--8- (child != null?) temp = curr->next
            curr->next = curr->child; 7--8--11..
            curr = 12; temp = 9. curr->next = temp; temp->prev = curr; traverse till null


*/