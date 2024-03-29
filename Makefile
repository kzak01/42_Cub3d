NAME = cub3d

BONUS_NAME = cub3d_bonus

SRC_BONUS =	src_bonus/main.c \
			src_bonus/img/img.c \
			src_bonus/key/door.c \
			src_bonus/key/key.c \
			src_bonus/key/mouse_move.c \
			src_bonus/key/movement.c \
			src_bonus/key/rotate.c \
			src_bonus/loop/frame_animation.c \
			src_bonus/loop/loop.c \
			src_bonus/loop/minimap.c \
			src_bonus/loop/ray_cast.c \
			src_bonus/loop/raycast_utils.c \
			src_bonus/loop/sprites_utils.c \
			src_bonus/loop/sprites.c \
			src_bonus/map/check_map.c \
			src_bonus/map/check_player.c \
			src_bonus/map/get_sprites.c \
			src_bonus/map/map.c \
			src_bonus/map/open_close_fd.c \
			src_bonus/map/read_map.c \
			src_bonus/map/utils.c \
			src_bonus/map/varius_check.c \
			src_bonus/utils/error.c \
			src_bonus/utils/free_exit.c \
			src_bonus/utils/init.c

SRC_MANDATORY = src/main.c \
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
			src/utils/init.c

SRC	= $(SRC_MANDATORY)

FLAGS			= -g -Wall -Wextra -Werror -fcommon


OBJS_DIR		= objs
OBJS			= $(addprefix $(OBJS_DIR)/, ${SRC:.c=.o})
OBJS_BONUS		= $(addprefix $(OBJS_DIR)/, ${SRC_BONUS:.c=.o})

LIBFT_DIR		= libft/
LIBFT_A			= libft/libft.a
LIBFT			= $(addprefix $(LIBF_DIR), $(LIBFT_A))

LIBFT_MAKE		= @cd libft && make --no-print-directory && make clean --no-print-directory
MLX_MAKE_MAC	= @cd mlx_mc && make --no-print-directory 2> /dev/null
MLX_MAKE_LINUX	= @cd mlx_linux && make --no-print-directory 2> /dev/null
RMLIB			= @cd libft && make fclean --no-print-directory
RMMLX			= @rm -f libmlx.dylib libmlx.a
MLX_DIR			= $(addprefix $(MLX_DIR), $(MLX_LIB))
# MLX				= minilibx/libmlx.a

CC	= @gcc

DEBUG_F	= -g -fsanitize=address

RACE_F	= -g -fsanitize=thread

LEAK_F  = -g -fsanitize=leak -llsan

ifeq ($(shell uname), Darwin)
	MLX_LIB	= mlx_mc/libmlx.a -Lmlx -lmlx -framework OpenGL -framework Appkit
	MLX_MAKE = $(MLX_MAKE_MAC)
else
	MLX_LIB	= mlx_linux/libmlx.a -lX11 -lXext -lXpm
	MLX_MAKE = $(MLX_MAKE_LINUX)
endif

.PHONY: all bonus clean fclean re norm sanitize race clean_all

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "	... [Making $(NAME)]"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) $(MLX_LIB) -lm -o $(NAME) > /dev/null
	@echo "		Cub3d compiled"

$(BONUS_NAME): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@echo "	... [Making $(BONUS_NAME)]"
	@$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBFT_A) $(MLX_LIB) -lm -o $(BONUS_NAME) > /dev/null
	@echo "		Cub3d compiled"

$(LIBFT):
	@echo "	... [Making libft]"
	@$(LIBFT_MAKE)
	@echo "		Libft compiled"

$(MLX):
	@echo "	... [Making Minilibx]"
	@$(MLX_MAKE)
	@echo "		Minilibx compiled"

# LINK ALL OBJECTS
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean_all: fclean
	$(RMLIB)

fclean: clean
	@echo "	... [Removing $(NAME)]"
	@rm -rf ${NAME}*
	@echo "		${RED}*.a's deleted${RESET}"
	$(RMLIB)

clean:
	@echo "	... [Removing ${NAME} objs files]"
	@rm   -rf ${OBJS_DIR}
	@echo "		${RED} ${NAME} OBJS deleted${RESET}"


norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) src/*.h src/*/*.h $(SRC_BONUS) src_bonus/*/*.h src_bonus/*.h libft/*/*c libft/*/*.h

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
