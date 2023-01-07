/*
Problem Title: 1 - Two Sum
Lang: C#
Runtime: 252 ms
Memory: 31.3 MB
Problem Url: https://leetcode.com/problems/two-sum
Submission Url: https://leetcode.com/problems/two-sum/submissions/302170779
*/

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        int[] result = new int[2];
        for(int index = 0; index < nums.Length; index++){
            int previous = target - nums[index];
            if(dict.ContainsKey(previous)){
                result[0] = dict[previous];
                result[1] = index;
                break;
            }
            dict[nums[index]] = index;
        }
        return result;
    }
}