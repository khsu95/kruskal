#include"set.h"

char set[10000] = { 0 };

ROOT Find(char vertical)
{
	int depth = 0;
	ROOT root;
	while (set[vertical] != vertical)
	{
		vertical = set[vertical];
		depth++;
	}
	root.depth = depth;
	root.vertical = vertical;

	return root;
}

int Union(ROOT root1, ROOT root2)
{
	if (root1.depth > root2.depth)		set[root1.vertical] = root2.vertical;
	else set[root2.vertical] = root1.vertical;
	return 0;
}