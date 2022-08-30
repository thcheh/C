import matplotlib.pyplot as plt
import os
f = open("dane.txt", "r")
i=-1
titles=[4]
t=[]
v=[]
for line in f:
    line=line.strip().split('\t')
    if(i!=-1):
        t.append(float(line[0]))
        v.append(float(line[2]))
    else:
        titles=line
        i+=1
plt.plot(t, v, label="Wykres prędkości od czasu")
plt.xlabel("Czas")
plt.ylabel("Prędkość")
plt.legend()
plt.savefig("Wykres_Prędkości")
os.system(".\Wykres_Prędkości.png")
