/*
Problem Title: 795 - Number of Subarrays with Bounded Maximum
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum
Submission Url: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/submissions/509275716
*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=0,sc=0,ans = 0;
        queue<int> q;
        for(int x : nums){
            
            if(x < left){
                sc++;
            }
            else if(x > right){
                q.push(sc);
                if(n > 0 ){
                    n+=sc;
                    ans += (n*(n+1))>>1;
                    while(!q.empty()){
                        int f = q.front();
                        q.pop();
                        ans -= (f*(f+1))>>1;
                    }
                }
                n=0;
                sc=0;
            }
            else{
                n+=sc;
                n+=1;
                q.push(sc);
                sc = 0;
            }
        }
        q.push(sc);
        if(n > 0 ){
            n+=sc;
            ans += (n*(n+1))>>1;
            while(!q.empty()){
                int f = q.front();
                q.pop();
                ans -= (f*(f+1))>>1;
            }
        }
        return ans;
    }
};