/*
Problem Title: 491 - Non-decreasing Subsequences
Lang: C++
Runtime: 641 ms
Memory: 137.3 MB
Problem Url: https://leetcode.com/problems/non-decreasing-subsequences
Submission Url: https://leetcode.com/problems/non-decreasing-subsequences/submissions/881548848
*/

class Solution {
    struct VectorHash {
        std::size_t operator()(const std::vector<int>& vec) const {
            std::size_t seed = vec.size();
            for(auto& i : vec) {
                seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
public:
    bool isNonDecreasingSubsequence(vector<int> subseq) {
        if(subseq.size() <= 1){
            return false;
        }
        for(int i=1; i < subseq.size(); i++) {
            if(subseq[i-1] > subseq[i]){
                return false;
            }
        }
        return true;
    }

    unordered_set<vector<int>, VectorHash> getAllSubsequences(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> results;
        int mx = pow(2, nums.size());

        for(int i = 3; i < mx; i++){
            vector<int> subseq;
            for(int x = 0; x < nums.size(); x++) {
                if( ((i>>x)&1) > 0 ) {
                    subseq.push_back(nums[x]);
                }
            }
            if(isNonDecreasingSubsequence(subseq)) {
                results.insert(subseq);
            }
        }
        return results;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> results;

        results = getAllSubsequences(nums);

        vector<vector<int>> ans;
        for(auto result : results) {
            ans.push_back(result);
        }
        return ans;
    }
};