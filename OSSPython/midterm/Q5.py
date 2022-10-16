import random

female_names = ["Alice", "Bianca", "Cindy", "Dorothy", "Emily", "Hera", "Isabel", "Jane", "Julia", "Lisa", "Monica"]
male_names = ["Alex", "Bradley", "Charles", "Eric", "George", "Harry", "Ivan", "James", "Kevin", "Lucas", "Mickey", "Sam"]

def assignName(sn):
    resultName = str()
    if(sn%2==1):
        resultName = random.choice(female_names)
        female_names.remove(resultName)
    else:
        resultName = random.choice(male_names)
        male_names.remove(resultName)
    return resultName

names = {}
nameslist = []
for i in range(100,106):
    names[i] = assignName(i)
    nameslist.append(names[i])
sortedlist = sorted(nameslist)
snlist=[]
for i in range(6):
    for j in range(6):
        if sortedlist[i] == nameslist[j]:
            snlist.append(100+j)
            break
#print(names)
for i in range(6):
    print(str(sortedlist[i])+", "+str(snlist[i]))
