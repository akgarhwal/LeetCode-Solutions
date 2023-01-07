/*
Problem Title: 1381 - Design a Stack With Increment Operation
Lang: C++
Runtime: 40 ms
Memory: 19.2 MB
Problem Url: https://leetcode.com/problems/design-a-stack-with-increment-operation
Submission Url: https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/312520062
*/

class CustomStack {
public:
    vector<int> stack;
    int max_size = 0;
    CustomStack(int maxSize) {
        max_size = maxSize;
    }
    
    void push(int x) {
        if(stack.size() != max_size){
            stack.push_back(x);
        }
    }
    
    int pop() {
        if(stack.size() == 0){
            return -1;
        }
        int temp = stack[stack.size()-1];
        stack.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
     
        int mx = min((int)stack.size(), k);
        
        for(int i = 0; i < mx;i++){
            stack[i] += val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */