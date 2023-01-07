/*
Problem Title: 448 - Find All Numbers Disappeared in an Array
Lang: C#
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
Submission Url: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/301885178
*/

public class Solution {
    public IList<int> FindDisappearedNumbers(int[] nums) {
        IList<int> res = new List<int>();
        int length = nums.Length;
        for(int index = 0; index < length; index++){
            if(nums[index] <= length){
                nums[nums[index]-1] = nums[nums[index]-1] + length;
            }
            else{
                int indexToUpdate = nums[index] - 1 - length;
                nums[indexToUpdate] = nums[indexToUpdate] > length ? nums[indexToUpdate] : nums[indexToUpdate]+ length;
            }
        }
        
        for(int index = 0; index < length; index++){
            if(nums[index] <= length) {
                res.Add(index + 1);
            }
        }
        return res;
    }
}