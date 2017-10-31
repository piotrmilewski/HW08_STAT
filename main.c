/*Team tat -- Piotr Milewski & Victor Teoh
  Period 10
  HW08
  2017-10-31*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

char *prettyBytes( long unsigned buff, int B, char *s){
  if (buff / 1024 >= 1){
    prettyBytes( buff / 1024, ++B, s);
  }
  else{
    sprintf( s, "%lu", buff);
    if (B == 0){
      strcat( s, "B");
    }
    else if (B == 1){
      strcat( s, "KB");
    }
    else if (B == 2){
      strcat( s, "MB");
    }
    else if (B == 3){
      strcat( s, "GB");
    }
    else if (B == 4){
      strcat( s, "TB");
    }
  }
  return s;
}
/*
char *convertMode( int perm, char *s){
  

}

char *lsify( int perm, char *s){


}
*/
int main(){

  struct stat buff;
  stat("main.c", &buff);

  printf("\nFile size of main.c: %lu\n", buff.st_size);
  printf("Mode of main.c: %o\n", buff.st_mode);
  printf("Time of last access: %s\n", ctime(&buff.st_atime));

  char s[256];
  printf("\nCoherent file size of main.c: %s\n", prettyBytes(buff.st_size, 0, s));

  //printf("%s\n", lsify( buff.st_mode, 
  //st_mode 
  //st_uid id of owner
  //st_gid id of group
  //ctime
  //file name
  return 0;
}
