#define vi vector<int>
void dfs(int root,vi adj[], int &timer, vi &in , vi &low, vector<vi> &bridges , int par)
{
      in[root] = low[root] = timer++ ;
      
      for(auto &nbr : adj[root])
      {
          // if parent edge then just continue
          if(nbr == par) continue;
          // nbr is not visited condn if(in[nbr] == 0)
          else if(in[nbr] == 0)
          {
              // first do normal dfs so that we get in and low time of nbr nodes
              dfs(nbr , adj , timer , in , low , bridges , root) ;
              // low time of nbr is > in time of root means 
              // of all discovery paths from backedges , there was no backkedge 
              // which could reduce low of nbr so there iis a bridge
              if(low[nbr] > in[root])
              {
                  if(root > nbr)
                      bridges.push_back({nbr , root}) ;
                  else bridges.push_back({root , nbr}) ;
              }
              // here it is low bcz it is not first backedge and it got its low from 
              // somewhere else not its nbr
              low[root] = min(low[root] , low[nbr]) ;
          }
          
          else{
              // here backedge is there so we update low[root] to in[nbr]
              // here it is in bcz it is first backedge
              low[root] = min(low[root] , in[nbr]) ;
          }

      }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int e) {
    // Write your code here
    
    vector<int> inTime(n , 0) , lowTime(n , 0) ;
    int timer = 1 ;
    vector<vector<int>> bridges ;
    
    vector<int> adjList[n];
    for(auto &edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    
    dfs(0 , adjList , timer , inTime , lowTime, bridges , -1) ;
    sort(begin(bridges) , end(bridges)) ;
    
    return bridges ;
    
}
