/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:53:41 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/06 20:59:56 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	clean_all(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img->mlx_img);
	mlx_destroy_image(game->mlx, game->img[1].mlx_img);
}

int		leave(t_game *game)
{
	clean_all(game);
	exit(0);
}

int	get_random_int()
{
	srand(clock());
	return ((rand() ^ (rand() << 15) ^ ((long long int) rand() << 30)));
}

/*
** YOU SHOULD ALWAYS SWITCH BETWEEN TWO IMAGE BUFFERS TO PREVENT TEARING
** (DOUBLE BUFFERING) 
*/

void	*refresh(t_game *game)
{
	static clock_t	t0 = 0;

	if (game->frame_ready && (!FRAME_CAP
	|| (double)(clock() - t0) > (double)CLOCKS_PER_SEC / (double)FRAME_CAP))
	{
		mlx_put_image_to_window(game->mlx, game->win,
								game->img_ptr->mlx_img, 0, 0);
		if (game->img_ptr == game->img)
		{
			copy_image(game->img, game->img + 1);
			game->img_ptr++;
		}
		else
		{
			copy_image(game->img + 1, game->img);
			game->img_ptr--;
		}
		t0 = clock();
		game->frame_ready = 0;
	}
	return (NULL);
}

t_cell	*find_cell(t_list *cell_list, int x, int y)
{
	t_cell	*cell;

	while (cell_list)
	{
		cell = cell_list->content;
		if (cell->x == x && cell->y == y)
			return (cell);
		cell_list = cell_list->next;
	}
	return (NULL);
}

int		get_pxl_color(t_data *data, int x, int y)
{
	char    *dst;

	if (x <= 0 || x >= data->width || y <= 0 || y >= data->height)
		return 0;
	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}

int		get_cell_color(t_data *data, int x, int y)
{
	return (get_pxl_color(data, (x * CELL_SIZE) + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2));
}

void	update_cells(t_snake *snake, t_data *screen)
{
	t_list	*node;
	t_list	*last;
	int		new_color;

	if (snake->x == snake->food_x && snake->y == snake->food_y)
	{
		snake->size++;
		new_color = snake->food_color;
		fill_cell(screen, snake->x, snake->y, new_color);
		ft_lstadd_front(&snake->cells_list, ft_lstnew(new_cell(snake->x,snake->y, new_color)));
		snake->food_x = abs(rand()) % GRID_WIDTH;
		snake->food_y = abs(rand()) % GRID_HEIGHT;
		while (get_cell_color(screen, snake->food_x, snake->food_y) != BG_COLOR)
		{
			snake->food_x = abs(rand()) % GRID_WIDTH;
			snake->food_y = abs(rand()) % GRID_HEIGHT;
		}	
		fill_cell(screen, snake->food_x, snake->food_y, snake->food_color = FLOOR(abs(get_random_int()) % 0xFFFFFF, 0x222222));
		printf("x%d y%d c 0x%x\n", snake->food_x, snake->food_y, snake->food_color);
		//return ;
	}
	else if ((snake->x + snake->dir_x < 0 || snake->x + snake->dir_x >= GRID_WIDTH
		|| snake->y + snake->dir_y < 0 || snake->y + snake->dir_y >= GRID_HEIGHT) ||
		(get_cell_color(screen, snake->x + snake->dir_x, snake->y + snake->dir_y) != BG_COLOR
		&& (snake->x + snake->dir_x != snake->food_x && snake->y + snake->dir_y != snake->food_y)))
		exit(0);
	node = snake->cells_list;
	while (node && node->next)
	{
		if (!(node->next->next))
		{
			last = node->next;
			node->next = NULL;
			last->next = snake->cells_list;
			snake->cells_list = last;
			return ;
		}
		node = node->next;
	}
}

void	update_snake(t_snake *snake, t_data *screen)
{
	t_cell	*cell;

	update_cells(snake, screen);
	cell = snake->cells_list->content;
	fill_cell(screen, cell->x, cell->y, 0);
	snake->x += snake->dir_x;
	snake->y += snake->dir_y;
	cell->x = snake->x;
	cell->y = snake->y;
	fill_cell(screen, cell->x, cell->y, cell->color);
	//printf("x%d y%d dx %d dy %d\n",cell->x, cell->y, snake->dir_x, snake->dir_y);
}

void	inputs_handler(t_game *game, t_key keys[K_BUFF_SIZE])
{
	t_snake	*snake;

	snake = &(game->snake);
	if (key_chr(keys, ESC_KEY, K_BUFF_SIZE))
		leave(game);
	if (!(snake->dir_y))
	{
		if (key_chr(keys, ARROW_UP_KEY, K_BUFF_SIZE))
		{
			snake->dir_y = -1;
			snake->dir_x = 0;
		}
		if (key_chr(keys, ARROW_DOWN_KEY, K_BUFF_SIZE))
		{
			snake->dir_y = 1;
			snake->dir_x = 0;
		}
	}
	else if (!(snake->dir_x))
	{
		if (key_chr(keys, ARROW_LEFT_KEY, K_BUFF_SIZE))
		{
			snake->dir_y = 0;
			snake->dir_x = -1;
		}
		if (key_chr(keys, ARROW_RIGHT_KEY, K_BUFF_SIZE))
		{
			snake->dir_y = 0;
			snake->dir_x = 1;
		}
	}
}

int		loop_handler(t_game *game)
{
	if (!game->frame_ready)
	{
		inputs_handler(game, game->keys);
		update_snake(&(game->snake), game->img_ptr);
		game->frame_ready = 1;
	}
	refresh(game);
	return (0);
}

int		main(void)
{
	t_game	game;
	
	init_display(&game);
	//draw_grid(game.img, 0xFF0000);
	//draw_grid(game.img + 1, 0xFF);
	init_snake(&game.snake);
	init_keys(game.keys);

	game.snake.food_x = abs(get_random_int()) % GRID_WIDTH + 1;
	game.snake.food_y = abs(get_random_int()) % GRID_HEIGHT + 1;
	fill_cell(game.img_ptr, game.snake.food_x, game.snake.food_y, game.snake.food_color = abs(get_random_int()) % 0xFFFFFF);
	mlx_loop_hook(game.mlx, loop_handler, (void *)&game);
	mlx_hook(game.win, KEY_PRESS, KEY_PRESS_MASK, key_press_hook, game.keys);
	mlx_hook(game.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release_hook, game.keys);
	mlx_hook(game.win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK, leave, &game);
	mlx_loop(game.mlx);
	return (0);
}