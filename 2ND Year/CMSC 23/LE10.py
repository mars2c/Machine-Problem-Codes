from abc import ABC,abstractmethod

class Fraction:
    def __init__(self,num:int,denom:int):
        self.__num = num
        self.__denom = denom
    def num(self):
        return self.__num
    def denom(self):
        return self.__denom
    def __str__(self) -> str:
        return str(self.__num) + "/" + str(self.__denom)

class Operation(ABC):
    @abstractmethod
    def execute(self, left:Fraction, right:Fraction) -> Fraction:
        pass
    @abstractmethod
    def __str__(self) -> str:
        pass

class Addition(Operation):
    def execute(self, left:Fraction, right:Fraction) -> Fraction:
        if left.denom() == right.denom():
            totalsum = left.num() + right.num()
            return (str(totalsum) + "/" + str(left.denom()))
        else:
            commonDenom = left.denom() * right.denom()
            numLeft = right.denom() * left.num()
            numRight = left.denom() * right.num()
            totalsum = numLeft + numRight
            return Fraction(totalsum,commonDenom)
    def __str__(self) -> str:
        return "+"

class Subtraction(Operation):
    def execute(self, left: Fraction, right: Fraction) -> Fraction:
        if left.denom() == right.denom():
            totaldiff = left.num() - right.num()
            return Fraction(totaldiff,left.denom())
        else:
            commonDenom = left.denom() * right.denom()
            numLeft = right.denom() * left.num()
            numRight = left.denom() * right.num()
            totaldiff = numLeft - numRight
            return Fraction(totaldiff,commonDenom)
    def __str__(self) -> str:
        return "-"

class Multiplication(Operation):
    def execute(self, left: Fraction, right: Fraction) -> Fraction:
        prodNum = left.num()*right.num()
        prodDenom = left.denom()*right.denom()
        return Fraction(prodNum,prodDenom)
    def __str__(self) -> str:
        return "*"

class Division(Operation):
    def execute(self, left: Fraction, right: Fraction) -> Fraction:
        quoNum = left.num()*right.denom()
        quoDenom = left.denom()*right.num()
        return Fraction(quoNum,quoDenom)
    def __str__(self) -> str:
        return "/"

class Calculation:
    def __init__(self,left:Fraction,right:Fraction,operation:Operation):
        self.__left = left
        self.__right = right
        self.__operation = operation #the parameter that represents the operation
        self.__answer = self.__operation.execute(self.__left, self.__right) #the answer should be calculated here

    def __str__(self):
        return str(self.__left) + " " + str(self.__operation) + " " + str(self.__right) + " = " + str(self.__answer)


f:Fraction = Fraction(1,3)
g:Fraction = Fraction(4,5)
print(Calculation(f, g, Addition()))
print(Calculation(f, g, Subtraction()))
print(Calculation(f, g, Multiplication()))
print(Calculation(f, g, Division()))

