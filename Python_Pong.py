import turtle #korzystamy z biblioteki żółwika

def create_window():
    window = turtle.Screen()
    window.title('Projekt Pong')
    window.bgcolor('black')
    window.setup(width=800,height=600) #ustawienie szerokości i wysokości ekranu
    window.tracer(0) #szybkość odświeżania
    return window
window = create_window()

def create_paddle(x,y,color): #definiujemy funkcję dwóch zmiennych
    paddle = turtle.Turtle() #tworzy jeden element do rysowania
    paddle.speed(0) #ustawia prędkość na zero
    paddle.shape('square') #tworzy prostokąt
    paddle.color(color) #nadanie koloru białego
    paddle.shapesize(stretch_wid=5,stretch_len=1) #szerokość i długość
    paddle.penup() #nie ma śladów żółwika
    paddle.goto(x,y) #przesuwam do punktu x:350, y:0
    return paddle #zwracam paddle

def create_ball(color):
    ball = turtle.Turtle()
    ball.speed(0)
    ball.shape('circle')
    ball.color(color)
    ball.penup()
    ball.goto(0,0)
    return ball

#tworzenie poszczególnych paletek oraz piłki
paddle_left = create_paddle(-350,0,'red')
paddle_right = create_paddle(350,0,'red')
ball = create_ball('blue')

window.listen() #słuchaj okienko

def paddle_left_change(distance):
    y = paddle_left.ycor() #pobranie obecnej współrzędnej
    y += distance
    paddle_left.sety(y) #ustawiam paddle_left na nową wartość
def paddle_left_up(): 
    paddle_left_change(20) #funkcja w funkcji
def paddle_left_down(): 
    paddle_left_change(-20) 

def paddle_right_change(distance):
    y = paddle_right.ycor()
    y += distance
    paddle_right.sety(y)
def paddle_right_up():
    paddle_right_change(20)
def paddle_right_down():
    paddle_right_change(-20)

#instrukcje dla lewej paletki
window.onkeypress(paddle_left_up,"w") #kiedy będzie wciśnięta literka w, to stanie się paddle_left_up
window.onkeypress(paddle_left_down,'s')

#instrukcje dla prawej paletki
#dla prawej paletki: Up, Down
window.onkeypress(paddle_right_up,"Up")
window.onkeypress(paddle_right_down,"Down")

#przesunięcie o wartość dla osi X i Y
ball.dx = 0.1
ball.dy = -0.1

#przesunięcie piłki
#ball.goto(390,0) # - piłka na krawędzi 

#print(paddle_left.ycor()) #wartość współrzędnej Y
#paddle_left.sety(10) #zmiana położenia paletki

while True:
    window.update()
    ball.setx(ball.xcor()+ball.dx)
    ball.sety(ball.ycor()+ball.dy)
    if ball.xcor() > 390 or ball.xcor() <-390: #jeżeli jest bramka
        ball.goto(0,0)
        ball.dx = ball.dx*-1
  
    #odbijanie się piłki od krawędzi
    #krawędź górna
    if ball.ycor()>290 or ball.ycor()<-290:
       # ball.sety(290)
        ball.dy = ball.dy*-1 #zwiększaliśmy to teraz zmniejszamy
    #prawa paletka

    #pierwszy if sprawdzamy czy to jest na linii paletki a nie gola
    if ball.xcor() > 340 and ball.xcor() < 350 and ball.ycor() < paddle_right.ycor()+40 and ball.ycor() > paddle_right.ycor()-40:
        ball.setx(340)
        ball.dx*=-1
    if ball.xcor() <-340 and ball.xcor() >-350 and ball.ycor() < paddle_left.ycor()+40 and ball.ycor() > paddle_left.ycor()-40:
        ball.setx(-340)
        ball.dx*=-1

    if ball.xcor() == paddle_left.xcor() and abs(paddle_left.ycor()-ball.ycor()) < 80:
        print("gooola nie ma....")
        print(paddle_left.ycor())
        ball.dx = -ball.dx

    if ball.xcor() == paddle_right.xcor() and abs(paddle_right.ycor()-ball.ycor()) < 80:
        print("gooola nie ma....")
        print(paddle_right.ycor())
        ball.dx = -ball.dx


