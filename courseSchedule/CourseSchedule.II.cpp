


class Solution {
public:
    // if has cycle, return false, else return true
    bool topologicalSort( int n, vector<int>& explored, vector<int>& path, 
                          unordered_map<int, vector<int>>& graph, 
                          vector<int>& result) 
    {
        
        for(int i=0; i<graph[n].size(); i++) {
            
            int prereq = graph[n][i];
            
            if ( path[prereq] ) {
                result.clear();
                return false;
            }
            
            path[prereq] = true;
            if (!topologicalSort(prereq, explored, path, graph, result)){
                result.clear();
                return false;
            }
            path[prereq] = false;
        }
        if (!explored[n]) {
            result.push_back(n);
        }
        explored[n] = true;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<int> result;
        vector<int> enterance (numCourses, true);
        
        //using map to stroe the graph, it's easy to search the edge for each node
        //the bool in pair means it is explored or not
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].first].push_back( prerequisites[i].second );
            enterance[prerequisites[i].second] = false;
        }

        //explored[] is used to record the node already checked!
        vector<int> explored(numCourses, false);

        //path[] is used to check the cycle during DFS
        vector<int> path(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if (!enterance[i] || explored[i]) continue;
            if (!topologicalSort(i, explored, path, graph, result)) return result;
        }
        //if there has one course hasn't been explored, means there is a cycle
        for (int i=0; i<numCourses; i++){
            if (!explored[i]) return vector<int>();
        }
        return result;
    }
};
