>>> """
... csc134
... M2Lab2- Python turtle
... Abdullah Zalzala
... 9/13/2025
... """
'\ncsc134\nM2Lab2- Python turtle\nAbdullah Zalzala\n9/13/2025\n'
>>> """
... I have no clue what this is but its cool :)
... """
'\nI have no clue what this is but its cool :)\n'
>>>
>>> import turtle as t
>>> import random
>>> import math
>>>
>>> t.bgcolor("red")
>>> t.title("M2Lab2")
>>>
>>> t.pensize(15)
>>> t.speed(50)
>>> t.fillcolor("blue")
>>> x=15
>>>
>>> for i in range(100):
...     t.pencolor("cyan")
...     t.fd(x)
...     t.right(12)
...     x=x+12
...     y=t.heading()
...     t.pencolor("orange")
...     t.left(50)
...     t.fd(x)
...     t.right(165)
...
>>>