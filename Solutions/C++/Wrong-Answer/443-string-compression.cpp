/*
Problem Title: 443 - String Compression
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/string-compression
Submission Url: https://leetcode.com/problems/string-compression/submissions/907455149
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int x = 0;
        for(int i = 0; i < chars.size(); ) {

            int j = i + 1, count = 1;
            while( j < chars.size()) {
                if(chars[j] == chars[i]) {
                    j++;
                    count++;
                } else {
                    break;
                }
            }

            if(count >= 2) {
                chars[x] = chars[i];
                x += 1;
                // cout<<x<<" "<<chars[i]<<" - "<<count<<endl;
                string countStr = to_string(count);
                for(int index = 0; index < countStr.size(); index++) {
                    chars[x] = countStr[index];
                    x += 1;
                }
            } else {
                x++;
            }
            i = j;
        }
        return x;
    }
};