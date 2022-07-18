import math

def SitoErastotenesa(x):
    tab = []
    for y in range(0, x+1):
        tab.append(0)

    for y in range(2,int(math.sqrt(x))):
        index = y*2
        while(index < x):
            tab[index] = 1
            index += y

    lp = ""
    for y in range(2, x):
        if(tab[y] == 0):
            lp = lp + str(y) + ", "

    return lp



print(SitoErastotenesa(200))
