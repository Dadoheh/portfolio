#kolko i krzyzyk, za pomoca turtle, w PyCharm

#biblioteki za pomoca ktorych stworzymy kolko i krzyzyk
import turtle
import random
import time

window = turtle.Screen() #stworzenie okna

BOK = 600
#wspolrzedne lewego gornego rogu
X = -300
Y = 300
window.setup(BOK,BOK) #tworzenie wymiarow okna
window.title('Kolko i krzyzyk')
window.bgcolor('blue')

#tworzenie zolwia rysujacego krzyzyki i kolka
xo = turtle.Turtle()
xo.color('white')
xo.speed(0)
xo.pensize(7)
xo.hideturtle()

#zmienna przechowujaca informacje czy i gdzie sa postawione kolka i krzyzyki - lista 3x3
tablica = [[None,None,None],
           [None,None,None],
           [None,None,None]]
kolej = random.choice(['x','o']) #losowanie kto zaczyna

#rysowanie siatki do gry
Odstep = int(BOK/3) #=200

for a in [1,2]:
    #pionowo:
    xo.penup()
    xo.goto(X +a*Odstep, Y)
    xo.pendown()
    xo.goto(X + a*Odstep, -Y)

    #poziomo:
    xo.penup()
    xo.goto(X, Y -a*Odstep)
    xo.pendown()
    xo.goto(-X, Y -a*Odstep)
#koniec fora



def sprawdz():
    #po skosie
    if tablica[0][0] == tablica[1][1] == tablica[2][2]: return tablica[2][2]
    if tablica[0][2] == tablica[1][1] == tablica[2][0]: return  tablica[2][0]

    #w wierszu
    for wiersz in range(3):
        if tablica[wiersz][0] == tablica[wiersz][1] == tablica[wiersz][2]: return tablica[wiersz][0]

    #w kolumnie
    for kolumna in range(3):
        if tablica[0][kolumna] == tablica[1][kolumna] == tablica[2][kolumna]: return tablica[0][kolumna]

    return None

#rysowanie funkcji click
def click(x,y):
    global kolej

    kolumna = 0
    wiersz = 0

    if x < X + Odstep: kolumna = 0
    elif x > X + 2*Odstep: kolumna = 2
    else: kolumna = 1

    if y < Y - 2*Odstep: wiersz = 2
    elif y > Y - Odstep: wiersz = 0
    else: wiersz = 1

    #sprawdzanie czy klikniete pole jest puste
    if tablica[wiersz][kolumna] != None: return

    #rysowanie X lub O
    kolumna_srodek = (kolumna*Odstep + Odstep/2) - BOK/2
    wiersz_srodek = (-wiersz*Odstep - Odstep/2) + BOK/2

    xo.penup()
    xo.goto(kolumna_srodek-25, wiersz_srodek-25)
    if kolej == 'x': xo.write('X', font=('Arial',50))
    else: xo.write('O', font=('Arial',50))

    #dodanie informacji x/o do tablicy
    tablica[wiersz][kolumna] = kolej

    if kolej=='o':kolej = 'x'
    else: kolej='o'

    #sprawdzenie wygranej
    if sprawdz() != None:
        xo.penup()
        xo.goto(-150,0)
        time.sleep(1)
        xo.clear()
        xo.write("Wygraly " +sprawdz(), font=('Arial',50))

#Obsluga zdarzenia klikniecia myszki
window.onclick(click)
window.listen()
window.mainloop()

