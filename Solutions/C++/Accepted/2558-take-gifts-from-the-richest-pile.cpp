/*
Problem Title: 2558 - Take Gifts From the Richest Pile
Lang: C++
Runtime: 31 ms
Memory: 9 MB
Problem Url: https://leetcode.com/problems/take-gifts-from-the-richest-pile
Submission Url: https://leetcode.com/problems/take-gifts-from-the-richest-pile/submissions/891687551
*/

class Solution {
public:
    int findMaxIndex(vector<int>& gifts) {
        int index = 0, mx = gifts[0];
        for(int i=1; i < gifts.size(); i++) {
            if(mx < gifts[i]){
                index = i;
                mx = gifts[i];
            }
        }
        return index;
    }
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        while(k--) {
            int index = findMaxIndex(gifts);
            int mx = gifts[index];
            int taken = mx - floor(sqrt(mx));
            gifts[index] = mx - taken;
        }
        
        for(int x : gifts){
            ans += (long long)x;
        }
        
        return ans;
    }
};