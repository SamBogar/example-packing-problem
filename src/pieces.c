/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:31:20 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/21 23:24:56 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

void	remove_piece(t_board *board, t_piece_c piece, int pos)
{
	t_uint64 *p;
	t_uint64 p_num;

	p_num = piece.piece->id << (pos % BOARD_SIZE);
	p = (t_uint64*)(board->s + (pos / BOARD_SIZE));
	*p = *p ^ p_num;
	if (piece.piece->fp == pos)
		piece.piece->fp = -1;
	piece.piece->lp = piece.piece->fp;
}

t_bool	place_piece(t_board *board, t_piece_c *piece, int pos)
{
	t_uint64 *p;
	t_uint64 p_num;

	p_num = piece->piece->id << (pos % BOARD_SIZE);
	p = (t_uint64*)(board->s + (pos / BOARD_SIZE));
	if (~(*p ^ p_num) & (*p | p_num))
		return (0);
	piece->bpos = pos;
	if (piece->piece->fp == -1)
		piece->piece->fp = pos;
	piece->piece->lp = pos;
	*p = *p | p_num;
	return (1);
}

void	ft_pop_res(t_board board, t_board *tmp, char *res, t_piece_c **pieces)
{
	int	i;
	int	pounds;
	int	pos;

	i = -1;
	while (pieces[++i])
	{
		pounds = 0;
		pos = 0;
		place_piece(tmp, pieces[i], pieces[i]->bpos);
		while (pounds != 4)
			if (!((tmp->s[pos / board.dim] >> (pos % board.dim)) % 2))
				pos++;
			else
			{
				pounds++;
				res[pos] = pieces[i]->let;
				pos++;
			}
		remove_piece(tmp, *pieces[i], pieces[i]->bpos);
	}
}

char	*get_color(char let)
{
	return (let == 'A' ? "\e[31m" :
		   let == 'B' ? "\e[32m" :
		   let == 'C' ? "\e[33m" :
		   let == 'D' ? "\e[34m" :
		   let == 'E' ? "\e[35m" :
		   let == 'F' ? "\e[36m" :
		   let == 'G' ? "\e[96m" :
		   let == 'H' ? "\e[90m" :
		   let == 'I' ? "\e[91m" :
		   let == 'J' ? "\e[92m" :
		   let == 'K' ? "\e[93m" :
		   let == 'L' ? "\e[94m" :
		   let == 'M' ? "\e[95m" :
		   let == 'N' ? "\e[96m" :
		   let == 'O' ? "\e[36m" :
		   let == 'P' ? "\e[31m" :
		   let == 'Q' ? "\e[32m" :
		   let == 'R' ? "\e[33m" :
		   let == 'S' ? "\e[34m" :
		   let == 'T' ? "\e[35m" :
		   let == 'U' ? "\e[36m" :
		   let == 'V' ? "\e[37m" :
		   let == 'W' ? "\e[90m" :
		   let == 'X' ? "\e[91m" :
		   let == 'Y' ? "\e[92m" :
		   "\e[37m");
}

void	print_board(t_board board, t_piece_c **pieces)
{
	int		i;
	char	*res;
	t_board	*tmp;

	i = -1;
	tmp = (t_board*)malloc(sizeof(board));
	set_board_dim(tmp, board.dim);
	ft_bzero(tmp->s, board.dim * board.dim);
	res = (char*)malloc(sizeof(char) * (board.dim) * (board.dim));
	ft_memset(res, '.', (board.dim) * (board.dim));
	res[(board.dim) * (board.dim)] = 0;
	ft_pop_res(board, tmp, res, pieces);
	while (res[++i])
		if (!((i + 1) % board.dim))
			printf("%s%c\n", get_color(*(res + i)), *(res + i));
		else
			printf("%s%c", get_color(*(res + i)), *(res + i));
}
