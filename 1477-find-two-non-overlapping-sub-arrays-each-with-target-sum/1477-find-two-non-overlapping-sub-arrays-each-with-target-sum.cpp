class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        vector<array<int,2>> v;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(mp.count(sum-target))    
                v.push_back({mp[sum-target]+1,i});
            
            mp[sum]=i;
        }
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
        for(auto a:v)
            pq.push({a[1]-a[0],a[0]});
        
        int an[arr.size()+1];
        for(int i=0;i<arr.size()+1;i++)
        {
            while(!pq.empty() and pq.top()[1]<i)
                pq.pop();
            if(pq.empty())
                an[i]=INT_MAX;
            else
             an[i]=pq.top()[0];
        }
        int ans=INT_MAX;
        for(auto p:v)
            if(an[p[1]+1]!=INT_MAX)
                ans=min(ans,p[1]-p[0]+an[p[1]+1]);
        
        if(ans==INT_MAX) return -1;
        return ans+2;
        
    }
};