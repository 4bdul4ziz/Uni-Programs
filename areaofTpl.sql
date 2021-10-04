--q1 area of triangle

DECLARE
base float;
height float;
area float;
BEGIN
height:= &height;
base := &base;
dbs_output.put_line('Height = '||height);
dbs_output.put_line('Base = '||base);
area := 0.5 * base * height;
dbs_output.put_line('The area of the triangle is ' ||area');
END;


