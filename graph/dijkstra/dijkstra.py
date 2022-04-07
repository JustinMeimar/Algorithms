import random

class node():
    def __init__(self, v):
        self.v = v
        #self.dist = random.randint(1,10);
        self.dist = 1e10
class minHeap():
    def __init__(self):

        self.heap = []
        self.size = 0

    def heapify(self, i):
        sml = i 
        lc = 2*i+1
        rc = 2*i+2
        if lc < self.size and self.heap[lc].dist < self.heap[sml].dist:
            sml = lc

        if rc < self.size and self.heap[rc].dist < self.heap[sml].dist:
            sml = rc

        if sml != i:
            temp = self.heap[sml]
            self.heap[sml] = self.heap[i]
            self.heap[i] = temp

            self.heapify(sml)
    
    def extractMin(self):
        last = self.size-1
        temp = self.heap[0]
        self.heap[0] = self.heap[last]
        self.heap.pop(last)
        self.size -= 1
        self.heapify(0)
        
        return temp
    
    def decreaseKey(self, old_node, new_node):
        i = self.heap.index(old_node)
        self.heap.pop(i)
        self.insert(new_node) 

    def insert(self, node):
        self.heap.insert(0, node)
        self.size += 1
        self.heapify(0)
        

    def __str__(self):
        chars = ""
        for node in self.heap:
            chars += str([node.v, node.dist])

        return chars

class Graph:
    def __init__(self, V):
        self.V = V
        self.arr = [[] for x in range(1,V)]

    def addEdge(self, n1, n2, w):
        self.arr[n1.v].append([n2, w])

    def __str__(self):
        """ 
        chars = ""
        for i in range(1, self.V):
            chars += str(self.arr[i]) + "\n"

        return chars
        """

if __name__ == "__main__":
    
    G = Graph(5)
    n1 = node(1)
    n2 = node(2)
    n3 = node(3)
    n4 = node(4)
    n5 = node(5)

    G.addEdge(n1, n2, 5)
    G.addEdge(n1, n3, 7)
    G.addEdge(n2, n3, 1)
    G.addEdge(n3, n4, 4)
    G.addEdge(n2, n4, 6)

    print(G)
    
    """
    h = minHeap()
    
    n1 = node(1)
    h.insert(n1) 
    h.insert(node(2))
    h.insert(node(3))
    h.insert(node(4))
    h.insert(node(5))
      
    print(h)


    """

"""
What are the properties of the heap?


                 min
                /  \
              e2    e3
            /  \   /   \ 
          e4   e5 e6   e7

 methods:

    extractmin():
        removes the minimum node (distance)
    
    heapify():
        maintains heap property
           
    decreaseKey():
        updates a element of the queue with a new value

    insert():

    delete():
    
dijkstra specifics:
    each node in the graph has a minimum distance, originiall initialized to -inf
    source node has dist 0, hence is root of heap

    so each node of the heap represents the shortest distance from the source to the node.
    

"""
