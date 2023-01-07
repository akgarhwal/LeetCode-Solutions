/*
Problem Title: 1338 - Reduce Array Size to The Half
Lang: C++
Runtime: 356 ms
Memory: 78.4 MB
Problem Url: https://leetcode.com/problems/reduce-array-size-to-the-half
Submission Url: https://leetcode.com/problems/reduce-array-size-to-the-half/submissions/776512817
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        
        for(int x : arr){
            mp[x]++;
        }
        
        vector<int> vec;
        for(auto pi : mp){
            vec.push_back(pi.second);
        }
        sort(vec.begin(), vec.end());
        int ans = 0, N = arr.size(), count = 0;
        for(int i = vec.size()-1; i>=0; i--){
            count += vec[i];
            ans++;
            if(count >= N/2){
                return ans;
            }
        }
        return ans;
    }
};