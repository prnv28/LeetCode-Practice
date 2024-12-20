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
    bool hasCycle(ListNode *head) {
       // Initialize a pointer 'temp'
    // at the head of the linked list
    ListNode* temp = head;  
    
    // Create a map to keep track of
    // encountered nodes
    std::unordered_map<ListNode*, int> nodeMap;  

    // Step 2: Traverse the linked list
    while (temp != nullptr) {
        // If the node is already in the
        // map, there is a loop
        if (nodeMap.find(temp) != nodeMap.end()) {
            return true;
        }
        // Store the current node
        // in the map
        nodeMap[temp] = 1;
        
        // Move to the next node
        temp = temp->next;  
    }

    // Step 3: If the list is successfully traversed 
    // without a loop, return false
    return false;
    }
};