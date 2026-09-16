class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int no1 = m - 1; 
        int no2 = n - 1;  
        int i = m + n - 1;  
        while (no2 >= 0) {  
            if (no1 >= 0 && nums1[no1] > nums2[no2]) {
                nums1[i--] = nums1[no1--];
            } else {
                nums1[i--] = nums2[no2--];
            }
        }
    }
}
