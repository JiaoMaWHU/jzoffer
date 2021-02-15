class Solution {
    public int sumNums(int n) {
        boolean res = (n != 0) && ((n += sumNums(n-1)) > 0);
        return n;
    }
}