contacts = {'Kim':'01012345678', 'Park':'01012345679', 'Lee':'01012345680'}
while True:
    inputStr = input("Enter a name : ")
    if inputStr == "":
        break
    elif inputStr in contacts:
        print(contacts.get(inputStr))
    else:
        print("None")
