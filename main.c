/*Team tat -- Piotr Milewski & Victor Teoh
  Period 10
  HW08
  2017-10-31*/

#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <errno.h>

void print_error(int err){
  if (err == -1){
    printf("%s\n", strerror(errno));
    exit(1);
  }
}

char *prettyBytes( long unsigned buff, int B, char *retStr){
  if (buff / 1024 >= 1){
    prettyBytes( buff / 1024, ++B, retStr);
  }
  else{
    sprintf( retStr, "%lu", buff);
    if (B == 0){
      strcat( retStr, "B");
    }
    else if (B == 1){
      strcat( retStr, "KB");
    }
    else if (B == 2){
      strcat( retStr, "MB");
    }
    else if (B == 3){
      strcat( retStr, "GB");
    }
    else if (B == 4){
      strcat( retStr, "TB");
    }
  }
  return retStr;
}

//get current status of bit in perm
char getBitMode( int permissions, int bit){
  return (permissions >> bit) & 1; //shift to the right "bit" times and check if 1st digit is a 1
}

char *convertMode( int permissions, char *retStr){
  char currMode; //sets current permission mode
  retStr[0] = '-'; //only checking files, not directories or links
  int i = 1;
  for (; i <= 9; i++) {
    if (i % 3 == 1)
      currMode = 'r';
    else if (i % 3 == 2)
      currMode = 'w';
    else if (i % 3 == 0)
      currMode = 'e';
    //check if current bit is a 1
    if (getBitMode( permissions, 9-i))
      retStr[i] = currMode;
    else
      retStr[i] = '-';
  }
  retStr[10] = 0; //null terminator
  return retStr;
}

char *lsifyPerms( int permissions, char *retStr){
  return convertMode( permissions, retStr);
}

int main(){

  struct stat buff;
  stat("main.c", &buff);

  printf("\nFile size of main.c: %lu\n", buff.st_size);
  printf("Mode of main.c: %o\n", buff.st_mode);
  printf("Time of last access: %s\n", ctime(&buff.st_atime));

  char retStr[256];
  printf("Coherent file size of main.c: %s\n", prettyBytes( buff.st_size, 0, retStr));

  char *retStr2[16];
  printf("\nPermissions in the ls -l format: %s\n", lsifyPerms( buff.st_mode, retStr2));

  return 0;
}
