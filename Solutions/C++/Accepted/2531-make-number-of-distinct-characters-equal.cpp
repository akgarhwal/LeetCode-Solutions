/*
Problem Title: 2531 - Make Number of Distinct Characters Equal
Lang: C++
Runtime: 47 ms
Memory: 16.8 MB
Problem Url: https://leetcode.com/problems/make-number-of-distinct-characters-equal
Submission Url: https://leetcode.com/problems/make-number-of-distinct-characters-equal/submissions/873806267
*/

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        // Two vectors to store the frequency of each character in the strings 
        vector<int> freq1(26, 0), freq2(26, 0);
        // Iterates through each character in the first string and stores its frequency in the vector freq1 
        for(char ch : word1){
            freq1[ch-'a']++;
        }
        // Iterates through each character in the second string and stores its frequency in the vector freq2
        for(char ch : word2){
            freq2[ch-'a']++;
        }
        
        // Iterates through each index of both vectors and checks 
        // if there is a character with non-zero frequency at both indices.
        // If so, it decrements the frequency of that character 
        // from one vector and increments it from another. (Swap Charactor)
        for(int i=0; i < 26; i++) {
            for(int j = 0; j <26; j++) {
                if(freq1[i] > 0  and freq2[j] > 0) {
                    freq1[i]--;
                    freq2[i]++;
                    freq1[j]++;
                    freq2[j]--;
                    
                    int dc1 = 0, dc2 = 0;
                    // Now counts the number of characters with non-zero frequencies in both vectors. 
                    for(int x = 0; x < 26; x++) {
                        if(freq1[x] > 0){
                            dc1++;
                        }
                         if(freq2[x] > 0){
                            dc2++;
                        }
                    }
                    // If they are equal, it returns true. 
                    if(dc1 == dc2){
                        return true;
                    }
                    // Otherwise, restores the frequencies to their original values before returning false. 
                    freq1[i]++;
                    freq2[i]--;
                    freq1[j]--;
                    freq2[j]++;
                }
            }
        }
        return false;
    }
};