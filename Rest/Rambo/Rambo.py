import os
import sys

install_path = "/opt/Rambo/Moduls/"
moduls = ["Nmap", "Gobuster", "Bufferoverflow", "Main"]


kod = ""


print("[RAMBO]")

for x in moduls:
    sys.stdout.write("Laduje "+x+"."*(100-len(x)))
    file = open(install_path+x+".py", "r")
    dane = file.read()
    file.close()
    kod = kod + dane;
    print("100%")

os.system("touch Rambo")
file = open("Rambo", "w")
file.write(kod)
file.close()
os.system("python3 Rambo")
os.system("rm Rambo")
