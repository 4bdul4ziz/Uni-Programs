import turtle as t


levels = 4

number_of_petals = 5

size_of_first_flower = 90


def center(d, x, y):
    t.goto(x, y-d)
    t.setheading(0)
    t.color("black", "goldenrod")
    t.begin_fill()
    t.circle(d)
    t.end_fill()
    t.up()


def petal(d, npetals, x, y, i, color):
    colors = ["MidnightBlue", "Navy", "MediumBlue",
              "RoyalBlue", "MediumSlateBlue", "CornflowerBlue"]
    t.down()
    t.color(colors[color % len(colors)])
    t.begin_fill()
    t.goto(x, y)
    t.setheading(360/npetals*i+90)
    t.right(45)
    t.circle(2.5*d, 90)
    t.setheading(360/npetals*i+90+180)
    t.right(45)
    t.circle(2.5*d, 90)
    t.end_fill()


def flower(d, npetals, x, y, color):
    for i in range(npetals):
        petal(d, npetals, x, y, i, color)
    center(d, x, y)
    # t.tracer(n=0, delay=0)


def flowers(n, petals, d, x, y, color):
    flower(d, petals, x, y, color)
    if n > 1:

        t.goto(x, y+3/2*d)
        t.setheading(180)
        t.circle(3/2*d, -360/(2*petals))

        for i in range(petals):
            x, y, z = t.xcor(), t.ycor(), t.heading()
            flowers(n-1, petals, d/2, t.xcor(), t.ycor(), color+1)
            t.up()
            t.goto(x, y)
            t.setheading(z)
            t.circle(3/2*d, -360/petals)
    # t.tracer(n=0, delay=0)


def main():
    t.up()
    t.speed(-100)
    t.update()
    t.hideturtle()
    flowers(levels, number_of_petals, size_of_first_flower, 0, 0, 0)

    canvas = t.getcanvas()
    canvas.postscript(file="resultat_turtle.ps", colormode='color')
    t.tracer(n=0, delay=0)
    t.update()


main()
