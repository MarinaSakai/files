#include <stdio.h>

int accuracy_check(int, char**);

int main(int argc, char** argv){

	accuracy_check(argc, argv);

	return 0;
}

int accuracy_check(int argc, char** argv){

	FILE *fpin, *fpout;
	char *fnamein = argv[1];
	char *fnameout =  argv[2];
	char c;
	int i, sum=0, wrong=0;
	double accuracy;
	char in[500000], out[500000];

	fpin = fopen(fnamein, "r");
	fpout = fopen(fnameout, "r");
	if(fpin == NULL || fpout == NULL){
		return -1;
	}

	fgets(in, 500000, fpin);
	fgets(out, 500000, fpout);

	fclose(fpin);
	fclose(fpout);

	for(i=0; i<500000; i++){
		sum++;
		if(in[i]!=out[i]){
			wrong++;
		}
	}

	accuracy = (double)wrong/sum;

	printf("accuracy is = %lf\n", accuracy);

	return 0;

}
