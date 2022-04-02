from graph import Graph

def dfs(G, s): #Graph G and start node s
    
    G.print_graph_list()
    q = []
    q.append(s)
    traverse_dfs(G, s, q)

def traverse_dfs(G, n, q):
    print("q: ", q)
    v = q.pop()
    print("v:", v)
    for e in G.graph_list[v]:
        q.append(e)
    
    

    traverse_dfs(G, n, q)

def bfs(G, s):
    S = []
    s.color = "Grey"
    S.append(s)
    print("S:", [x.val for x in S]) 
    while S != []:
        v = S.pop(0) #remove from list
        print("S.1", [x.val for x in S], "popped:", v.val)
        
        for n in G.graph_list[v.val]:
            
            if n.color == "White":
                print(n.val, n.color)
                n.color = "Grey"
                S.append(n)

        v.color = "Black"
        print(v.val, v.color)
            #S.append(n)
    
    print(S)

def main():

    G = Graph(5)
    G.create_random_graph()
    G.print_graph_list()
    #dfs(G, 0) 
    bfs(G, G.graph_list[0][0]) 

main()
