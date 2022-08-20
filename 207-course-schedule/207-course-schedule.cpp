class Solution {
public:
    bool isCycle(int src,vector<int>adj[],vector<bool>&vis,vector<bool>&dfsvis)
    {
        vis[src]=true;
        dfsvis[src]=true;
        for(int child: adj[src])
        {
            if(!vis[child])
            {
                if(isCycle(child,adj,vis,dfsvis))
                    return true;
            }
            else if(dfsvis[child])
                  return true;
        }
        
        dfsvis[src]=false;
        return false;
    }
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            int x=prerequisites[i][0],y=prerequisites[i][1];
            adj[x].push_back(y);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>dfsvis(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(isCycle(i,adj,vis,dfsvis))
                    return false;
            }
        }
        
        return true;
        
    }
};