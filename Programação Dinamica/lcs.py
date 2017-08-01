#!/usr/bin/python3

def main():
	str1 = input()
	str2 = input()

	matriz = []

	for i in range(len(str1) + 1):
		matriz.append([0 for i in range(len(str2) + 1)])

	print(lcs(matriz, str1, str2))

def lcs(matriz, str1, str2):
	for i in range(1, len(matriz)):
		for j in range(1, len(matriz[0])):
			if str1[i-1] == str2[j-1]:
				matriz[i][j] = matriz[i-1][j-1] + 1
			else:
				matriz[i][j] = max(matriz[i-1][j], matriz[i][j-1])
	return matriz[len(str1)][len(str2)]

if __name__ == '__main__':
	main()