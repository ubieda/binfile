#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Invalid arguments\n");
        return -1;
    }

    char *filename = argv[1];
    int len = strtol(argv[2], NULL, 0);

    printf("Creating %s, %d bytes long\n", filename, len);

    uint8_t *data = malloc(len);

    if (argc == 4) {
        int val = strtol(argv[3], NULL, 0);
        memset(data, val, len);        
    } else {
        for (size_t i = 0 ; i < len ; i++) {
            data[i] = (uint8_t)(i);
        }
    }

    FILE *file = fopen(filename, "w");
    fwrite(data, len, 1, file);

    fclose(file);
    free(data);

    return 0;
}
