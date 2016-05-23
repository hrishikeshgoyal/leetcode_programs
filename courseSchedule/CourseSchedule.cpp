


class Solution {
public:

    bool hasCycle(int n, vector<int>& explored, vector<int>& path, map<int, vector<int>>& graph) {
        
        for(int i=0; i<graph[n].size(); i++){
            
            //detect the cycle
            if ( path[graph[n][i]] ) return true;
            
            //set the marker
            path[graph[n][i]] = true;
            
            if (hasCycle(graph[n][i], explored, path, graph)) {
                return true;
            }
            //backtrace reset
            path[graph[n][i]] = false;
        }
        //no cycle found, mark this node can finished!
        explored[n] = true;
        return false;
        
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        //using map to stroe the graph, it's easy to search the edge for each node
        //the bool in pair means it is explored or not
        map<int, vector<int>> graph;
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].first].push_back( prerequisites[i].second );
        }
        
        //explored[] is used to record the node already checked!
        vector<int> explored(numCourses, false);
        
        //path[] is used to check the cycle during DFS
        vector<int> path(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            
            if (explored[i]) continue;
            if (hasCycle(i, explored, path, graph)) return false;
            

        }
        return true;
    }
};
