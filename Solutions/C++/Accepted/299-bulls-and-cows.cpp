/*
Problem Title: 299 - Bulls and Cows
Lang: C++
Runtime: 0 ms
Memory: 6.8 MB
Problem Url: https://leetcode.com/problems/bulls-and-cows
Submission Url: https://leetcode.com/problems/bulls-and-cows/submissions/774963020
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0, y = 0;
        
        map<char, int> mp1, mp2;
        
        for(int i = 0; i < secret.size(); i++) {
            
            if(secret[i] != guess[i]){
                mp1[secret[i]] += 1;
                mp2[guess[i]] += 1;
            }
            else{
                x += 1;
            }
        }
        
        for(auto ele : mp1){
            
            if(mp2.find(ele.first) != mp2.end()){
                y += min(mp1[ele.first], mp2[ele.first]);
            }
        }
        
        return to_string(x) + "A" + to_string(y) + "B";
    }
};