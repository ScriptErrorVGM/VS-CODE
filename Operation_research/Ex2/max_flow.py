import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import maximum_flow

graph = csr_matrix([[0, 5], [0, 0]])
print(maximum_flow(graph, 0, 1))
print(maximum_flow(graph, 0, 1).flow_value) #5

print(maximum_flow(graph, 0, 1, method='edmonds_karp'))
print(maximum_flow(graph, 0, 1, method='edmonds_karp').flow_value) #5

graph = csr_matrix([[0, 5, 0], [0, 0, 3], [0, 0, 0]])
print(maximum_flow(graph, 0, 2)) 
print(maximum_flow(graph, 0, 2).flow_value) #3


                    #0  #1  #2  #3  #4  #5
graph = csr_matrix([[0, 16, 13,  0,  0,  0],    #0
                    [0,  0, 10, 12,  0,  0],    #1
                    [0,  4,  0,  0, 14,  0],    #2
                    [0,  0,  9,  0,  0, 20],    #3
                    [0,  0,  0,  7,  0,  4],    #4
                    [0,  0,  0,  0,  0,  0]])   #5
print(maximum_flow(graph, 0, 5))
print(maximum_flow(graph, 0, 5).flow_value) #23