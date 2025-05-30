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
        if(!head) return head;
        ListNode* temp2 = head;
        ListNode* temp1 = head;
        while(n--){
            temp1 = temp1->next;
        }
        if(temp1==NULL) return head->next;

        
        while(temp1->next!=NULL){
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        ListNode* delNode = temp2->next;
        if(temp2->next!=NULL) temp2->next = temp2->next->next;
        delete delNode;
        return head;
    }
};