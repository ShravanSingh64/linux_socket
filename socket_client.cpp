#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <cstdio>

static const char* socket_path = "/tmp/socket";
static const unsigned int s_recv_len = 200;
static const unsigned int s_send_len = 100;

int main(int argc, char* argv[])
{
	int sock = 0;
	int data_len = 0;
	int result_received=0;
	struct sockaddr_un remote;
	char recv_msg[s_recv_len];
	char send_msg[s_send_len];
	//char* send_content="quit";
	memset(recv_msg, 0, s_recv_len*sizeof(char));
	memset(send_msg, 0, s_send_len*sizeof(char));

	if(argc>3)
	{
		fprintf(stderr,"Arguments cannot be more than 2: Too Many Arguments \n");
		return 10;
	}
	
	if( (sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1  )
	{
		fprintf(stderr,"Client: Error on socket() call \n");
		return 1;
	}

	remote.sun_family = AF_UNIX;
	strcpy( remote.sun_path, argv[1] );
	data_len = strlen(remote.sun_path) + sizeof(remote.sun_family);

	//printf("Client: Trying to connect... \n");
	if( connect(sock, (struct sockaddr*)&remote, data_len) == -1 )
	{
		fprintf(stderr,"Error on connect call \n");
		return 2;
	}

	//printf("Client: Connected \n");
	strcpy(send_msg,argv[2]);
	if( send(sock, send_msg, strlen(send_msg)*sizeof(char), 0 ) == -1 )
	{
		fprintf(stderr,"Client: Error on send() call \n");
	}
	
	memset(send_msg, 0, s_send_len*sizeof(char));
	memset(recv_msg, 0, s_recv_len*sizeof(char));
	
	close(sock);
		
	return 0;
}
