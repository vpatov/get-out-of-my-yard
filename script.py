import pyglet
import threading
import time
import platform
from pyglet.window import key
import PIL.Image as Image 
import PIL.ImageDraw as ImageDraw



# display = platform.get_display(display_name)
# screens = pyglet.display.get_screens()
event_loop = pyglet.app.EventLoop()
color = 'red'
window = pyglet.window.Window(fullscreen=True)

document = pyglet.text.decode_text('INTRUDER!!! Stay away from my bitcoins!')
document.set_style(0, 5, dict(font_name='Arial', font_size=36, color=(200,200,150,1)))
layout = pyglet.text.layout.TextLayout(document, 300, 300)
# pyglet.gl.glClearColor(150,0,0,1)

@window.event
def on_draw():
	window.clear()
	layout.draw()
	

@window.event
def on_key_press(symbol, modifiers):
    if symbol == key.A:
        print('The "A" key was pressed.')
    elif symbol == key.LEFT:
        pyglet.gl.glClearColor(150,150,0,1)
    elif symbol == key.RIGHT:
        pyglet.gl.glClearColor(150,0,0,1)
    elif symbol == key.ENTER:
        print('The enter key was pressed.')

		

@event_loop.event
def on_window_close(window):
    event_loop.exit()


def update(dt):
	global color
	if color == 'red':
		color = 'yellow'
		pyglet.gl.glClearColor(150,150,0,1)
	else:
		color = 'red'
		pyglet.gl.glClearColor(150,0,0,1)

# pyglet.clock.schedule_interval(update, 0.1)


pyglet.app.run()
print("Hello")
