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
			src/map/open_close_fd.c \
			src/map/read_map.c \
			src/map/utils.c \
			src/map/varius_check.c \
			src/utils/error.c \
			src/utils/free_exit.c \
			src/utils/init.c \

SRC_FILE_BONUS = src_bonus/main.c \
			src_bonus/img/img.c \
			src_bonus/key/key.c \
			src_bonus/key/movement.c \
			src_bonus/key/rotate.c \
			src_bonus/loop/loop.c \
			src_bonus/loop/ray_cast.c \
			src_bonus/loop/raycast_utils.c \
			src_bonus/map/check_map.c \
			src_bonus/map/check_player.c \
			src_bonus/map/map.c \
			src_bonus/map/open_close_fd.c \
			src_bonus/map/read_map.c \
			src_bonus/map/utils.c \
			src_bonus/map/varius_check.c \
			src_bonus/utils/error.c \
			src_bonus/utils/free_exit.c \
			src_bonus/utils/init.c \

SRC	= $(SRC_MAIN)

FLAGS			:= -g -Wall -Wextra -Werror -fcommon


OBJS_DIR		= objs
OBJS			= $(addprefix $(OBJS_DIR)/, ${SRC:.c=.o})

LIBFT_DIR		:= libft/
LIBFT_A			:= libft/libft.a
LIBFT			= $(addprefix $(LIBF_DIR), $(LIBFT_A))

LIBFT_MAKE		:= @cd libft && make --no-print-directory && make clean --no-print-directory
MLX_MAKE_MAC	:= @cd minilibx && make --no-print-directory 2> /dev/null
MLX_MAKE_LINUX	:= @cd mlx && make --no-print-directory 2> /dev/null
RMLIB			:= @cd libft && make fclean --no-print-directory
RMMLX			:= @rm -f libmlx.dylib libmlx.a
MLX_DIR			= $(addprefix $(MLX_DIR), $(MLX_LIB))

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

.PHONY: all bonus clean fclean re norm sanitize race clean_all

all: $(NAME)

$(NAME): $(OBJS)
	@echo "	... [Making libft]"
	@$(LIBFT_MAKE)
	@echo "		Libft compiled"
	@echo "	... [Making Minilibx]"
	@$(MLX_MAKE)
	@echo "		Minilibx compiled"
	@echo "	... [Making $(NAME)]"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) $(MLX_LIB) -lm -o $(NAME) > /dev/null
	@echo "		Cub3d compiled"

# LINK ALL OBJECTS
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

bonus: SRC := $(SRC_FILE_BONUS)
bonus: MLX_LIB := minilibx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework Appkit
bonus: FLAGS += -DBONUS
bonus: OBJS_DIR := objs
bonus: clean_all $(NAME)

clean_all: fclean
	$(RMLIB)

fclean: clean
	@echo "	... [Removing $(NAME)]"
	@rm -rf ${NAME}
	@echo "		${RED}*.a's deleted${RESET}"
	$(RMLIB)

clean:
	@echo "	... [Removing ${NAME} objs files]"
	@rm   -rf ${OBJS_DIR}
	@echo "		${RED} ${NAME} OBJS deleted${RESET}"


norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC_MAIN) $(SRC_BONUS) libft/*/*c libft/*/*.h

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

# .PHONY : all clean fclean re
