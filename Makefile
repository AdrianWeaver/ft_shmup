
NAME			=		ft_shmup

#############################################################################
#																			#
#								COMPILER									#
#																			#
#############################################################################

CC				=	c++

CFLAGS			=	-MMD -Wall -Wextra -Werror -g3

INC				=	-I ./includes/

SILENT			=	--no-print-directory

#############################################################################
#																			#
#									PATHS									#
#																			#
#############################################################################

SRCS_PATH		=	./sources/
OBJS_PATH		=	./objects/
SRCS_PARSING	=	./parsing/
SRCS_ERRORS		=	./errors/
SRCS_CORE		=	./core/
SRCS_UTILS		=	./utils/
SRCS_DISPLAY	=	./display/


#############################################################################
#																			#
#									FILES									#
#																			#
#############################################################################

SRCS				=\
					$(addprefix $(SRCS_CORE),	\
						main.cpp\
					)\
					$(addprefix $(SRCS_PARSING),	\
						my_example_parsing_file.cpp\
					 )\
					$(addprefix $(SRCS_ERRORS),		\
						my_example_error_file.cpp\
					 )\
					$(addprefix $(SRCS_UTILS),		\
						my_example_utils_file.cpp\
					)\
					$(addprefix $(SRCS_DISPLAY),		\
						ms_init_ncurse.cpp\
					)

OBJS			=	$(addprefix $(OBJS_PATH), $(SRCS:.cpp=.o))
DEPS			=	$(OBJS:.o=.d)
#LIBFT			=	$(addprefix $(LIBFT_PATH), libft.a)

#############################################################################
#																			#
#									RULES									#
#																			#
#############################################################################

all:				$(NAME)

$(NAME):			$(OBJS) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJS) -o $@ -lncurses
					@echo "Linking files"

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.cpp
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
					@make -C $(LIBFT_PATH) $(SILENT)

clean:
					@rm -rf $(OBJS_PATH)
					@echo "Objects cleaned!"

fclean:				clean
					@rm -f $(NAME)

re:					fclean
					@make all $(SILENT)

test:				$(NAME)
					./$(NAME)

vtest:				$(NAME)
					valgrind --leak-check=full\
					--show-leak-kinds=all\
					./$(NAME)

-include $(DEPS)
.PHONY:				all clean fclean re test
