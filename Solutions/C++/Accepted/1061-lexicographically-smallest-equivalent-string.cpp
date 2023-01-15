/*
Problem Title: 1061 - Lexicographically Smallest Equivalent String
Lang: C++
Runtime: 0 ms
Memory: 6.6 MB
Problem Url: https://leetcode.com/problems/lexicographically-smallest-equivalent-string
Submission Url: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/submissions/877763970
*/

class Solution {
public:


    int find(vector<int>& dsu, int x) {
        if(dsu[x] == x){
            return x;
        }
        return dsu[x] = find(dsu, dsu[x]);
    }

    void merge(vector<int>& dsu, int x, int y){
        x = find(dsu, x);
        y = find(dsu, y);

        if(x < y) {
            dsu[y] = x; 
        } else {
            dsu[x] = y;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> dsu(26,0);

        for(int i = 0; i < 26; i ++) {
            dsu[i] = i;
        }

        for(int i = 0; i < s1.size(); i ++) {
            merge(dsu, s1[i]-'a', s2[i]-'a');
        }
        string ans = "";
        for(int i = 0; i < baseStr.size(); i ++){
            ans += char(find(dsu,baseStr[i]-'a') + 'a');
        }
        return ans;
    }
};
