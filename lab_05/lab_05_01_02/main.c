#include "process.h"

int main()
{
    FILE *file = stdin;
    int index = 0;

    if (process(file, &index) == NO_DATA)
    {
        fprintf(stdout, "No input data");

        return NO_DATA;
    }

    fprintf(stdout, "%d\n", index);

    return EXIT_SUCCESS;
}
