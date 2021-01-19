
import time

logFile = open("logs.txt",'w')
fIn = open("files/in.txt", "r")
fOut = open("files/out.html", 'w')

seconds = time.time()
result = time.localtime(seconds)
log = ("Czas uruchomienia programu: \n"
      "data {}.{}.{}r.\ngodz {}:{}:{} \n".format(result.tm_mday, result.tm_mon, result.tm_year,
                                                 result.tm_hour, result.tm_min, result.tm_sec))
logFile.write(log)

#obsługa błędów
def data(reason):
    seconds = time.time()
    result = time.localtime(seconds)
    log = ("Czas programu: \n"
          "data {}.{}.{}r.\ngodz {}:{}:{} \nPowod wpisu: {}\n\n".format(result.tm_mday, result.tm_mon, result.tm_year
                                            ,result.tm_hour, result.tm_min, result.tm_sec, reason))
    logFile.write(log)

def html(data):
    fOut.write('<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><title>LiczbyZaprzyjaznione</title></head><body><h1><center>{}</center></h1><h2><center>By Dawid K</center></h2></body></html>'.format(data))

#funkcje znajdujące dzielniki, sumujące dzielniki, sprawdzające równość
def dzielniki(liczba1):
    liczba = []
    for i in range(1, int((liczba1/2)+1)):
        if liczba1 % i == 0:
            liczba.append(i)
    return liczba

def sumowanie(dana,lendana):
    suma = 0
    for i in range(0,lendana):
        suma += dana[i]
    return suma

def sprawdzanie(liczba1, liczba2, suma1, suma2):
    if liczba1 == suma2 and liczba2 == suma1:
        return True
    else:
        return False

try:
    #liczba1 = int(input("Podaj pierwszą liczbę"))
    liczba1 = (fIn.readline())
    liczba1 = int(liczba1)
    er = "Wpisano poprawnie pierwsza liczbe: {}".format(liczba1)
    data(er)
except ValueError as er:
    data(er)

try:
    #liczba2 = int(input ("Podaj drugą liczbę"))
    liczba2 = (fIn.readline())
    liczba2 = int(liczba2)
    er = "Wpisano poprawnie druga liczbe: {}".format(liczba2)
    data(er)
except ValueError as er:
    data(er)

#Testowanie
try:
    dzielniki1 = (dzielniki(liczba1))
    er = "Wpisano poprawnie dzielniki liczby1: {}".format(dzielniki1)
    data(er)
except Exception as er:
    data(er)
try:
    dzielniki2 = (dzielniki(liczba2))
    er = "Wpisano poprawnie dzielniki liczby2: {}".format(dzielniki2)
    data(er)
except Exception as er:
    data(er)

try:
    suma1 = sumowanie(dzielniki1,len(dzielniki1))
    er = "obliczono poprawnie sume dzielnikow pierwszej liczby: {}".format(suma1)
    data(er)
except Exception as er:
    data(er)
try:
    suma2 = sumowanie(dzielniki2,len(dzielniki2))
    er = "obliczono poprawnie sume dzielnikow drugiej liczby: {}".format(suma2)
    data(er)
except Exception as er:
    data(er)

print(suma1,suma2)
try:
    if (sprawdzanie(liczba1,liczba2,suma1,suma2)):
        er = ("Podane liczby: {}, {} sa liczbami zaprzyjaznionymi".format(liczba1,liczba2))
        print(er)
        data(er)
        html(er)
    else:
        er = ("Podane liczby: {}, {} nie sa liczbami zaprzyjaznionymi".format(liczba1,liczba2))
        print(er)
        data(er)
        html(er)
except Exception as er:
    data(er)
    html(er)

logFile.close()
fIn.close()
fOut.close()