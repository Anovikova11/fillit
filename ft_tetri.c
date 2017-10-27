/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:57:22 by alnoviko          #+#    #+#             */
/*   Updated: 2017/10/25 13:57:24 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A Tetrimino is a classic Tetris geometric figure composed of 4 blocks.

// ** Each character must be either a block character (’#’) or an empty character (’.’)
// ** Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).

// "####\n....\n....\n....\n\n"

#include "fillit.h"

/*
** 1. Check if each block has 12 dots, and 4 '#', and 4-5 newlines.
** Each Tetrimino fit in a 4x4 square and ends with a newline = 21 chars total,
** last block has 20 chars.
** 
** All Tetriminos must be separated by a newline each.
** Our test file should contain between 1 and 26 Tetriminos.
** In case of error return (0), otherwise return (1).
*/

int 	ft_char_check(char *buf)
{
	int	dots;
	int hash;
	int newl;

	dots = 0;
	hash = 0;
	newl = 0;

	while (*buf)
	{
		if (*buf == '.')
			dots++;
		if (*buf == '#')
			hash++;
		if (*buf == '\n')
			newl++;
		buf++;
	}
	if (dots == 12 && hash == 4 && (newl == 4 || newl == 5))
		return (1);
	return (0);
}

int		ft_row_count(char *str)
{
	int i;
	int row;

	row = 0;
	i = 0;
	while (i < 19)
	{
		if (str[i] == '#')
		{
			row = row + 1;
			while (str[i] != '\n')
				i++;
		}
		i++;
	}
	return (row);
}

/*
** Checks connection counts, if we have 6 or 8 connections, the tetrimino is
** valid.
*/

int 	ft_row_check(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}
