import itertools

import networkx as nx
import numpy.random as rnd
import matplotlib.pyplot as plt

graph = nx.Graph()

graph

graph.add_node('A')
graph.add_node('B')
graph.add_node('C')

graph.nodes()

def add_edge(f_item, s_item, graph=None):
  graph.add_edge(f_item, s_item)
  graph.add_edge(s_item, f_item) 

add_edge('A', 'B', graph=graph)
add_edge('B', 'C', graph=graph)
add_edge('C', 'D', graph=graph)
add_edge('D', 'C', graph=graph)
add_edge('C', 'A', graph=graph)

nx.draw_circular(graph,
         node_color='red',
         node_size=1000,
         with_labels=True)
plt.show()