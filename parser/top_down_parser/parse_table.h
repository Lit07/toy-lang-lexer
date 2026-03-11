#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H

#define NT 6
#define T 10

char *nonterminals[NT] = {
"E","L","L'","R","R'","F"
};

char *terminals[T] = {
"id","+","-","*","/","(",")","&&","||","$"
};

char *table[NT][T] = {

/* id */ /* + */ /* - */ /* * */ /* / */ /* ( */ /* ) */ /* && */ /* || */ /* $ */

/* E */
{"L","","","","","L","synch","","","synch"},

/* L */
{"RL'","","","","","RL'","synch","","","synch"},

/* L' */
{"","+RL'","-RL'","","","","ε","","ε","ε"},

/* R */
{"FR'","","","","","FR'","synch","","","synch"},

/* R' */
{"","","","","","","ε","&&FR'","ε","ε"},

/* F */
{"id","","","","","(E)","synch","","",""}

};

#endif