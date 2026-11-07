#define pp pair<int,int>
#define ppp pair<int,pp>
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pp,vector<pp>,greater<pp>> freeServers;
        for(int i=0;i<servers.size();i++){
            freeServers.push({servers[i],i});
        }
        priority_queue<ppp,vector<ppp>,greater<ppp>> usedServers;
        int n = tasks.size();
        vector<int> ans(n,0);
        long long time = 0;
        for(int i=0;i<n;i++){
            time = max(time,(long long )i);
            while(!usedServers.empty() && time >= usedServers.top().first){
                auto server = usedServers.top(); usedServers.pop();
                freeServers.push(server.second);
            }
            if (freeServers.empty()) {
                time = usedServers.top().first;
                while (!usedServers.empty() && usedServers.top().first <= time) {
                    auto server = usedServers.top(); usedServers.pop();
                    freeServers.push(server.second);
                }
            }

            auto currServer = freeServers.top(); freeServers.pop();
            ans[i] = currServer.second;
            usedServers.push({time+tasks[i],currServer});
        }
        return ans;
    }
};