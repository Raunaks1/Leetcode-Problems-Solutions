class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();
        ArrayList<Integer> arr = new ArrayList<>();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                ans++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                int j = i;
                while (j < n && s.charAt(j) == '0') {
                    j++;
                }
                arr.add(j - i);
                i = j - 1;
            }
        }

        int temp = -1;
        for (int i = 1; i < arr.size(); i++) {
            temp = Math.max(temp, arr.get(i) + arr.get(i - 1));
        }

        if (temp != -1) {
            ans += temp;
        }

        return ans;
    }
}