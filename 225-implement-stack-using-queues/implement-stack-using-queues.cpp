class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        while(n--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(!empty()){
            int val = q.front();
            q.pop();
            return val;
        } else{
            return -1;
        }
    }
    
    int top() {
        if(!empty())
            return q.front();
        else
            return -1;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */