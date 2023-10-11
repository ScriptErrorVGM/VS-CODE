from scipy.optimize import linprog
import numpy as np


obj = [-20,-12,-40,-25]

L_ineq = [[ 1, 1, 1, 1],    #Manpower
          [ 3, 2, 1, 0],    #Material A
          [ 0, 1, 2, 3]]    #Material B

R_ineq = [ 50,  #Manpower
           100, #Material A
           90]  #Material B



opt = linprog(c=obj, A_ub=L_ineq, b_ub=R_ineq,
              method="revised simplex")


print('#1 try ==============================\n')
#print(opt)

print(opt.message)
print(opt.x)
print(opt.slack)
print(opt.fun)


#----------------------------------------------------------------------#

obj = -np.random.randint(10,50, size=3*12)
#print(obj)

L_ineq = np.random.randint(10,size=(12,12*3))       #Manpower
                                                    #Material A
                                                    #Material B
#print(L_ineq)

R_ineq = np.random.randint(100,1000, size=12)  #Manpower
            #Material A
            #Material B
print(R_ineq)


opt = linprog(c=obj, A_ub=L_ineq, b_ub=R_ineq,
              method="revised simplex")

print('#2 try ==============================\n')

print(opt.message)
print(opt.x)
print(opt.slack)
print(opt.fun)
