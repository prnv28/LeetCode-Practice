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

        if(head==NULL) return head;
        if(head->next==NULL){
            if(n==0) return head;
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tmp = NULL;
        while(n--){
            tmp = fast;
            fast = fast->next;
        }
        
        if(fast==NULL){
            return head->next;
        }

        while(fast!= NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;

    }
};