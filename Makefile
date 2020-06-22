all : prog

prog : serveur.o client.o
	gcc -o prog serveur.o -c client.o

serveur.o : serveur.c
	gcc -pthread -o serveur -c serveur.c

client.o : client.c
	gcc -o client -c client.c
