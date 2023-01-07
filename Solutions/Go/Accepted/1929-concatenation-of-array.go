/*
Problem Title: 1929 - Concatenation of Array
Lang: Go
Runtime: 4 ms
Memory: 6.3 MB
Problem Url: https://leetcode.com/problems/concatenation-of-array
Submission Url: https://leetcode.com/problems/concatenation-of-array/submissions/558405522
*/

func getConcatenation(nums []int) []int {
    n := len(nums)
    ans := make([]int, 2*n, 2*n)
    for i := 0; i < 2*n; i++ {
        if i >= n {
            ans[i] = nums[i-n]
        } else {
            ans[i] = nums[i]
        }
    } 
    return ans
}