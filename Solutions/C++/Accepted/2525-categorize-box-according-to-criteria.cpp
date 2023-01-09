/*
Problem Title: 2525 - Categorize Box According to Criteria
Lang: C++
Runtime: 3 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/categorize-box-according-to-criteria
Submission Url: https://leetcode.com/problems/categorize-box-according-to-criteria/submissions/873692684
*/

class Solution {
public:
    // This function checks if a box is bulky based on its length, width, and height
    bool isBoxBulky(int length, int width, int height) {
         // Check if any of the dimensions are greater than or equal to 10,000
        if(max(length, max(width, height)) >= 1e4) {
            return true;
        }
        // Calculate the volume of the box and check if it is greater than or equal to 1 billion
        long volume = 1LL * length * width * height;
        if(volume >= 1e9) {
            return true;
        }
        // If neither condition is met, then the box is not bulky 
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