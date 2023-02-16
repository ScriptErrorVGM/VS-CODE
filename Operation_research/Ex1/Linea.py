# from scipy.optimize import linprog

# obj = [-1,-2,3,-1]

# L_ineq = [[ 1, 2, 0, 0],
#           [ 0,-2,-2, 1]]

# R_ineq = [1000, 
#             0]

# L_eq = [[ 1, 0,-3, 0]]
# R_eq = [150]

# bnd = [ (0,100),                #x1
#         (None,1000),            #x2
#         (2,1000),               #x3
#         (0,None)]               #x4

# opt = linprog(c=obj, A_ub=L_ineq, b_ub=R_ineq,
#               A_eq=L_eq, b_eq=R_eq, bounds=bnd,
#               method="simplex")

# print(opt)

from pulp import LpMaximize, LpProblem, LpStatus, lpSum, LpVariable

model = LpProblem(name="small-problem", sense=LpMaximize)

x1 = LpVariable(name="x1", lowBound=0, upBound=100)
x2 = LpVariable(name="x2", upBound=1000)
x3 = LpVariable(name="x3", lowBound=2, upBound=1000)
x4 = LpVariable(name="x4", lowBound=0)

model += (x1 + 2*x2 <= 1000, "first_constraint")
model += (x1 - 3*x3 == 150, "second_constraint")
model += (2*x2 + 2*x3 - x4 >= 0, "third_constraint")

obj_func = x1 + 2*x2 - 3*x3 + x4
model += obj_func

#print(model)

status = model.solve()

print(f"status: {model.status}, {LpStatus[model.status]}")

print(f"objective: {model.objective.value()}")

for var in model.variables():
    print(f"{var.name}: {var.value()}")
    
for name, constraint in model.constraints.items():
    print(f"{name}: {constraint.value()}")





