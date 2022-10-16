class Television:
    maker=""
    def __init__(self, maker="CAU"):
        Television.maker = maker
        self.__owner = ""
    def getOwner(self):
        return self.__owner

    def setOwner(self, owner):
        self.__owner = owner

    def __str__(self):
        return "제조사 이름 {} 소유자 이름 {}".format(Television.maker, self.__owner)

myTv = Television("MM") # Assume that "MM" is the maker of the Television
yourTv = Television()
myTv.setOwner("Kim")
yourTv.setOwner("Lee")
print(myTv.getOwner())
print(myTv)
print(yourTv)
