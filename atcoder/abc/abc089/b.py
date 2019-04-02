n = int(input())

S = list(input().split())

print('Four' if len(set(S)) == 4 else 'Three')  
