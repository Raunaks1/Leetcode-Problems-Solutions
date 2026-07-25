class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
          int n = nums.length;
        Arrays.sort(nums);

        List<List<Integer>> list = new ArrayList<>();
        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i]; 

            int start = i+1, end = n-1;
            while(start < end) {
                if(nums[start] + nums[end] <= target) {
                    if(nums[start] + nums[end] == target) {
                        list.add(new ArrayList<>(Arrays.asList(nums[i], nums[start], nums[end])));
                        
                        while(start < end && nums[start] == nums[start+1]) start++;
                        while(start < end && nums[end] == nums[end-1]) end--;
                    } 
                    start += 1;
                } else end -= 1;
            }
        }

        return list;
    }
}