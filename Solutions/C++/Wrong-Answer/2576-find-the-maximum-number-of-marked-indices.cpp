/*
Problem Title: 2576 - Find the Maximum Number of Marked Indices
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices
Submission Url: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/submissions/905081080
*/

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int ans = 0;
        multiset<int> st;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        
        for(int i=0; i < nums.size(); i++) {
            
            int num = nums[i] * 2;
            
            auto it = st.lower_bound(num);
            
            if (it != st.end()) {
                ans += 2;
                st.erase(it);
                auto it2 = st.find(nums[i]);
                if(it2 != st.end()) {
                    st.erase(it2);
                }
            }
        }
        
        return ans;
    }
};