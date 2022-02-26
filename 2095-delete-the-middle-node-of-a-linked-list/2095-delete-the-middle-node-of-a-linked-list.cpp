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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast=head,*slow=head,*real=head;
        if (head == NULL) {
          return NULL;
       }
       if (head->next == NULL) {
          delete head;
          return NULL;
       }
        
        int count=0;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next; 
            count++;
        }
        for(int i=0;i<count-1;i++){
            real=real->next;
        }
        real->next=real->next->next;
        return head;
    }
};