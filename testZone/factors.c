#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *factor = NULL;
	char *buffer = NULL;
	size_t buff_size = 0;
	unsigned long long int num, i;

	if (argc != 2)
	{
		fprintf(stderr, "kindly execute with the name of file\n");
		exit(EXIT_FAILURE);
	}
	factor = fopen(argv[1], "r");
	if (!factor)
	{
		fprintf(stderr, "can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (getline(&buffer, &buff_size, factor) == -1)
			break;
		num = atoi(buffer);

		for (i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				printf("%lld=%lld*%lld\n", num, num/i, i);
				break;
			}
			i++;
		}
	}
	free(buffer);
	fclose(factor);

	return (0);
}
