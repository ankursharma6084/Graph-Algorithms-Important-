int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    // Code here

    vector<int> dist(n , 1e9) ;


// why n-1 relaxations bcz longest path is linked list graph 
// whose max length is n-1
// eg ->     1 -> 2 -> 3 -> 4 -> 5 (n = 5 , m = 5-1) ;

    for(int i=1; i<n; i++)
    {
	for(auto &edge : edges)
	{
	    int from = edge[0] , to = edge[1] , wt = edge[2] ;
	    if(dist[from] + wt < dist[to])
	    {
		 dist[to] = dist[from] + wt ;
	    }
	}
    }

for(auto &edge : edges)
{
    int from = edge[0] , to = edge[1] , wt = edge[2] ;
    if(dist[from] + wt < dist[to])
    {
	 return 1 ;
    }
}
    return 0 ;
}


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    
    vector<int> dist(n+1 , 1e9) ;
    dist[src] = 0 ;
    
    // why n-1 bcz longest path is linked list graph 
    // whose max length is n-1
    // eg ->     1 -> 2 -> 3 -> 4 -> 5 (n = 5 , m = 5-1) ;
    
    for(int i=1; i<=n-1; i++)
    {
        for(auto &x: edges)
        {
            int from = x[0] , to = x[1] , wt = x[2] ;
            if(dist[to] > dist[from] + wt)
            {
                dist[to] = dist[from] + wt ;
            }
        }
    }
    
    return dist[dest] ;
    
}
