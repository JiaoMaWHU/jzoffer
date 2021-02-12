class Solution {
    public char firstUniqChar(String s) {
        LinkedHashMap<Character, Integer> lmap = new LinkedHashMap<Character, Integer>();
        Integer v;
        for(int i=0; i<s.length(); i++) {
            v = lmap.getOrDefault(s.charAt(i), 0);
            lmap.put(s.charAt(i), ++v);
        }
        for(Map.Entry<Character, Integer> entry: lmap.entrySet()) {
            if(entry.getValue()==1) {
                return entry.getKey().charValue();
            }
        }
        return ' ';
    }
}