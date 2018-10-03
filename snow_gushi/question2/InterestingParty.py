class InterestingParty():
    def bestInvitation(self, first, second):
        first = list(first)
        second = list(second)
        count_dict = {}
        for f, s in zip(first, second):
            if f not in count_dict:
                count_dict[f] = 1
            else:
                counter = count_dict[f]
                count_dict[f] = counter + 1
            if s not in count_dict:
                count_dict[s] = 1
            else:
                counter = count_dict[s]
                count_dict[s] = counter + 1
        return max(count_dict.values())
