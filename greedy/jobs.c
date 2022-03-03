#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int insertionSort(int* jobs, int n){
    // 2 3 4 7 8 9 5
    //         j=5 i=6
    //int i = 1; //first index
    for(int i =1; i<n; i++){
        printf("%d", jobs[i]);
    }
    return 0;
}

int jobs(int *jobs, int n){
    return 0;    
}

int main(){
    
    int length = 7;
    int* jobs = malloc(length*sizeof(struct job));
    printf("%d", length*sizeof(struct job) );
    //printf("%d", sizeof(jobs));

    for(int i = 0; i< length; i++){
        struct job job_i;
        job_i.length = 7;
        job_i.start = 5;
        memcpy((jobs + 8*i), &job_i, sizeof(struct job)); 
    }
    //printf("%d\n", sizeof(jobs));
    //printf("%d, %d", *(jobs), *(jobs+4)); 
    return 0;
}