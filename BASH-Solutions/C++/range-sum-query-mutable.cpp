/* Question: Range Sum Query - Mutable
 * Lang: cpp
 * Runtime: 739 ms
 * Memory: 153.1 MB
 * Question Url: https://leetcode.com/problems/range-sum-query-mutable
 * Submission Url:
 * https://leetcode.com/problems/range-sum-query-mutable/submissions/761100507
 */

class NumArray {
  vector<int> tree;
  vector<int> arr;

public:
  NumArray(vector<int> &nums) {
    arr = nums;
    tree.assign(nums.size() * 4, 0);
    build(0, nums.size() - 1, 1);
  }

  int build(int s, int e, int node) {
    if (s == e) {
      return tree[node] = arr[s];
    }
    int m = s + (e - s) / 2;
    int left = build(s, m, node * 2);
    int right = build(m + 1, e, node * 2 + 1);
    return tree[node] = left + right;
  }

  void update(int index, int val) { update(index, val, 1, 0, arr.size() - 1); }

  int update(int ind, int val, int node, int st, int end) {

    if (ind == st and st == end) {
      return tree[node] = val;
    }
    if (st == end) {
      return tree[node];
    }
    if (ind < st) {
      return tree[node];
    }
    if (ind > end) {
      return tree[node];
    }
    int mid = st + (end - st) / 2;
    int left = update(ind, val, node * 2, st, mid);
    int right = update(ind, val, node * 2 + 1, mid + 1, end);
    return tree[node] = left + right;
  }

  int sumRange(int left, int right) {
    return range(left, right, 1, 0, arr.size() - 1);
  }

  int range(int l, int r, int node, int s, int e) {
    if (s == l and e == r) {
      return tree[node];
    }
    if (s == e and (e < l or r < s)) {
      return 0;
    }
    if (s == e) {
      return tree[node];
    }
    if (s >= l and e <= r) {
      return tree[node];
    }
    int m = s + (e - s) / 2;
    int ans = 0;
    if (l <= m) {
      ans += range(l, r, node * 2, s, m);
    }
    if (r > m) {
      ans += range(l, r, node * 2 + 1, m + 1, e);
    }
    return ans;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
