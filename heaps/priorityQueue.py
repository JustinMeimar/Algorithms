from maxHeap import max_heapify
from buildHeap import buildHeap
#implement intitialize, insert, maximum, extract maximum, increase key

class priorityQueue:
    def __init__(self, A):
        self.heap = buildHeap(A)

    def maximum(self): 
        return self.heap[0]
        
    def extractMaximum(self):
        A = self.heap
        val = A[0]
        A[0] = A[-1]
        max_heapify(A, 0)
        return val
 
    def increaseKey(self, i, new_key):
        #inverse of maxHeapify
        A = self.heap
        A[i] = new_key

        while(i > 1 and A[i//2] < A[i]):
            temp = A[i]
            A[i] = A[i//2]
            i = (i//2)
        
    
    def insert(self, A, new_key):
        pass
    
    def __str__(self):
        return str(self.heap)

def main(): 

    a = [4,6,15,11,5,17,5,6,13,5,1,12] 
    pq = priorityQueue(a) 
    print(pq.maximum())
    print(pq) 
    mxe = pq.extractMaximum()
    print(mxe)
    print(pq)

if __name__ == "__main__":
    main()
