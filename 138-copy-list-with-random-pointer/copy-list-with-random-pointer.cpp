/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void printLL(Node* head){
        while(head){
            if(head->random){
                cout<<head->val<<", Random :"<<head->random->val<<endl;
            }else{
                cout<<head->val<<endl;
            }
            head = head->next;
        }
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        printLL(head);
        Node* tmp = head;
        while(tmp){
            Node* node = new Node(tmp->val);
            node->next = tmp->next;
            tmp->next = node;
            tmp = node->next;
        }
        // printLL(head);

        tmp = head;
        Node* ans = tmp->next;
        while(tmp){
            Node* node = tmp->next;
            Node* rndm = tmp->random;
            Node* nxt = node->next;

            if(rndm){
                node->random = rndm->next;
            }
            tmp = nxt;
        }

        tmp = head;
        while(tmp){
            Node* node = tmp->next;
            tmp->next = node->next;
            if(node->next){
                node->next = node->next->next;
            }
            tmp = tmp->next;
        }

        // printLL(head);
        // printLL(ans);
        return ans;

    }
};