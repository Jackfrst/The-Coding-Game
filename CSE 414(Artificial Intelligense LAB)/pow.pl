power(0,N,0):- N>0.
power(X,0,1):- X>0.
power(X,N,V):-
    X>0,N>0,
    N1 is N-1,
    power(X,N1,V1),
    V is V1*X.
