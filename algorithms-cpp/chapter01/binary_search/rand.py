#!/usr/bin/python

import random

res = set()

for i in range(0, 20):
    res.add(random.randint(0, 100))

lis = [i for i in res]
lis.sort()

for i in lis:
    print i
