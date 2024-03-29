/*
Problem Title: 605 - Can Place Flowers
Lang: C++
Runtime: 18 ms
Memory: 20.3 MB
Problem Url: https://leetcode.com/problems/can-place-flowers
Submission Url: https://leetcode.com/problems/can-place-flowers/submissions/918426822
*/

class Solution {

public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int count = 0;

        for (int i = 0; i < flowerbed.size(); i++) {

            // Check if the current plot is empty.

            if (flowerbed[i] == 0) {

                // Check if the left and right plots are empty.

                bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);

                bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);

                

                // If both plots are empty, we can plant a flower here.

                if (emptyLeftPlot && emptyRightPlot) {

                    flowerbed[i] = 1;

                    count++;

                }

            }

        }

        return count >= n;

    }

};
        
