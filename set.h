#ifndef SET_H
#define SET_H
typedef struct ROOT {
	char vertical;
	int depth;
}ROOT;

extern char set[10000];

ROOT Find(char vertial);
int Union(ROOT root1, ROOT root2);

#endif