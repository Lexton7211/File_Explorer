#include "logic.h"
#include <stdlib.h>

char* systemCommand(const char *command){
	FILE *fp = popen(command, "r");
	if (fp == NULL) {
		perror("popen failed");
		return NULL;
	}

	char *buffer = NULL;
	char chunk[1024];
	size_t size = 0;
	//printf("%ld", sizeof(buffer));
	while (fgets(chunk, sizeof(chunk), fp) != NULL) {
		size_t len = strlen(chunk);
		char *temp = realloc(buffer, size + len + 1);
		if(!temp){
			free(buffer);
			pclose(fp);
			return NULL;
		}
		buffer = temp;
		memcpy(buffer + size, chunk, len + 1);
		size += len;
	}
	pclose(fp);
	return buffer;
}
