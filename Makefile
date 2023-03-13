NAME := cub3d

SRC_MAIN = 	src/main.c \
			src/img/img.c \
			src/key/key.c \
			src/key/movement.c \
			src/key/rotate.c \
			src/loop/loop.c \
			src/loop/ray_cast.c \
			src/loop/raycast_utils.c \
			src/map/check_map.c \
			src/map/check_player.c \
			src/map/map.c \
			src/map/utils.c \
			src/map/varius_check.c \
			src/utils/error.c \
			src/utils/free_exit.c \
			src/utils/init.c \

SRC	= $(SRC_MAIN)

FLAGS				:= -g -Wall -Wextra -Werror -fcommon
MINI_FLAG			:= -Imlx

OBJS				= $(addprefix $(OBJS_DIR)/, ${SRC:.c=.o})
LIBFT				= $(addprefix $(LIBF_DIR), $(LIBFT_A))
MLX_DIR				= $(addprefix $(MLX_DIR), $(MLX_LIB))

OBJS_DIR			= objs

LIBFT_DIR	:= libft/
LIBFT_A		:= libft/libft.a

LIBFT_MAKE	:= @cd libft && make --no-print-directory && make clean --no-print-directory
MLX_MAKE_MAC	:= @cd minilibx && make --no-print-directory 2> /dev/null
MLX_MAKE_LINUX	:= @cd mlx && make --no-print-directory 2> /dev/null
RMLIB		:= @cd libft && make fclean --no-print-directory
RMMLX		:= @rm -f libmlx.dylib libmlx.a

CC	= @gcc

DEBUG_F	= -g -fsanitize=address

RACE_F	= -g -fsanitize=thread

LEAK_F  = -g -fsanitize=leak -llsan

ifeq ($(shell uname), Darwin)
	MLX_LIB	= minilibx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework Appkit
	MLX_MAKE = $(MLX_MAKE_MAC)
else
	MLX_LIB	= mlx/libmlx.a -lX11 -lXext -lXpm
	MLX_MAKE = $(MLX_MAKE_LINUX)
endif

$(NAME): $(OBJS)
	@echo "	... [Making libft]"
	@$(LIBFT_MAKE)
	@echo "		${GREEN}Libft compiled${RESET}"
	@echo "	... [Making Minilibx]"
	@$(MLX_MAKE)
	@echo "		${GREEN}Minilibx compiled${RESET}"
	@echo "	... [Making $(NAME)]"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) ${MLX_LIB} -lm -o $(NAME) > /dev/null
	@echo "		${GREEN}Cub3d compiled${RESET}"

# LINK ALL OBJECTS
$(shell echo $(OBJS_DIR))/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	@echo "	... [Removing ${NAME} objs files]"
	@rm   -rf ${OBJS_DIR}
	@echo "		${RED} ${NAME} OBJS deleted${RESET}"

fclean: clean
	@echo "	... [Removing $(NAME)]"
	@rm -rf ${NAME}
	@echo "		${RED}*.a's deleted${RESET}"
	$(RMLIB)

clean_all: fclean
	$(RMLIB)

norm:
	@norminette -R CheckForbiddenSourceHeader src/*.c src/*.h src/*/*.c src/*/*.h libft/*c libft/*.h

sanitize:	re $(OBJS)
			@$(CC) $(DEBUG_F) $(OBJS) $(LIBFT_A) ${MLX_LIB} -lm -o $(NAME)
			$(info [Making with fsanitize=address ...])

race:		re $(OBJS)
			@$(CC) $(RACE_F) $(OBJS) $(LIBFT_A) ${MLX_LIB} -o $(NAME)
			$(info [Making with fsanitize=thread ...])

leak:		re $(OBJS)
			@$(CC) $(LEAK_F) $(OBJS) $(LIBFT_A) ${MLX_LIB} -o $(NAME)
			$(info [Making with fsanitize=leak ...])

re: 		fclean $(NAME)

ree:		clean_all $(NAME)

.PHONY : all clean fclean re
