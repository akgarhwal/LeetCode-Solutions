/*
Problem Title: 528 - Random Pick with Weight
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/random-pick-with-weight
Submission Url: https://leetcode.com/problems/random-pick-with-weight/submissions/349664183
*/

class Solution {
public:
    vector<int> count;
    vector<int> W;
    int index;
    int co = 0;
    int limit = 0;
    Solution(vector<int>& w) {
        count.resize(w.size());
        index = 0;
        W = w;
        for(int x : W){
            limit += x;
        }
    }
    
    int pickIndex() {
        
        int index = rand() % W.size();
        
        
        if(limit == co){
            for(int i =0 ; i<W.size();i++){
                count[i] = 0;
            }
            co=0;
        }
        
        while(count[index] == W[index]){
            index++;
            if(index >= W.size()){
                index = 0;
            }
        }
        count[index]++;
        co++;
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */