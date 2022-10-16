cash = 100000
for i in range(10):
    cash = 1.05*cash
cash = cash // 1000
cash = cash * 1000
print(int(cash))
