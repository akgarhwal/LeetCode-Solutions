/*
Problem Title: 1535 - Find the Winner of an Array Game
Lang: C++
Runtime: 252 ms
Memory: 63.1 MB
Problem Url: https://leetcode.com/problems/find-the-winner-of-an-array-game
Submission Url: https://leetcode.com/problems/find-the-winner-of-an-array-game/submissions/374925011
*/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int i = 1, count = 0;
        while( i < arr.size()){
            if(arr[0] > arr[i]){
                count++;
            }
            else{
                swap(arr[0],arr[i]);
                count=1;
            }
            i++;
            if(count == k){
                return arr[0];
            }
        }
        return arr[0];
    }
};