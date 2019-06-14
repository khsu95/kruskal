#include"set.h"

char set[10000] = { 0 };

ROOT Find(char vertical)
{
	int depth = 0;
	ROOT root;
	while (set[vertical - 65] != vertical - 65)
	{
		vertical = set[vertical - 65];
		depth++;
	}
	root.depth = depth;
	root.vertical = vertical;

	return root;
}

int Union(ROOT root1, ROOT root2)
{
	if (root1.depth > root2.depth)		set[root1.vertical - 65] = root2.vertical;
	else set[root2.vertical - 65] = root1.vertical;
	return 0;
}