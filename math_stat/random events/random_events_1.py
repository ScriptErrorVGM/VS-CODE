#В урне 4 белых и 6 черных шаров. Из урны наудачу извлечены 2 шара. 
#Найти вероятность того, что они разного цвета.

from func import *

N = c_no_r(10,2)
print(N)

mA = 4 * 6 
print(mA)

PA = mA / N
print(PA) 