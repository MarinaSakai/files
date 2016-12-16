#include<stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main_prg(int, char**);
void fill_a(char* ans);


int main(int argc, char** argv){

  struct rusage u;
  struct timeval start, end;
  
  getrusage(RUSAGE_SELF, &u);
  start = u.ru_utime;
  
  main_prg(argc, argv);
  
  getrusage(RUSAGE_SELF, &u );
  end = u.ru_utime;
  
  fprintf(stderr, "%lf\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6);
    
  return(0);
}

int main_prg(int argc, char** argv){
  /** implement here  **/
    
    //input mushikui
    char ans[500001];
    //strncpy(ans,argv[1],500000);
    scanf("%s",ans);
    
    
    
    //x->a
    fill_a(ans);
    
    //input keywords
    char key[50000];
    while(scanf("%s",key)==1){
        //printf("_%s\n",key);
    }
    
    printf("%s\n",ans);
    

  return(0);
}

void fill_a(char* ans){
    //x->a
    int i;
    for(i=0;i<500001;i++){
        if(ans[i]=='x'){
            ans[i]='a';
        }
    }
}
