f = [0 for i in range(50)]
g = [0 for i in range(50)]
h = [0 for i in range(50)]

f[0] = 1
g[0] = h[0] = 0
f[1] = h[1] = 0
g[1] = 1

for n in range(2, 20):
    h[n] = g[n-1]
    g[n] = f[n-1] + h[n-1]
    f[n] = f[n-2] + (2 * g[n-1])

print(f[int(input())])
