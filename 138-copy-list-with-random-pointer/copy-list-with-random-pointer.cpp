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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* tmp = head;
        while(tmp){
            Node* node = new Node(tmp->val);
            mp[tmp] = node;
            tmp = tmp->next;
        }

        tmp = head;
        while(tmp){
            Node* node = mp[tmp];
            Node* nxt = tmp->next;
            Node* rndm = tmp->random;
            node->next = mp[nxt];
            node->random = mp[rndm];
            tmp = tmp->next;
        }

        return mp[head];


    }
};