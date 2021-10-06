TITLE:- CREATING PL/SQL BLOCKS.

Q1: Find Factorial of Numbers using Exception in PLSQL
DECLARE
N INT;
I INT;
F INT;
E1 EXCEPTION;
E2 EXCEPTION;
BEGIN
N:=6;
F:=1;
I:=1;
IF N<0 THEN
RAISE E1;
ELSE IF N=0 THEN
RAISE E2;
ELSE
WHILE I<=N LOOP
F:=F*I;
I:=I+1;
END LOOP;
END IF;
END IF;
DBMS_OUTPUT.PUT_LINE('FACTORIAL:'||F);
EXCEPTION
WHEN E1 THEN
DBMS_OUTPUT.PUT_LINE('FACTORIAL OF NEGATIVE NO CAN NOT BE FOUND');
WHEN E2 THEN
DBMS_OUTPUT.PUT_LINE('FACTORIAL OF ZERO IS 1');

END;
/
FACTORIAL:720

Statement processed.

FACTORIAL OF NEGATIVE NO CAN NOT BE FOUND
Statement processed.

FACTORIAL OF ZERO IS 1
Statement processed.




*********Q2**********
Q2: Find Prime  Numbers  in PLSQL

DECLARE
M NUMBER(3):=&M;
N NUMBER(3):=&N;
PRIME NUMBER;
R NUMBER;
PCOUNT NUMBER:=0;
BEGIN
DBMS_OUTPUT.PUT_LINE('PRIME NOS ARE');
<<OUTER_LOOP>>

FOR I IN M..N
LOOP
PRIME:=1;
<<INNER_LOOP>>
FOR J IN 2..I-1
LOOP
R:=MOD(I,J);
IF R=0 THEN
PRIME:=0;
END IF;
EXIT WHEN PRIME=0;
END LOOP INNER_LOOP;

IF PRIME=1 THEN
DBMS_OUTPUT.PUT_LINE(I);
PCOUNT:=PCOUNT+1;
END IF;
END LOOP OUTER_LOOP;
IF PCOUNT=0 THEN
DBMS_OUTPUT.PUT_LINE('NO PRIME NUMBER BETWEEN '||M||' AND '||N);
ELSE
DBMS_OUTPUT.PUT_LINE('TOTAL COUNT OF PRIME NUMBERS BETWEEN '||M||' AND '||N ||' IS ' ||PCOUNT);
END IF;
END;
/

Enter value for m: 1
old   2: M NUMBER(3):=&M;
new   2: M NUMBER(3):=1;
Enter value for n: 30
old   3: N NUMBER(3):=&N;
new   3: N NUMBER(3):=30;
PRIME NOS ARE
1
2
3
5
7
11
13
17
19
23
29
TOTAL COUNT OF PRIME NUMBERS BETWEEN 1 AND 30 IS 11

PL/SQL procedure successfully completed.


**********Q3**************
Q3: Find FIRST 50 NUMBERS OF FIBBONACI SERIES using Exception in PLSQL

DECLARE
A INT;
B INT;
C INT;
BEGIN
A:=&A;
B:=&B;
C:=0;
DBMS_OUTPUT.PUT_LINE('FIRST 50 NUMBERS OF FIBBONACI SERIES ARE');
LOOP
DBMS_OUTPUT.PUT_LINE(A);
DBMS_OUTPUT.PUT_LINE(B);
A:=A+B;
B:=A+B;
C:=C+2;
IF C=50 THEN
EXIT;
END IF;
END LOOP;
END;
/

Enter value for a: 0
old   6: A:=&A;
new   6: A:=0;
Enter value for b: 1
old   7: B:=&B;
new   7: B:=1;
FIRST 50 NUMBERS OF FIBBONACI SERIES ARE
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
10946
17711
28657
46368
75025
121393
196418
317811
514229
832040
1346269
2178309
3524578
5702887
9227465
14930352
24157817
39088169
63245986
102334155
165580141
267914296
433494437
701408733
1134903170
1836311903
2971215073
4807526976
7778742049

PL/SQL procedure successfully completed.


*********Q4***********
Q4: Find Square root in PLSQL
DECLARE
A INT;
B INT;
N INT;
BEGIN
A:=&A;
B:=&B;
N:=1;
WHILE B>0 LOOP
N:=N*A;
B:=B-1;
END LOOP;
DBMS_OUTPUT.PUT_LINE('A^B :'||N);
END;
/
Enter value for a: 5
old   6: A:=&A;
new   6: A:=5;
Enter value for b: 4
old   7: B:=&B;
new   7: B:=4;
A^B :625

PL/SQL procedure successfully completed.

**********Q5*************
CREATE TABLE STUDENT(ROLLNO NUMBER(2), SUB1 NUMBER(3),SUB2 NUMBER(3), SUB3 NUMBER(3), SUB4 NUMBER(3), SUB5 NUMBER(3) ,PERCENT NUMBER(5,2),GRADE VARCHAR2(20));
TABLE CREATED
SQL> DESC STUDENT;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 ROLLNO                                             NUMBER(2)
 SUB1                                               NUMBER(3)
 SUB2                                               NUMBER(3)
 SUB3                                               NUMBER(3)
 SUB4                                               NUMBER(3)
 SUB5                                               NUMBER(3)
 PERCENT                                            NUMBER(5,2)
 GRADE                                              VARCHAR2(20)

SQL> INSERT INTO STUDENT VALUES(&ROLLNO, &SUB1,&SUB2,&SUB3,&SUB4,&SUB5,&PERCENT,'&GRADE');
Enter value for rollno: 01
Enter value for sub1: 84
Enter value for sub2: 37
Enter value for sub3: 40
Enter value for sub4: 75
Enter value for sub5: 78
Enter value for percent: NULL
Enter value for grade: NULL
old   1: INSERT INTO STUDENT VALUES(&ROLLNO, &SUB1,&SUB2,&SUB3,&SUB4,&SUB5,&PERCENT,'&GRADE')
new   1: INSERT INTO STUDENT VALUES(01, 84,37,40,75,78,NULL,'NULL')

1 row created.

SQL> /
Enter value for rollno: 02
Enter value for sub1: 56
Enter value for sub2: 45
Enter value for sub3: 35
Enter value for sub4: 54
Enter value for sub5: 36
Enter value for percent: NULL
Enter value for grade: NULL
old   1: INSERT INTO STUDENT VALUES(&ROLLNO, &SUB1,&SUB2,&SUB3,&SUB4,&SUB5,&PERCENT,'&GRADE')
new   1: INSERT INTO STUDENT VALUES(02, 56,45,35,54,36,NULL,'NULL')

1 row created.

SQL> /
Enter value for rollno: 03
Enter value for sub1: 90
Enter value for sub2: 89
Enter value for sub3: 98
Enter value for sub4: 80
Enter value for sub5: 96
Enter value for percent: NULL
Enter value for grade: NULL
old   1: INSERT INTO STUDENT VALUES(&ROLLNO, &SUB1,&SUB2,&SUB3,&SUB4,&SUB5,&PERCENT,'&GRADE')
new   1: INSERT INTO STUDENT VALUES(03, 90,89,98,80,96,NULL,'NULL')

1 row created.

SQL> /
Enter value for rollno: 04
Enter value for sub1: 78
Enter value for sub2: 76
Enter value for sub3: 67
Enter value for sub4: 87
Enter value for sub5: 56
Enter value for percent: NULL
Enter value for grade: NULL
old   1: INSERT INTO STUDENT VALUES(&ROLLNO, &SUB1,&SUB2,&SUB3,&SUB4,&SUB5,&PERCENT,'&GRADE')
new   1: INSERT INTO STUDENT VALUES(04, 78,76,67,87,56,NULL,'NULL')

1 row created.

SQL> /
Enter value for rollno: 05
Enter value for sub1: 37
Enter value for sub2: 56
Enter value for sub3: 45
Enter value for sub4: 23
Enter value for sub5: 35
Enter value for percent: NULL
Enter value for grade: NULL
old   1: INSERT INTO STUDENT VALUES(&ROLLNO, &SUB1,&SUB2,&SUB3,&SUB4,&SUB5,&PERCENT,'&GRADE')
new   1: INSERT INTO STUDENT VALUES(05, 37,56,45,23,35,NULL,'NULL')

1 row created.


SQL> SELECT * FROM STUDENT; (BEFORE UPDATE PERCENT AND GRADE NULL)

    ROLLNO       SUB1       SUB2       SUB3       SUB4       SUB5    PERCENT
---------- ---------- ---------- ---------- ---------- ---------- ----------
GRADE
--------------------
         1         84         37         40         75         78
NULL

         2         56         45         35         54         36
NULL

         3         90         89         98         80         96
NULL


    ROLLNO       SUB1       SUB2       SUB3       SUB4       SUB5    PERCENT
---------- ---------- ---------- ---------- ---------- ---------- ----------
GRADE
--------------------
         4         78         76         67         87         56
NULL

         5         37         56         45         23         35
NULL


DECLARE

ROLL1 STUDENT.ROLLNO%TYPE;
SUB11 STUDENT.SUB1%TYPE;
SUB12 STUDENT.SUB2%TYPE;
SUB13 STUDENT.SUB3%TYPE;
SUB14 STUDENT.SUB4%TYPE;
SUB15 STUDENT.SUB5%TYPE;

PER1 STUDENT.PERCENT%TYPE;
GRADE1 STUDENT.GRADE%TYPE;

BEGIN
ROLL1:=&ROLL1;
SELECT SUB1,SUB2,SUB3,SUB4,SUB5 INTO SUB11,SUB12,SUB13,SUB14,SUB15 FROM STUDENT WHERE ROLLNO=ROLL1;
PER1:=(SUB11+SUB12+SUB13+SUB14+SUB15)/5;

IF PER1<40 THEN
DBMS_OUTPUT.PUT_LINE('FAILED');
UPDATE STUDENT SET PERCENT= PER1, GRADE='FAILED' WHERE ROLLNO=ROLL1;
ELSIF PER1<=60 AND PER1>=40 THEN
DBMS_OUTPUT.PUT_LINE('PASS CLASS');
UPDATE STUDENT SET PERCENT= PER1, GRADE='PASS CLASS' WHERE ROLLNO=ROLL1;
ELSIF PER1<=75 AND PER1>60 THEN
DBMS_OUTPUT.PUT_LINE('FIRST CLASS');
UPDATE STUDENT SET PERCENT= PER1, GRADE='FIRST CLASS' WHERE ROLLNO=ROLL1;
ELSE
DBMS_OUTPUT.PUT_LINE('DISTINCTION');
UPDATE STUDENT SET PERCENT= PER1, GRADE='DISTICTION' WHERE ROLLNO=ROLL1;
END IF;
END;
/

Enter value for roll1: 1
old  14: ROLL1:=&ROLL1;
new  14: ROLL1:=1;
FIRST CLASS

PL/SQL procedure successfully completed.

SQL> /
Enter value for roll1: 2
old  14: ROLL1:=&ROLL1;
new  14: ROLL1:=2;
PASS CLASS

PL/SQL procedure successfully completed.

SQL> /
Enter value for roll1: 3
old  14: ROLL1:=&ROLL1;
new  14: ROLL1:=3;
DISTINCTION

PL/SQL procedure successfully completed.

SQL> /
Enter value for roll1: 4
old  14: ROLL1:=&ROLL1;
new  14: ROLL1:=4;
FIRST CLASS

PL/SQL procedure successfully completed.

SQL> /
Enter value for roll1: 5
old  14: ROLL1:=&ROLL1;
new  14: ROLL1:=5;
FAILED

PL/SQL procedure successfully completed.

SQL> SELECT * FROM STUDENT;(AFTER UPDATE PERCENT AND GRADE ARE NOT NULL THEY ARE UPDATED APPROPRIATELY)

    ROLLNO       SUB1       SUB2       SUB3       SUB4       SUB5    PERCENT
---------- ---------- ---------- ---------- ---------- ---------- ----------
GRADE
--------------------
         1         84         37         40         75         78       62.8
FIRST CLASS

         2         56         45         35         54         36       45.2
PASS CLASS

         3         90         89         98         80         96       90.6
DISTICTION


    ROLLNO       SUB1       SUB2       SUB3       SUB4       SUB5    PERCENT
---------- ---------- ---------- ---------- ---------- ---------- ----------
GRADE
--------------------
         4         78         76         67         87         56       72.8
FIRST CLASS

         5         37         56         45         23         35       39.2
FAILED




********Q6********* 
CREATE TABLE ACCT_MSTR(ACCT_NO VARCHAR(5) PRIMARY KEY,CURBAL NUMBER(3));

Table created.

SQL> INSERT INTO ACCT_MSTR VALUES('&ACCT_NO',&CURBAL);
Enter value for acct_no: SB1
Enter value for curbal: 500
old   1: INSERT INTO ACCT_MSTR VALUES('&ACCT_NO',&CURBAL)
new   1: INSERT INTO ACCT_MSTR VALUES('SB1',500)

1 row created.

SQL> /
Enter value for acct_no: SB5
Enter value for curbal: 500
old   1: INSERT INTO ACCT_MSTR VALUES('&ACCT_NO',&CURBAL)
new   1: INSERT INTO ACCT_MSTR VALUES('SB5',500)

1 row created.

SQL> /
Enter value for acct_no: SB9
Enter value for curbal: 500
old   1: INSERT INTO ACCT_MSTR VALUES('&ACCT_NO',&CURBAL)
new   1: INSERT INTO ACCT_MSTR VALUES('SB9',500)

1 row created.

SQL> /
Enter value for acct_no: SB13
Enter value for curbal: 500
old   1: INSERT INTO ACCT_MSTR VALUES('&ACCT_NO',&CURBAL)
new   1: INSERT INTO ACCT_MSTR VALUES('SB13',500)

1 row created.

SQL> SELECT * FROM ACCT_MSTR;

ACCT_     CURBAL
----- ----------
SB1          500
SB5          500
SB9          500
SB13         500

BEGIN
UPDATE ACCT_MSTR
SET CURBAL=200 WHERE
ACCT_NO='SB13';
COMMIT;
END;
/

PL/SQL procedure successfully completed.

SQL> SELECT * FROM ACCT_MSTR;

ACCT_     CURBAL
----- ----------
SB1          500
SB5          500
SB9          500
SB13         200


************Q7************
Q7) FIND ODD and EVEN NUMBERS
DECLARE
N INT;
BEGIN
N:=&N;
IF N MOD 2=0 THEN
DBMS_OUTPUT.PUT_LINE('IT IS EVEN NUMBER');
ELSE
DBMS_OUTPUT.PUT_LINE('IT IS ODD NUMBER');
END IF;
END;
/
Enter value for n: 5
old   4: N:=&N;
new   4: N:=5;
IT IS ODD NUMBER

PL/SQL procedure successfully completed.

SQL> /
Enter value for n: 4
old   4: N:=&N;
new   4: N:=4;
IT IS EVEN NUMBER

PL/SQL procedure successfully completed.