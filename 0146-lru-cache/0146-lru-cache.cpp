class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;

            node(int _key,int _val){
                key = _key;
                val = _val;
            }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    map<int,node*> mp;
    int capacity;

    LRUCache(int cap) {
        this->capacity = cap;
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    void addNode(node* newNode){
        node* newNext = this->head->next;
        newNode->next = newNext;
        newNode->prev = this->head;
        this->head->next = newNode;
        newNext->prev = newNode;
    }

    void deleteNode(node* delNode){
        node* delNext = delNode->next;
        node* delPrev = delNode->prev;
        delPrev->next = delNext;
        delNext->prev = delPrev; 
    }
    
    int get(int key_) {
        // cout<<"Get :: "<<this->mp.size()<<"\n";
        if(this->mp.find(key_)!=this->mp.end()){
            node* temp = this->mp[key_];
            int res = temp->val;
            this->mp.erase(key_);
            deleteNode(temp);
            addNode(temp);
            this->mp[key_] = this->head->next;
            return res;
        }
        return -1;
    }

    void prinDLL(){
        node* temp = this->head->next;
        while(temp!=this->tail){
            cout<<temp->key<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    void put(int key, int value) {
        if(this->mp.find(key)!=this->mp.end()){
            node* temp = this->mp[key];
            this->mp.erase(key);
            deleteNode(temp);
        }

        if(mp.size()==this->capacity){
            // cout<<"Put (Before) :: "<<this->mp.size()<<"\n";
            // prinDLL();
            this->mp.erase(this->tail->prev->key);
            deleteNode(this->tail->prev);
            // cout<<"Put (After) :: "<<this->mp.size()<<"\n";

        }

        addNode(new node(key,value));
        this->mp[key] = this->head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */