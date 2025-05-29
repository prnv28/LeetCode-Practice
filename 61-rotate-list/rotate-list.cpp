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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* tmp = head;
        int length = 1;
        while(tmp->next!=NULL){
            length++;
            tmp = tmp->next;
        }
        tmp->next = head;
        k = k%length;
        int end = length - k;
        while(end--){
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};