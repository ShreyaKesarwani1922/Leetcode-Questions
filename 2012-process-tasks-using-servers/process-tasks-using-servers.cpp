class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using P=pair<int,int>;
        using B=pair<long long,int>;

        priority_queue<P,vector<P>,greater<P>> freeServer;
        priority_queue<B,vector<B>,greater<B>> busyServer;

        int n=servers.size();
        int m=tasks.size();

        vector<int> ans(m);

        for(int i=0;i<n;i++){
            freeServer.push({servers[i],i});
        }

        long long time=0;

        for(int i=0;i<m;i++){
            time=max(time,(long long )i);

            if(freeServer.empty()){
                time=max(time,busyServer.top().first);
            }

            while(!busyServer.empty() && busyServer.top().first<=time){
                int idx=busyServer.top().second;

                freeServer.push({servers[idx],idx});

                busyServer.pop();
            }

            int idx=freeServer.top().second;
            ans[i]=idx;
            busyServer.push({time+tasks[i],idx});
            freeServer.pop();
        }

        return ans;
    }
};