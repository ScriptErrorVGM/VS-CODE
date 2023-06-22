import numpy as np
from scipy.optimize import linprog

cons = np.random.randint(-1,1, size=(4,9))

sinks = np.random.randint(0,1, size=9)

capacity = np.random.randint(1,5,  size=9)

res = linprog(-sinks, A_eq=cons, 
              b_eq = np.zeros(cons.shape[0]),
                A_ub=np.eye(capacity.size),
                b_ub=capacity)

print(res)
print(res.ineqlin.residual)