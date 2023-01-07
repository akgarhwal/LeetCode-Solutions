/*
Problem Title: 41 - First Missing Positive
Lang: C#
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/first-missing-positive
Submission Url: https://leetcode.com/problems/first-missing-positive/submissions/303450161
*/

public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int lastIndex = 0;
        for(int ind = 0; ind < nums.Length; ind++){
            
            if(nums[ind] > 0 && nums[ind] <= ind && nums[ind] != ind+1) {
                int temp = nums[ind];
                int ind2 = nums[ind];
                nums[ind] = nums[ind2-1];
                nums[ind2-1] = temp;
                Console.WriteLine($"SWAP : {ind} <--> {ind2-1}");
            }
            //Console.WriteLine($"I : {ind} , LI : {lastIndex}, N : {nums[lastIndex]}");
            while(lastIndex < nums.Length && (lastIndex+1) == nums[lastIndex]){
                lastIndex += 1;
                //Console.WriteLine("HHH");
            }
            foreach(var x in nums){
                Console.Write(x + " ");
            }
            Console.WriteLine(" ");
        }
        //Console.WriteLine(lastIndex);
        return lastIndex+1;
    }
}