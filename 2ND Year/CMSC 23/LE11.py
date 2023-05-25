from abc import ABC, abstractmethod

class State(ABC):
    @abstractmethod
    def compress(self):
        pass
    @abstractmethod
    def release(self):
        pass
    @abstractmethod
    def heat(self):
        pass
    @abstractmethod
    def cool(self):
        pass

class Matter:
    def __init__(self,name:str):
        self.__name = name
        self.__state = LiquidState(self) #change this to the appropriate initial state (liquid)
    def changeState(self,newState:State):
        self.__state = newState
    def compress(self):
        self.__state.compress()
    def release(self):
        self.__state.release()
    def cool(self):
        self.__state.cool()
    def heat(self):
        self.__state.heat()
    def __str__(self):
        return "%s is currently a %s" % (self.__name,self.__state) #formatting strings just like you format strings in C
    
class SolidState(State):
    def __init__(self, matter:Matter):
        self.__matter = matter
    def compress(self):#Solid -> same
        print("compressing")
    def cool(self):#Solid -> same
        print("solidifying")
    def release(self):#Liquid
        print("melting")
        self.__matter.changeState(LiquidState(self.__matter))
    def heat(self):#Liquid
        print("melting")
        self.__matter.changeState(LiquidState(self.__matter))    
    def __str__(self) -> str:
        return "solid"

class LiquidState(State):
    def __init__(self, matter:Matter):
        self.__matter = matter
    def compress(self):#Solid
        print("solidifying")
        self.__matter.changeState(SolidState(self.__matter))
    def cool(self):#Solid
        print("freezing")
        self.__matter.changeState(SolidState(self.__matter))
    def release(self):#Gas
        print("evaporating")
        self.__matter.changeState(GaseousState(self.__matter))
    def heat(self):#Gas
        print("evaporating")
        self.__matter.changeState(GaseousState(self.__matter))
    def __str__(self) -> str:
        return "liquid"
    
class GaseousState(State):
    def __init__(self, matter:Matter):
        self.__matter = matter
    def compress(self):#Liquid
        print("condensing")
        self.__matter.changeState(LiquidState(self.__matter))
    def cool(self):#Liquid
        print("cooling")
        self.__matter.changeState(LiquidState(self.__matter))
    def release(self):#Gas -> same
        print("releasing")
    def heat(self):#Gas -> same
        print("heating")
    def __str__(self) -> str:
        return "gas"


water:Matter = Matter("water")
print(water)
water.compress()
print(water)
water.heat()
print(water)
water.release()
print(water) 
water.heat()
print(water)
water.cool()
print(water)
