import math

def buildMaxHeap(A):
    
    i = math.floor(len(A)/2)

    while i >= -1:  
        maxHeapify(A, i+1)
        i-=1

def getRightChild(A, i):
    end = len(A) -1
    if (2*i) + 1 > end:
        return -1
    return 2*end +1

def getLeftChild(A, i):
    end = len(A) -1
    if (2*i)  > end:
        return -1
    return 2*end

def heapify(A, i):
    print("-"*20)
    print(A)

    lc = getLeftChild(A, i)
    rc = getRightChild(A, i)
    largest = i
    
    if lc > 0 and A[lc] > A[i]:
        largest = lc
    if rc > 0 and A[rc] > A[i]:
        largest = rc

    if largest != i:
        temp = A[i]
        A[i] = A[largest]
        A[largest] = A[i]
        
        heapify(A, largest)

    print(lc, rc)
def main():
    
    array = [4,1,7,9,3,10,14,8,2,16]
    #buildMaxHeap(array)
    i = math.floor(len(array)/2) + 3
    heapify(array, i) 
if __name__ == "__main__":
    main()
