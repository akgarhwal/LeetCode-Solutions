/*
Problem Title: 1426 - Counting Elements
Lang: C++
Runtime: 4 ms
Memory: 6.9 MB
Problem Url: https://leetcode.com/problems/counting-elements
Submission Url: https://leetcode.com/problems/counting-elements/submissions/321077753
*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int num : arr){
            if(mp.count(num) > 0){
                mp[num] += 1;
            }
            else{
                mp[num] = 1;
            }
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int num: arr){
            if(mp.count(num+1) > 0){
                ans += mp[num];
                mp[num] = 0;
            }
            
        }
        return ans;
    }
};