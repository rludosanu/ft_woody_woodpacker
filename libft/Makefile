# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 13:04:33 by cdrouet           #+#    #+#              #
#    Updated: 2017/03/30 11:43:15 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = libft/

SRC = ft_printf.c \
	  pct_d.c \
	  pct_d2.c \
	  spec_f.c \
	  pct_d3.c \
	  pct_s.c \
	  pct_gs.c \
	  pct_p.c \
	  pct_gd.c \
	  pct_i.c \
	  pct_o.c \
	  pct_o2.c \
	  pct_go.c \
	  pct_u.c \
	  pct_gu.c \
	  pct_x.c \
	  pct_gx.c \
	  pct_c.c \
	  pct_gc.c \
	  ft_atoi.c \
	  ft_ctoa_base.c \
	  ft_isdigit.c \
	  ft_itoa.c \
	  ft_itoa_base.c \
	  ft_ltoa_base.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strchr.c \
	  ft_strcpy.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strnew.c \
	  ft_strrchr.c \
	  ft_strsub.c \
	  ft_toupper.c \
	  ft_strcat.c \
	  spec_f2.c \
	  ft_strcmp.c \
	  ft_diese.c \
	  ft_atoi_base.c \
	  ft_putwchar_t.c \
	  ft_option_wchar_t.c \
	  ft_option_wchar_t2.c \
	  pct_b.c \
	  ft_color.c \
	  pct_n.c \
	  ft_decal.c \
	  spec_f3.c \
	  ft_decal_d.c \
	  spec_f4.c \
	  ft_isascii.c \
   	  ft_memchr.c \
   	  ft_putnbr_fd.c \
  	  ft_striter.c \
   	  ft_strmapi.c \
   	  ft_strnstr.c \
   	  ft_tolower.c \
   	  ft_memcmp.c \
  	  ft_striteri.c \
	  ft_strncat.c \
	  ft_isprint.c \
   	  ft_memcpy.c \
  	  ft_putchar_fd.c \
	  ft_putstr_fd.c  \
	  ft_strctrim.c \
	  ft_strncmp.c \
   	  ft_strsplit.c \
	  ft_bzero.c \
	  ft_memdel.c \
  	  ft_putendl.c \
  	  ft_strdel.c \
  	  ft_strlcat.c \
   	  ft_strncpy.c \
	  ft_strstr.c \
	  ft_isalnum.c \
   	  ft_memalloc.c \
	  ft_memmove.c \
   	  ft_putendl_fd.c \
  	  ft_strdup.c \
  	  ft_strnequ.c \
	  ft_isalpha.c \
   	  ft_memccpy.c \
   	  ft_memset.c \
  	  ft_putnbr.c \
  	  ft_strclr.c \
  	  ft_strequ.c \
  	  ft_strmap.c \
  	  ft_strtrim.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  get_next_line.c \

BIN = $(SRC:.c=.o)

BIN_PATH=./
SRC_PATH=./

FLAG = -Wall -Wextra -Werror

$(NAME) : $(BIN)
	$(info Done !)
	$(info Compiling library...)
	@ar rc $(NAME) $(BIN) ; ranlib $(NAME)
	$(info Done !)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@/bin/echo -n "."
	@clang -I./ $(FLAG) -o $@ -c $<

all : $(NAME)

clean :
	$(info Cleaning binaries...)
	@rm -f $(BIN)
	$(info Done !)

fclean : clean
	$(info Cleaning library...)
	@rm -f $(NAME)
	$(info Done !)

re : fclean all
