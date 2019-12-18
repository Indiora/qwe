#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CHARS 100
#define WORDS 30
#define SIMB 33


char* strwr(){
    char c;
    int size = SIMB;
    char* str = (char*)malloc(SIMB * sizeof(char));
    int currentchar = 0;
    while((c = getchar()) != '\n'){
        if (currentchar == (SIMB - 2)){
            size += SIMB;
            str = (char*)realloc(str, size * sizeof(char));
        }
        str[currentchar] = c;
        currentchar++;
    }
    str[currentchar] = '\0';
    return str;

}
char* textwr(){
    char c;
    int size = CHARS;
    int currentchar = 0;
    char* text = (char*)malloc(CHARS * sizeof(char));
    while((c = getchar()) != '\n'){
        if (currentchar == (CHARS - 2)){
            size += CHARS;
            text = (char*)realloc(text, size * sizeof(char));
       }
        text[currentchar] = c;
        currentchar++;
    }
    text[currentchar] = '\0';
    return text;
}

char** smash(char* text, int* count) {
    char *word;
    char **words;
    int Count = 0;
    words = malloc(sizeof(char *));
    word = strtok(text, " .\n");
    while (word != NULL) {
        words[Count] = word;
        Count++;
        words = (char **) realloc(words, (Count + 1) * sizeof(char *));
        word = strtok(NULL, " .\n");
    }
    *count = Count;
    return words;
}



int comp(const void *a, const void *b) {
    char *p1 = (char *) a;
    char *p2 = *(char **) b;
    return strcmp(p1, p2);

}

int main() {
    char* text;
    char* str;
    char** textwd;
    int count;
    text = textwr(text);
    str = strwr(str);
    //printf("%s 00", str);
    //printf("%s 00", text);
    textwd = smash(text, &count);
    qsort(textwd, count, sizeof(char*), strcmp);
    //printf("%s", textwd[2]);
    if ( (char *)bsearch(str, textwd, count, sizeof(char *), comp)) {
        printf("exists\n");
    } else {
        printf("doesn't exist\n");
    }
    return 0;
}
