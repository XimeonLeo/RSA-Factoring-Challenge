#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void work(u_int64_t);

int main(int ac, char **av)
{
	FILE *factorFile = NULL;
	char *string = NULL;
	size_t size = 0;
	u_int64_t dgt;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	factorFile = fopen(av[1], "r");
	if (!factorFile)
	{
		fprintf(stderr, "Error: can't open this %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (getline(&string, &size, factorFile) == -1)
			break;
		dgt = atoi(string);
		work(dgt);

	}
	free(string);
	fclose(factorFile);
	

	return (0);
}

void work(u_int64_t dgt)
{
	u_int64_t jmp = 3;

	if (dgt % 2 == 0)
	{
		printf("%lu=%lu*%d\n", dgt, dgt / 2, 2);
		return;
	}
	while (jmp * jmp <= dgt)
	{
		if (dgt % jmp == 0)
		{
			printf("%lu=%lu*%ld\n", dgt, dgt / jmp, jmp);
			return;
		}
		jmp += 2;
	}
	printf("%lu=%lu*%d\n", dgt, dgt, 1);
	return;
}
