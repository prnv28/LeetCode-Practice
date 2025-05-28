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
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(l1!=NULL || l2!=NULL){
            int n1 = 0;
            int n2 = 0;
            if(l1!=NULL){
                n1 = l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                n2 = l2->val;
                l2 = l2->next;
            }
            int sum = (n1+n2+carry)%10;
            carry = (n1+n2+carry) / 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if(carry>0){
            curr->next = new ListNode(carry);
        }
        return head->next;
    }
};