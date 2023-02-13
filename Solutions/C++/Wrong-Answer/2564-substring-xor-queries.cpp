/*
Problem Title: 2564 - Substring XOR Queries
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/substring-xor-queries
Submission Url: https://leetcode.com/problems/substring-xor-queries/submissions/896298874
*/

class Solution {
public:
    
    string intToBinaryString(int n) {
        
        string result = "";
        
        while(n > 0) {
            result += (n%2) ? '1' : '0';
            n = n >> 1;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    int findSubString(string main, string target){
        for(int i=0; i < main.size(); i++) {
            string temp = main.substr(i, target.size());
            if(temp == target) {
                return i;
            }
        }
        return -1;
    }
    
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        
        for(auto query: queries) {
            int x = query[0]^query[1];
            
            string binaryX = intToBinaryString(x);
            int pos = findSubString(s, binaryX);
            
            vector<int> temp(2, -1);
            if(pos != -1){
                temp[0] = pos;
                temp[1] = pos + binaryX.size() - 1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};