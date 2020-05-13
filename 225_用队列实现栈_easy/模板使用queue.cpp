class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //队列和栈是反的
        //eg. 队列：321  栈：123
        //所以压入的时候，将原本队列里的元素反过来就好了
        //eg.目前队列里是123，压入4为4123，应该变为1234
        int size = q.size();
        q.push(x);
        while(size--){
            int cur = q.front();
            q.pop();
            q.push(cur);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //队列里存放顺序和栈相同
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
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