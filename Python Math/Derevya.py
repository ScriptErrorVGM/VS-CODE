import matplotlib.pyplot as plt
import networkx as nx

def tree(p):
	v = set(map(lambda x: x + 1, range(len(p) + 2)))
	i = 0
	for u in p:
		w = min(v.difference(p[i:-1]))
		v.remove(w)
		yield (u, w)
		i = i + 1
	yield tuple(v)
code = input("Введие код прюфера: ") 
code = list(map(lambda x: int(x), code.split(' ')))
vertices = list(tree(code))

print(vertices)

G = nx.Graph()

for edge in vertices:
	G.add_edge(edge[0], edge[1])
	
subax1 = plt.subplot(221)
nx.draw_spectral(G, with_labels = True)

plt.show()
		
