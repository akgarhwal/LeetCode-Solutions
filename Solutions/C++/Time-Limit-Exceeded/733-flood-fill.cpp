/*
Problem Title: 733 - Flood Fill
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/flood-fill
Submission Url: https://leetcode.com/problems/flood-fill/submissions/338126658
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        while(!q.empty()){
            pair<int,int> pi = q.front();q.pop();
            for(int i =0 ;i < 4; i++){
                int new_x = pi.first + dr[i], new_y = pi.second + dc[i];
                if(new_x >=0 and new_x < image.size() and new_y >=0  and new_y< image[0].size() and image[new_x][new_y] == oldColor){
                    q.push({new_x, new_y});
                    image[new_x][new_y] = newColor;
                }
            }
        }
        return image;
    }
};