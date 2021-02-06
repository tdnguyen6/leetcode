import functools
############## ---- Fast IO Functions ---- ##############
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


def solve(*args):
    digits, n = args
    ld = len(digits)
    ln = len(n)
    ld_pow_i = [1] * ln
    for i in range(1, ln):
        ld_pow_i[i] = ld_pow_i[i - 1] * ld

    eq = [False] * ln
    sm = [0] * ln

    for i in range(ln):
        for j in range(ld):
            if n[i] == digits[j]:
                eq[i] = True
            elif n[i] > digits[j]:
                sm[i] += 1

    ans = functools.reduce(
        lambda a, b: a + b, ld_pow_i[1:]) if ln > 1 else 0  # first digit = 0

    for i in range(ln):
        ans += sm[i] * ld_pow_i[-(i + 1)]
        if not eq[i]:
            break
        elif i == ln - 1:
            ans += 1

    return ans


n_test = ii()

for _ in range(n_test):
    digits = list(map(str, i().decode().split()))
    n = iS()
    o(solve(digits, n))
