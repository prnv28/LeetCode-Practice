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
    ListNode* reverseList(ListNode* head){
        if(!head) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;

    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* tmp = head;
        int n = 0;
        while(tmp){
            n++;
            tmp = tmp->next;
        }
        k = k%n;
        if(k==0) return head;

        ListNode* rvr = reverseList(head);
        tmp = rvr;
        ListNode* prev = NULL;
        while(k--){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = NULL;
        ListNode* post = reverseList(tmp);
        ListNode* pre = reverseList(rvr);
        
        tmp = pre;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = post;
        return pre;
        return pre;
    }
};