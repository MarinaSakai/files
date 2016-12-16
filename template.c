#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

int main_prg(int, char**);
void fill_a(char*);
void match_key(char*, char*);
void control_match_key(char*, char**);


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

//noribenとkeyあげたらnoribenのうちkeyが該当できる場所を全て書き換えていく
void match_key(char* noriben, char* key){
	
	int key_len = strlen(key);
	int head,i,k;
	
	for(head=0; head<500000-key_len; head++){

		//checking if key matches
		for(i=0; i<key_len; i++){
			if((key[i]!=noriben[head+i]) && (noriben[head+i]!='x')){
				break;
			}
			if(i==key_len-1){//key match -> fill noriben
				for(k=0; k<key_len; k++){
					if(noriben[head+k]=='x'){
						noriben[head+k]=key[k];
					}
				}
			}
		}
		//
		
	}
}

void control_match_key(char* noriben, char** key){

	int i;
	///////////////////!!!!!!!!
	//ここのiの上限を変えると精度調整になる
	for(i=0; i<15; i++){
		match_key(noriben, key[i]);
	}

}
