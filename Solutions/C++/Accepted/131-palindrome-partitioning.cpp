/*
Problem Title: 131 - Palindrome Partitioning
Lang: C++
Runtime: 233 ms
Memory: 140.8 MB
Problem Url: https://leetcode.com/problems/palindrome-partitioning
Submission Url: https://leetcode.com/problems/palindrome-partitioning/submissions/882758915
*/

class Solution {
public:

    bool isPalindrome(string s){
        int st = 0, end = s.size()-1;
        while(st < end){
            if(s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }

    void dfs(int i, string str, string subStr, vector<string> cur, vector<vector<string>>& ans) {
        if(i >= str.size()){
            ans.push_back(cur);
            return;
        }

        for(int x = i; x < str.size(); x++ ) {
            subStr = subStr + str[x];
            if(isPalindrome(subStr)) {
                cur.push_back(subStr);
                dfs(x+1, str, "", cur, ans);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(0, s, "", cur, ans);
        return ans;
    }
};

/*








*/