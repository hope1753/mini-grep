    #include <stdio.h>
    #include <string.h>

    #define MAXLINES 1000
    #define MAXLEN 300

    typedef struct {
        int number;
        int invert;
        int count;
    } Options;

// 방법 A: 선언 시 0으로 통째로 초기화 (C99 표준)
// Options options = {0}; 

// 방법 B: 지정 지정자(Designated Initializer) 활용
// Options options = { .number = 0, .invert = 0, .count = 0 };

    Options __init__options__(Options o) {
        o.count = 0;
        o.invert = 0;
        o.number = 0;

        return o;
    }
    int main(int argc, char *argv[]) {
        char *fname;
        int found = 0, c;
        long lineno = 0;
        Options options;
        char line[MAXLEN];

        options = __init__options__(options);
        
        while (--argc > 0 && (*++argv)[0] == '-') {
            while (c = *++argv[0]) 
            {
                switch (c)
                {
                case 'n':
                    options.number = 1;
                    break;
                case 'v':
                    options.invert = 1;
                    break;
                
                case 'c':
                    options.count = 1;
                    break;
                
                default:
                    printf("grep : illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
                }
            }
            
        }

        if (argc != 2) {
            printf("Usage : ./main -n -v -c pattern filename\n");
            return found;
        }
        
        char *pattern = (*argv++);
        FILE *fp = fopen(*argv, "r");

        if (fp == NULL) {
            perror("Error: The file cannot be found .");
            return -1;
        }
        while (fgets(line, sizeof(line), fp) != NULL) {
            lineno++;
            if (strstr(line, pattern) && options.invert != 1) {
                found++;
                if (options.number == 1) {
                    printf("%ld. ", lineno);
                }
                printf("%s", line);
            }
            if (!strstr(line, pattern) && options.invert == 1) {
                found++;
                if (options.number == 1) {
                    printf("%ld", lineno);
                }
                printf("%s", line);
            }
        }
        if (options.count) {
            printf("\nFound : %d\n", found);
        }

        fclose(fp);
        
        return found;
    }