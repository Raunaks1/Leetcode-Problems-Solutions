class Solution {
    public int findGCD(int[] nums) {
        Arrays.sort(nums);
        int min = nums[0];
        int max = nums[nums.length-1];
        int gcd = min;
        int i = 1;
		
        while(i<=max){
            if(min%i ==0 & max%i==0){
                gcd = i;
            }
            i++;
        }
		
        return gcd;
    }
}