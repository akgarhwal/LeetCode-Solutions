/* Question: First Unique Number
 * Lang: cpp
 * Runtime: 464 ms
 * Memory: 81.5 MB
 * Question Url: https://leetcode.com/problems/first-unique-number
 * Submission Url:
 * https://leetcode.com/problems/first-unique-number/submissions/331445657
 */

class FirstUnique {
private:
  void findFirstUnique() {
    while (current_index < nums.size()) {
      if (mp[nums[current_index]] == 1) {
        unique = nums[current_index];
        break;
      }
      current_index += 1;
    }
    if (current_index == nums.size()) {
      unique = -1;
      return;
    }
  }

public:
  unordered_map<int, int> mp;
  vector<int> nums;
  int current_index, unique;
  FirstUnique(vector<int> &nums) {
    this->nums = nums;
    unique = -1;
    current_index = 0;
    for (int num : nums) {
      mp[num] += 1;
    }
    findFirstUnique();
  }

  int showFirstUnique() { return unique; }

  void add(int value) {
    mp[value] += 1;
    nums.push_back(value);
    if (value == unique or unique == -1) {
      findFirstUnique();
    }
  }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
