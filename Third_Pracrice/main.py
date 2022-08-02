# import numpy as np
# from nltk.probability import FreqDist
# import matplotlib.pyplot as plt
import math
import csv
# import scipy
import random
# from openpyxl import Workbook
# from openpyxl.drawing.image import Image

sample = []

with open('Price-Mileage.csv') as csv_file:  # Читаем выборку из файла 0 работы
    spam_reader = csv.reader(csv_file, quotechar='|')
    for row in spam_reader:
        x, y = row[0].split(';')
        if y.isdigit(): sample.append(int(y))

sample.sort()  # Используя встроенную функцию сортировки получаем ранжированный ряд

R = sample[len(sample) - 1] - sample[0]  # Размах
print("R =", R)

k = round(1 + math.log2(len(sample)))  # Число интервалов(Формула Стёрджеса)
print("k = ", k)

h = round(R / k)  # Длина интервала
print("h =", h)

k += 1  # Иначе интервалы не покроют выборку

x0 = sample[0] - h / 2  # Начало первого частичного интервала
if x0 < 0:
    x0 = 0

print("x0 =", x0)

interval = []
x = x0

for i in range(k):
    interval.append([(x, x + h), 0, 0])
    x += h

# Получаем интервальный ряд
for i in sample:
    for j in range(k):
        if interval[j][0][0] < i <= interval[j][0][1]:
            interval[j][1] += 1
            break

for i in interval:
    i[2] = i[1] / len(sample)

print(interval)

middle_int = []

# Вычисляем серидины интервалов
for i in range(len(interval)):
    middle_int.append(interval[i][0][0] + h / 2)

n = len(sample)

Xs = 0  # Выброчное среднее по x

Dsx = 0  # Дисперсия по x

s = 0  # СКО по x

for i in range(n):
    Xs += sample[i]
Xs = Xs / n

for i in range(n):
    Dsx += (sample[i] - Xs) ** 2
Dsx = Dsx / n
d = math.sqrt(Dsx)
s = math.sqrt(Dsx) * n / (n - 1)

TY1 = 1.981      # t гамма для 95% n = 115
TY2 = 2.62       # t гамма для 99% n = 115
D1 = TY1*s/math.sqrt(n)
D2 = TY2*s/math.sqrt(n)
LB = Xs - D1
RB = Xs + D1
LB2 = Xs - D2
RB2 = Xs + D2
Q1 = 0.143      # q для n=100 95%
Q2 = 0.198      # q для n=100 99%

SLB1 = s - s*Q1
SRB1 = s + s*Q1
SLB2 = s - s*Q2
SRB2 = s + s*Q2

# Пункт 3

laplas_arg = []
for i in range(8):
    laplas_arg.append((interval[i][0][1]-Xs)/d)

laplas = [-0.5, -0.2224, 0.0040, 0.2823, 0.4279, 0.4838, 0.4976, 0.4998, 0.499986, 0.5]
p = []      # Исправленные частоты
for i in range(k):
    p.append(laplas[i + 1] - laplas[i])

m = []      # m'
for i in range(k):
    if(p[i]*115 > 0.00005):
        m.append(p[i]*115)

sumat = sum(m)

m2 = []      # (m-m')/m'
for i in range(len(m)):
    m2.append(((interval[i][1]-m[i])**2)/m[i])

ans = sum(m2)       # Последнее слагаемое в сумме равно 620, за счёт деления 1 на число близкое к 0
Xi2 = 12.6
print(ans)
print(f'Хи2 набл = {ans}')
print(f'Xs = {Xs}')
print(f'Ds = {s}')
print(f'e1 = {D1}')
print(f'Xs  [{LB};{RB}]')
print(f'e2 = {D2}')
print(f'Xs  [{LB2};{RB2}]')
print(f'q для n=100 95% {Q1}')
print(f'q для n=100 99% {Q2}')
print(f'S 95% [{SLB1};{SRB1}]')
print(f'S 99% [{SLB2};{SRB2}]')
print(f'pi[{p}]')
print(f'm[{m}]')
print(sum(p))

