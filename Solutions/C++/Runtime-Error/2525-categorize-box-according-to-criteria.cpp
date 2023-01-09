/*
Problem Title: 2525 - Categorize Box According to Criteria
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/categorize-box-according-to-criteria
Submission Url: https://leetcode.com/problems/categorize-box-according-to-criteria/submissions/873692026
*/

class Solution {
public:
    // This function checks if a box is bulky based on its length, width, and height
    bool isBoxBulky(int length, int width, int height) {
        if(max(length, max(width, height)) >= 1e4) {
            return true;
        }
        int volume = length * width * height;
        if(volume >= 1e9) {
            return true;
        }
        return false;
    }

    string categorizeBox(int length, int width, int height, int mass) {

        bool isBulky = isBoxBulky(length, width, height);
        bool isHeavy = (mass >= 100) ? true : false; 

        if(isBulky and isHeavy) {
            return "Both";
        }
        if(!isBulky and !isHeavy) {
            return "Neither";
        }
        if(isBulky and !isHeavy) {
            return "Bulky";
        }
        return "Heavy";
    }
};