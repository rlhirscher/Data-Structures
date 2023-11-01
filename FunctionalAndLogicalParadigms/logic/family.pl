/*
 * Ryan Hirscher
 * CSC4510 Programming Language Design
 * 10/17/2023
 * Logic Programming (Prolog) Family Tree
 *
 * This program is a knowledge base for a family tree example. Below are facts that identify the males, females, and parents. Following that are the rules that identify relationships between the facts.
 *
 * To Compile: gplc family.pl
 * To Execute: ./family 
 *
 * The user is then prompted for a query. See the README for query examples.
 * The prompt agent can be terminated with "halt."
*/

/*-------*/
/* Facts */
/*-------*/

/* Males */
male(allen).
male(brian).
male(harold).
male(david).
male(leonard).
male(arthur).
male(oliver).
male(peter).
male(frank).
male(steve).
male(jeremy).
male(zach).
male(tom).
male(jason).
male(michael).

/* Females */
female(nancy).
female(grace).
female(elizabeth).
female(marie).
female(kate).
female(christine).
female(naomi).
female(irene).
female(tracey).
female(rachel).
female(jane).
female(shannon).
female(jennifer).
female(belinda).
female(susan).
female(anne).

/* Parents - (parent, child) */
parent(allen, grace).
parent(anne, grace).
parent(brian, leonard).
parent(elizabeth, leonard).
parent(allen, kate).
parent(anne, kate).
parent(david, arthur).
parent(christine, arthur).
parent(brian, naomi).
parent(elizabeth, naomi).
parent(harold, oliver).
parent(marie, oliver).
parent(harold, tracey).
parent(marie, tracey).
parent(david, peter).
parent(christine, peter).
parent(grace, irene).
parent(leonard, irene).
parent(grace, frank).
parent(leonard, frank).
parent(kate, rachel).
parent(arthur, rachel).
parent(kate, nancy).
parent(arthur, nancy).
parent(naomi, steve).
parent(oliver, steve).
parent(naomi, jane).
parent(oliver, jane).
parent(tracey, jeremy).
parent(peter, jeremy).
parent(frank, shannon).
parent(rachel, shannon).
parent(frank, zach).
parent(rachel, zach).
parent(frank, jennifer).
parent(rachel, jennifer).
parent(nancy, tom).
parent(steve, tom).
parent(nancy, jason).
parent(steve, jason).
parent(nancy, belinda).
parent(steve, belinda).
parent(jane, michael).
parent(jeremy, michael).
parent(jane, susan).
parent(jeremy, susan).

/*-------*/
/* Rules */
/*-------*/

/* Married to */
spouse(X, Y) :-
    male(X),
    female(Y),
    parent(X, Z),
    parent(Y, Z),
    X \= Y.

/* Mother */
mother(X, Y) :-
    female(X),
    parent(X, Y).

/* Father */
father(X, Y) :-
    male(X),
    parent(X, Y).

/* Brother */
brother(X, Y) :-
    male(X),
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

/* Sister */
sister(X, Y) :-
    female(X),
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

/* Son */
son(X, Y) :-
    male(X),
    parent(Y, X).

/* Daughter */
daughter(X, Y) :-
    female(X),
    parent(Y, X).

/* Father of parent */
grandfather(X, Y) :-
    male(X),
    parent(X, Z),
    parent(Z, Y).

/* Mother of parent */
grandmother(X, Y) :-
    female(X),
    parent(X, Z),
    parent(Z, Y).

/* Sister of parent */
aunt(X, Y) :-
    female(X),
    parent(Z, Y),
    sister(X, Z).

/* Brother of parent */
uncle(X, Y) :-
    male(X),
    parent(Z, Y),
    brother(X, Z).

/* Brother or sister of at most twice removed parents */
cousin(X, Y) :-
    parent(Z, X),
    parent(W, Y),
    (brother(Z, W); sister(Z, W)),
    X \= Y.
