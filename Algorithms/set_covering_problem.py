states_needed = set(["mt","wa","or","id","nv","ut","ca","az"]) # set cannot have duplicates

stations = {
    "kone" : set(["id","nv","ut"]),
    "ktwo" : set(["wa","id","mt"]),
    "kthree" : set(["or","nv","ca"]),
    "kfour" : set(["nv","ut"]),
    "kfive" : set(["ca","az"])
}

final_stations = set()

while states_needed:

    best_station = None # which covers the most uncovered stations
    states_covered = set()
    for station, states_for_station in stations.items(): # find out the station covering most uncovered stations
        covered = states_needed & states_for_station # intersection -> set of uncovered states that this station covers
        if len(covered) > len(states_covered): # check if this station covers more than the current best station
            best_station = station
            states_covered = covered
    final_stations.add(best_station)
    states_needed = states_needed - states_covered

print(final_stations)