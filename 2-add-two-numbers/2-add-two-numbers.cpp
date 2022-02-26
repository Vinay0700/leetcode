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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode *ans= new ListNode();
        ListNode *dummy=ans;
        ListNode *d1=l1;
        ListNode *d2=l2;
        while(d1 || d2 ||carry==1){
            int sum=0;
            if(d1){
                sum+=d1->val;
                d1=d1->next;
            }
            if(d2){
                sum+=d2->val;
                d2=d2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            ListNode *node= new ListNode(sum%10);
            dummy->next=node;
            dummy=dummy->next;
            
        }
        return ans->next;
        
        
    }
};