/*
Problem Title: 1354 - Construct Target Array With Multiple Sums
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/construct-target-array-with-multiple-sums
Submission Url: https://leetcode.com/problems/construct-target-array-with-multiple-sums/submissions/305701998
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
            
            int new_ele = top - (total - top);

            if(total-top > 1){
                new_ele = top % (total-top);
            }
            else if (total-top == 1) {
                new_ele = 1;
            }
            
            if(new_ele >= top) {
                break;
            }
            
            cout<<new_ele<<" -> ";
            
            pop_heap(target.begin(), target.end());
            target.pop_back();
            
            target.push_back(new_ele);
            push_heap(target.begin(), target.end());
            
            total = accumulate(target.begin(), target.end(), 0LL);      
            top = target.front();
        }
        
        cout<<top<<" -- "<<endl; 
        
        bool ans = true;
        
        for(auto ele : target){
            cout<<ele<<", ";
            ans = ans & ((ele != 1) ? false : true);
        }
        return ans;
    }
};