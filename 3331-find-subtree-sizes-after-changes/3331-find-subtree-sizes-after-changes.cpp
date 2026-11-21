class Solution {
public:
    int f(int u, int par, vector<vector<int>>& adj, string& s, vector<int>& ancs, vector<int>& subsize){
        int prev = ancs[s[u]-'a'];
        ancs[s[u]-'a'] = u;
        int cnt = 1;
        for(int v : adj[u]){
            if(v==par) continue;
            int c = f(v, u, adj, s, ancs, subsize);
            if(ancs[s[v]-'a']!=-1){
                int anc = ancs[s[v]-'a'];
                subsize[anc] += c;
            }else{
                cnt += c;
            }
        }
        subsize[u] += cnt;
        ancs[s[u]-'a'] = prev;
        return subsize[u];
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }
        vector<int> subsize(n, 0), ancs(26, -1);
        f(0, -1, adj, s, ancs, subsize);
        return subsize;
    }
};