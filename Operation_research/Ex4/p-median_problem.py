from pulp import *

# Load data
with open("pmedian_data.txt") as file:
    m, n, p = map(int, file.readline().split())
    c = [[int(x) for x in file.readline().split()] for i in range(m)]

# Define the problem
prob = LpProblem("p-median", LpMinimize)

# Define decision variables
x = LpVariable.dicts("x", [(i,j) for i in range(m) for j in range(n)], 0, 1, LpBinary)
y = LpVariable.dicts("y", [j for j in range(n)], 0, 1, LpBinary)

# Define objective function
prob += lpSum([c[i][j] * x[(i,j)] for i in range(m) for j in range(n)])

# Define constraints
for i in range(m):
    prob += lpSum([x[(i,j)] for j in range(n)]) == 1

for i in range(m):
    for j in range(n):
        prob += x[(i,j)] <= y[j]
                 
prob += lpSum([y[j] for j in range(n)]) == p

# Solve the problem using branch-and-bound algorithm
prob.solve(PULP_CBC_CMD(gapRel=0.0, threads=1, timeLimit=600)) 

# Print results
print("Optimal objective value:", value(prob.objective))
for j in range(n):
    if y[j].value() > 0.5:
        print("Facility", j, "is located.")
        for i in range(m):
            if x[(i,j)].value() > 0.5:
                print("- Customer", i, "is served.") 