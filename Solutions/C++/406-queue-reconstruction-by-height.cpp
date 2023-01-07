/*
Problem Title: 406 - Queue Reconstruction by Height
Lang: C++
Runtime: 349 ms
Memory: 25.2 MB
Problem Url: https://leetcode.com/problems/queue-reconstruction-by-height
Submission Url: https://leetcode.com/problems/queue-reconstruction-by-height/submissions/733903289
*/

bool sort_by( vector<int> first, vector<int> second){
    if(first[0] != second[0]){
        return first[0] > second[0];
    }
    return first[1] < second[1];
}
class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> queue;
        sort(people.begin(), people.end(), sort_by);
        
        for(auto ele : people){
            queue.insert(queue.begin() + ele[1], ele);
        }
        
        return queue;
    }
};