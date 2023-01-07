/*
Problem Title: 1356 - Sort Integers by The Number of 1 Bits
Lang: C++
Runtime: 20 ms
Memory: 10.2 MB
Problem Url: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
Submission Url: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/submissions/305744580
*/

bool cmp(pair<int,int> f, pair<int,int> s){
    
    if(f.first != s.first){
        return f.first < s.first;
    }
    return f.second < s.second;
}
class Solution {
public:
    
    int countOfSetBits(int num){
        int ans = 0;
        while(num > 0){
            ans ++;
            num = num & (num-1);
        }
        return ans;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int,int>> new_arr;
        
        for(auto ele : arr){
            
            new_arr.push_back({countOfSetBits(ele), ele});
            
        }
        
        sort(new_arr.begin(), new_arr.end(), cmp);
        
        vector<int> res;
        
        for(auto pi : new_arr){
            
            res.push_back(pi.second);
        }
        return res;
    }
};