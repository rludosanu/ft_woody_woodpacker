EXEC		=	woody_woodpacker
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	main\
				elf\
				encrypt\
				file\
				patch
OBJ			=	$(addsuffix .o, $(SRC))
LIB			=	./libft/libftprintf.a
LIBPATH		=	./libft/
LIBID		=	ftprintf
PACKER		=	depacker
NASM		=	nasm
NASMFLAGS	=	-f elf64
ASMSRC		=	test_decryptage.s

$(EXEC): $(LIB) $(OBJ) $(PCK)
	$(info Compiling $(EXEC))
	@$(CC) -I$(LIBPATH) $(CFLAGS) -o $@ $^ -L$(LIBPATH) -l$(LIBID)
	$(NASM) $(NASMFLAGS) -o $(PACKER) $(ASMSRC)

all: $(EXEC)

$(LIB): 
	$(info Compiling libft)
	@make -C $(LIBPATH)
	@echo "Done !"

%.o: %.c
	$(info Compiling $< into $@ ...)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(LIBPATH)

clean:
	$(info Cleaning . and ./libft ...)
	@make $@ -C $(LIBPATH)
	rm -f $(OBJ)
	$(info Done !)

fclean: clean
	$(info Cleaning . and ./libft ...)
	@make $@ -C $(LIBPATH)
	@rm -rf $(EXEC)
	$(info Done !)

re: fclean all

.PHONY: all clean fclean re
