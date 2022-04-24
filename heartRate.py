import cv2
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import datetime
import pytimeparse
import statistics as st
from skimage import color
from pylab import *
from skimage import data, io, color
from scipy.signal import find_peaks
flag=0
t=1
time=0
flag1=0
xx=list()
mag_max=list()
CIEl_values=list()
CIEa_values=list()
CIEb_values=list()    
r_values=list()
g_values=list()
b_values=list()
labx=list()
rgbx=list()
magnitude_spectruma=list()
peaks=list()
start=datetime.datetime.now();
def NormalisedIntensity(mylist):
    mean=np.mean(mylist)
    summ=0
    mylist=(mylist-np.mean(mylist))/st.stdev(mylist.tolist())
    return mylist.sum()
x=cv2.VideoCapture(0)
while True:
    ret,photo=x.read()
    time1=datetime.datetime.now()
    diff=time1-start
    seconds = pytimeparse.parse(str(diff))
    #print("secons ",seconds)
    face=cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
    cord=face.detectMultiScale(photo)
    if len(cord) == 1:
        flag=0
        flag1=0
        for i in range(len(cord)):
            x1=cord[i][0]
            y1=cord[i][1]
            x2=x1+cord[i][2]
            y2=y1+cord[i][3]
            x3 = (x2-x1)/2+x1
            x4 = x3-20
            x5 = x3+20
            string = "Remain still for 90 frames: "+str(t) +"frame" 
            crop_photo=cv2.rectangle(photo,(x1,y1),(x2,y2),(0,255,0),3)
            crop1 = cv2.rectangle(photo,(int(x4),y1+20),(int(x5),y1+40),(255,0,0),3)
            crop2 = crop1.copy()
            forehead=crop1[int(y1+20):int(y1+40),int(x4):int(x5),:]
            CIE = color.rgb2lab(forehead)
            crop1[int(y1+20):int(y1+40),int(x4):int(x5),]=CIE
            grey=cv2.cvtColor(forehead,cv2.COLOR_BGR2GRAY)
            font=cv2.FONT_HERSHEY_SIMPLEX
            bottomLeftCornerOfText=(100,35) 
            fontScale=0.7
            fontColor=(0,255,0)
            lineType=2
            val = int(CIE[:,:,2].mean())
            cv2.putText(crop1,string, bottomLeftCornerOfText,font, fontScale,fontColor,2,cv2.LINE_AA)
            cv2.imshow('pic',crop1)
            R=NormalisedIntensity(forehead[:,:,0].flatten())
            G=NormalisedIntensity(forehead[:,:,1].flatten())
            B=NormalisedIntensity(forehead[:,:,2].flatten())
            L=NormalisedIntensity(CIE[:,:,0].flatten())
            A=NormalisedIntensity(CIE[:,:,1].flatten())
            B=NormalisedIntensity(CIE[:,:,2].flatten())
            if((R+G+B)!=0):
                r_values.append(R/(R+G+B))
                g_values.append(G/(R+G+B))
                b_values.append(B/(R+G+B))
                rgbx.append(t)
            if((L+A+B)!=0):
                CIEl_values.append(L/(L+A+B))
                CIEa_values.append(A/(L+A+B))
                CIEb_values.append(B/(L+A+B))
                labx.append(t)
            ff_transform=np.fft.fft2(CIE[:,:,1],norm="ortho")
            fshift=np.fft.fftshift(ff_transform)
            magnitude_spectrum = 20*np.log(np.abs(fshift))
            mag_max.append(magnitude_spectrum.max())
            total = int(x.get(cv2.CAP_PROP_FPS))
            time=time+1
            xx.append(time)
            if(t>=90):
                num_of_peaks=find_peaks(mag_max)
                print("HEARTRATE ",(num_of_peaks[0].size*60)/seconds)
                plt.figure(5)
                plt.title("Heart-rate Against time", loc='center',fontsize=16,fontweight=2)
                plt.xlabel("Time (Seconds)")
                plt.ylabel("Power Spectrum")
                t="Heart-rate\n"+str(round((num_of_peaks[0].size*60)/seconds))+" bpm"
                plt.text(0.02, 0.5, t, fontsize=20, transform=plt.gcf().transFigure)
                plt.subplots_adjust(left=0.45)
                plt.plot(xx,mag_max)
                plt.draw()
                plt.pause(0.01)   
                plt.show()
                flag=1
            if(cv2.waitKey(1)==13):
                flag=1
                print(flag)
                break
    if(flag==1):
        fig=plt.figure(1)
        fig.suptitle("Variation of heartrate in LAB channel with time")
        plt.subplot(3,1,1)
        plt.plot(labx,CIEl_values,'-',label="L*",color="black")
        plt.legend(loc='upper right')
        plt.subplot(3,1,2)
        plt.plot(labx,CIEa_values,'--',label="a*",color="black")
        plt.legend(loc='upper right')
        plt.subplot(3,1,3)
        plt.plot(labx,CIEb_values,'-.',label="b*",color="black")
        plt.legend(loc='upper right')
        fig1=plt.figure(2)
        fig1.suptitle("Variation of heartrate in RGB channel with time")
        plt.title("Variation of heartrate in RGB channel")
        plt.subplot(3,1,1)
        plt.plot(rgbx,r_values,'-',label="R",color="red")
        plt.legend(loc='upper right')
        plt.subplot(3,1,2)
        plt.plot(rgbx,g_values,'-',label="G",color="green")
        plt.legend(loc='upper right')
        plt.subplot(3,1,3)
        plt.plot(rgbx,b_values,'-',label="B",color="blue")
        plt.legend(loc='upper right')
        plt.show()
        break
    else:
        print("face Not Found")
    t=t+1
    

cv2.destroyAllWindows()
x.release() 