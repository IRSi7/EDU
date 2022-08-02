from nltk.probability import FreqDist
import matplotlib.pyplot as plt
import math
import csv

sample: list[int] = []

with open('Price-Mileage.csv') as csv_file:  # Читаем выборку из файла 0 работы
    spam_reader = csv.reader(csv_file, quotechar='|')
    for row in spam_reader:
        x, y = row[0].split(';')
        if y.isdigit(): sample.append(int(y))


sample.sort()  # Используя встроенную функцию сортировки получаем ранжированный ряд
print("Ранжированный: ", sample)

abs_frequency = []  # Список с абсолютными частотами
frequency = FreqDist(sample)   # Список с частотами

for i in frequency.values():
    abs_frequency.append(i / len(sample))  # Получаем абс частоты

a = 0   # Счётчик вариант
var_row = {}  # Вариационный ряд

for i in frequency.keys():  # Формируем вариационный ряд в двумерный список
    var_row[i] = [list(frequency.values())[a], abs_frequency[a]]
    a += 1

print("Вариационный ряд: ", var_row)

R = sample[len(sample) - 1] - sample[0]  # Размах
print("R =", R)

k = round(1 + math.log2(len(sample)))  # Число интервалов(Формула Стёрджеса)
print("k = ", k)

h = R / k   # Длина интервала
print("h =", h)

x0 = sample[0] - h / 2   # Начало первого частичного интервала

if x0 < 0:  # Исключение для отрицательной цены
    x0 = 0;
print("x0 =", x0)

row_interval = {}   # Интервальный ряд
for i in range(k + 1):
    counter = 0
    for q in sample:
        if (q <= x0 + ((1 + i) * h)) and (q > x0 + i * h):  # Проверка на попадание в интервал, иначе след итерация
            counter += 1
    row_interval[str(x0 + i * h) + "; " + str(x0 + ((1 + i) * h))] = [counter, counter / len(sample)]  # Запись в список

print("Интервальный ряд: ", row_interval)

cen_interval = [x0 + h / 2 + h * i for i in range(k + 1)]   # Определение центров инт ряда
print("Центры интервального ряда: ", cen_interval)

# Рисуем полигон частот
x = cen_interval
y = [row_interval.get(i)[0] for i in row_interval]
plt.plot(x, y)  # Функция для точек
plt.title("Полигон частот")
plt.savefig("abs_polygon.png")
plt.clf()

# Рисуем полигон относительных частот
y = [row_interval.get(i)[1] for i in row_interval]
plt.plot(x, y)  # Функция для точек
plt.title("Полигон относительных частот")
plt.savefig("otn_polygon.png")
plt.clf()

# Рисуем гистограмму частот
x = [x0 + i * h + h / 2 for i in range(k + 1)]
y = [row_interval.get(i)[0] for i in row_interval]
plt.bar(x, y, width=h)  # Функция для столбцов
plt.title("Гистограмма частот")
plt.savefig("abs_fr_bar_graph.png")
plt.clf()

# Рисуем гистограмму относительных частот
y = [row_interval.get(i)[1] for i in row_interval]
plt.bar(x, y, width=h)  # Функция для столбцов
plt.title("Гистограмма относительных частот")
plt.savefig("otn_fr_bar_graph.png")
plt.clf()

FnX = []
FnX_main = []
q = 0
for i in [row_interval.get(i_tmp)[1] for i_tmp in row_interval]:
    q += i
    FnX.append(round(q, 2))
for i in [row_interval.get(i_tmp)[0] for i_tmp in row_interval]:
    q += i
    FnX_main.append(round(q, 2))
X = []
Y = FnX
U = []
V = FnX
for i in range(k + 1):
    U.append(x0 + h * i)
    X.append(x0 + h * i + h)
plt.quiver(X, Y, -h, 0, angles='xy', scale_units='xy', scale=1, color='b')
plt.title("Эмпирическая функция распределения относительных частот")
plt.xlim(-2000, 250000)
plt.savefig("emp_func_otn.png")
plt.clf()

Y = FnX_main
V = FnX_main
plt.quiver(X, Y, -h, 0, angles='xy', scale_units='xy', scale=1, color='b')
plt.title("Эмпирическая функция распределения частот")
plt.xlim(-2000, 250000)
plt.savefig("emp_func.png")
plt.clf()

plt.plot(cen_interval, FnX_main)
plt.title("Кумулята частот")
plt.savefig("cum.png")
plt.clf()

plt.plot(cen_interval, FnX)
plt.title("Кумулята относительных частот")
plt.savefig("cum_otn.png")
plt.clf()