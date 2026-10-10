class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> freq(100001,0);
        long long k=1LL*k1+k2;
        long long sum=0;
        int maxx=0;

        for(int i=0;i<nums1.size();i++){
            int d=abs(nums1[i]-nums2[i]);
            sum+=d;
            freq[d]++;
            maxx=max(maxx,d);
        }

        if(sum<=k) return 0;

        for(int i=maxx;i>=0 && k>0;i--){
            long long move=min(k,(long long)freq[i]);
            freq[i]-=move;
            freq[i-1]+=move;
            k-=move;
        }

        long long ans=0;
        for(int i=0;i<=maxx;i++)
            ans+=(long long)i*i*freq[i];

        return ans;

    }
};