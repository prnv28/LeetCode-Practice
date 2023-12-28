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

        ListNode* prev = NULL;
        ListNode* curr = head;
    
        while(curr){
            ListNode* nxt = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};