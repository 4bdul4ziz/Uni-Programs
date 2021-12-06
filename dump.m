clc
clear all
l1=input('enter value for link1: ');
m1=input('enter mass1: ');
v1=input('enter v1: ');
a1=input('enter acc1: ');
g=9.8;
l2=input('enter value for link2: ');
m2=input('enter mass2: ');
a2=input('enter acc2: '); 
v2=input('enter v2: ');
theta1=input('enter theta1: ');
theta2= -90:1:90;
t1=(m1*l1^2 + m2*(l1^2 + 2*l1*l2*cosd(theta2) + l2^2))*a1 + m2*(l1*l2*cosd(theta2) + l2^2)*a2 - m2*l1*l2*sind(theta2)*(2*v1*v2 + v2^2) + (m1 + m2)*l1*9.8*cosd(theta1) + m2*9.8*l2*cosd(theta1+theta2);
t2=m2*(l1*l2*cosd(theta2)+l2^2)*a1+m2*l2^2*a2+m2*l1*l2*v1^2*sind(theta2)+m2*9.8*l2*cosd(theta1+theta2);
plot(theta2,t2);
hold on;
plot(theta2,t1);
xlabel('Theta2');
ylabel('Torque');