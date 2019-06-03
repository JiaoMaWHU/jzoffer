class Solution {
 public:
  vector<int> staticSeq;
  bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty()) return false;
    staticSeq = sequence;
    return checkThisTree(0, staticSeq.size() - 1);
  }

  bool checkThisTree(int s, int e) {
    if (e == s) return true;
    int end = -1;
    bool ret = true;
    while (staticSeq[end + 1] < staticSeq[e]) {
      end++;
    }
    for (int i = end + 1; i < e; i++) {
      if (staticSeq[i] < staticSeq[e]) return false;
    }
    if (end != -1) {
      ret = checkThisTree(0, end);
    }
    if (end != e - 1) {
      ret &= checkThisTree(end + 1, e - 1);
    }
    return ret;
  }
};