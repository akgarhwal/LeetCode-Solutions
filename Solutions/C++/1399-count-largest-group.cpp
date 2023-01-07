/*
Problem Title: 1399 - Count Largest Group
Lang: C++
Runtime: 12 ms
Memory: 6.4 MB
Problem Url: https://leetcode.com/problems/count-largest-group
Submission Url: https://leetcode.com/problems/count-largest-group/submissions/322992180
*/

class Solution {
public:
    int sumOfDigit(int n){
        int sum = 0;
        while(n){
            sum += (n%10);
            n = n/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        
        for(int i = 1; i <= n; i++){
            int sum = sumOfDigit(i);
            if(mp.count(sum) > 0){
                mp[sum] += 1;
            }
            else{
                mp[sum] = 1;
            }
        }
        int ans = 0, mx = INT_MIN;
        for(auto pi : mp){
            if(pi.second > mx){
                mx = pi.second;
                ans = 0;
            }
            if(pi.second == mx){
                ans += 1;
            }
        }
        return ans;
    }
};