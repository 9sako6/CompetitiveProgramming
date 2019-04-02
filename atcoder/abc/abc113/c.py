n, m = list(map(int, input().split()))
city_dict = {}

for i in range(m):
    p, y = list(map(int, input().split()))
    if city_dict.get(p) == None:
        city_dict[p] = [[y, i]]
    else:
        city_dict[p].append([y, i])

ID = []

for ken, city_and_id in city_dict.items():
    city_and_id.sort()
    for j, city in enumerate(city_and_id):
       num_padded = '%06d' % (j+1)
       ken_padded = '%06d' % ken
       ID.append([str(ken_padded)+str(num_padded), city[1]])

ID = sorted(ID, key=lambda x:x[1])

for city_id in ID:
    print(city_id[0])