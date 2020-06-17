CC = gcc 
# on utilsera $(CC) chaque fois qu'onvoudra faire allusion au compilateur

EXEC = exe_name
SRC = (willcard *.c) 
OBJ = $(SRC:.c=.o) #remplace les fichiers objets

all : $(EXEC)

#toutes les cibles en .o je vais les créer à partir des .c
%.o : %.c
	$(CC) -o $(OBJ) -c $<

#l'executable
$(EXEC) : $(OBJ)
	$(CC) -o $@ $^

#Pour la suppression de tous les fichiers objet (command : make clean)
clean : 
	rm -rf *.o

# Variable spéciales
$@ nom cible
$< nom pemière dépendance
$^ liste dépendance
$? liste dépendance plus récente que la cible
$* nom du fichier, sans son extension
