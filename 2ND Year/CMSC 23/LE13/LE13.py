from abc import ABC, abstractmethod

class Headline:
    def __init__(self, headline:str, details:str, source:str):
        self.__headline = headline
        self.__details = details
        self.__source = source

    def __str__(self) -> str:
        return "%s(%s)\n%s" % (self.__headline, self.__source, self.__details)

class Weather:
    def __init__(self, temp:float, humidity:float, outlook:str):
        self.__temp = temp
        self.__humidity = humidity
        self.__outlook = outlook

    def __str__(self) -> str:
        return "%s: %.1fC %.1f" % (self.__outlook, self.__temp, self.__humidity)

class Subscriber(ABC):
    @abstractmethod
    def update(self, newHeadline:Headline, newWeather:Weather):
        pass

class PushNotifier:
    def __init__(self, currentWeather:Weather, currentHeadline:Headline) -> None:
        self.__currentWeather = currentWeather
        self.__currentHeadline = currentHeadline
        self.__subscriber = []
    def changeHeadline(self, newHeadline:Headline):
        self.__currentHeadline = newHeadline
        self.notifySubscribers()
    def changeWeather(self, newWeather:Weather):
        self.__currentWeather = newWeather
        self.notifySubscribers()
    def subscribe(self, newSubscriber:Subscriber):
        newSubscriber.update(self.__currentHeadline, self.__currentWeather)
        self.__subscriber.append(newSubscriber)
    def unsubscriber(self, exSubscriber:Subscriber):
        self.__subscriber.remove(exSubscriber)
    def notifySubscribers(self):
        for subscriber in self.__subscriber:
            subscriber.update(self.__currentHeadline, self.__currentWeather)

class EmailSubscriber(Subscriber):
    def __init__(self, emailAddress:str):
        self.__emailadd = emailAddress
    def update(self, newHeadline:Headline, newWeather:Weather):
        print("Send email to: %s" % self.__emailadd)
        print("New Headline: %s" % newHeadline)
        print("New Weather: %s" % newWeather)

class FileLogger(Subscriber):
    def __init__(self, filename):
        self.__filename = filename 
    def update(self, newHeadline: Headline, newWeather: Weather):
        with open(self.__filename, "a+") as f:
            f.write("\nNew Headline %s \n\n" % newHeadline)
            f.write("New Weather %s \n\n------" % newWeather)       




h = Headline("Dalai Lama Triumphantly Names Successor After Discovering Woman With ‘The Purpose Of Our Lives Is To Be Happy’ Twitter Bio","Details","The Onion")
w = Weather(25.0,0.7,"Cloudy")
p = PushNotifier(w,h)
e = EmailSubscriber("heyyou@gmail.com")
f = FileLogger("log.in")

p.subscribe(f)
p.subscribe(e)

print()
p.changeWeather(Weather(100, 1, "Super Natural"))
print()
p.changeHeadline(Headline("New Headline", "New Source", "New Details kekeke"))
