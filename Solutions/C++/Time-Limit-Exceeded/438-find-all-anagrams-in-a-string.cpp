/*
Problem Title: 438 - Find All Anagrams in a String
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/find-all-anagrams-in-a-string
Submission Url: https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/340608351
*/

class Solution {
public:
    string get_str(vector<int> arr){
        string t = "";
        for(int i = 0; i<26; i++){
            int x = arr[i];
            t += char(i+'a') + to_string(x);
        }
        return t;
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
        
        string sp = get_str(arr2);
        if( get_str(arr) == sp)
            ans.push_back(first);
        while(second < s.size()){
            arr[s[second++]-'a']++;
            arr[s[first++]-'a']--;
            if( get_str(arr) == sp)
                ans.push_back(first);
        }
        return ans;
    }
};