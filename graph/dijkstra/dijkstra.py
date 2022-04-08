import random


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
    
    def returnNodeIndex(self, node):
        i = self.heap.index(node)
        return i

    def decreaseKey(self, n, val):
        """
         i = self.heap.index(old_node)   #where is node_to_be updated
        node = self.heap[i]             #get node
        node.dist = val                 #update
        self.heap.pop(i)                #remove old node
        self.insert(node)
        """
        i = self.heap.index(n)
        new_node = self.heap[i]
        new_node.dist = val
        self.heap.remove(n)
        self.size -= 1

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

class node():
    def __init__(self, v):
        self.v = v
        #self.dist = random.randint(1,10);
        self.dist = 1e10

class Graph:
    def __init__(self, V):
        self.V = V
        self.arr = [[] for x in range(1,V+1)]
        self.nodes = []
    
    def addEdge(self, n1, n2, w):
       
        if n1 not in self.nodes:
            self.nodes.append(n1)
        
        if n2 not in self.nodes:
            self.nodes.append(n2)
        
        self.arr[n1.v-1].append([n2, w])
        self.arr[n2.v-1].append([n1, w])
    
    def dijkstra(self, src):
        #initialize all nodes into a priority queue (min-heap) and remove the source node

        dist_table = {}        
        src.dist = 0

        Q = minHeap()
        for n in self.nodes:
            Q.insert(n)
        
        while Q.size != 0:
            src = Q.extractMin()
           
            for e in self.arr[src.v-1]:
                w = e[1] #weight of edge
                tar_node = e[0]
                if tar_node.dist > src.dist + w:
                    
                    Q.decreaseKey(e[0], e[1] + src.dist) 
                    dist_table[e[0].v] = e[1] + src.dist 
 
        print("Shortest Distance for Each Vertex: \n", dist_table)     
        #find neighbours of src
        

    def __str__(self):
        
        chars = ""
        for i in range(1, self.V+1):
            chars += f"\n {i}: "
            for obj in self.arr[i-1]:
                chars += "{ " + str(obj[0].v) + ", " + str(obj[1]) + " }  " 
        return chars
        

if __name__ == "__main__":
    
    
    
    G = Graph(5)

    n1 = node(1)
    n2 = node(2)
    n3 = node(3)
    n4 = node(4)
    n5 = node(5)

    G.addEdge(n1, n2, 5) # 1 -- 2  w = 5
    G.addEdge(n1, n3, 7) # 1 -- 3  w = 7
    G.addEdge(n2, n3, 1) # 2 -- 3  w = 1
    G.addEdge(n3, n4, 4) # 3 -- 4  w = 4
    G.addEdge(n2, n4, 6) # 2 -- 4  w = 6
    G.addEdge(n4, n5, 3) # 4 -- 5  w = 3
    
    #adjacency list established 
    print(G)
    src = n1
    G.dijkstra(n1)
    
    

    # h = minHeap()
    
    # n1 = node(1)
    # h.insert(n1) 
    
    # n2 = node(2)
    # h.insert(n2)

    # n3 = node(4)
    # h.insert(n3)

    # h.insert(node(4))
    # n5 = node(5)
    
    # h.insert(n5)
    # print(h, h.size)
    # h.decreaseKey(n3, 1) 


    # h.decreaseKey(n1, 6) 
    # h.decreaseKey(n5, 7)
    # h.decreaseKey(n2, 4)
    # print(h, h.size)

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
