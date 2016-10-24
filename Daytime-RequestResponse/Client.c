#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include<sys/time.h>
int main(){
int sockfd,n=0;

char recvline[1000+1];
struct sockaddr_in servaddr;
struct timeval stop, start;


time_t ticks;
gettimeofday(&start, NULL);
if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0) {
printf("Socket Error!!!");
exit(0);
}else
printf("CLIENT:Client sockfd = %d\n",sockfd);

bzero(&servaddr, sizeof(servaddr));

servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(5000);
servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

ticks = time(NULL);

//printf("%.24s",ctime(&ticks));

int conn_status = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

while( (n=read(sockfd,recvline,1000))>0) {
recvline[n] = '\0'; /* null terminate */
if(fputs(recvline,stdout) == EOF) {
printf("fputs error!!!");
exit(0);
}
//do stuff
gettimeofday(&stop, NULL);
printf("RTT :  %lu ms\n", stop.tv_usec - start.tv_usec);
}
}
