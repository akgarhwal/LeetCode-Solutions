/*
Problem Title: 215 - Kth Largest Element in an Array
Lang: Go
Runtime: 12 ms
Memory: 3.5 MB
Problem Url: https://leetcode.com/problems/kth-largest-element-in-an-array
Submission Url: https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/728189327
*/

func findKthLargest(nums []int, k int) int {
    sort.Ints(nums)
    return nums[len(nums)-k]
}