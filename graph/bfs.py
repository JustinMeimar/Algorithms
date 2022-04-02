
class Graph:
    def __init__(self, v):
        self.v = v

        self.adj = [[] for x in range(0,v)]

    
    def addEdge(self, v1, v2):
    
        self.adj[v1].append(v2)

    def dfs(self, G, s):
        visited = [False for i in range(self.v)] 
        stack = []
        stack.append(s)

        while(len(stack) > 0):
            s = stack[-1]
            stack.pop()

            if not visited[s]:
                print(s, end=" ")
                visited[s] = True

            for n in self.adj[s]:
                if not visited[n]:
                    stack.append(n)



def main():

    G = Graph(6)
    
    G.addEdge(0,2)
    G.addEdge(0,4)
    G.addEdge(2,4)
    G.addEdge(2,3)
    G.addEdge(4,1)
    G.addEdge(1,3)
    G.addEdge(1,5)

    G.dfs(G, 0)

if __name__ == "__main__":

    main()
