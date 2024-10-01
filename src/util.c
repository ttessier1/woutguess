#include "util.h"
#include "config.h"

int steg_stat ;
int steg_foil;
int steg_foilfail;

void* checkedmalloc(size_t n)
{
	void* p;

	if (!(p = malloc(n))) {
		fprintf(stderr, "checkedmalloc: not enough memory\n");
		exit(1);
	}

	return p;
}