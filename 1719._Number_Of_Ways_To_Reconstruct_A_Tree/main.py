############## ---- Fast IO Functions ---- ##############
from collections import *
from typing import *
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


def checkWays(pairs: List[List[int]]) -> int:
    adjs = defaultdict(set)
    deg = defaultdict(lambda: 0)
    connected = [[False for _ in range(501)] for _ in range(501)]
    for p in pairs:
        i, j = p[0], p[1]
        adjs[i].add(j)
        adjs[j].add(i)
        deg[i] += 1
        deg[j] += 1
        connected[i][j] = connected[j][i] = True

    vst = defaultdict(lambda: False)
    adj = {}
    root = -1
    for k, v in adjs.items():
        vst[k]
        adj[k] = sorted(v, key=lambda x: deg[x], reverse=True)
        if len(v) == len(adjs) - 1:
            root = k


    if root < 0:
        return 0

    mul = False
    def dfs(i, act):
        nonlocal mul
        if vst[i]:
            return True
        for p in act:
            if not connected[p][i]:
                return False

        vst[i] = True
        act.append(i)
        if i in adj:
            for j in adj[i]:
                if not mul:
                    mul = deg[i] == deg[j]
                if not dfs(j, act):
                    return False

        act.pop()
        return True

    return 1 + int(mul) if dfs(root, []) else 0


for _ in range(ii()):
    L = []
    for _ in range(ii()):
        L.append(imil())
    o(checkWays(L))
