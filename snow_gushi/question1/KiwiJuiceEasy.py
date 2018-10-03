class KiwiJuiceEasy(object):
    def thePouring(self, capacities, bottles, fromId, toId):
        capacities = list(capacities)
        bottles = list(bottles)
        fromId = list(fromId)
        toId = list(toId)
        for index, each_from_id in enumerate(fromId):
            f = fromId[index]
            t = toId[index]
            space = capacities[t] - bottles[t]

            if ( space >= bottles[f]):
                vol = bottles[f]
                print(vol)
                print(bottles[t])
                bottles[t] += vol
                bottles[f] = 0
            else:
                vol = space
                bottles[t] += vol
                bottles[f] -= vol

        return bottles
