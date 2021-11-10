clear all
clc
l1=input('Enter Value for Link 1: ');
l2=input('Enter Value for Link 2: ');
l3=input('Enter Value for Link 3: ');
for i=1:360;
    w(i)=((l2*l3)*(sqrt((l2^2)+(l3^2)+(2*l2*l3*cosd(i))))*abs(sind(i)));
end 
plot(w);
theta3=acosd((sqrt(((l2^2)+(l3^2))^2+(12*(l2^2)*(l3^2)))-((l2^2)+(l3^2)))/(6*l2*l3))
W=((l2*l3)*(sqrt((l2^2)+(l3^2)+(2*l2^2*l3^2*cosd(theta3))))*abs(sind(theta3)));
fprintf('Value of Theta3: %d',theta3);
fprintf('\nValue of W: %d\n',W);