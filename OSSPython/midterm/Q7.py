status = False
while status == False:
    inputStr = input("Enter a sentence : ")
    editStr = inputStr.replace("a","")
    editStr = editStr.replace("A","")
    resultStr = ""
    for i in range(len(editStr)):
        if editStr[i].isupper() == True:
            resultStr+=editStr[i].lower()
        else:
            resultStr+=editStr[i].upper()
    print(resultStr)
    if "2" in editStr:
        break
