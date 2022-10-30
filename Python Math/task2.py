from time import sleep

def prufer(vertices, edges):
    v = vertices[:]
    e = edges[:]
    code = []
    max_leaf = len(v)
    while len(v) > 2:
        #sleep(2)
        #print(f"code: {code}")
        # Choosing leaf u with min number.
        for i in map(lambda x: x + 1, list(range(max_leaf))):
            #print(f"    i? {i}")
            if i in v:
                #print(f"i: {i}")
                # leaf check.
                neighbors = 0
                vertex_to_add = ''
                edge_to_remove_index = 0
                for k, edge in enumerate(e):
                    if str(i) in edge:
                        #print(f"edge: {edge}")
                        neighbors += 1
                        vertex_to_add = edge[0] if edge[0] != str(i) else edge[1]
                        #print(f"k:{k}")
                        edge_to_remove_index = k
                if neighbors <= 1:
                    # Found the min leaf.
                    code.append(vertex_to_add)
                    #print(f"rm edge: {e[edge_to_remove_index]}")
                    del e[edge_to_remove_index]
                    v.remove(i)
                    #print(f"v-left: {v}")
                    #print(f"e-left: {e}")
                    break
    return code


vertices = list(range(int(input("Введите количество вершин: ")))) # list(map(lambda x: x + 1, range(6)))
edges = list(input("Введите рёбра: ").split(" ")) # ['21', '14', '54', '65', '53']

print(prufer(vertices, edges))
