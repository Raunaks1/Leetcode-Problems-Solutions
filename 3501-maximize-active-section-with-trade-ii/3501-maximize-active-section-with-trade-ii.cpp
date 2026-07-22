
class Solution {
public:
    void build(int l , int r , int node , vector<int>& tree , vector<pair<int,int>>& v){
        if(l == r){
            tree[node] = 0 ; 
            return ;
        }
        int mid = (l+r)>>1;
        build(l , mid , 2*node , tree , v) ; 
        build(mid+1 , r , 2*node+1 , tree , v) ; 

        int maxi = max(tree[2*node] , tree[2*node+1]) ; 

        if (v[mid].first == 0) {
            if (mid + 2 <= r) maxi = max(maxi, v[mid].second + v[mid + 2].second);
        } else {
            if (mid - 1 >= l) maxi = max(maxi, v[mid + 1].second + v[mid - 1].second);
        }

        tree[node] = maxi ; 
    }

    void update(int indx , int l , int r , int node , int val , vector<pair<int,int>>& v , vector<int>& tree){
        if(l == r){
            v[l].second = val ;
            return ; 
        }
        int mid = (l+r)>>1;
        if(indx <= mid){
            update(indx , l , mid , 2*node , val , v , tree) ; 
        }else{
            update(indx , mid+1 , r , 2*node+1 , val , v , tree) ; 
        }
        int maxi = max(tree[2*node] , tree[2*node+1]) ; 

        if (v[mid].first == 0) {
            if (mid + 2 <= r) maxi = max(maxi, v[mid].second + v[mid + 2].second);
        } else {
            if (mid - 1 >= l) maxi = max(maxi, v[mid + 1].second + v[mid - 1].second);
        }

        tree[node] = maxi ; 
    }

    int query(int node , int l , int r , int ql , int qr ,vector<int>& tree , vector<pair<int,int>>& v){
        if(r < ql || l > qr) return 0 ; 
        if(ql <= l && qr >= r) return tree[node] ;
        int mid = (l+r)>>1 ; 
        int o1 = query(2*node , l , mid , ql , qr , tree , v) ; 
        int o2 = query(2*node+1 , mid+1 , r , ql , qr , tree , v) ;
        int maxi = max(o1 , o2) ;
        if (v[mid].first == 0) {
            if (check(mid , l , r , ql , qr) && check(mid+2 , l , r , ql , qr)){
                maxi = max(maxi, v[mid].second + v[mid + 2].second);
            }
        } else {
            if (check(mid-1 , l , r , ql , qr) && check(mid+1 , l , r , ql , qr)){
                maxi = max(maxi, v[mid + 1].second + v[mid - 1].second);
            }
        }
        return maxi ;
    }
    bool check(int indx , int l , int r , int ql , int qr){
        return indx >= max(l , ql) && indx <= min(r , qr) ; 
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<pair<int,int>> v ; 
        int ct = 1 ; int prev = s[0]-'0' ; 
        int n = s.size() ; 
        int curr_len = 0 ; 
        curr_len += (s[0] == '1') ;
        for(int i = 1 ; i < n ; i++){
            curr_len += (s[i]=='1') ;
            if(prev == s[i]-'0'){
                ct++ ; 
            }else{
                v.push_back(make_pair(prev , ct)) ; 
                prev = s[i] - '0' ; 
                ct = 1 ; 
            }
        }
        v.push_back(make_pair(prev , ct)) ;
        n = v.size() ; 
        vector<int> indx(n , v[0].second-1) ;
        for(int i = 1 ; i < n ; i++){
            indx[i] = v[i].second + indx[i-1] ;
        }

        vector<int> tree(4*n , -1) ; 
        build(0 , n-1 , 1 , tree , v) ; 
        vector<int> ans ; 
        for(auto i : queries){
            int l = i[0] ; 
            int r = i[1] ; 
            if(l == r){
                ans.push_back(curr_len) ;
                continue ;
            }
            int indx_l = lower_bound(indx.begin() , indx.end() , l) - indx.begin() ; 
            int indx_r = lower_bound(indx.begin() , indx.end() , r) - indx.begin() ; 
            int curr_l = v[indx_l].second ; 
            int curr_r = v[indx_r].second ; 
            int new_l = curr_l - (l -  (indx_l > 0 ? (indx[indx_l - 1] + 1) : 0 ) ) ; 
            int new_r = curr_r - (indx[indx_r] - r ) ;
            update(indx_l , 0 , n-1 , 1 , new_l , v , tree) ; 
            update(indx_r , 0 , n-1 , 1 , new_r , v , tree) ;
            int curr_ans = query(1 , 0 , n-1 , indx_l , indx_r , tree , v) ; 
            ans.push_back(curr_ans + curr_len) ; 
            update(indx_l , 0 , n-1 , 1 , curr_l , v , tree) ; 
            update(indx_r , 0 , n-1 , 1 , curr_r , v , tree) ;
        }
        return ans ;
    }
};


