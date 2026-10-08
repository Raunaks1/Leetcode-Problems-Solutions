class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder sb = new StringBuilder();
        int front = 0, back = 0, j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                front++;
            else
                back++;

            if (front != 0 && front == back) {
                front = 0;
                back = 0;
                String str = s.substring(j + 1, i);
                sb.append(str);
                j = i+1;
            }

        }
        if (front != 0 && front == back) {
            String str = s.substring(j + 1, s.length() - 1);
            sb.append(str);
        }
        return sb.toString();
        
    }
}