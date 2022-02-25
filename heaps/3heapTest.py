import random
import math

def splitLeaf(heap, n):
    print(heap, n)
    x = math.ceil((n-1)/3)
    print(x)
def main():
    for k in range(20):
        x = random.randint(4,17)
        heap = [] 
        for i in range(x):
            heap.append(i+1)

        splitLeaf(heap, x) 

if __name__ == "__main__":
    main()
