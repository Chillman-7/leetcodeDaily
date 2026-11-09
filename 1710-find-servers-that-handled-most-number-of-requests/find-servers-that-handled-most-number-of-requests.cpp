class Solution {
public:

    typedef pair<int,int>p; //Stores {finishTime,serverId}


    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>available_Servers;
        for(int i=0;i<k;i++){
            available_Servers.insert(i);
        }
    vector<int>result;

        //Min heap to maintain when which server will become free after getting load(load[i]) at that time(time[i])
         
         priority_queue<p,vector<p>,greater<p>> busyServers;

         //To store which server got howmany requests
         vector<int>count(k,0);

         for(int i=0;i<arrival.size();i++){
            int time = arrival[i];
            //free the servers untill this time and add that freed server in available servers.
            while(!busyServers.empty() && busyServers.top().first <= time){
               int server = busyServers.top().second;
               busyServers.pop();
               available_Servers.insert(server);
            }

            int target = i%k;
            //So check in availableServers,if i get targetServer then fine else the next availableServer in orderedSet.
            auto it = available_Servers.lower_bound(target);
         

         if(it == available_Servers.end()){
            //Wrap aroun
            it = available_Servers.begin();
         }

         if( available_Servers.empty()){
            //no servers available,drop current Request
            continue;
         }
         int target_Server = *it;


         //erase as this server is gng to be busy n add it in busyServer
         available_Servers.erase(it);

         busyServers.push({time+load[i],target_Server});

         count[target_Server]++;

         }
         int maxReq = *max_element(count.begin(),count.end());

         for(int i=0;i<k;i++){
            if(count[i] == maxReq){
                result.push_back(i);
            }
         }
         return result;
    }
};