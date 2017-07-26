def calc(matriz, fim):
    for i in range(fim - 2, -1, -1):
        for j in range(i + 1):
            if matriz[i + 1][j] > matriz[i+1][j+1]:
                matriz[i][j] += matriz[i + 1][j]
            else:
                matriz[i][j] += matriz[i + 1][j + 1]
    return matriz[0][0]

x = int(input())

m = []
# leitura da matriz
for i in range(x):
    m.append([int(k) for k in input().split()])

print(calc(m, x))
