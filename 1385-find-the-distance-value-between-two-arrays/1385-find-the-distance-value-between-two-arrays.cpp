class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c=0;
        bool ok=true;
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d)
                    ok=false;
            }
            if(ok) c++;
            ok=true;
        }
        return c;
    }
};