#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *factorFile = NULL;
	size_t size = 0;
	char *val = NULL;
	unsigned long long int dgt, divisor;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	factorFile = fopen(argv[1], "r");
	if (!factorFile)
	{
		fprintf(stderr, "Error: can't open this file: %s\n", argv[1] );
		exit(EXIT_FAILURE);
	}
	while (getline(&val, &size, factorFile) != -1)
	{
		dgt = atoi(val);
		for (divisor = 2; divisor < dgt; divisor++)
		{
			if (dgt % divisor == 0)
			{
				printf("%llu=%llu*%llu\n", dgt, (dgt / divisor), divisor);
				break;
			}
		}
	}
	free(val);
	fclose(factorFile);


	return (0);
}
