#This is normal functions
import PIL.ImageGrab
import datetime

def getscreenshot():
    now = datetime.datetime.now()
    im = PIL.ImageGrab.grab()
    stamp = now.strftime("%Y-%m-%d %H:%M")
    #im.show()
    im.save("screenshot//screenshot-" + stamp + ".png")