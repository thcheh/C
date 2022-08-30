import matplotlib.pyplot as plt
import os
f = open("dane.txt", "r")
i=-1
titles=[4]
t=[]
a=[]
for line in f:
    line=line.strip().split('\t')
    if(i!=-1):
        t.append(float(line[0]))
        a.append(float(line[3]))
    else:
        titles=line
        i+=1
plt.plot(t, a, label="Wykres przyspieszenia od czasu")
plt.xlabel("Czas")
plt.ylabel("Przyspieszenie")
plt.legend()
plt.savefig("Wykres_Przyspieszenia")
os.system(".\Wykres_Przyspieszenia.png")