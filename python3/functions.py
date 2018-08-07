#This is normal functions
if os.name == "posix":
    import pyscreenshot as ImageGrab
else:
    import PIL.ImageGrab
import datetime
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
import os

def getscreenshot():
    now = datetime.datetime.now()
    if os.name == "posix":
        im = ImageGrab.grab()
    else:
        im = PIL.ImageGrab.grab()
    stamp = now.strftime("%Y-%m-%d %H:%M")
    im.save("screenshot//screenshot-" + stamp + ".png")
    
def send_whatsapp():
    if os.name == "posix":
        driver = webdriver.Chrome('drivers/chrome_driver/chromedriver')
    else:
        driver = webdriver.Chrome('drivers/chrome_driver/chromedriver.exe')
 
    driver.get("https://web.whatsapp.com/")
    wait = WebDriverWait(driver, 600)
 
    # Replace 'Friend's Name' with the name of your friend 
    # or the name of a group 
    target = '"Friend\'s Name"'
 
    # Replace the below string with your own message
    string = "Message sent using Python!!!"
 
    x_arg = '//span[contains(@title,' + target + ')]'
    group_title = wait.until(EC.presence_of_element_located((By.XPATH, x_arg)))
    group_title.click()
    inp_xpath = '//div[@class="input"][@dir="auto"][@data-tab="1"]'
    input_box = wait.until(EC.presence_of_element_located((By.XPATH, inp_xpath)))
    for i in range(100):
        input_box.send_keys(string + Keys.ENTER)
        time.sleep(1)
        