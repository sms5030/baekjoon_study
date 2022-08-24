M, N = map(int, input().split())
checkPrimeNumber = []

for i in range(N + 1):
    checkPrimeNumber.append(True)
checkPrimeNumber[0] = False
checkPrimeNumber[1] = False

for i in range(2, N + 1):
    if checkPrimeNumber[i] == True:
        index = i * 2;
        while index <= N:
            checkPrimeNumber[index] = False
            index += i;
            
for i in range(M, N + 1):
    if checkPrimeNumber[i] == True:
        print(i)