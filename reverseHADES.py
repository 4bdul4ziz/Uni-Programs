import pyttsx3

engineio = pyttsx3.init()
voices = engineio.getProperty('voices')
engineio.setProperty('rate', 200)    
engineio.setProperty('voice',voices[0].id)

def speak(text):
    engineio.say(text)
    engineio.runAndWait()

speak("What do you want me to say?")
while(1):
    phrase = input("--> ")
    if (phrase == "exit"):
        exit(0)
    speak(phrase)
    print(voices)
