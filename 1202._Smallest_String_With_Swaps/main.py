############## ---- Fast IO Functions ---- ##############
from typing import List
import io
import os
import sys
i = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def ii():
    return(int(i()))


def iS():
    return i().decode().strip()


def icl():
    s = iS()
    return(list(s[:len(s) - 1]))


def imi():
    return(map(int, i().split()))


def imil():
    return(list(imi()))


def o(w='', end='\n'):
    sys.stdout.write(str(w) + end)

#########################################################


def smallestStringWithSwaps(s: str, pairs: List[List[int]]) -> str:
    if not pairs:
        return s
    l = len(s)
    uf = [-1] * l

    def find(i):
        if uf[i] < 0:
            return i
        else:
            uf[i] = find(uf[i])
            return uf[i]

    # union
    for p in pairs:
        i, j = find(p[0]), find(p[1])
        if i != j:
            if uf[i] > uf[j]:
                i, j = j, i
            uf[i] += uf[j]
            uf[j] = i

    res = list(s)
    sds = {}
    counter = {}
    v = []
    from sortedcontainers import SortedList
    for i in range(len(s)):
        v.append(find(i))
        if v[i] in sds:
            sds[v[i]].add(s[i])
        else:
            sds[v[i]] = SortedList(s[i])
            counter[v[i]] = 0

    for i in range(len(s)):
        sd = sds[v[i]]
        if counter[v[i]] < len(sd):
            res[i] = sd[counter[v[i]]]
            counter[v[i]] += 1
    return ''.join(res)


for _ in range(ii()):
    s = iS()
    p = []
    for _ in range(ii()):
        p.append(imil())
    o(smallestStringWithSwaps(s, p))
