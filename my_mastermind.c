#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
void get_input(char user_input[],int code_lenght){

    int nb_of_bytes_Read;
    bool validInput= false;
    while(!validInput){
     nb_of_bytes_Read = read(0,user_input,code_lenght);
    if(nb_of_bytes_Read == -1){
        printf("Error from stdin\n");
    }else if (nb_of_bytes_Read ==0) {
        printf("it seems you don't enter any input\n");
        exit(0);
    }else{
        user_input[code_lenght-1]='\0';
        if(nb_of_bytes_Read - 1 != 4){
            printf("Please enter 4 digits\n");
        }else{
            validInput=true;
        }
    }
    }
    
}
char * generate_random(int nb_of_char_to_read){
   char* code;
   srand(time(NULL));
        code = (char*)malloc((nb_of_char_to_read)*sizeof(char));
        const char range_of_int[]="012345678";
        for(int j=0; j<4;j++){
            int index= rand()% 9;

            code[j]= range_of_int[index];
        }
        code[4]='\0';
        return code;
}
int main(int argc,char** argv){
    int getopt_output;
    char* code ;
    int attempts = 10;

    char user_input[4];

    int nb_of_char_to_read=4;
    code=generate_random(nb_of_char_to_read);


    while((getopt_output=getopt(argc,argv,"c:t:"))!=-1){
        switch(getopt_output){
            case 'c':
            if(code!=NULL){
                free(code);
            }
            code= optarg;
            break;
            case 't':
            attempts= atoi(optarg);
            break;
        }
    };

  for(int i=0;i<attempts;i++){
      printf("Will you find the secret code?\n"); 
      printf("Please enter a valid guess\n");

      get_input(user_input,5);


    if(strncmp(code,user_input,nb_of_char_to_read)==0){

      printf("Congratz! You did it!\n");

      break;
    }else{
        int X=0;
        int Y=0;
        int matched_l[4]={0};
        int matched_k[4]={0};
        for(int k=0;k<nb_of_char_to_read;k++){
            for(int l=0;l<nb_of_char_to_read;l++){
                if(code[k]==user_input[l] && k==l){
                 X++;
                 matched_l[l]=1;
                 matched_k[k]=1;
                }
                else if(code[k]==user_input[l] && k!=l && !matched_l[l] && !matched_k[k]){
                    Y++;
                    matched_l[l]=1;
                    matched_k[k]=1;
                }
            }
        }
        printf("Well placed pieces: %d\n",X);
    printf("Misplaced pieces: %d\n",Y);
    }
    
  }

    
    return 0;
}
