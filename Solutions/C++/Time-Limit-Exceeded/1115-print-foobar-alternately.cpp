/*
Problem Title: 1115 - Print FooBar Alternately
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/print-foobar-alternately
Submission Url: https://leetcode.com/problems/print-foobar-alternately/submissions/485092621
*/

class FooBar {
private:
    int n;
    bool lock = false;
    bool lock2 = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            while(lock == true){
                // cout<<"a"<<endl;
            }
            
            while(lock == false){
            
        	    printFoo();
                lock = true;
            
            }
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            while(lock == false){
             // cout<<"b"<<endl;
            }
            
        	while(lock == true){
            
        	    printBar();
                lock = false;
            
            }
        }
    }
    
    
};