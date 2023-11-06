class LRUCache {
public:
    // declaring our data structures
    class Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node (int key, int val) {
            this->key = key;
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    unordered_map <int, Node*> map;
    int cap;
    int currSize = 0;

// functions 
    LRUCache(int capacity) {
        cap = capacity;
    }

    void pushToEnd (Node *node) {
        if (node == tail) return;
        if (node == head) {
            head = node->next;
        }
        else {
            node->prev->next = node->next;
        }
        node->next->prev = node->prev;
        node->next = nullptr;
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void deleteLRUnode () {
        Node *temp = head->next;
        map.erase(head->key);
        delete head;
        if (!temp) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = temp;
        }
        currSize--;
        return;
    }

    void addToEnd (Node *node) {
        map[node->key] = node;
        if (!tail) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        currSize++;
    }


// main functions to be implemented
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node *curr = map[key];
        pushToEnd (curr);

        return curr->val;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node *curr = map[key];
            curr->val = value;
            pushToEnd(curr);
        }
        else {
            Node *newnode = new Node (key, value);
            if (currSize == cap) {
                deleteLRUnode();
            }
            addToEnd(newnode);
        }
    }
};