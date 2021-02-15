class Solution {
    public String reverseWords(String s) {
        String[] cp = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(int i = cp.length -1; i>=0; i--) {
            sb.append(cp[i]);
            sb.append(" ");
        }
        return sb.toString().trim();
    }
}