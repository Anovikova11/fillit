/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:58:01 by alnoviko          #+#    #+#             */
/*   Updated: 2017/10/24 12:58:04 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 1. Read our test file.
** 2. Check if test file contains only '.', # or \n.
** 3. In main we open a test file, with ft_read we read it.
** 4. BUF is where we read our file, 1 byte is how many bytes we read every time.
** 5. 1 byte = 1 character. 
** 6. At the begining of a while loop tert_map = NULL, so we copy BUF into ter_map with ft_strdup. 
** 7. Then we add 1 character every time with ft_strjoin. Buf adds 1 character every time.
*/

char	*ft_read(int fd)
{
	int		ret;
	char	*buf;
	char	*tetr_map;

	buf = ft_strnew(21);
	while ((ret = read(fd, buf, 21)))
	{
		if (*buf != '.' && *buf != '#' && *buf != '\n')
			return (NULL);
		if (tetr_map == NULL)
			tetr_map = ft_strdup(buf);
		else 
			tetr_map = ft_strjoin(tetr_map, buf);
		ft_bzero(buf, 21);
	}
	// close(fd);
	return (tetr_map);
}

int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	ft_putstr(ft_read(fd));
	return (0);
}

// int main()
// {
// 	int fd;
// 	int ret;
// 	char buf[2];

// 	ft_bzero(buf, 2);

// 	fd = open("file", O_RDONLY);
// 	if (fd == -1)
// 		{
// 			ft_putstr("open() failed\n");
// 			return (1);
// 		}
// 	while ((ret = read(fd, buf, 1)))
// 	{
// 		//if (*buf != '.' && *buf != '#' && *buf != '\n')
// 		//	return (0);
// 		//buf[ret] = '\0';
// 	//	ft_putnbr (ret);
// 		ft_putstr (buf);
		
// 	}
// 	//ft_putnbr(ret);
// 	if (close(fd) == -1)
// 	{
// 		ft_putstr("close() error\n");
// 		return (1);
// 	}
// 	return (0);
// }


