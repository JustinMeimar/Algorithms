from maxHeap import max_heapify
import math

def buildHeap(A):
    #assuming binary heap
    i = len(A)//2
    while(i >= 0):
        max_heapify(A, i) 
        i-= 1
    
    return A

def main():

    A = [15,4,17,2,14,5,7,8,9,12]
    print(A)
    buildHeap(A)
    print(A)

if __name__ == "__main__":
    main()
