import numpy as np
import matplotlib.pyplot as plt
import math
import csv
import random
from itertools import islice

def calc_distance(coordinate_1, coordinate_2):
    return (coordinate_1[0] - coordinate_2[0]) ** 2 + (coordinate_1[1] - coordinate_2[1]) ** 2

plot_cnt = 0


def recalc_centroids(cluster):
    centroid = []
    temp_1 = 0
    temp_2 = 0
    len_cluster = len(cluster)
    for i in range(len_cluster):
        temp_1 += cluster[i][0]
        temp_2 += cluster[i][1]
    centroid.append(temp_1 / len_cluster)
    centroid.append(temp_2 / len_cluster)
    return centroid


def recalc_medoids(s, clu, medoid):
    m = 10 ** 10
    ans = -1
    for i in range(len(clu)):
        med = medoid
        cluL = clu
        med = s[cluL[i]]
        rang = all_ranges(s, clu, med)
        if rang < m:
            m = rang
            ans = i
    if ans != -1:
        medoid = s[clu[ans]]
    return clu, medoid


def all_ranges(s, clu, medoid):
    ans = 0
    for i in range(len(clu)):
        ans += calc_distance(medoid, s[clu[i]])
    return ans


def calc_distance(coordinate_1, coordinate_2):
    return (coordinate_1[0] - coordinate_2[0]) ** 2 + (coordinate_1[1] - coordinate_2[1]) ** 2


def cluster_index(D, cluster):
    cnt = 0
    D_new = []
    for p in D:
        D_new.append((p[0], p[1], cnt))
        cnt += 1
    def get_index(crd):
        for i in range(len(D_new)):
            if D_new[i][:2] == tuple(crd):
                ret = D_new[i][2]
                D_new.remove(D_new[i])
                return ret
        print(crd)
        raise 'fuck'
    return [get_index(c) for c in cluster]

def k_means(centers, s):
    centers_new = centers
    ku = len(centers)
    for max in range(200):
        thr = []
        clu = []
        clus = []
        for i in range(ku):
            clus.append([])
        
        for point in s:
            distance = []
            min = float('inf')
            l = 0
            for j in range(ku):
                distance.append(calc_distance(centers_new[j], point))
                if distance[j] < min:
                    min = distance[j]
                    l = j
            clus[l].append(point)

        centers_old = centers_new.copy()
        for i in range(ku):
            centers_new[i] = recalc_centroids(clus[i])
        for j in range(ku):
            thr.append(bool(calc_distance(centers_old[j], centers_new[j])))
        
        for l in range(ku):
            clu.append(cluster_index(s, clus[l]))
        if not any(thr):
            break
    return centers_new, clu


def k_meds(meds, s):
    med_new = meds
    ku = len(meds)
    for mx in range(200):
        thr = []
        clu = []
        clus = []
        for i in range(ku):
            clus.append([])

        for point in s:
            distance = []
            min = 1000
            l = 0
            for j in range(ku):
                distance.append(calc_distance(med_new[j], point))
                if distance[j] < min:
                    min = distance[j]
                    l = j
            clus[l].append(point)
        meds_old = med_new.copy()
        for l in range(ku):
            clu.append(cluster_index(s, clus[l]))
        for i in range(ku):
            clu[i], med_new[i] = recalc_medoids(s, clu[i], meds[i])
        for j in range(ku):
            thr.append(calc_distance(meds_old[j], med_new[j]))
        if not any(thr):
            break
    return med_new, clu


def make_plot(centers, sample, clusters):
    mycolors = ['orange', 'black', 'blue', 'green', 'cyan', 'pink', 'brown', 'yellow']
    sample = np.array(sample)
    fig, ax = plt.subplots()
    for i, coordinate in enumerate(centers):
        ax.plot(coordinate[0], coordinate[1], 'r*')
        ax.text(coordinate[0] + 0.1, coordinate[1] - 0.1, 'Center ' + str(i))
    labels_ = ['red'] * len(sample)
    sum =0
    for i in range(len(clusters)):
        for index in range(len(clusters[i])):
            labels_[clusters[i][index]] = mycolors[i]
    # for cluster in clusters:
    #     for index in cluster:
    #         ax.text(D[index, 0] + 0.01, D[index, 1] + 0.1, index)
    scatter = ax.scatter(sample[:, 0], sample[:, 1], s=15, c=labels_, cmap='rainbow')
    legend = ax.legend(*scatter.legend_elements(fmt='Cluster {x:.0f}'), bbox_to_anchor=(1, 0.7))
    ax.add_artist(legend)

    global plot_cnt 
    plt.savefig(f'plt_{plot_cnt}.png')
    plot_cnt += 1
    plt.clf()


def rang_R(point, sam, R):
    clu = []
    for i in sam:
        ze = calc_distance(point, i)
        if ze <= R:
            clu.append(i)
    return clu

def plus_means(ku, sam):
    cens = []
    cens.append(random.choice(sam))       # Центроиды
    def min_range(point, cens, samp):
        mi = 10 * 10
        for i in range(len(cens)):
            ze = calc_distance(point, cens[i])
            if ze < mi:
                mi = ze
                ans = i
        return mi
    while len(cens) < ku:
        summa = 0
        for i in sam:
            summa += (min_range(i, cens, sam))**2
        rand_arg = random.uniform(0.0, 1.0)*summa
        summa = 0
        for i in sample:
            summa += (min_range(i, cens, sam))**2
            if summa >= rand_arg:
                cens.append(i)
                break
    return(cens)



sample = []

with open('Credit.csv', 'r') as csv_file:
    reader = csv.reader(csv_file, delimiter=';')
    sample = [[float(row[0]), float(row[1])] for row in islice(reader, 1, None)]

for i in range(len(sample)):
    sample[i][0] = int(sample[i][0])
    sample[i][1] = int(sample[i][1])

from collections import Counter
counter = Counter(map(tuple, sample))

for i in counter:
    if counter[i] > 1:
        print(i, counter[i])

n = len(sample)
k = math.ceil(math.sqrt(n / 2))

Xs = 0  # Выброчное среднее по x
Ys = 0  # По y

Dsx = 0  # Дисперсия по x
Dsy = 0  # По s

sy = 0  # Исправленное СКО по y
sx = 0  # По x

for i in range(n):
    Xs += sample[i][0]
Xs = Xs / n

for i in range(n):
    Ys += sample[i][1]
Ys = Ys / n

for i in range(n):
    Dsx += (sample[i][0] - Xs) ** 2
Dsx = Dsx / n

for i in range(n):
    Dsy += (sample[i][1] - Ys) ** 2
Dsy = Dsy / n

sx = math.sqrt(Dsx) * n / (n - 1)
sy = math.sqrt(Dsy) * n / (n - 1)

for i in range(n):  # Нормализация точек
    sample[i][0] = (sample[i][0] - Xs) / sx
    sample[i][1] = (sample[i][1] - Ys) / sy

X = [sample[i][0] for i in range(n)]
Y = [sample[i][1] for i in range(n)]

plt.scatter(x=X, y=Y, s=15)
ax = plt.gca()
ax.set(title='Выборка')
#  Добавляем подписи к осям:
ax.set_xlabel('Price')
ax.set_ylabel('Mileage')
plt.savefig(f'plt_{plot_cnt}.png')
plot_cnt += 1
plt.clf()


plt.show()

e = 0.01
means_init = random.sample(sample, k)

U, clusters = k_means(means_init, sample)

print(clusters)

s = set()
for cl in clusters:
    s |= set(cl)

print('AAAAA: ', set(range(len(sample))) - s)


make_plot(U, sample, clusters)

meds_init = random.choices(sample, k = k)
meds_index = []
# for i in range(k):
#     for j in range(len(sample)):
#         if meds_init[i] == sample[j]:
#             meds_index.append(j)
#             break
# samp = sample
# samp = [x for x in samp if x not in meds_init]

meds_init, clusters = k_meds(means_init, sample)
make_plot(meds_init, sample, clusters)

plus_init = plus_means(k, sample)
U, clusters = k_means(means_init, sample)
make_plot(U, sample, clusters)

def silhouette(centers, clus, samp):
    for i in range(len(samp)):
        for j in range(len(clus)):
            for l in range(len(clus[j])):
                if i == clus[j][l]:
                    samp[i].append(j)
                    break
            if len(samp[i]) == 3:
                break

    def min_rang(point, cens, sam):
        mi = 10*10
        for i in range(len(cens)):
            if i != point[2]:
                ze = calc_distance(point, cens[i])
                if ze < mi:
                    mi = ze
                    ans = i
        return ans

    ans = 0
    for i in range(len(samp)):
        a = all_ranges(samp, clus[samp[i][2]], samp[i])
        b = all_ranges(samp, clus[min_rang(samp[i], centers, samp)], samp[i])
        ans += (b-a)/max(a, b)
        samp[i].pop(2)
    return ans

silhous_means = []
silhous_meds = []
silhous_plus = []
for i in range(2, 11):
    means_init = random.sample(sample, i)
    means_init, clusters1 = k_means(means_init, sample)
    clusters1[0].append(1)
    clusters1[0].append(73)
    clusters1[0].append(103)
    silhous_means.append(silhouette(means_init, clusters1, sample))


    meds_init = random.choices(sample, k=i)
    meds_init, clusters2 = k_meds(meds_init, sample)
    clusters2[0].append(1)
    clusters2[0].append(73)
    clusters2[0].append(103)
    silhous_meds.append(silhouette(meds_init, clusters2, sample))

    plus_init = plus_means(k, sample)
    plus_init, clusters3 = k_means(means_init, sample)
    clusters3[0].append(1)
    clusters3[0].append(73)
    clusters3[0].append(103)
    silhous_plus.append(silhouette(plus_init, clusters2, sample))

    # make_plot(means_init, sample, clusters1)
    # make_plot(meds_init, sample, clusters2)

X = [2, 3, 4, 5, 6, 7, 8, 9, 10]
plt.plot(X, silhous_means, color='red')
plt.plot(X, silhous_meds, color='cyan')
plt.plot(X, silhous_plus, color='yellow')
plt.savefig(f'plt_silhouette.png')
plt.clf()

meds_init = random.choices(sample, k=3)
meds_init, clusters2 = k_meds(meds_init, sample)

means_init = random.sample(sample, 3)
means_init, clusters1 = k_means(means_init, sample)

plus_init = plus_means(9, sample)
plus_init, clusters3 = k_means(means_init, sample)

def ranges_clusters(clus, centrs, samp):
    ans = 0
    for i in range(len(clus)):
        ans += all_ranges(samp,clus[i],centrs[i])
    return ans

qual_mean = ranges_clusters(clusters1, means_init, sample)
qual_meds = ranges_clusters(clusters2, meds_init, sample)
qual_plus = ranges_clusters(clusters3, plus_init, sample)

#make_plot(means_init, sample, clusters1)
#make_plot(meds_init, sample, clusters2)

print(f'\nqual_mean = {qual_mean}')
print(f'\nqual_meds = {qual_meds}')
print(f'\nqual_plus = {qual_plus}')

