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
	int end;
	struct job* next_job;
};
/*
struct six_threads{
	
	struct job* t1; // ptr to first job on thread 1
	struct job* t2; // ptr to frist job on thread 2... 
	struct job* t3; // etc
	struct job* t4;
	struct job* t5;
	struct job* t6;
	
};
*/
int getEnd(struct job* job){
	
	return (job->start + job->length);	
}

struct job** jobSort(struct job** jobs, int n){
	//sort jobs by end time
    for(int j=1; j<n; j++){
		struct job* key = jobs[j];
		int i = j-1;

		while((i >=0) && (jobs[i]->end > key->end)){
			jobs[i+1] = jobs[i];
			i--;
		}
		jobs[i+1] = key;
    }
    return jobs;
}

int scheduleJobs(struct job** jobs, int n){
	struct job** threads = malloc(THREADS*sizeof(struct job*));
	//six_threads == [j][][j][][][]
	//				  | |  |
	//				  | | 
	//				  | 
	jobSort(jobs, n);
	int cur_thread = 0;
	threads[0] = jobs[0];
	for(int i = 1; i<n; i++){
		//for each job
		//make greedy choice: 
		//put at thread that is done job, or put at new thread 
		while(threads[cur_thread]->next_job != NULL){
			threads[cur_thread] = threads[cur_thread]->next_job;
		}	
		while(threads[cur_thread]->end > jobs[i]->start){
			cur_thread++;
		}
		while()
		threads[cur_thread] = jobs[i];
			
		printf("%d", cur_thread);
		
	}

	return 0;
}
void printJobs(struct job** jobs, int n){
	//print length and start time
	printf("start | length | end\n");
	for(int i = 0; i<n; i++){
		printf("%d, %d, %d\n",jobs[i]->start, jobs[i]->length, jobs[i]->end);
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
			job_i->start = 2*i+9;
			job_i->length = 3*i+2;	

		}else{
			job_i->start = 5*i+-5;
			job_i->length = 2*i-1;
		}
		job_i->end = getEnd(job_i);
		job_i->next_job = NULL;
		jobs[i] = job_i;
	}    
	//jobs before	
	printJobs(jobs, length);
	//sort jobs by end
	scheduleJobs(jobs, length);
	//jobs after	
	printJobs(jobs, length);
	
	freeJobs(jobs, length);
	return 0;
}
