/*
Problem Title: 1354 - Construct Target Array With Multiple Sums
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/construct-target-array-with-multiple-sums
Submission Url: https://leetcode.com/problems/construct-target-array-with-multiple-sums/submissions/305700353
*/

class Solution {
public:
    bool isPossible(vector<int>& target) {
     
        
        make_heap(target.begin(), target.end());
        
        long long total = accumulate(target.begin(), target.end(), 0);
        
        int top = target.front();
        while (top > 1) {
            
            if(total-top > top){
                break;
            }
            
            int new_ele = top % (total - top);
            
            pop_heap(target.begin(), target.end());
            
            target.pop_back();
            
            target.push_back(new_ele);
            
            total = accumulate(target.begin(), target.end(), 0);
      
            push_heap(target.begin(), target.end());
            top = target.front();
        }
        
        bool ans = true;
        
        for(auto ele : target){
            ans = (ele != 1) ? false : ans;
            if(ans == false){
                break;
            }
        }
        return ans;
    }
};