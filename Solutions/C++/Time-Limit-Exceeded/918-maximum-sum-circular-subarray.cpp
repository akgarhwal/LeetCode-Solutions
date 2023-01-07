/*
Problem Title: 918 - Maximum Sum Circular Subarray
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximum-sum-circular-subarray
Submission Url: https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/339922530
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans = INT_MIN, last_zero = 0, cur_sum = 0;
        for(int i = 0; i<(2*A.size());i++){
            
            if(i - last_zero >= A.size()){
                cur_sum -= A[last_zero%(A.size())];
                last_zero++;
                int temp = cur_sum + A[i%(A.size())], ti = last_zero;
                while(ti < i){
                    temp -= A[ti%(A.size())];
                    ans = max(ans, temp);
                    ti++;
                }
            }
            cur_sum += A[i%(A.size())];
            ans = max(ans, cur_sum);
            if(cur_sum < 0){
                cur_sum = 0;
                last_zero = i+1;
            }
        }
        return ans;
    }
};