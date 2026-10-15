class Solution {
    public int sumCounts(List<Integer> nums) {
        int sum = 0;
        Set<Integer> st = new HashSet<>();
        for(int i=0; i<nums.size(); i++){
            st.clear();    
            for(int j=i; j<nums.size(); j++){
                st.add(nums.get(j));
                int size = st.size();
                sum += size*size;
            }
        }
        return sum;
    }
}