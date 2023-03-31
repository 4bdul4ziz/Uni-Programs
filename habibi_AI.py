import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib

engine = pyttsx3.init("sapi5")
voices = engine.getProperty("voices")
engine.setProperty("voice", voices[0].id)  # 1 for beta wamen voice


def speak(audio):
    """
    The speak function speaks
    """
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    """
    Greets the user based on time of day.
    """
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("Morning, ya Habibi!")
    elif hour >= 12 and hour < 18:
        speak("Let's go and have some bebsi, the sun is at noon, ya habibi!")
    else:
        speak("Shawerma for dinner, evenings, ya habibi!")
    speak("")


def takeCommand():
    """
    Takes microphone input from user.
    """
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening ...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing..")
        query = r.recognize_google(audio, language="en-uk")
        print(f"User said: {query}\n")

    except Exception as e:
        print(e)
        print("Habibi, I do not understand what you said..")
        return "None"
    return query


def sendEmail(to, content):
    """
    Function to send Email to an address
    """
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.ehlo()
    server.starttls()
    # replace with your email and pass to send
    server.login("youremail@gmail.com", "your-password")
    server.sendmail("youremail@gmail.com", to, content)
    server.close()


if __name__ == "__main__":
    wishMe()
    while True:
        query = takeCommand().lower()

        if "wikipedia" in query:
            speak("Searching Wikipedia")
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("According to Wikipedia")
            print(results)
            speak(results)

        elif "open youtube" in query:
            webbrowser.open("youtube.com")

        elif "open google" in query:
            webbrowser.open("google.com")

        elif "open stackoverflow" in query:
            webbrowser.open("stackoverflow.com")

        elif "habibi moment" in query:
            webbrowser.open("https://www.youtube.com/watch?v=J0MqmDs7M-g")

        elif "play music" in query:
            music_dir = "/Users/abdul/Music"
            songs = os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir, songs[4]))

        elif "open spotify" in query:
            codePath = ""
            os.startfile(codePath)

        elif "the time" in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"Baka, the time is {strTime}")

        elif "open code" in query:
            codePath = ""
            os.startfile(codePath)

        elif "email to" in query:
            try:
                speak("What should I say?")
                content = takeCommand()
                to = "address@gmail.com"
                sendEmail(to, content)
                speak("Email has been sent, ya habibi!")
            except Exception as e:
                print(e)
                speak("Malish! The email can not be sent.")
