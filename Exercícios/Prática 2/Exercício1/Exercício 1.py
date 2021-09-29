import math
x1 = 1
x2 = 1
step = 1
while (x1 < 20):
    x1 = x1+step
    y1 = math.exp(x1)
    print(x1,y1)
step = 0.1
while (x2 < 20):
    x2 = x2 + step
    y2 = math.exp(x2)
print(x1 == x2)