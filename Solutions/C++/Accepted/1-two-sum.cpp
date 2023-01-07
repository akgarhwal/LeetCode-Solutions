/*
Problem Title: 1 - Two Sum
Lang: C++
Runtime: 18 ms
Memory: 12 MB
Problem Url: https://leetcode.com/problems/two-sum
Submission Url: https://leetcode.com/problems/two-sum/submissions/867882818
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered map to store the value and its index in the vector
        unordered_map<int,int> num_index_map;

        // Iterate through the vector and store each value and its index in the map
        for(int index = 0; index < nums.size(); index++){
            num_index_map[nums[index]] = index;
        }

        // Create a vector to store the two indices of the values that sum up to target 
        vector<int> answer(2);

        // Iterate through the vector again and check if there is a value that sums up to target with current value 
        for(int index = 0; index < nums.size(); index++){
            int second = target - nums[index]; // Calculate the second number needed to sum up to target 
            
            // Check if there is a number in the map that sums up with current number and make sure it's not itself 
            if(num_index_map.find(second) != num_index_map.end() && num_index_map[second] != index) { 
                answer[0] = index; // Store first index in answer vector 
                answer[1] = num_index_map[second]; // Store second index in answer vector 
                break; // Break out of loop once both indices are found 
            }
        }
        return answer; // Return answer vector containing two indices of values that sum up to target 
    }
};