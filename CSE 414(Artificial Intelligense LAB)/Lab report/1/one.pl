male(jhon).
male(prince).
male(ally).
male(pat).
male(alex).
male(bob).
male(jim).
male(tot).
female(mary).
female(ana).
female(ally).
female(pam).
parent(jhon,mary).
parent(jhon,prince).
parent(mary,alex).
parent(mary,ana).
parent(prince,pat).
parent(prince,ally).
parent(alex,bob).
parent(ana,jim).
parent(pat,jim).
parent(jim,pam).
parent(jim,tot).
mother(X,Y):-female(X),parent(X,Y).
father(X,Y):-male(X),parent(X,Y).
grandfather(X,Y):-male(X),parent(X,Z),parent(Z,Y).
grandmother(X,Y):-female(X),parent(X,Z),parent(Z,Y).
sister(X,Y):- X\=Y,female(X),parent(Z,X),parent(Z,Y).
brother(X,Y):- X\=Y,male(X),parent(Z,X),parent(Z,Y).
uncle(X,Y):-male(X),parent(Z,Y),brother(X,Z).
aunt(X,Y):-female(X),parent(Z,Y),sister(X,Z).
cousine(W,X):-parent(Y,W),parent(Z,X),brother(Y,Z).
cousine(W,X):-parent(Y,W),parent(Z,X),sister(Y,Z).
predecessor(X,Y):-parent(X,Y).
predecessor(X,Y):-parent(X,Z),predecessor(Z,Y).

cls:- write('\33\[2J').


