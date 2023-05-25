from abc import ABC,abstractmethod
from typing import Concatenate

class Sentence:
    def __init__(self,words:[str]):
        self.__words = words
    def __str__(self) -> str:
        sentenceString = ""
        for word in self.__words:
            sentenceString += word + " "
        return sentenceString[:-1]

class FormattedSentence(ABC, Sentence):
    def __init__(self, wrappedSentence:Sentence):
        self._wrappedSentence = wrappedSentence
    
    @abstractmethod
    def __str__(self) -> str:
        pass

class BorderedSentence(FormattedSentence):
    def __str__(self) -> str:
        UDborder = "-" * (len(str(self._wrappedSentence))+2)
        sideborder = "\n|"+ (str(self._wrappedSentence)) + "|\n"
        return UDborder + sideborder + UDborder

class FancySentence(FormattedSentence):
    def __str__(self) -> str:
        return ("-+" + (str(self._wrappedSentence)) + "+-")

class UpperCaseSentence(FormattedSentence):
    def __str__(self) -> str:
        return str(self._wrappedSentence).upper()


s = Sentence(["hey","there"])
print(s)
print()
print(BorderedSentence(s))
print()
print(FancySentence(UpperCaseSentence(s)))
print()
print(UpperCaseSentence(BorderedSentence(s)))
print()
print(BorderedSentence(FancySentence(s)))
print()
print(FancySentence(BorderedSentence(s)))
print()
print(FancySentence(UpperCaseSentence(s)))
print()
print(BorderedSentence(FancySentence(UpperCaseSentence(s))))
print()
print(FancySentence(FancySentence(BorderedSentence(BorderedSentence(s)))))