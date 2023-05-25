from abc import ABC, abstractmethod

class SearchAlgorithm(ABC):
    def __init__(self, target:int, searchSpace:[int]):
        self._searchSpace = searchSpace
        self._currentIndex = 0
        self._solutions = []
        self._target = target

    def bruteForceSolution(self):
        candidate = self.first()
        while(self.isSearching()):
            if self.isValid(candidate):
                self.updateSolution(candidate)
            candidate = self.next()
        return self._solutions

    def first(self) -> int:
        return self._searchSpace[0]

    def next(self) -> int:
        self._currentIndex += 1
        if self.isSearching():
            return self._searchSpace[self._currentIndex]
    
    def isSearching(self) -> bool:
        return self._currentIndex < len(self._searchSpace)
    
    @abstractmethod
    def isValid(self, candidate) -> bool:
        pass

    @abstractmethod
    def updateSolution(self, candidate):
        pass

class EqualitySearchAlgorithm(SearchAlgorithm):
    def isValid(self, candidate) -> bool: 
        if candidate == self._target:
            return True
            
    def updateSolution(self, candidate):
        if self.isValid(candidate):
            self._solutions.append(candidate)

class DivisibilitySearchAlgorithm(SearchAlgorithm):
    def isValid(self, candidate) -> bool:
        if candidate % self._target == 0:
            return True
    
    def updateSolution(self, candidate):
        if self.isValid(candidate):
            self._solutions.append(candidate)

class MinimumSearchAlgorithm(SearchAlgorithm):
    def __init__(self, target:int, searchSpace:[int]):
        self._searchSpace = searchSpace
        self._currentIndex = 0
        self._target = target
        self._solutions = searchSpace

    def isValid(self, candidate) -> bool:
        if candidate < self._solutions[0]:
            return True
    
    def updateSolution(self, candidate):
        if self.isValid(candidate) == True:
            self._solutions = [candidate]
            
            



e = EqualitySearchAlgorithm(2,[4,2,3,6,1,5,2])
print(e.bruteForceSolution())
print()

m = MinimumSearchAlgorithm(None,[4,2,3,6,1,5,2])
print(m.bruteForceSolution())
print()

d = DivisibilitySearchAlgorithm(2,[4,2,3,6,1,5,2])
print(d.bruteForceSolution())