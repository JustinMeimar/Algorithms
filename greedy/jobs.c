#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define THREADS 6
/*
lets say we have a multithreaded processor, but want to minimize the cores used.
what should we do ? 
sort jobs by order of ending time.
--------------------  ----------------   ----------------
       ----------   -------   ------
           ------------  ---------------
*/
struct job{
    int start;
    int length;
};

int getEnd(struct job* job){

	return (job->start + job->length);	
}
int jobSort(struct job** jobs, int n){
	//sort jobs by end time
    for(int j=1; j<n; j++){
		struct job* key = jobs[j];
		int i = j-1;

		while((i >=0) && (getEnd(jobs[i]) > getEnd(key))){
			jobs[i+1] = jobs[i];
			i--;
		}
		jobs[i+1] = key;
    }
    return 0;
}

int jobs(int *jobs, int n){
    return 0;    
}
void printJobs(struct job** jobs, int n){
	//print length and start time
	printf("start | length | end\n");
	for(int i = 0; i<n; i++){
		printf("%d, %d, %d\n",jobs[i]->start, jobs[i]->length, getEnd(jobs[i]));
	}
	return;
}

void freeJobs(struct job** jobs, int n){
	//go through pointers in pointer arrray, then free **jobs	
	for(int i = 0; i<n; i++){
		free(jobs[i]);
	}	
	free(jobs);
	return;
}

int main(){
    
    int length = 7;
    struct job** jobs = malloc(length*sizeof(struct job*));
		
	for(int i = 0; i< length; i++){
		struct job* job_i = malloc(sizeof(struct job));
		if(i % 2 == 0){
			job_i->start = i+7;
			job_i->length = i+1;

		}else{
			job_i->start = 2*i+1;
			job_i->length = 3*i-8;
		}	
		jobs[i] = job_i;
	}    
	//jobs before	
	printJobs(jobs, length);
	//sort jobs by end	
	jobSort(jobs, length);
	//jobs after	
	printJobs(jobs, length);
	
	freeJobs(jobs, length);
	return 0;
}
