/*
Problem Title: 155 - Min Stack
Lang: C++
Runtime: 40 ms
Memory: 14.6 MB
Problem Url: https://leetcode.com/problems/min-stack
Submission Url: https://leetcode.com/problems/min-stack/submissions/322707800
*/

class MinStack {
public:
    /** initialize your data structure here. */
    vector<long long> stack;
    int capacity, size;
    long long min;
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
        if(x < min){
            long long new_ele = x + (x - min);
            stack[size++] = new_ele;
            min = x;
        }
        else{
            stack[size++] = x;
        }
    }
    
    void pop() {
        if(stack[size-1] < min){
            min = 2LL*min - stack[size-1];
        }
        size--;
    }
    
    int top() {
        if(stack[size-1] < min){
            return (int)min;   
        }
        return (int)stack[size-1];
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