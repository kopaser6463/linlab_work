from random import *
sum_size = 100000000
with open("input.txt", "w") as o:
    s = " ".join([str(randint(0,3)) for i in range(sum_size)])
    o.write("1 "+str(sum_size)+"\n")
    o.write(s)
    o.write("\n")
    o.write("1 "+str(sum_size)+"\n")
    o.write(s)
    o.write("\n")
