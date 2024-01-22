#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char* convert_in_base(long long int num, int base) {
    char representation[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* result = malloc(sizeof(char) * MAX_SIZE);
    int index = 0;

    do {
        result[index++] = representation[num % base];
        num /= base;
    } while (num != 0);

    result[index] = '\0';

    // Reverse the result string as the actual result is in reverse
    for(int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    return result;
}

void print_help() {
    printf("Usage: ./c2b [options] [number]\n");
    printf("Convert the given number to the specified base.\n");
    printf("Options:\n");
    printf("  -b BASE                   Specify the base of the output number (default : 2).\n");
    printf("  -B, --input-base BASE     Specify the base of the input number (default : 10).\n");
    printf("  --help, -h                Display this help message and exit.\n");
}

int main(int argc, char *argv[]) {
    int base = 2; // base de sortie
    int input_base = 10; // base d'entrée
    long long  int num;
    char *endptr;

    if (argc < 2) {
        printf("Usage: %s [-b base] [-B input_base] number\n", argv[0]);
        return 1;
    }

    int i = 1;
    while (i < argc - 1) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        }

        if (strcmp(argv[i], "-b") == 0) {
            base = strtol(argv[++i], &endptr, 10);
            if(base < 2 || base > 16) {
                printf("Invalid output base\n");
                return 1;
            }

            if (*endptr != '\0') {
                printf("Invalid output base\n");
                return 1;
            }
        } else if (strcmp(argv[i], "--input-base") == 0 || strcmp(argv[i], "-B") == 0) {
            input_base = strtol(argv[++i], &endptr, 10);
            if(input_base < 2 || input_base > 16) {
                printf("Invalid input base\n");
                return 1;
            }

            if (*endptr != '\0') {
                printf("Invalid input base\n");
                return 1;
            }
        }
        i++;
    }

    num = strtoull(argv[argc - 1], &endptr, input_base);
    if (*endptr != '\0') {
        printf("Invalid number\n");
        return 1;
    }

    char* result = convert_in_base(num, base);
    printf("%s\n", result);
    free(result);

    return 0;
}