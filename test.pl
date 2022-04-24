%list manipulation in the same way as the %list
(define evens (lambda (x) (if (null? x) (list) (cons (car x) (evens (cdr x))))))
(define odds (lambda (x) (if (null? x) (list) (cons (car x) (odds (cdr x))))))
(define evens-odds (lambda (x) (if (null? x) (list) (cons (car x) (evens-odds (cdr x))))))
(define odds-evens (lambda (x) (if (null? x) (list) (cons (car x) (odds-evens (cdr x))))))



(const 8 ())
(cobst ((function () {
    (define (f x) (if (null? x) (list) (cons (car x) (f (cdr x))))
    (f (list 1 2 3 4 5 6 7 8))
    }))
})))


function (lambda (x) (if (null? x) (list) (cons (car x) (f (cdr x)))))





bigger x, y = if x > y then x else y


[1,2,3,4,5,6,7,8,9,10] = [Head | Tail].
Head = 1
Tail = [2,3,4,5,6,7,8,9,10]


[quod, licet, jovi, non, licet, bovi] = [_, x | _].


%for having the last element
?- [quod, licet, jovi, non, licet, bovi] = [_, X, Y, Z, A | Tail].


%List manipulation

?- [1,2,3,4,5,6,7,8,9,10] = [Head | Tail].
Head = 1,
Tail = [2, 3, 4, 5, 6, 7, 8, 9, 10].

?- [quod, licet, jovi, non, licet, bovi] = [_, x | _].
false.

?- [quod, licet, jovi, non, licet, bovi] = [_, X | _].
X = licet.

?- [quod, licet, jovi, non, licet, bovi] = [_, X | Tail].
X = licet,
Tail = [jovi, non, licet, bovi].

?- [quod, licet, jovi, non, licet, bovi] = [_, X, Y].
false.

?- [quod, licet, jovi, non, licet, bovi] = [_, X, Y | Tail].
X = licet,
Y = jovi,
Tail = [non, licet, bovi].

?- [quod, licet, jovi, non, licet, bovi] = [_, X, Y, Z, A, B | Tail].
X = A, A = licet,
Y = jovi,
Z = non,
B = bovi,
Tail = [].

?- [quod, licet, jovi, non, licet, bovi] = [_, X, Y, Z, A | Tail].
X = A, A = licet,
Y = jovi,
Z = non,
Tail = [bovi].


[elephant, [], X, parent(X, tom), [a,b,c], f(22)]

concat_list(X, Y, [a,b,c,d]).

X = []
Y = [a, b, c ,d]


X = [a].

parent(peter, sharon).
parent(peter, lucy).

male(peter).

female(lucy).
female(sharon).
father(X, Y) :-
    parent(X, Y),
    male(X).

sister(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    female(X).


factorial(1, 1). % base case
     factorial(N, Result) :-  % recursion step
       N > 1,
       N1 is N - 1,
       factorial(N1, Result1),
       Result is Result1 * N.

