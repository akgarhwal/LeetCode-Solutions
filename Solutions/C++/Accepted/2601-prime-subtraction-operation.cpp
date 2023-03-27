/*
Problem Title: 2601 - Prime Subtraction Operation
Lang: C++
Runtime: 40 ms
Memory: 25.8 MB
Problem Url: https://leetcode.com/problems/prime-subtraction-operation
Submission Url: https://leetcode.com/problems/prime-subtraction-operation/submissions/922267226
*/

class Solution {
public:
    void seive_algo(vector<bool> &vec, int n) {
        vec[0] = vec[1] = false;
        for(int i=2; i*i<n; i++){
            for(int j=2*i; j<n; j+=i){
                vec[j] = false;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(1001, true);
        vector<int> prime;

        seive_algo(isPrime, 1001);

        for(int i=0; i<1001; i++) {
            if(isPrime[i]) {
                prime.push_back(i);
            }
        }
        
        int ans = 0;
        int prev = nums[n-1];

        for(int i=n-2; i>=0; i--){
            if(nums[i] < prev) {
                prev = nums[i]; 
                continue;
            }

            ans = 1;
            
            for(int sub=0; sub<prime.size() && prime[sub]<nums[i]; sub++) {
                if(nums[i]-prime[sub] < prev) {
                    prev = nums[i]-prime[sub];
                    ans = 0;
                    break;
                }
            }
            
            if(ans) {
                break;
            }

        }
        return !ans;
    }
};