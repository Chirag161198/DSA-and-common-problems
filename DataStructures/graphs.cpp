#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<queue>
#include<set>

using namespace std;

struct edgeNode{
    string label; // to-label
    float weight; // weight associated to (x,y) edge
    edgeNode* next; // next edge
};

class Graph{
    private:
        unordered_map <string, edgeNode*> map;
        unordered_map <string, int> degree;
        set <string> uniqueVertices;

        const string undiscovered = "undiscovered";
        const string discovered = "discovered";
        const string processed = "processed";

    public: 
        
        void insertEdgeNode(string fromLabel, string toLabel, float weight, bool directed){
            edgeNode * headOfFrom = map[fromLabel];
            edgeNode * node = new edgeNode({toLabel, weight, headOfFrom});
            map[fromLabel] = node;
            uniqueVertices.insert(fromLabel);
            uniqueVertices.insert(toLabel);
            
            if(!directed) insertEdgeNode(toLabel, fromLabel, weight, true);
            else {
                degree[fromLabel]++;
                degree[toLabel]++;
            }
        }

        void printGraph(){
            edgeNode * temp;
            for(auto it : map){
                cout<<it.first<<" connect to ";
                temp = it.second;
                while(temp!=NULL){
                    cout<<"("<<temp->label<<", "<<temp->weight<<") ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }

        int getEdgeWeight(string fromLabel, string toLabel){
            if(checkEdgeExist(fromLabel, toLabel)){
                edgeNode * head = map[fromLabel];
                while(head!=NULL){
                    if(head->label==toLabel) return head->weight;
                    head = head->next;
                }
            }
            else{
                return -1;
            }
        }

        set <string> getUniqueVertices(){
            return uniqueVertices;
        }

        bool checkEdgeExist(string fromLabel, string toLabel){
            edgeNode* head = map[fromLabel];
            
            while(head!=NULL){
                if(head->label==toLabel)
                    return true;
            }
            
            return false;
        }

        bool removeEdge(string fromLabel, string toLabel){
            if(checkEdgeExist(fromLabel, toLabel)){
                edgeNode * head = map[fromLabel];
                if(head->label==toLabel){
                    map.erase(fromLabel);
                } else {
                    while(head->next->label!=toLabel){
                        head = head->next;
                    }
                    head->next = head->next->next;
                }
                return true;
            }
            return false;
        }
        
        unordered_map <string, string> bfs(string startNode){
            edgeNode * temp;
            
            /*
            parent : <child vertex, parent vertex>
            status : <vertex, status>
            */
            unordered_map <string, string> status, parent;

            queue <string> q;
            string currentVertex;
            q.push(startNode);

            for(auto vertex: uniqueVertices){
                status[vertex] = undiscovered;
                parent[vertex] = "";
            }
            status[startNode] = discovered;

            while(!q.empty()){
                currentVertex = q.front();
                q.pop();

                temp = map[currentVertex];
                while(temp!=NULL){
                    if(status[temp->label]==undiscovered){
                        q.push(temp->label);
                        status[temp->label] = discovered;
                        parent[temp->label] = currentVertex;
                    }                    
                    temp = temp->next;
                }

                status[currentVertex] = processed;
            }
            return parent;
        }

        void dfs_util(
            string currentVertex, 
            unordered_map <string, string> & status, 
            unordered_map <string, string> & parent, 
            unordered_map <string, int> & entryTime,
            unordered_map <string, int> & exitTime,
            int & currentTime){
            
            edgeNode* temp;

            status[currentVertex] = discovered;
            entryTime[currentVertex] = currentTime;
            currentTime++;

            temp = map[currentVertex];
            while(temp!=NULL){
                if(status[temp->label]!=discovered){
                    parent[temp->label] = currentVertex;
                    dfs_util(
                        temp->label, status, parent, entryTime, exitTime, currentTime
                    );
                }                    
                temp = temp->next;
            }
            exitTime[currentVertex] = currentTime;
            currentTime++;
        }

        unordered_map <string, string> dfs(string fromLabel){
            cout<<"Called"<<endl;
            /*
            parent : <child vertex, parent vertex>
            status : <vertex, status>
            */
            unordered_map <string, string> status, parent;
            unordered_map <string, int> entryTime, exitTime;
            int time = 0;

            parent[fromLabel] = "";
            dfs_util(
                fromLabel, status, parent, entryTime, exitTime, time
            );
            return parent;
        }

        int numberOfEdges(string fromLabel, string toLabel){
            unordered_map <string, string> parent = bfs(fromLabel);
            string currentVertex = toLabel;
            int edges = 0;
            while(currentVertex!=fromLabel){
                currentVertex = parent[currentVertex];
                edges++;
                if(currentVertex=="") return -1;
            }
            return edges;
        }
};

int main(){
    Graph graph = Graph();
    
    graph.insertEdgeNode("A", "B", 1, false);
    graph.insertEdgeNode("A", "C", 2, true);
    graph.insertEdgeNode("C", "D", 3, true);
    graph.insertEdgeNode("D", "E", 4, false);
    
    
    //graph.printGraph();

    //graph.removeEdge("B","A");

    //cout<<"Weight from C to D = "<<graph.getEdgeWeight("C", "D")<<endl;

    unordered_map <string, string> parent = graph.bfs("A");
    cout<<"BFS (Parent ---> Child):"<<endl;
    for(auto it : parent){
        if(it.second!=""){
            cout<<it.second<<" ---> "<<it.first<<endl;
        }
    }

    parent = graph.dfs("A");
    cout<<"DFS (Parent ---> Child):"<<endl;
    for(auto it : parent){
        if(it.second!=""){
            cout<<it.second<<" ---> "<<it.first<<endl;
        }
    }

    cout<<"egdes from A to E: "<<graph.numberOfEdges("A","E");
}