#include "key.h"

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
		game->key.key_esc = 1;
	// else if (key == K_AR_U)
	// 	game->key.key_up = 1;
	// else if (key == K_AR_R)
	// 	game->key.key_right = 1;
	// else if (key == K_AR_L)
	// 	game->key.key_left = 1;
	// else if (key == K_AR_D)
	// 	game->key.key_down = 1;
	return (0);
}

int	key_release(int	key, t_game *game)
{
	if (key == K_ESC)
		game->key.key_esc = 0;
	// else if (key == K_AR_U)
	// 	game->key.key_up = 0;
	// else if (key == K_AR_R)
	// 	game->key.key_right = 0;
	// else if (key == K_AR_L)
	// 	game->key.key_left = 0;
	// else if (key == K_AR_D)
	// 	game->key.key_down = 0;
	return (0);
}

void	key_used(t_game *game)
{
	// if (game->key.key_up)
	// 	move_up(game);
	// if (game->key.key_down)
	// 	move_behind(game);
	// if (game->key.key_right)
	// 	rotate_right(game);
	// if (game->key.key_left)
	// 	rotate_left(game);
	if (game->key.key_esc)
	{
		//fare free
		exit(0);
	}
}
