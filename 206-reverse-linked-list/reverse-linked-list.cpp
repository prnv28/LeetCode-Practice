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
    ListNode* reverseList(ListNode* head) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* nxt = head->next;
        nxt->next = head;
        head->next = NULL;
        return newHead;
        
    }
};