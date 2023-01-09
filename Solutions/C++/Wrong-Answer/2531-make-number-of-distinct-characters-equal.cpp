/*
Problem Title: 2531 - Make Number of Distinct Characters Equal
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/make-number-of-distinct-characters-equal
Submission Url: https://leetcode.com/problems/make-number-of-distinct-characters-equal/submissions/873801434
*/

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> freq1(26, 0), freq2(26, 0);
        
        for(char ch : word1){
            freq1[ch-'a']++;
        }
        for(char ch : word2){
            freq2[ch-'a']++;
        }
        
        for(int i=0; i < 26; i++) {
            for(int j = 0; j <26; j++) {
                
                if(freq1[i] > 0  and freq2[j] > 0) {
                    
                    freq1[i]--;
                    freq2[i]++;
                    freq1[j]++;
                    freq2[i]--;
                    
                    int dc1 = 0, dc2 = 0;
                    
                    for(int x = 0; x < 26; x++) {
                        if(freq1[x] > 0){
                            dc1++;
                        }
                         if(freq2[x] > 0){
                            dc2++;
                        }
                    }
                    
                    if(dc1 == dc2){
                        return true;
                    }
                    
                    freq1[i]++;
                    freq2[i]--;
                    freq1[j]--;
                    freq2[i]++;
                }
            }
        }
        return false;
    }
};