from collections import deque

graph = {}

# first degree connections
graph["you"] = ["alice","bob","claire"]

# second degree connections
graph["alice"] = ["peggy"]
graph["bob"] = ["anuj","peggy"]
graph["claire"] = ["thom","jonny"]

# third degree connections
graph["peggy"] = []
graph["anuj"] = []
graph["thom"] = []
graph["jonny"] = []

search_queue = deque()
search_queue += graph["you"]

# name of mango-seller ends with 'm'
def person_is_seller(name):                                                                                                                                                                                                                    
    return name[-1] == 'm'

def search_mango_seller(search_queue,graph):
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if not person in searched:
            searched.append(person)
            if person_is_seller(person):
                print(person + " is a mango seller!")
                return True
            else:
                search_queue += graph[person]

    return False

search_mango_seller(search_queue,graph)