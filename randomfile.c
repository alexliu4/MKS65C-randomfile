#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>


int generateRand(){
  int fd = open("/dev/random", O_RDONLY);
  //printf("%d\n", fd);
  int rd;
  read(fd, &rd, sizeof(int));
  int cl = close(fd);
  // if (cl == 0){
  //   printf("file has been closed\n");
  // }
  //printf("The random: %d\n", rd);
  return rd;
}

int main(){
  long arr[10];
  printf("random number array \n");
  int i;
  for (i = 0; i < 10; i++){
    arr[i] = generateRand();
    printf("The %dth element in array: %lu\n", i, arr[i]);
  }

  //first file 
  int file1 = open("file.txt", O_CREAT | O_WRONLY,0777);
  printf("\nWriting numbers to file.txt\n");
  write(file1, arr, sizeof(arr));

  printf("Reading numbers from file.txt to verify\n\n");
  long arr1[10];

  //second file to verify
  int file2 = open("file.txt", O_RDONLY,0777);
  read(file2, arr1, sizeof(arr1));

  printf("Verification that values are the same:\n");
  for (int i = 0; i < 10; i++){
    printf("Random number %d: %lu\n",i,arr1[i]);
  }

  printf("\nclosing files\n");
  close(file1);
  close(file2);
  return 0;
}
