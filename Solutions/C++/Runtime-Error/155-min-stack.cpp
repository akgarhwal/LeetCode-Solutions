/*
Problem Title: 155 - Min Stack
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/min-stack
Submission Url: https://leetcode.com/problems/min-stack/submissions/322703575
*/

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    int capacity, size, min;
    MinStack() {
        
        min = INT_MAX;
        size = 0;
        capacity = 1;
        stack.resize(capacity);
    }
    
    void push(int x) {
        if(size == capacity){
            capacity *= 2;
            stack.resize(capacity);
        }
        if(x <= min){
            int new_ele = (min == INT_MAX) ? x : x + (x - min);
            stack[size++] = new_ele;
            min = x;
        }
        else{
            stack[size++] = x;
        }
    }
    
    void pop() {
        if(top() <= min){
            min = 2*min - top();
        }
        size--;
    }
    
    int top() {
        return stack[size-1];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */