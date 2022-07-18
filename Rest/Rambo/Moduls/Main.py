import os

os.system("clear")

while(True):
    command = input("-> ")
    if(command == "bufferoverflow"):
        __bufferoverflow__()
    elif(command == "exit"):
        exit(0)
    else:
        os.system(command)
