from scipy.optimize import linprog	
import time
import numpy as np


start = time.time()
c = [7, 3, 6,4,8,2,1,5,9]
A_ub = [[1,1,1,0,0,0,0,0,0],
               [0,0,0,1,1,1,0,0,0],
               [0,0,0,0,0,0,1,1,1]] 
b_ub = [74,40,36] 
A_eq = [[1,0,0,1,0,0,1,0,0],
               [0,1,0,0,1,0,0,1,0],
               [0,0,1,0,0,1,0,0,1]] 
b_eq = [20,45,30] 
print('fun: ',linprog(c, A_ub, b_ub, A_eq, b_eq).fun) #Стоимость доставки
print('message: ',linprog(c, A_ub, b_ub, A_eq, b_eq).message)
print('nit: ',linprog(c, A_ub, b_ub, A_eq, b_eq).nit)
print('slack: ',linprog(c, A_ub, b_ub, A_eq, b_eq).slack)
print('status: ',linprog(c, A_ub, b_ub, A_eq, b_eq).status)
print('succes: ',linprog(c, A_ub, b_ub, A_eq, b_eq).success)
print('x: ',linprog(c, A_ub, b_ub, A_eq, b_eq).x)

stop = time.time()
print ("Время :")
print(stop - start)

#--------------------------------------------------#

print('\n--------#2--------')

b_ub = [74,40,36] # Запасы
b_eq = [20,45,30] # Спрос
A=np.array([[7,3,6],[4,8,2],[1,5,9]]) #  список стоимости перевозки единицы товара от заказчиков к потребителям
m, n = A.shape
c=list(np.reshape(A,n*m))     # Преобразование матрицы A в список c.
A_ub= np.zeros([m,m*n])
for i in np.arange(0,m,1):    # Заполнение матрицы условий –неравенств.
         for j in np.arange(0,n*m,1):
                  if i*n<=j<=n+i*n-1:
                        A_ub  [i,j]=1
A_eq= np.zeros([m,m*n])
for i in np.arange(0,m,1):    # Заполнение матрицы условий –равенств.
         k=0
         for j in np.arange(0,n*m,1):
                  if j==k*n+i:
                           A_eq [i,j]=1
                           k=k+1

print('fun: ',linprog(c, A_ub, b_ub, A_eq, b_eq).fun) #Стоимость доставки
print('message: ',linprog(c, A_ub, b_ub, A_eq, b_eq).message)
print('nit: ',linprog(c, A_ub, b_ub, A_eq, b_eq).nit)
print('slack: ',linprog(c, A_ub, b_ub, A_eq, b_eq).slack)
print('status: ',linprog(c, A_ub, b_ub, A_eq, b_eq).status)
print('succes: ',linprog(c, A_ub, b_ub, A_eq, b_eq).success)
print('x: ',linprog(c, A_ub, b_ub, A_eq, b_eq).x)


print('\n--------#3--------')

b_ub = np.random.randint(50,100, size=4)  # Запасы
b_eq = np.random.randint(10,50, size=4)   # Спрос
A=np.random.randint(10,size=(4,4))        #  список стоимости перевозки единицы товара от заказчиков к потребителям
print("A : \n",A)
m, n = A.shape
c=list(np.reshape(A,n*m))# Преобразование матрицы A в список c.
A_ub= np.zeros([m,m*n])
for i in np.arange(0,m,1):# Заполнение матрицы условий – неравенств.
         for j in np.arange(0,n*m,1):
                  if i*n<=j<=n+i*n-1:
                        A_ub  [i,j]=1
A_eq= np.zeros([m,m*n])
for i in np.arange(0,m,1):# Заполнение матрицы условий – равенств.
         k=0
         for j in np.arange(0,n*m,1):
                  if j==k*n+i:
                           A_eq [i,j]=1
                           k=k+1

print('fun: ',linprog(c, A_ub, b_ub, A_eq, b_eq).fun) #Стоимость доставки
print('message: ',linprog(c, A_ub, b_ub, A_eq, b_eq).message)
print('nit: ',linprog(c, A_ub, b_ub, A_eq, b_eq).nit)
print('slack: ',linprog(c, A_ub, b_ub, A_eq, b_eq).slack)
print('status: ',linprog(c, A_ub, b_ub, A_eq, b_eq).status)
print('succes: ',linprog(c, A_ub, b_ub, A_eq, b_eq).success)
print('x: ',linprog(c, A_ub, b_ub, A_eq, b_eq).x)