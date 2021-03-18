/*
 CFLAG Generator
-----------------
LividPhysics 2021
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    char cmd[512];
    char comp[4];
    int cc;
    bool lang = true; // true = C, false = C++

    printf("?> C or C++? (1 or 2, default 1): ");
    cc = getchar();

    if(cc == (int) '2') { // looking for the char, not the numerical representation
        strcpy(comp, "g++");
        lang = false;
    } else {
        strcpy(comp, "gcc");
    }

    char tbc[63]; char ofn[63]; 
    char spc = ' '; // strncat does wacky things if i just add ' '
    
    printf("?> What is to be compiled? (1 filename): ");
    scanf("%s", tbc); // tbc means to be compiled
    printf("?> What will the output file be? (1 filename): ");
    scanf("%s", ofn); // ofn means output file name
    strcat(cmd, comp); strcat(cmd, " -o "); strcat(cmd, ofn); strncat(cmd, &spc, 1); strcat(cmd, tbc);
    printf("#> %s\n", cmd);
    getchar(); // clear the buffer

    // c/c++ versions
    printf("?> Using any special C/C++ versions? (y/N, default n): "); // y is 121
    int yn = getchar();

    // custom C/C++ versions
    if(yn == (int) 'y') {
        // if they want to use special versions
        getchar(); // clear the buffer
        if(lang) {
            // 6 possible versions that can be changed
            printf("1) C90    4) GNU 90\n2) C99    5) GNU 99\n3) C11    6) GNU 11\n");
            printf("?> Which version? (type a number, default GNU 11): ");
            int cstdc = getchar();
            switch(cstdc) {
                // TODO: make this look less shitty. maybe select from a list of versions?
                case (int) '1':
                    printf("Adding C90 flag");
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=c90");
                    break;
                case (int) '2':
                    printf("Adding C99 flag");
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=c99");
                    break;
                case (int) '3':
                    printf("Adding C11 flag");
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=c11");
                    break;
                case (int) '4':
                    printf("Adding GNU90 flag");
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=gnu90");
                    break;
                case (int) '5':
                    printf("Adding GNU99 flag");
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=gnu99");
                    break;
                default:
                    printf("Adding GNU11 flag"); // GNU11 C is the default for gcc
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=gnu11");
                    // i mean in theory you don't need this flag, but it's nice to give the illusion of choice
                    break;
            }
        } else {
            printf("1) C++98    6) GNU++98\n2) C++03    7) GNU++03\n3) C++11    8) GNU++11\n4) C++14    9) GNU++14\n5) C++17    0) GNU++17\n");
            printf("?> Which version? (type a number, default GNU++14): ");
            int cppstdc = getchar();
            switch(cppstdc) {
                case (int) '1':
                    // version is C++98
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=c++98");
                    break;
                case (int) '2':
                    // version is C++03
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=c++03");
                    break;
                case (int) '3':
                    // version is C++11
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=c++11");
                    break;
                case (int) '4':
                    // version is C++14
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=c++14");
                    break;
                case (int) '5':
                    // version is C++17
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=c++17");
                    break;
                case (int) '6':
                    // version is C++98
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=gnu++98");
                    break;
                case (int) '7':
                    // version is C++03
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=gnu++03");
                    break;
                case (int) '8':
                    // version is C++11
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=gnu++11");
                    break;
                // 9 is skipped because GNU++14 (#9) is the default in g++
                case (int) '0':
                    // version is C++17
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=gnu++17");
                    break;
                default:
                    // version is C++14
                    strncat(cmd, &spc, 1); strcat(cmd, "-std=gnu++14"); // default C++ version. again, illusion of choice
                    break;
            }
        }
        getchar(); // clear the buffer
    }
    printf("#> %s\n", cmd);
    printf("Copying to clipboard...\n");

    // copy the command to the clipboard
    // xclip -selection clipboard report.txt
    system("touch temp");
    FILE *fp = fopen("temp", "w");
    char * tc = cmd;
    tc++;
    fprintf(fp, "%s", tc);
    fclose(fp);

    system("xclip -selection clipboard temp");
    system("rm temp");
    printf("Copied!\n");
}