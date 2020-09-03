/*
  Find all paths from vertex 'from' to 'to' in a graph
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>

using namespace std;

class Graph
{
private:
  unordered_map<string, vector<string>> edges;
  set<string> vertices;

  void path_util(string from, string to, vector<string> current, vector<vector<string>> &paths)
  {
    // If we have reached 'to' vertex then add current to paths and return
    if (current.size() > 0)
    {
      if (current[current.size() - 1] == to)
      {
        paths.push_back(current);
        return;
      }
    }

    // Start from 'from' and traverse each node
    bool present = false;
    for (int i = 0; i < edges[from].size(); i++)
    {
      // Check if the next node is already a part of solution
      present = false;
      for (int j = 0; j < current.size(); j++)
      {
        if (current[j] == edges[from][i])
          present = true;
      }
      if (present)
        continue;

      // Backtracking
      current.push_back(edges[from][i]);
      path_util(edges[from][i], to, current, paths);
      current.erase(current.end());
    }
  }

public:
  void addEdge(string from, string to, bool directed = false)
  {
    this->vertices.insert(from);
    this->vertices.insert(to);

    this->edges[from].push_back(to);

    if (!directed)
    {
      addEdge(to, from, true);
    }
  }

  void traverse(string from)
  {
    queue<string> pending;
    set<string> discovered, allVertices = this->vertices;
    string to;

    pending.push(from);
    allVertices.erase(from);

    if (this->edges.find(from) == this->edges.end())
    {
      cout << "No vertex named " << from << endl;
      return;
    }

    cout << "Edges in the graph are from --> to" << endl;

    while (!pending.empty())
    {
      from = pending.front();
      pending.pop();

      for (int i = 0; i < this->edges[from].size(); i++)
      {
        to = this->edges[from][i];
        cout << from << " --> " << to << endl;
        if (discovered.find(to) != discovered.end())
        {
          pending.push(to);
          allVertices.erase(to);
        }
      }

      if (!allVertices.empty())
      {
        pending.push(*allVertices.begin());
        allVertices.erase(*allVertices.begin());
      }
    }
  }

  void findAllPathFromTo(string from, string to)
  {
    if (from == to)
    {
      cout << "from and to vertex are same" << endl;
      return;
    }

    vector<vector<string>> paths;
    path_util(from, to, vector<string>({from}), paths);
    if (paths.size() == 0)
    {
      cout << "No path exist from " << from << " to " << to << endl;
      return;
    }
    cout << "All paths from " << from << " to " << to << " are:" << endl;
    for (int i = 0; i < paths.size(); i++)
    {
      cout << paths[i][0] << " ---> " << paths[i][1];
      for (int j = 2; j < paths[i].size(); j++)
      {
        cout << " ---> " << paths[i][j];
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph g;
  g.addEdge("1", "2", true);
  g.addEdge("1", "3");
  g.addEdge("1", "4", true);
  g.addEdge("1", "5", true);
  g.addEdge("2", "6");
  g.addEdge("3", "6", true);
  g.addEdge("3", "4", true);
  g.addEdge("4", "6", true);
  g.addEdge("5", "6", true);
  g.traverse("1");
  g.findAllPathFromTo("1", "6");
}