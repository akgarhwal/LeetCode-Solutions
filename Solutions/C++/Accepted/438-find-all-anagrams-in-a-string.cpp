/*
Problem Title: 438 - Find All Anagrams in a String
Lang: C++
Runtime: 120 ms
Memory: 59 MB
Problem Url: https://leetcode.com/problems/find-all-anagrams-in-a-string
Submission Url: https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/773479123
*/

class Solution {
public:
    bool CHECK(vector<int> arr, vector<int> arr2){
        for(int i = 0; i<26; i++){
            if(arr[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()){
            return ans;    
        }
        vector<int> arr(26,0);
        
        int first = 0, second = 0;
        while(second < p.size()){
            arr[s[second++]-'a']++;
        }
        
        vector<int> arr2(26,0);
        int second2 = 0;
        while(second2 < p.size()){
            arr2[p[second2++]-'a']++;
        }
        
        if( CHECK(arr, arr2))
            ans.push_back(first);
        while(second < s.size()){
            arr[s[second++]-'a']++;
            arr[s[first++]-'a']--;
            if( CHECK(arr, arr2))
                ans.push_back(first);
        }
        return ans;
    }
};