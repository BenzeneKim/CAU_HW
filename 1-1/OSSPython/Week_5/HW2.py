def maxmin(a,b,c,d):
    return max(a,b,c,d), min(a,b,c,d)
maxD, minD = maxmin(float(input("Please enter a number : ")),float(input("Please enter a number : ")),float(input("Please enter a number : ")),float(input("Please enter a number : ")))
print("Max value = ", maxD, ", Min value = ", minD)
