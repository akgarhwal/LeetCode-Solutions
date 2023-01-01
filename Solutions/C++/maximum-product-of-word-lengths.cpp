/* Question: Maximum Product of Word Lengths
 * Lang: cpp
 * Runtime: 348 ms
 * Memory: 20.8 MB
 * Question Url: https://leetcode.com/problems/maximum-product-of-word-lengths
 * Submission Url:
 * https://leetcode.com/problems/maximum-product-of-word-lengths/submissions/498918933
 */

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            vector<int> arr(26, 0);
            for(char ca : words[i]){
                arr[ca-'a'] = 1;
            }
            for(int j = i+1; j < words.size(); j++){
                
                bool is_diff = true;
                
                for(char cb : words[j]){
                    if(arr[cb-'a'] == 1){
                        is_diff = false;
                    }
                }
                
                if(is_diff){
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }
};
