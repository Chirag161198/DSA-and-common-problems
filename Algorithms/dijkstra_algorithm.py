# Three hash tables required
# 1. Graph
# 2. Costs
# 3. Path/Parent Node

graph = {
    "start":{
        "a":6,
        "b":2
    },
    "a":{
        "finish":1
    },
    "b":{
        "a":3,
        "finish":5
    },
    "finish":{}
}
# print(graph)

inf = float("inf")
costs = {
    "a": 6,
    "b": 2,
    "finish": inf
}
# print(costs)

parent = {
    "a" : "start",
    "b" : "start",
    "finish" : None
}
# print(parent)

processed = []

def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs.keys():
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node


node = find_lowest_cost_node(costs) # Find the lowest cost node that hasn't been processed
while node is not None: # If you have processed the while loop is done
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys(): # Go through all its neighbors
        new_cost = cost + neighbors[n] 
        if costs[n] > new_cost: # Update if cheaper
            costs[n] = new_cost
            parent[n] = node
    processed.append(node) # Mark the node processed
    node = find_lowest_cost_node(costs) # Repeat

print('Shortest path to finish: ' + str(costs["finish"]))

print("The path: ", end='')
path = " finish"
node = "finish"
while node!="start":
    path = " " + parent[node] + path
    node = parent[node]
print(path)