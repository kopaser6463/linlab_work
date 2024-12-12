array = [[1,2,3],[1,2,3]]
arrayb = [[1,2],[3,1],[3,3]]

for i in range(len(array)):
    for ii in range(len(arrayb[0])):
        s = 0
        for j in range(len(array[0])):
            s += array[i][j] * arrayb[j][ii]
        print(s)

import numpy as np
print(np.matmul(np.array(array) , np.array(arrayb)))
