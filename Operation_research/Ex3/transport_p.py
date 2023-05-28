from pulp import *

# Creates a list of all the supply nodes
warehouses = ["A", "B", "C"]

# Creates a dictionary for the number of units of supply for each supply node
supply = {"A": 300, "B": 600, "C":600}

# Creates a list of all demand nodes
projects = ["1", "2", "3"]

# Creates a dictionary for the number of units of demand for each demand node
demand = {
    "1": 150,
    "2": 450,
    "3": 900,
}

# Creates a list of costs of each transportation path
costs = [  # Projects
    [5,1,9],  # A   warehouses
    [4,2,8],  # B
    [8,7,2]   # C
]

# The cost data is made into a dictionary
costs = makeDict([warehouses, projects], costs, 0)

# Creates the 'prob' variable to contain the problem data
prob = LpProblem("Material Supply Problem", LpMinimize)

# Creates a list of tuples containing all the possible routes for transport
Routes = [(w, b) for w in warehouses for b in projects]

# A dictionary called 'Vars' is created to contain the referenced variables(the routes)
vars = LpVariable.dicts("Route", (warehouses, projects), 0, None, LpInteger)


# The minimum objective function is added to 'prob' first
prob += (
    lpSum([vars[w][b] * costs[w][b] for (w, b) in Routes]),
    "Sum_of_Transporting_Costs",
)


# The supply maximum constraints are added to prob for each supply node (warehouses)
for w in warehouses:
    prob += (
        lpSum([vars[w][b] for b in projects]) <= supply[w],
        "Sum_of_Products_out_of_warehouses_%s" % w,
    )

# The demand minimum constraints are added to prob for each demand node (project)
for b in projects:
    prob += (
        lpSum([vars[w][b] for w in warehouses]) >= demand[b],
        "Sum_of_Products_into_projects%s" % b,
    )

# The problem is solved using PuLP's choice of Solver
prob.solve()

# Print the variables optimized value
for v in prob.variables():
    print(v.name, "=", v.varValue)
    
# The optimised objective function value is printed to the screen
print("Value of Objective Function = ", value(prob.objective))