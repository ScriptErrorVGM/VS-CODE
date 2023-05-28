from scipy.optimize import linprog

obj = [-1,-2,3,-1]

L_ineq = [[ 1, 2, 0, 0],
           [ 0,-2,-2, 1]]

R_ineq = [1000, 
             0]

L_eq = [[ 1, 0,-3, 0]]
R_eq = [150]

bnd = [ (0,100),                #x1
         (None,1000),            #x2
         (2,1000),               #x3
        (0,None)]               #x4

opt = linprog(c=obj, A_ub=L_ineq, b_ub=R_ineq,
             A_eq=L_eq, b_eq=R_eq, bounds=bnd,
              method="simplex")

print(opt)