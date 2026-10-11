class Solution {
    public int sumOfSquares(int[] nums) {
        int ans = 0;
        int n = nums.length;
        int first = nums[0] * nums[0];
        int last = nums[n -1] * nums[n -1];
        for(int i = 1; i < n -1; i++){
            if(n % i == 0){
                ans = ans + nums[i -1] * nums[i -1];
            }
        }
        if(n < 3 && n > 1){
            return first + last + ans;
        }else if(n == 1){
            return first;
        }
        return (ans + last);
    }
}