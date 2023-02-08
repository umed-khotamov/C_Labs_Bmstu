#include "average.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        return NO_FILE;

    FILE *file;
    
    file = fopen(argv[1], "r");

    if (file == NULL)
        return FILE_OPEN_ERROR;
    
    int return_code = 0;
    double average = 0;

    if ((return_code = find_average(file, &average)))
        return return_code;
    
    rewind(file);

    double res = find_close_to_average(file, average);

    fclose(file);

    printf("%lf\n", res);

    return EXIT_SUCCESS;
}
