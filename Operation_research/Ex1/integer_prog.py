import numpy as np
#from numpy import random
from scipy.optimize import LinearConstraint
from scipy.optimize import milp
from scipy.optimize import linprog

c = -np.random.randint(10, size=3*12)
#c = -np.array([0, 1])
A = np.random.randint(10,size=(12,12*3))
#A = np.array([[-1, 1], [3, 2], [2, 3]])
b_u = np.random.randint(1000, size=12)
#b_u = np.array([1, 12, 12])
b_l = np.full_like(b_u, -np.inf)

constraints = LinearConstraint(A, b_l, b_u)
integrality = np.ones_like(c)

res = milp(c=c, constraints=constraints, integrality=integrality)
print(res.x)

res = milp(c=c, constraints=constraints)  # OR:
# from scipy.optimize import linprog; res = linprog(c, A, b_u)
print(res.x)

res = linprog(c, A, b_u)
print(res.x)