# Nombre de la librería
LIB = libcpu128.a

# Archivos fuente de la librería
SRCS = cpu128.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -O2

# Regla principal: compilar la librería
all: $(LIB)

# Crear librería estática
$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

# Regla para compilar .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(LIB)
