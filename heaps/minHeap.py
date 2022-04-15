import random

class minHeap():
    def __init__(self):
        self.heap = [] 
        self.size = 0
     
    # O(logn)
    def minHeapify(self, i):
        
        lc = 2*i+1
        rc = 2*i+2
        s = i

        if lc <= self.size-1  and self.heap[lc] < self.heap[s]:
            
            temp = self.heap[s]
            self.heap[s] = self.heap[lc]
            self.heap[lc] = temp
            
            s = lc

        if rc <= self.size-1 and self.heap[rc] < self.heap[s]:
            
            temp = self.heap[s]
            self.heap[s] = self.heap[rc]
            self.heap[rc] = temp

            s = rc

        if s != i:
            self.minHeapify(s)
    
    # O(logn)
    def insert(self, num):
             
        self.heap.insert(0, num)
        self.size += 1
        self.minHeapify(0)
        print(self.heap)
    
    # O(logn)
    def delete(self, i):
        
        sml = self.heap[self.size-1]
        self.heap.pop() 
        self.size -= 1
        self.heap[i] = sml
        self.minHeapify(i) 
        
        
    # O(logn)
    def extractMin(self):
        
        sml = self.heap[0]
        self.heap[0] = self.heap[self.size-1] 
        self.heap.pop()
        self.minHeapify(0) 
        self.size -= 1

        return sml
    
    def heapSort(self):
        srt = []
        for i in range(0, self.size):
            
            x = self.extractMin()
            print(x, self.heap)
            srt.append(x)

        return srt

    
    def verifyHeap(self):
        i = 0
        for i in range(0, self.size):
            print(self.heap[i])
            
            p = i//2
            if i % 2 == 0 and i != 0:
                p -= 1
            print(i, p)

            if self.heap[p] > self.heap[i]:
                print("heap property BROKEN")

                return False

        return True


    def __str__(self):
        
        return str(self.heap)

def main():
    
    h = minHeap()
    
    
    for i in range(0, 11):
        
        ins = False 
        while not ins:
            x = random.randint(1,25)

            if x not in h.heap:
                h.insert(x)
                ins = True
             

    print(h)
    h.verifyHeap()
    #h.heapSort() 
    #lst = h.heapSort() 
    #print(h, lst)


if __name__ == "__main__":

    main()












