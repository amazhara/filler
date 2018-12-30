# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/16 16:53:47 by amazhara          #+#    #+#              #
#    Updated: 2018/12/30 14:10:26 by amazhara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre

NAME :=		amazhara.filler

SRC_PATH :=	src/
INC_PATH :=	includes/
LIB_PATH :=	printf/
VIS_PATH :=	visualizer/
OBJ_PATH :=	.obj/

CC :=		clang
CFLAGS :=	-g -Wall -Wextra -Werror
IFLAGS :=	-I $(INC_PATH) -I $(LIB_PATH)

LIB :=		$(LIB_PATH)libftprintf.a
VIS :=		amazhara.vis
HFILES :=	filler
FILES :=	filler pars_map worck_with_figur worck_with_figur_p2

HDRS :=		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIB) $(VIS_PATH)$(VIS) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIB) -o $(NAME)
$(LIB):
	make -C $(LIB_PATH)
$(VIS_PATH)$(VIS):
	make -C $(VIS_PATH)
	@ ln -s $(VIS_PATH)$(VIS) $(VIS)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
	make clean -C $(VIS_PATH)
fclean: mfclean
	make fclean -C $(LIB_PATH)
	make fclean -C $(VIS_PATH)
re: fclean all

mclean:
	rm -rf $(OBJ_PATH)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all
