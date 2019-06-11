class Solution {
 public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    vector<int> v(numbers.size());
    for (auto &n : numbers) {
      if (++v[n] > (numbers.size() / 2)) {
        return n;
      }
    }
    return 0;
  }
};