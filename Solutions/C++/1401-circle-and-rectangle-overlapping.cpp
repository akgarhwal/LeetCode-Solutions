/*
Problem Title: 1401 - Circle and Rectangle Overlapping
Lang: C++
Runtime: 0 ms
Memory: 6.1 MB
Problem Url: https://leetcode.com/problems/circle-and-rectangle-overlapping
Submission Url: https://leetcode.com/problems/circle-and-rectangle-overlapping/submissions/323000733
*/

class Solution {
public:
    int distanceFromCenter (int cx, int cy, int x, int y){
        return (int)(sqrt((cx-x)*(cx-x) + (cy-y)*(cy-y)));
    }
    
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // center is inisde rect
        if( x_center >= x1 and  x_center <= x2 and y_center >= y1 and y_center <= y2){
            return true;
        }
        
        //circle overlap rect 
        // lower side
        for(int i = x1; i <= x2; i++){
            int dist = distanceFromCenter(x_center, y_center, i, y1);
            if(dist <= radius){
                return true;
            }
        }
        //left
        for(int i = y1; i <= y2; i++){
            int dist = distanceFromCenter(x_center, y_center, x1, i);
            if(dist <= radius){
                return true;
            }
        }
        //top
         for(int i = x1; i <= x2; i++){
            int dist = distanceFromCenter(x_center, y_center, i, y2);
            if(dist <= radius){
                return true;
            }
        }
        //right
         for(int i = y1; i <= y2; i++){
            int dist = distanceFromCenter(x_center, y_center, x2, i);
            if(dist <= radius){
                return true;
            }
        }
        
        return false;
    }
};