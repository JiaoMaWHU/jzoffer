class Solution {
 public:
  vector<string> Permutation(string str) {
    vector<string> ret;
    if (str.empty()) return ret;
    permutation(str, 0, ret);
    sort(ret.begin(), ret.end());
    return ret;
  }

  void permutation(string &str, size_t n, vector<string> &ret) {
    if (n == str.size() - 1) {
      ret.push_back(str);
      return;
    }
    for (int i = n; i < str.size(); i++) {
      if (str[i] == str[n] && i != n) {
        continue;
      }
      swap(str[i], str[n]);
      permutation(str, n + 1, ret);
      swap(str[i], str[n]);
    }
  }
};