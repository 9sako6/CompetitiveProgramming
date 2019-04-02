flag = []

def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    ref_item = arr[0]

    more = []
    less = []
    same = []

    for item in arr:
        if item[1] > ref_item[1]:
            more.append(item)
        elif item[1] < ref_item[1]:
            less.append(item)
        else:
            flag.append(True)
            same.append(item)

    more = quick_sort(more)
    less = quick_sort(less)

    return less + same + more



N = int(input())
cards = [input().split() for _ in range(N)]
sorted_cards = quick_sort(cards)
print('Not stable' if flag else 'Stable')
for card in sorted_cards:
    print(card[0], card[1])
