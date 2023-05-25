from abc import ABC,abstractmethod

class Iterator(ABC):
    @abstractmethod
    def next(self):
        pass
    @abstractmethod
    def hasNext(self):
        pass

class Collection(ABC):
    @abstractmethod
    def newIterator(self):
        pass

class MyList(Collection):
    def __init__(self, elements):
        self.__elements = elements
    def size(self):
        return len(self.__elements)
    def elementAtIndex(self,index):
        return self.__elements[index]
    def newIterator(self):
        return ReverseListIterator(self)

class ListIterator(Iterator):
    def __init__(self, list):
        self.__traversedList = list
        self.__currentIndex = 0
    def next(self):
        self.__currentIndex += 1
        return self.__traversedList.elementAtIndex(self.__currentIndex-1)
    def hasNext(self):
        return self.__currentIndex < self.__traversedList.size()

class ReverseListIterator(Iterator):
    def __init__(self, traversedList:MyList):
        self.__traversedList = traversedList
        self.__currentIndex = traversedList.size()
    def next(self):
        self.__currentIndex -= 1
        return self.__traversedList.elementAtIndex(self.__currentIndex)
    def hasNext(self):
        return self.__currentIndex > 0






c:Collection = MyList([1,2,3,4,5,6,7,8,9,10])
iter:Iterator = c.newIterator()
while(iter.hasNext()):
    print(iter.next())