def sortHelper(e):
    return e[0]/e[1]


def generate_keys(c):
    l = []
    for i in range(0, c):
        l.append((i/c, (i+1)/c))
    return l


def fractional_fit(l):
    # base case
    if len(l) == 0 or len(l) == 1:
        return len(l)
    # sort by value of a/b
    l.sort(key=sortHelper)
    c = 2
    # maximum possible length of outpu will be 18(acc to question)
    while c <= 18:
        # generate keys of ranges for c(eg.for c=2 (0,0.5),(0.5,1.0)
        # c=3 (0.0, 0.3333333333333333), (0.3333333333333333, 0.6666666666666666), (0.6666666666666666, 1.0)
        k = generate_keys(c)
        d = {}
        for i in l:
            fraction = i[0]/i[1]
            for j in k:
                if fraction >= j[0] and fraction < j[1]:
                    d[j] = fraction
        if len(d) != len(k):
            return c-1
        c += 1


l1 = [(6, 12), (0, 5), (5, 7), (4, 11)]
l2 = [(5, 15), (0, 5), (7, 19), (17, 23), (5, 18), (10, 11)]
l3 = [(34, 52), (61, 82), (71, 80), (36, 76),
      (15, 84), (36, 53), (79, 80), (5, 67), (31, 62), (15, 57)]
l4 = [(171, 202), (41, 42), (43, 85), (164, 221), (97, 130), (12, 23), (15, 62), (41, 128),
      (11, 25), (31, 49), (6, 35), (85, 137), (16, 241), (82, 225), (11, 26), (74, 149), (127, 203)]

print(fractional_fit(l4))
