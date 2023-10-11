from pulp import *

# Создает список всех узлов снабжения
warehouses = ["A", "B", "C"]

# Создает справочник по количеству единиц снабжения для каждого узла снабжения
supply = {"A": 300, "B": 600, "C":600}

# Создает список всех требуемых узлов
projects = ["1", "2", "3"]

# Создает словарь для количества единиц спроса для каждого узла спроса
demand = {
    "1": 150,
    "2": 450,
    "3": 900,
}

# Создает список затрат по каждому маршруту транспортировки
costs = [  # Проекты
    [5,1,9],  # A   склады
    [4,2,8],  # B
    [8,7,2]   # C
]

# Данные о затратах заносятся в словарь
costs = makeDict([warehouses, projects], costs, 0)

# Создает переменную 'prob', содержащую данные о проблеме
prob = LpProblem("Material Supply Problem", LpMinimize)

# Создает список кортежей, содержащий все возможные маршруты для транспортировки
Routes = [(w, b) for w in warehouses for b in projects]

# Создается словарь под названием "Vars", содержащий переменные, на которые ссылаются (маршруты)
vars = LpVariable.dicts("Route", (warehouses, projects), 0, None, LpInteger)


# Сначала в "prob" добавляется минимальная целевая функция
prob += (
    lpSum([vars[w][b] * costs[w][b] for (w, b) in Routes]),
    "Sum_of_Transporting_Costs",
)


# Ограничения на максимальный объем поставок добавляются в prob для каждого узла снабжения (складов).
for w in warehouses:
    prob += (
        lpSum([vars[w][b] for b in projects]) <= supply[w],
        "Sum_of_Products_out_of_warehouses_%s" % w,
    )

# Ограничения минимального спроса добавляются в prob для каждого узла спроса (проекта)
for b in projects:
    prob += (
        lpSum([vars[w][b] for w in warehouses]) >= demand[b],
        "Sum_of_Products_into_projects%s" % b,
    )

# Проблема решается с помощью выбранного PuLP's solve
prob.solve()

# Выведите оптимизированное значение переменных
for v in prob.variables():
    print(v.name, "=", v.varValue)
    
# Оптимизированное значение целевой функции выводится на экран
print("Value of Objective Function = ", value(prob.objective))
