import random
class Node:

    def __init__(self, val):

        self.val = val
        self.color = "White" 
    
    

class Graph:

    def __init__(self, v):
        
        self.time = 0
        self.trvsl_arr = []
        self.v = v
        self.e = 7

        self.graph_list = [[] for x in range(v)]
        self.graph_matrix = [[0 for y in range(v)] for x in range(v)] 

    def create_random_graph(self):

        for i in range(self.e):
            src = Node(random.randrange(0, self.v))
            dest = Node(random.randrange(0, self.v))
            
            #no self loops or double edges
            if dest.val in [x.val for x in self.graph_list[src.val]] or dest.val == src.val:
                while dest.val in [x.val for x in self.graph_list[src.val]] or dest.val == src.val:
                    src = Node(random.randrange(0, self.v))
                    dest = Node(random.randrange(0, self.v))

            while src.val == dest.val and self.graph_matrix[src.val][dest.val] == 1:
                src = Node(random.randrange(0, self.v))
                dest = Node(random.randrange(0, self.v))
     

            self.graph_list[src.val].append(dest)
            self.graph_matrix[src.val][dest.val] = 1

    def print_graph_list(self):
        for i in range(self.v):
            print(i, "-->", [x.val for x in self.graph_list[i]])
        print()
    

if __name__ == "__main__":

    g = Graph(6)
    g.create_random_graph()
    g.print_graph_list()
