#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User
{
	char nom[30];
	int age;
}User;

int main(void)
{
	int socketServer = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrServer;
	addrServer.sin_addr.s_addr = inet_addr("192.168.1.89");
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(30000);

	bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));
	printf("bind : %d\n", socketServer);

	listen(socketServer, 5);
	printf("listen\n");

	struct sockaddr_in addrClient;
	socklen_t csize = sizeof(addrServer);
	int socketClient = accept(socketServer, (struct sockaddr *)&addrClient, &csize);
	printf("accept\n");

	printf("client %d\n", socketClient);

	
	User user = {
		.nom = "Arthur",
		.age = 19
	};

	close(socketClient);
	close(socketServer);
	printf("close\n");
	return 0;
};
