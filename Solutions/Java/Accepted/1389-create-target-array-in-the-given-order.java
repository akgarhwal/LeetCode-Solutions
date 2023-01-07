/*
Problem Title: 1389 - Create Target Array in the Given Order
Lang: Java
Runtime: 3 ms
Memory: 40.2 MB
Problem Url: https://leetcode.com/problems/create-target-array-in-the-given-order
Submission Url: https://leetcode.com/problems/create-target-array-in-the-given-order/submissions/869024003
*/

class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < nums.length; i++) {
            int ind = index[i];
            list.add(ind, nums[i]);
        }

        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}