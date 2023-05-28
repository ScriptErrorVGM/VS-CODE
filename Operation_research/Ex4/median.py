import PyMDL

nodes = [i for i in range(N)]
locations = {i for i in nodes}
arcs = {(i,j) for i in nodes for j in locations}


p=5

distance = {(i,j):np.hypot(X[i]-X[j],Y[i]-Y[j]) 
            for i in nodes 
            for j in locations}

mdl=Model("Pmedian")

x=mdl.binary_var_dict(arcs, name='x')
y=mdl.binary_var_dict(locations, name='y')

mdl.minimize(mdl.sum(distance[i,j]*x[i,j] 
                     for j in locations
                     for i in nodes))

mdl.add_constraints(mdl.sum(x[i,j] for j in locations)==1
                    for i in nodes)
mdl.add_constraints(mdl.sum(y[j] for j in locations)==p)
mdl.add_constraints(x[i,j]-y[j] <= 0 for i in nodes 
                    for j in locations)
solution = mdl.solve(log_output=True)