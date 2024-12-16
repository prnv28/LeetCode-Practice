/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        while(node==nullptr || node->next==nullptr) return;
        node->val=node->next->val;
        ListNode* temp = node->next;
        node->next=node->next->next;
        delete temp;
    }
};