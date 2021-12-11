clear all
clc
max_voltage=240;
min_voltage=210;
a=120;
b=320;
voltage=(b-a)*rand(100,1)+a;
new_voltage=[];
for i=0:99
	if((voltage(i+1)>max_volatge) &&(voltage(i+1)>min_voltage))
		new_voltage(i+1)=max_voltage;
	elseif((voltage(i+1)<min_voltage)&&(voltage(i+1)<max_voltage))
		new_voltage(i+1)=min_voltage;
	else
		new_voltage(i+1)=voltage(i+1);
	end
end
x=linspace(0,99,100);
plot(x,voltage,'DisplayName','Unregulated voltage');
title('Unregulated vs Regulated voltage');
xlabel('Time (in seconds)')
ylabel('Voltage (in V) ')
hold on
plot(x,new_voltage,'DisplayName','Unregulated voltage');
hold off
legend