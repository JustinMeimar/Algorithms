from  maxHeap import max_heapify

def heapSort(A, n):
    hsort = [0 for n in range(0,n)]
    while n > 0:
        print(A[n-1]) 
        hsort[n-1] = A[0]
        A = A[1:] 
        max_heapify(A, 1)
        
        n-=1;

    return hsort

def main():
    
    heap = [17,15,14,12,11,9,8,1,3,4] 
    print(heap)
    hsort = heapSort(heap, 10)
    print(hsort)

if __name__ == "__main__":
    main()
