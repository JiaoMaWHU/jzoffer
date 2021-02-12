class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s == null) {
            return 0;
        }
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int length = 0;
        int maxLen = 0;
        int start = 0;
        for (int i=0; i<s.length(); i++) {
            Integer oid = map.put(s.charAt(i), i);
            if(oid != null && oid >= start) {
                maxLen = Math.max(maxLen, length);
                length = i-oid-1;
                start = oid+1;
            }
            length++;
        }
        maxLen = Math.max(maxLen, length);
        return maxLen;
    }
}