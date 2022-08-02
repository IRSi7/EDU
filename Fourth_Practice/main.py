import numpy as np
import matplotlib.pyplot as plt
import math
import csv
import random


# Читает выборку
def ReadS():
    with open('Price-Mileage.csv') as csv_file:  # Читаем выборку из файла 0 работы
        s = []
        spam_reader = csv.reader(csv_file, quotechar='|')
        for row in spam_reader:
            x, y = row[0].split(';')
            if y.isdigit() and x.isdigit():
                s.append([int(x), int(y)])
    return s


# Считает выборочное среднее
def find_Xs(s):
    x = 0
    for i in range(n):
        x += s[i]
    return x / len(s)


# Считает дисперсию
def find_Dx(s, x):
    d = 0
    for i in range(n):
        d += (s[i] - x) ** 2
    return d / n


# Возвращает все величины посчитанные в 1 работе
# в принципе можем попробовать прочитать их с Эксельки
def first(s):
    s.sort()  # Используя встроенную функцию сортировки получаем ранжированный ряд

    R = s[len(sample) - 1] - s[0]  # Размах
    print("R =", R)

    k = round(1 + math.log2(len(s)))  # Число интервалов(Формула Стёрджеса)
    print("k = ", k)

    h = round(R / k)  # Длина интервала
    print("h =", h)

    k += 1  # Иначе интервалы не покроют выборку

    x0 = s[0] - h / 2  # Начало первого частичного интервала
    if x0 < 0:
        x0 = 0

    print("x0 =", x0)

    interval = []
    x = x0

    for i in range(k):
        interval.append([(x, x + h), 0, 0])
        x += h

    # Получаем интервальный ряд
    for i in s:
        for j in range(k):
            if interval[j][0][0] < i <= interval[j][0][1]:
                interval[j][1] += 1
                break

    for i in interval:
        i[2] = i[1] / len(sample)

    print(interval)

    middle_int = []
    accum_freq = []
    accum_afreq = []
    accum_freq.append(0)
    accum_afreq.append(0)
    a = 0
    b = 0

    # Вычисляем серидины интервалов и их накопленные частоты
    for i in range(len(interval)):
        a = a + interval[i][2]
        b = b + interval[i][1]
        middle_int.append(interval[i][0][0] + h / 2)
        accum_afreq.append(a)
        accum_freq.append(b)

    C = middle_int[int(k / 2)]  # Число С из теории, h было вычислено ранее при построении интервального ряда
    con_var = []  # Условные варианты

    for i in range(k):
        con_var.append([int((middle_int[i] - C) / h), interval[i][1], interval[i][2]])

    SEM = []  # Выборочные начальные моменты до 4 порядка
    CEM = []  # Выборочные центральные моменты до 4 порядка

    # Вычисляем условные эмп момент 1 порядка
    for i in range(4):
        SEM.append(0)
        for j in range(k):
            SEM[i] += (con_var[j][0] ** (i + 1)) * con_var[j][2]

    CEM.append(0)  # Центральный момент 1 порядка (выборочное среднее для усл вариант)
    CEM.append(SEM[1] - SEM[0] ** 2)  # 2 порядка (выборочная дисперсия для усл вариант)
    CEM.append(SEM[2] - 3 * SEM[1] * SEM[0] + 2 * SEM[0] ** 3)  # 3 порядка
    CEM.append(SEM[3] - 4 * SEM[0] * SEM[3] + 6 * (SEM[0] ** 2) * SEM[3] - 3 * SEM[0] ** 4)  # 4 порядка

    Xs = 0  # Выборочное среднее по обычной формуле
    CXs = 0  # Выборочное среднее через моменты условных вариант
    Ds = 0  # Дисперсия по обычной формуле
    CXs = 0  # Дисперсия через моменты условных вариант

    for i in range(k):
        Xs += middle_int[i] * interval[i][2]

    for i in range(k):
        Ds += (middle_int[i] - Xs) ** 2 * interval[i][2]

    CXs = SEM[0] * h + C  # Из формулы метода упрощённых вычислений
    CDs = CEM[1] * (h ** 2)  # Из формулы метода упрощённых вычислений
    ds = math.sqrt(Ds)  # Выборочное СКО
    cds = math.sqrt(CEM[1])  # Выборочное СКО для усл вариант

    Asym = CEM[2] / (cds ** 3)  # Коэффициэнт ассиметрии для условных вариант (как я понимаю это и есть стат оценка?)
    Excess = CEM[3] / (cds ** 4)  # Коэффициент эксцесса для условных вариант

    sDs = Ds * len(sample) / (len(sample) - 1)  # Исправленная выборочная дисперсия
    so = math.sqrt(sDs)  # Исправленное выборочное СКО

    Mod = 0  # Частость модального интервала
    i0 = 0  # Его номер
    Mod0 = 0  # Истинное значение моды

    for i in range(k):
        if interval[i][1] > Mod:
            Mod = interval[i][1]
            i0 = i

    Mod0 = int(interval[i0][0][0] + h * ((interval[i0][2] - interval[i0 - 1][2]) / (
                (interval[i0][2] - interval[i0 - 1][2]) + (interval[i0][2] - interval[i0 + 1][2]))))

    i0 = 0  # Номер медианного интервала
    Med0 = 0  # Истинное значение медианы

    for i in range(k):
        if accum_afreq[i] > 0.5:
            i0 = i
            break

    px = 0  # Число нужное для линейной интерполяции медианы
    for i in range(i0 - 1):
        px += 1 / interval[i][2]

    # Med0 = interval[i0][0][1] + (h/interval[i0][2])*(0.5 - h*px)
    # При выполнении линейной интерполяции для медианы получилось неадекватно большое отрицательное число
    # Я не знаю с чем это связано поэтому найду её просто как серидину ранжированной ряда

    Med0 = s[int(len(s) / 2)]

    CV = Xs / ds  # Коэффициент вариации

    return (interval, middle_int, Asym, Excess, Mod0, Med0, CV)


sample = ReadS()

n = len(sample)
k = math.ceil(math.sqrt(n / 2))

Xs = find_Xs([sample[i][0] for i in range(n)])  # Выброчное среднее по x
Ys = find_Xs([sample[i][1] for i in range(n)])  # По y

Dsx = find_Dx([sample[i][0] for i in range(n)], Xs)  # Дисперсия по x
Dsy = find_Dx([sample[i][1] for i in range(n)], Ys)  # По y

sx = math.sqrt(find_Dx([sample[i][0] for i in range(n)], Xs))  # CКО по x
sy = math.sqrt(find_Dx([sample[i][1] for i in range(n)], Ys))  # СКО по y

intervalX, middle_intX, AsymX, ExcessX, Mod0X, Med0X, CVX = first([sample[i][0] for i in range(n)])
intervalY, middle_intY, AsymY, ExcessY, Mod0Y, Med0Y, CVY = first([sample[i][1] for i in range(n)])

print(
    f'Параметры выборки по X:\n'
    f'\n\tВыборочное среднее X: {Xs}'
    f'\n\tДисперсия X: {Dsx}'
    f'\n\tСКО X: {sx}'
    f'\n\tАссиметрия X: {AsymX}'
    f'\n\tЭксцес X: {ExcessX}'
    f'\n\tМода X: {Mod0X}'
    f'\n\tМедиана X: {Med0X}'
    f'\n\tКоэф. вариации X: {CVX}')
print(
    f'\nПараметры выборки по Y:\n'
    f'\n\tВыборочное среднее Y: {Ys}'
    f'\n\tДисперсия Y: {Dsy}'
    f'\n\tСКО Y: {sy}'
    f'\n\tАссиметрия Y: {AsymY}'
    f'\n\tЭксцес Y: {ExcessY}'
    f'\n\tМода Y: {Mod0Y}'
    f'\n\tМедиана Y: {Med0Y}'
    f'\n\tКоэф. вариации Y: {CVY}\n')

corr = [[0 for i in range(10)] for i in range(10)]
i = 0
j = 0
l = 0

# Заполняем таблицу ковариации
while i < len(sample):
    while j != 9:
        if intervalX[j][0][0] < sample[i][0] < intervalX[j][0][1]:
            break
        j += 1
    while l != 9:
        if intervalY[l][0][0] < sample[i][1] < intervalY[l][0][1]:
            break
        l += 1
    corr[l][j] += 1
    j = 0
    l = 0
    i += 1

# Mxy
for i in range(10):
    corr[9][i] = sum(map(lambda x: x[i], corr))

# Myx
for i in range(10):
    corr[i][9] = sum(corr[i])

print('\n'.join(map(str, corr)))

# Подсчёт ковариации
Cov = 0
for i in range(9):
    for j in range(9):
        Cov += middle_intX[j] * middle_intX[i] - Xs * Ys

Cov /= len(sample)  # Ковариация
print("Cov = " + str(Cov))

Cov /= sx * sy  # Исправленная ковариация
print("Cov = " + str(Cov))

DsX = 0  # межгрупповое CКО св X
XY = 0  # межгруповое серднее выборочное
for i in range(k):
    Xyi = 0
    for j in range(k):
        XY += corr[i][j] * middle_intX[j] * middle_intY[i]
        Xyi += corr[i][j] * middle_intX[j]
    if corr[i][9] != 0:
        Xyi /= corr[i][9]
    DsX += ((Xyi - Xs) ** 2) * corr[i][9]

XY /= n

r = (XY - Xs * Ys) / (sx * sy)  # Коэффициэнт корреляции
print("Коэф. кореляции r = " + str(r))

# Интервал для 95%
z = 0.5 * math.log((1 + r) / (1 - r))
se = 1 / ((115) ** 0.5)
z_l = z - 2.306 * se
z_u = z + 2.306 * se
z_l = math.tanh(z_l)
z_u = math.tanh(z_u)
print(f'Доверительный интервал для 95% [{z_l};{z_u}]')

# Интервал для 99%
z = 0.5 * math.log((1 + r) / (1 - r))
se = 1 / ((99) ** 0.5)
z_l = z - 3.355 * se
z_u = z + 3.355 * se
z_l = math.tanh(z_l)
z_u = math.tanh(z_u)
print(f'Доверительный интервал для 99% [{z_l};{z_u}]')

# Наблюдаемое значение признака
T_emp = (r * math.sqrt(n - 2)) / math.sqrt(1 - r ** 2)
# Критическое значение признака (табличное)
T_crit = 1.98
print(f'T_emp = {T_emp}')
if abs(T_emp) < T_crit:
    print("H0 верна")
else:
    print("H0 неверна")
