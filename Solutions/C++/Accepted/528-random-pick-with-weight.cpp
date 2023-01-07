/*
Problem Title: 528 - Random Pick with Weight
Lang: C++
Runtime: 176 ms
Memory: 40.5 MB
Problem Url: https://leetcode.com/problems/random-pick-with-weight
Submission Url: https://leetcode.com/problems/random-pick-with-weight/submissions/349667839
*/

class Solution {
public:
    vector<int> count;
    Solution(vector<int>& w) {
        count.resize(w.size());
        for(int i=0;i<w.size();i++){
            if(i!=0){
                count[i] = count[i-1] + w[i];
            }
            else{
                count[i] = w[i];
            }
        }
    }
    
    int pickIndex() {
        int index = rand() % count[count.size() - 1];
        int ans = upper_bound(count.begin(), count.end(), index) - count.begin();
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */