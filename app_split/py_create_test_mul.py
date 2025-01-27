from random import *
sum_size = 1000



with open("input2.txt", "w") as o:
    o.write(str(sum_size)+ " "+str(sum_size)+"\n")
    for i in range(sum_size):
        print(i)
        for ii in range(sum_size):
            o.write(str(choice([0]*1000+[1])) + " ")
        o.write("\n")
    o.write(str(sum_size)+ " "+str(sum_size)+"\n")
    for i in range(sum_size):
        print(i)
        for ii in range(sum_size):
            o.write(str(choice([0]*1000+[1])) + " ")
        o.write("\n")

#1000:2 :1
#1500:7 :3.5
#2000:24:12
#2500:43:21

#50:2
#75:18
#100:32
#n**6
