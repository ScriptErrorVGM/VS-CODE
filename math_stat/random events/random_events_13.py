#Число грузовых машин, проезжающих мимо колонки, относится к числу легковых как 3:2. 
#Вероятность того, что грузовая машина будет заправляться, равна 0,1, 
#а того, что будет заправляться легковая 0,2. 
#У бензоколонки заправляется машина. Какова вероятность того, что это грузовая машина?


from func import *

#p1 + p2 = 2a + 3a = 1; a = 1/5 
P1 = 3/5
P2 = 2/5

PA = (P1*0.1)/(P1*0.1 + P2*0.2)
print(PA) 