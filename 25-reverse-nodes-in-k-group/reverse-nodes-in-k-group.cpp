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
    int lengthLL(ListNode* head){
        int length = 0;
        while(head){
            head = head->next;
            length++;
        }
        return length;
    }

    ListNode* algo(ListNode* head,int k, int length){
        if(!head) return NULL;
        if(length<k) return head;

        int count = 0;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        ListNode* cur = head;
        while(cur!=NULL && count<k){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            count++;
        }

        length -= k;
        if(nxt){
            head->next = algo(nxt,k,length);
        }
        return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = lengthLL(head);
        return algo(head,k,length);
    }
};