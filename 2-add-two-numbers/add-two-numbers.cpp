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
        ListNode* head = l2;
        ListNode* l1_prev= NULL;
        ListNode* l2_prev = NULL;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            int rem = sum%10;
            l2->val = rem;
            l1_prev = l1;
            l2_prev = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l2==NULL){
            while(l1){
                int sum = l1->val + carry;
                carry = sum/10;
                int rem = sum%10;
                l2_prev->next = new ListNode(rem);
                l1 = l1->next;
                l2_prev = l2_prev->next;
            }
        }
        if(l1==NULL){
            while(l2){
                int sum = l2->val + carry;
                carry = sum/10;
                int rem = sum%10;
                l2->val = rem;
                l2_prev = l2;
                l2 = l2->next;
            }
        }
        if(carry>0){
            l2_prev->next=new ListNode(carry);
        }
        return head;
    }
};