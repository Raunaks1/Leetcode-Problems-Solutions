#define _int64 long long

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& a, int k) {
        int i,j,n,h;
        _int64 ans,len,tot,sum;
        vector<pair<_int64,_int64> > d;
        n=a.size();
        ans=0;
        d.clear();
        h=0;
        tot=0;
        sum=0;
        j=n-1;
        for (i=n-1;i>=0;i--)
        {
            while ((j>=0)&&(tot-sum<=k))
            {

                len=1;
                while ((d.size()>h)&&(d.back().first<a[j]))
                {
                    len+=d.back().second;
                    tot-=d.back().first*d.back().second;
                    d.pop_back();
                }
                tot+=len*a[j];
                sum+=a[j];
                d.push_back(make_pair(a[j],len));
                j--;
                
            }
            ans+=i-j-1;
            if (tot-sum<=k) ans++;
            d[h].second--;
            tot-=d[h].first;
            if (d[h].second==0) h++;
            sum-=a[i];
        }
        return ans;
    }
};