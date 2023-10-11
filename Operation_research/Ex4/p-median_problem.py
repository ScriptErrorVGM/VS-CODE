from pulp import *

# Загружка данных из файла
with open("pmedian_data.txt") as file:
    m, n, p = map(int, file.readline().split())
    c = [[int(x) for x in file.readline().split()] for i in range(m)]

# Определитель проблемы
prob = LpProblem("p-median", LpMinimize)

# Определили переменные для принятия решения
x = LpVariable.dicts("x", [(i,j) for i in range(m) for j in range(n)], 0, 1, LpBinary)
y = LpVariable.dicts("y", [j for j in range(n)], 0, 1, LpBinary)

# Определим целевую функцию
prob += lpSum([c[i][j] * x[(i,j)] for i in range(m) for j in range(n)])

# Определим ограничения
for i in range(m):
    prob += lpSum([x[(i,j)] for j in range(n)]) == 1

for i in range(m):
    for j in range(n):
        prob += x[(i,j)] <= y[j]
                 
prob += lpSum([y[j] for j in range(n)]) == p

# Решим задачу, используя алгоритм ветвления и привязки(branch-and-bound algorithm)
prob.solve(PULP_CBC_CMD(gapRel=0.0, threads=1, timeLimit=600)) 

# Результаты вывода
print("Optimal objective value:", value(prob.objective))
for j in range(n):
    if y[j].value() > 0.5:
        print("Facility", j, "is located.")
        for i in range(m):
            if x[(i,j)].value() > 0.5:
                print("- Customer", i, "is served.") 