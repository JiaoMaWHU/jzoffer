class Solution {
 public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> ret;
    if (input.empty() || k == 0 || k > input.size()) {
      return ret;
    }
    for (int i = 0; i < k; i++) {
      int min = INT_MAX, index = i;
      for (int j = i; j < input.size(); j++) {
        if (input[j] < min) {
          min = input[j];
          index = j;
        }
      }
      int tmp = input[i];
      input[i] = input[index];
      input[index] = tmp;
      ret.push_back(input[i]);
    }
    return ret;
  }
};