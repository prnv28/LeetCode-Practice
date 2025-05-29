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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        k = k%len;
        if(k==0) return head;
        head = reverse(head);
        temp = head;
        ListNode* prev = NULL;
        while(k--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        temp = reverse(temp);
        head = reverse(head);
        prev = head;
        while(prev->next!=NULL){
            prev = prev->next;
        }
        prev->next = temp;
        return head;
    }
};