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
        int length = 1;
        ListNode* tmp = head;
        while(tmp->next!=NULL){
            length++;
            tmp = tmp->next;
        }

        k = k%length;
        tmp->next = head;
        ListNode* prev = NULL;
        int i=0;
        while(i<length-k){
            i++;
            prev = head;
            head = head->next;
        }

        prev->next = NULL;
        return head;
    }
};