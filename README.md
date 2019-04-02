# Competitive Programming

Competitive programming is an extreme sport.

- [Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/home)
  - Language(for Human beings): English, Japanese
- [AtCoder](https://atcoder.jp/?lang=en)
  - Language(for Human beings): English, Japanese
- [Codeforces](https://codeforces.com/)
  - Language(for Human beings): English, Russian


## Examples of getting input samples (Python3)

**1行に文字列1つ**

```
S
```

```
s = input()
```

**1行に整数**

```
N
```

```
n = int(input())
```

**1行にスペース区切りで文字列複数**

```
S1 S2
```

```
# 複数の変数に格納
s1, s2 = input().split()

# 1つの配列に格納
s_list = input().split()

# lambda式を使う
I = lambda:input().split()
s1, s2 = I()
s_list = I()
```

**1行にスペース区切りで整数複数**

```
N1 N2
```

```
# 複数の変数に格納
n1, n2 = map(int, input().split())

# 1つの配列に格納
n_list = list(map(int, input().split())) # list()がないとmapオブジェクトが格納される

# lambda式を使う
I = lambda:list(map(int, input().split()))
n1, n2 = I()
n_list = I()
```

**複数(N)行それぞれに整数1つずつ**

```
N
n1
n2
...
nN
```

```
N = int(input())
n = [int(input()) for _ in range(N)]
```

**複数(N)行それぞれにスペース区切りで整数M個ずつ**

```
N M
n11 n12 ... n1M
n21 n22 ... n2M
...
nN1 nN2 ... nNM
```

```
I = lambda:list(map(int, input().split()))
N, M = I()
n = [I() for _ in range(N)]
```
