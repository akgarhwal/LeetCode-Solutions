/*
Problem Title: 2526 - Find Consecutive Integers from a Data Stream
Lang: C++
Runtime: 288 ms
Memory: 122.6 MB
Problem Url: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream
Submission Url: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/submissions/873698740
*/

class DataStream {
public:
    int count = 0;
    int value = 0, k = 0;
    DataStream(int val, int K) {
        value = val;
        k = K;
        count = 0;
    }
    
    bool consec(int num) {
        if(num == value){
            count++;
        } else {
            count = 0;
        }
        if(count >= k) {
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */