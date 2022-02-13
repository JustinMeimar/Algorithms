import math
import sys

def buildMaxHeap(A):
    
    i = math.floor(len(A)/2)

    while i >= -1:  
        maxHeapify(A, i+1)
        i-=1

def getRightChild(A, i):
    end = len(A) -1
    if (2*i) + 2 > end:
        return -1
    return 2*i +2

def getLeftChild(A, i):
    end = len(A) -1
    if (2*i) + 1 > end:
        return -1
    return 2*i + 1

def max_heapify(A, i):
    lc = getLeftChild(A, i)
    rc = getRightChild(A, i)
    largest = i
    length = len(A) 
    if lc > 0 and lc < length and A[lc] > A[i]:
        largest = lc
    if rc > 0 and rc < length and A[rc] > A[largest]:
        largest = rc
    if largest != i:
        temp = A[i]
        A[i] = A[largest]
        A[largest] = temp 
        max_heapify(A, largest)

def isPowerOfTwo(x):
    #use bitwise operations
    r_counter = 0 
    bit_c = 0
    while(r_counter < 31):
        #do 31 bit shifts and comparissons:
        lsbit = (x >> r_counter) & 1
        if lsbit == 1:
            bit_c += 1
        if bit_c > 1:
           return False
        r_counter+= 1
    
    return True

def buildHeap(array, size):
    i = size//2
    while(i >= 0):
        max_heapify(array, i)
        i-=1
            
def printHeap(array):
    powers = 1;
    i = 0; 
    while(i < len(array)):
         
        print(array[i], end=' ')
        #print(isPowerOfTwo(i))
        if isPowerOfTwo(i):
            print("\n")    
        i+=1 
    print() 

def main():
        #    0 1 2 3 4 5 6 7 8 9 10 
    array = [4,1,7,9,3,10,14,8,2,16]
    print("pre-heap", array) 
    buildHeap(array, len(array)) 
    print("post-heap", array) 
     
    

if __name__ == "__main__":
    main()
