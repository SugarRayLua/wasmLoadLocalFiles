#include "emscripten.h"
#include <stdio.h>

EMSCRIPTEN_KEEPALIVE void readLuaFile() {
	FILE *f = fopen("/tmp/test.lua", "r");
	// max length of test.lua file = 32 chart
	char buf[32];
	if (fgets(buf, 32, f) == NULL) {
		fprintf(stderr, "problem reading file");
		return;
	}

	printf("%s\n", buf);
	fclose(f);
}
