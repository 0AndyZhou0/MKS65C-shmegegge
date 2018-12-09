#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
  key_t key = 823;
  int shmid;
  char * data;
  
  shmid = shmget(key, 200, 0666 | IPC_CREAT);
  data = shmat(shmid, (void *)0, 0);

  printf("data currently : %s\n",data);

  char ans;
  char * line;
  char temp;
  
  while(ans != 'y' && ans != 'n'){
    printf("Do you want to change the data? (y/n)\n");
    scanf("%c", &ans);
    
    //Clears line
    scanf("%[^\n]", line);
    scanf("%c", &temp);
  }
  
  if(ans == 'y'){
    
    
    printf("Insert data : ");
    scanf("%[^\n]", line);
    strcpy(data, line);

    //Clears line
    scanf("%[^\n]", line);
    scanf("%c", &temp);
  }

  printf("data currently : %s\n",data);
  
  printf("Do you want to delete the data? (y/n)\n");
  scanf("%c", &ans);

  if(ans == 'y'){
    shmctl(shmid, IPC_RMID, NULL);
  }
  
  shmdt(data);
  
  return 0;
}
