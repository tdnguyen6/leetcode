############## ---- Fast IO Functions ---- ##############
from typing import *
from collections import *
import numpy as np
from sortedcontainers import *
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


def minimumTimeRequired(jobs: List[int], k: int) -> int:
    if k == len(jobs):
        return max(jobs)

    work = [0] * k
    ans = int(10e9)
    jobs.sort(reverse=True)

    def backtrack(n=0):
        nonlocal ans
        if n == len(jobs):
            ans = min(ans, max(work))
            return
        v = set()
        for i in range(k):
            if work[i] + jobs[n] < ans and work[i] not in v:
                v.add(work[i])
                work[i] += jobs[n]
                backtrack(n + 1)
                work[i] -= jobs[n]

    backtrack()
    return ans


for _ in range(ii()):
    j = imil()
    k = ii()
    o(minimumTimeRequired(j, k))
