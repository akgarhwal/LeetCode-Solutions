/*
Problem Title: 448 - Find All Numbers Disappeared in an Array
Lang: C#
Runtime: 304 ms
Memory: 43.4 MB
Problem Url: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
Submission Url: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/301889752
*/

public class Solution {
    public IList<int> FindDisappearedNumbers(int[] nums) {
        IList<int> res = new List<int>();
        int length = nums.Length,  indexToUpdate = -1;
        
        // First make elements negative if associated index is an element in the array
        for(int index = 0; index < length; index++){
            indexToUpdate = Math.Abs(nums[index]) - 1;
            if (nums[indexToUpdate] > 0) {
                nums[indexToUpdate] = -nums[indexToUpdate];
            }
        }
        for(int index = 0; index < length; index++){
            if(nums[index] > 0) {
                res.Add(index + 1);
            }
        }
        return res;
    }
}