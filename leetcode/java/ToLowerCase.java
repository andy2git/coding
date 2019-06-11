class Solution {
    public String toLowerCase(String str) {
        if (str == null || str.isEmpty()) return str;

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            char x = str.charAt(i);
            if (Character.isLowerCase(x)) sb.append(x);
            else sb.append(Character.toLowerCase(x));
        }
        return sb.toString();
    }
}
