import matplotlib.pyplot as plt
import os
f = open("dane.txt", "r")
i=-1
titles=[4]
t=[]
x=[]
for line in f:
    line=line.strip().split('\t')
    if(i!=-1):
        t.append(float(line[0]))
        x.append(float(line[1]))
    else:
        titles=line
        i+=1
plt.plot(t, x, label="Wykres wychylenia od czasu")
plt.xlabel("Czas")
plt.ylabel("Wychylenie")
plt.legend()
plt.savefig("Wykres_Wychylenia")
os.system(".\Wykres_Wychylenia.png")