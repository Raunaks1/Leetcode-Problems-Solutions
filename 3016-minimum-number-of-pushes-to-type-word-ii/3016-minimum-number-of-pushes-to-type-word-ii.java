class Solution {
    public int minimumPushes(String word) {
        int[] freq = new int[26];
        for(char c : word.toCharArray()) {
            freq[c - 'a']++;
        }
        List<int[]> raunak = new ArrayList<>();
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) 
            raunak.add(new int[]{i,freq[i]});
        }
        raunak.sort((a,b) -> b[1] - a[1]);
        int total = 0;
        int n = raunak.size();
        for(int i=0; i<n; i++) {
            int a = raunak.get(i)[1];
            int b = (i/8) + 1;
            total += a * b;
        }
        return total;
    }
}