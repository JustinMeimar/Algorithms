#there is nothin especially different about this algorithm compared to conventional quicksort.
#the only difference is that it handles two Arrays of the same size, and sorts one, then the
#other... an effective equivalent could be to call regualr quicksort twice, with two recursive calls
#rather than once with four. Good practice on implementing quick sort in any case. 
def quickJar(A1, A2, l, h):
    
    if l < h: 
      
        j = partition(A1, l, h)
        k = partition(A2, l, h)
        
        quickJar(A1, A2,l, j-1)
        quickJar(A1, A2,j+1, h)
        quickJar(A1, A2,l, k-1)
        quickJar(A1, A2,k+1, h)
       
       
def partition(A, l, h): 
    piv = h
    
    i = l
    j = h-1
    
    while(i <= j):
        
        while(A[i] < A[piv]):
            i+=1
        while(A[j] > A[piv]):
            j-=1 
        if i <= j:
            temp = A[j]
            A[j] = A[i]
            A[i] = temp
 
    temp = A[piv]
    A[piv] = A[i]
    A[i] = temp
    
    return i

def main():
    setJars = [7,6,3,5,1,10,8,2,9,4]
    setLids = [3,4,7,1,9,8,10,6,2,5]
    quickJar(setJars, setLids, 0, 9)
    print(setJars, setLids)

if __name__ == "__main__":
    main()
