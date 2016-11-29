Attachment dm report.doc successfully uploaded and added.
Conversation opened. 2 messages. All messages read.

Skip to content
Using Gmail with screen readers
25 of 1,914
 
dc 10
Inbox
	x
Abhigna Reddy		AttachmentsNov 27 (3 days ago)
to run: 1) gcc -pthread -o mutex mutex.c 2)./mutex 3) gcc -pthread -o join jo...
Sai Gowri Kumar <saigowri.kumar@gmail.com>
	
AttachmentsNov 27 (3 days ago)
	
to Rajesh
2 Attachments
	
Click here to Reply or Forward
2.08 GB (1%) of 115 GB used
Manage
Terms - Privacy
Last account activity: 6 minutes ago
Open in 1 other location  Details
	
	
More
Abhigna Reddy's profile photo
	Abhigna Reddy
Show details

#include <stdio.h>
#include <pthread.h>
#define NTHREADS 10
void *thread_function(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;
main()
{
pthread_t thread_id[NTHREADS];
int i, j;
for(i=0; i < NTHREADS; i++)
{
pthread_create( &thread_id[i], NULL, thread_function, NULL );
}
for(j=0; j < NTHREADS; j++)
{
pthread_join( thread_id[j], NULL);
}
/* Now that all threads are complete I can print the final result. */
/* Without the join I could be printing a value before all the threads */
/* have been completed.*/
printf("Final counter value: %d\n", counter);
}
void *thread_function(void *dummyPtr)
{
printf("Thread number %ld\n", pthread_self());
pthread_mutex_lock( &mutex1 );
counter++;
pthread_mutex_unlock( &mutex1 );
}
