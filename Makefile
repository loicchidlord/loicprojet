all : serveur client

serveur : serveur.c 
	gcc -o serveur serveur.c -lpthread

client : client.c 
	gcc -o client client.c

clean:
		rm -f client
		rm -f serveur
		rm -f *.o
