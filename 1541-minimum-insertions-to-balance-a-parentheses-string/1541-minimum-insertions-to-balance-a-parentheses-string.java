class Solution {
    public int minInsertions(String s) {
         int right = 0;
        int ans = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                if (right % 2 > 0) {
                    right--;
                    ans++;
                }
                right += 2;
            } else {
                right--;
                if (right < 0) {
                    right += 2;
                    ans++;
                }
            }
        }
        return ans + right;
    }
}