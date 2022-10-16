import time
from datetime import date

day=["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"]

secs = time.time()
tm = time.localtime(secs)

print("Today is " + str(tm.tm_year) + "/" +str(tm.tm_mon)+"/"+str(tm.tm_mday)+", "+str(day[date(tm.tm_year, tm.tm_mon, tm.tm_mday).weekday()]))
