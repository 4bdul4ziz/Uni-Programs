

--q6 fibo nibba
DECLARE
first_number := 0; --fibo nibba frst numb
second_number := 1; --fibo nibba scnd numb
temp_number;

n number := &n; 
i number;

begin

	dbms_output.put_line('Fibonacci Series:');

print first two term first_number and second_number
	dbms_output.put_line(first_number);
	dbms_output.put_line(second_number);

 loop i = 2 to n
	for i in 2..n
	loop
		temp:=first_number+second_number;

first_number := second_number;
second_number := temp_number;

	dbms_output.put_line(temp_number);
end loop;

END;