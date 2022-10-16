class BankAccount:
    def __init__(self, name):
        print("A bank account of James has been created.")
        self.__balance = 0
        self.__name = name
    def __str__(self):
        return "The balance of James is {} won".format(self.__balance)
    def __add__(self,y):
        if self.getName==y.getName:
            return "Total of balance is {} won for james".format(self.__balance+y.getBalance())
        else:
            return "The owners are not the same" 
    def withdraw(self, amount):
        self.__balance -= amount
        print("You have withdrawn", amount, "won from your account.")
        return self.__balance
    def deposit(self, amount):
        self.__balance += amount
        print("You have deposited", amount, "won into your account.")
        return self.__balance
    @property
    def getName(self):
        return self.__name
    def getBalance(self):
        return self.__balance

a = BankAccount("James")

a.deposit(10000)

a.withdraw(3000)

print(a)

b = BankAccount("James")

b.deposit(2000)

c = BankAccount("Harry")

c.deposit(4000)

print(a+b)

print(a+c)

print(a)
