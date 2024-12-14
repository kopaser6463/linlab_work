import numpy as np
from random import random, randint, seed
seed(6)

array = [[1,0,0],[0,0,3]]
arrayb = [[0,2],[0,1],[0,4]]

for i in range(len(array)):
    for ii in range(len(arrayb[0])):
        s = 0
        for j in range(len(array[0])):
            s += array[i][j] * arrayb[j][ii]
        #print(s)

import numpy as np

np.array(array) , np.array(arrayb)

class vay:
    def __init__(self):
        self.values = []
        self.row = []
        self.col = []
        self.n = 0
        self.m = 0

    def conv(self, mat):
        self.n = len(mat)
        self.m = len(mat[0])
        for i in range(len(mat)):
            for ii in range(len(mat[0])):
                if mat[i][ii] != 0:
                    self.values.append(mat[i][ii])
                    self.row.append(i)
                    self.col.append(ii)
    def by_index(self, x,y):
        for i in range(len(self.values)):
            if self.row[i] == x and self.col[i] == y:
                return self.values[i]
        return 0
    def light(self):
        s = 0
        for i in range(self.values):
            if self.row[i] == self.col[i]:
                s+=self.values[i]
        return s
    def output(self):
        print("value :" + " ".join(map(str, map(int, self.values))))
        print("row   :" + " ".join(map(str, map(int, self.row))))
        print("col   :" + " ".join(map(str, map(int, self.col))))
        print("rows: " + str(self.n) + " cols: " + str(self.m))
def gen_sparce(a,b,percentage):
    arr = np.zeros([a,b])
    for i in range(a):
        for ii in range(b):
            if random() < percentage:
                arr[i][ii] = randint(0,10)

    return arr.astype(int)
array = gen_sparce(5,5,0.6)
arrayb = gen_sparce(5,5,0.1)

array = np.array([[2, 0, 3], [0, 0, 0], [0, 7, 0]])
arrayb = np.array([[0, 9, 2], [4, 0, 3], [0, 0, 0]])

v1 = vay()
v2 = vay()
v1.conv(array)
v2.conv(arrayb)
print(np.matmul(np.array(array) , np.array(arrayb)))

if 1:
    for i in range(len(v1.values)):
        x = v1.row[i]
        for ii in range(v2.n):
            #print(v2.by_index(x,ii))
            if v2.by_index(v1.col[i],ii) != 0:
                #print(v1.by_index(x,v1.col[i]), x, v1.col[i])
                #print(v2.by_index(v1.col[i],ii), v1.col[i], ii)
                s = v1.by_index(x,v1.col[i]) * v2.by_index(v1.col[i],ii)
                print(s,x, ii)
                     #v r  c
            #YOU NEED TO SUM THEM IF THEY HAVE SAME INDEXES
            #WHICH I DID NOT MADE BECOUSE I AM LAZY

if 0:
    for i in range(len(v1.values)):
        x = v1.row[i]
        for ii in range(v2.n):
            if v2.by_index(v1.col[i],ii) != 0:
                s = v1.by_index(x,v1.col[i]) * v2.by_index(v1.col[i],ii)
                print(s,x, ii)
