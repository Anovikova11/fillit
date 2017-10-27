/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:21:53 by alnoviko          #+#    #+#             */
/*   Updated: 2017/10/20 17:22:00 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

char	*ft_read(int fd);
int		ft_test1(char *file);

// A Tetriminos is a 4-blocks geometric figure you probably already heard of, thanks to the popular game Tetris.
// The goal of the program is to rearrange tetrominoes blocks into the smallest 
// possible combination in the upper left corner.
// To identify each Tetriminos in the square solution, you will assign a capital letter (starting with ’A’) 
// to each Tetriminos in the order they appear in the file. A file will contain 26 Tetriminos maximum. 
// If the file contains at least one error, the program must display error on the standard output and exit properly.


// If the number of parameters sent to your executable is not 1, 
// your program must display its usage and exit properly. 
// If you don’t know what a usage is, execute the command cp without arguments in your Shell. 



// Start off in the top-left corner. See if a 1x1 square would work.

// If it will work, increase the sides lengths of the square by 1 and repeat.
// If it won't work, move right and repeat. If you've reached the right-most position, move to the next line.

// When increasing the square size, we can just do a binary search over the next row and column to see if that row / column contains an obstacle at any of those positions.

// When moving to the right, we can do a binary search for each next column to determine if that column contains an obstacle at any of those positions.

// When moving down, we can do a similar binary on each of the columns in the target position.


// Frees an allocated map structure.
// Prints an allocated map structure to standard output.
// Allocates a new map structure with specified size.
// Places a tetrimino on map at specified position, checking if the placement is possible.
// Sets a tetrimino on a map at a position with the specified character. 
// To place, call with c=tetri->value. To remove, call with c='.'






#endif
