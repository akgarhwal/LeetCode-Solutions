/*
Problem Title: 374 - Guess Number Higher or Lower
Lang: C++
Runtime: 3 ms
Memory: 5.8 MB
Problem Url: https://leetcode.com/problems/guess-number-higher-or-lower
Submission Url: https://leetcode.com/problems/guess-number-higher-or-lower/submissions/885996082
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while(low <= high){

            int mid = low + ((high-low)>>1);

            if(guess(mid) == 0) {
                return mid;
            }

            if(guess(mid) > 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};