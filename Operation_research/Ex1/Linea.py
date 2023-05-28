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





