def binary_output(n):
    b = [0 for i in range(n)]
    i = 0
    while True:
        print(b)
        i += 1
        p = 1
        j = i
        while j % 2 == 0:
            j //= 2
            p += 1
        if p <= n:
            b[p - 1] = 1 - b[p - 1]
        if p > n:
            break


binary_output(int(input("Enter output for task 1.13: ")))
print()
