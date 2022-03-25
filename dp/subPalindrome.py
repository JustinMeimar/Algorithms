#im doing these in python now because I just dont have the time. 
import numpy as np

def long_sub_palindrome(pstr):
    D = []
    for i in range(len(pstr)):
        s_D = []
        for j in range(len(pstr)):
            s_D.append(0)

        D.append(s_D)
    
    i = 1 
    for i in range(len(pstr)-1):
        j = i 
        for j in range(len(pstr)-1):
            
            temp = -1
            if(pstr[i] == pstr[j]):
                temp = D[i+1][j-1] + 2
             
            D[i][j] = max(
                        D[i+1][j],
                        D[i][j-1],
                        temp
                    )
    print_table(D) 

def print_table(D):

    for i in range(len(D)):
        print("")
        for j in range(len(D[i])):
            print(f"{D[i][j]} ", end="") 

def main():

    long_sub_palindrome("peqqde");

main()
