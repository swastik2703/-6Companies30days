#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[10];
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> topo;
        int n = numCourses;
        vector<int> in(n,0);
        queue<int> q;
        for(int i=0; i<n; i++){
            for(auto j : adj[i]){
                in[j]++;
            }
        }

        for(int node = 0; node < n; node++){
            if(!in[node]) q.push(node);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto i : adj[node]){
                in[i]--;
                if(!in[i]) q.push(i);
            }
        }
        return topo.size() == n;
    }
};