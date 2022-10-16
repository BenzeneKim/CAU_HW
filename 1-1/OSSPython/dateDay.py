from datetime import date, datetime

day=["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"]


dateVal = input("Please enter the date : ").split('.')
inputDate = date(int(dateVal[0]),int(dateVal[1]), int(dateVal[2]))

print(dateVal[0]+"."+dateVal[1]+"."+dateVal[2]+" is "+day[inputDate.weekday()])
