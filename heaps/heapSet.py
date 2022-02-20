from buildHeap import buildHeap
from maxHeap import getLeftChild, getRightChild

def heapSetNoExtern(A, x, y, i):
    
    if A[i] < y:
        print(A[i], end=", ")

    lc = 2*i+1 
    rc = 2*i+2

    if lc < size and A[lc] > x:  
        heapSetNoExtern(A, x, y, lc)  
    
    if rc < size and A[rc] > x:
        heapSetNoExtern(A, x, y, rc)

    return 0

def heapSet(A, x, y, i):
   
    #base case
    if i == -1:
        return 0
    
    if A[i] < y:
        print(A[i], end=", ")

    lc = getLeftChild(A, i)
    rc = getRightChild(A, i)
 
    if A[lc] > x:  
        heapSet(A, x, y, lc)  
    
    if A[rc] > x:
        heapSet(A, x, y, rc)

    return 0

def main():
    A = [17,13,15,7,11,2,7,3,4,5,10,1,1,5,6]
    heap = buildHeap(A)
    print(heap)
    heapSet(A, 4, 13, 0) 
    print(" ")
    heapSetNoExtern(A, 4, 13, 0)

if __name__ == "__main__":
    main()
