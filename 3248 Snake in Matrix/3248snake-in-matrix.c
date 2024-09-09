#include <string.h>
int finalPositionOfSnake(int n, char** commands, int commandsSize) {
    int i=0,j=0;
    for(int x=0;x<commandsSize;x++){
        if(strcmp("UP",commands[x])==0)
            i--;
        else if(strcmp("DOWN",commands[x])==0)
            i++;
        else if(strcmp("RIGHT",commands[x])==0)
            j++;
        else if(strcmp("LEFT",commands[x])==0)
            j--;
    }
    return (i*n)+j;
}