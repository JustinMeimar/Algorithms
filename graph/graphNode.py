import random

class queue:
    def __init__(self):
        self.vals = []

    def enqueue(self, x):
        self.vals.append(x)

    def dequeue(self):
        x = self.vals.remove(self.vals[0])

        return x

class graphNode:

    def __init__(self, value):
        
        self.neighbours = []
        self.value = value
    
    
    def __str__(self):

        return str(self.value) 

def bfs(q):
      
    u = q.dequeue()

    while q.vals != []:
        for n in u.neighbours:
            q.enqueue(n)
            print(n)


def main():

    
    nodes = []
    for i in range(0,9):
        x = graphNode(i)
        nodes.append(x)
    
    
    for n in nodes:
        x = random.randint(1,8)
        
        n.neighbours.append(nodes[1:x])
        #print(n, x, n.neighbours)
    
    q = queue()
    q.enqueue(nodes[0])
    bfs(q)
    
    
if __name__ == "__main__":

    main()
