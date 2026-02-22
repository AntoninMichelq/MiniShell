# Nom de l'exécutable final
NAME = miniShell

# Compilateur et flags (options de compilation)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Liste des fichiers sources (.c)
SRCS = miniShell.c exec_cmd.c

# Transformation de la liste des .c en .o (fichiers objets)
OBJS = $(SRCS:.c=.o)

# Règle principale : compiler l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Règle pour compiler les fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet (objets + exécutable)
fclean: clean
	rm -f $(NAME)

# Recommencer à zéro
re: fclean $(NAME)

.PHONY: all clean fclean re