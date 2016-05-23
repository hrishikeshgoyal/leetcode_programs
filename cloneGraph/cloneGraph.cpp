

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        
        //create a map, key is source node, value is clone node.
        map<UndirectedGraphNode*, UndirectedGraphNode*> cloneMap;
        
        //using queue for breadth first search
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        //clone the root
        UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
        cloneMap[node] = cloneNode;
        
        //breadth first search
        while(!q.empty()){
            UndirectedGraphNode* n = q.front();
            q.pop();
            //for each neighbors
            for(int i=0; i<n->neighbors.size(); i++){
                UndirectedGraphNode* neighbor= n->neighbors[i];
                //not existed in cloneMap
                if (cloneMap.find(neighbor)==cloneMap.end()){
                    //clone a node
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(neighbor->label);
                    cloneMap[n]->neighbors.push_back(newNode);
                    cloneMap[neighbor] = newNode;
                    
                    //put the neighbors into the queue
                    q.push(neighbor);
                }else{
                    cloneMap[n]->neighbors.push_back(cloneMap[neighbor]);
                }
            }
        }
        
        return cloneNode;
    }
};
