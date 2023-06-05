import networkx as nx
import matplotlib.pyplot as plt

G=nx.DiGraph()

G.add_nodes_from(["0","1","2","4","5"])

G.add_edges_from([
    ("0","1", {"capacity" : 16}),
    ("0","2", {"capacity" : 13}),
    ("1","2", {"capacity" : 10}),
    ("1","3", {"capacity" : 12}),
    ("2","1", {"capacity" : 4}),
    ("2","4", {"capacity" : 14}),
    ("3","2", {"capacity" : 9}),
    ("3","5", {"capacity" : 20}),
    ("4","3", {"capacity" : 7}),
    ("4","5", {"capacity" : 4})
])

from networkx.algorithms.flow import shortest_augmenting_path
flow_value,flow_dict = nx.maximum_flow(G, "0", "5", flow_func=shortest_augmenting_path)
print(flow_value)
print(flow_dict)

# визуализация ----------------------

pos=nx.spring_layout(G) # pos = nx.nx_agraph.graphviz_layout(G)
nx.draw_networkx(G,pos)
labels = nx.get_edge_attributes(G,'capacity')
nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
plt.savefig('first_flow.png')
plt.show()


#print(flow_dict.keys())
#print(flow_dict.values())
#print(flow_dict.items())

print("----------------------------------------------")
for key,value in flow_dict.items() :

    for i in value :
        
        print(key + " : {" + i + f": {value[i]}" + '}')

        G.add_edge(key,i, capacity = value[i])

pos=nx.spring_layout(G) # pos = nx.nx_agraph.graphviz_layout(G)
nx.draw_networkx(G,pos)
labels = nx.get_edge_attributes(G,'capacity')
nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
plt.savefig('max_flow.png')
plt.show()