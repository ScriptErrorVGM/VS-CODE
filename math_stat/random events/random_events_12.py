#Среди  поступающих  на  склад  деталей  30%  из  цеха  1,  70%  −  из  цеха  2. 
#Вероятность брака для цеха 1 равна 0,02, для цеха 2 – 0,03. 
#Наудачу взятая деталь оказалась доброкачественной. 
#Какова вероятность того, что она изготовлена в цехе 1?

from func import *

PA_1 = 1 - 0.02
PA_2 = 1 - 0.03

PA = (PA_1*0.7)/(PA_1*0.7 + PA_2*0.3)
print(PA)