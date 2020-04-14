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
