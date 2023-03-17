class Solution {
private:
    vector<vector<int>> neighbors;
    vector<int> timestamp;
    vector<int> low;
    vector<vector<int>> criticals;
 
    void dfs(int node,int parent,int ts){
        if(timestamp[node]>0) return;
        
        timestamp[node]=ts+1;
        low[node]=ts+1;
        ts++;
        
        for(auto neighbor:neighbors[node]){
            if(neighbor==parent) continue;
            dfs(neighbor,node,ts);
            low[node]=min(low[node],low[neighbor]);
        }
        
        if(parent!=-1 && low[node]>timestamp[parent]) criticals.push_back({parent,node});
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    timestamp.resize(n);
    low.resize(n);
    neighbors.resize(n);
        for(auto c:connections){
            neighbors[c[0]].push_back(c[1]);
            neighbors[c[1]].push_back(c[0]);
        }  
    dfs(0,-1,0);
 
        return criticals;
        
    }
};
//wangtian