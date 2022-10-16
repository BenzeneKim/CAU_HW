def multiply(x, *args):
    ans = x
    #print(ans)
    for i in range(len(args)):
        ans *= args[i]
        #print(ans)
    return ans

print("answer =", multiply(7, 3, 5))
print("answer =", multiply(99, 2, 6, 9, 4, 3))
print("answer =", multiply(1, 11, 5, 8, 15, 17, 13, 32, 120, 8, 91))
