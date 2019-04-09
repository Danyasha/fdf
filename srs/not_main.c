/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:22:13 by btorp             #+#    #+#             */
/*   Updated: 2019/04/03 21:03:38 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static	int		exiter(char *s)
// {
// 	ft_putstr(s);
// 	return (0);
// }

// int		m2ain(int argn, char **argv)
// {
// 	int	fd;
// 	t_point	**map;

// 	fd = open(argv[1], O_RDONLY);
// 	if (argn != 2)
// 		return(exiter("usage: ./fdf filename\n"));
// 	if (read(fd, NULL, 0) < 0)
// 		return(exiter("invalid file\n"));
// 	if(!(map = validate_main(fd)))
// 		return(exiter("bad map\n"));

// 	close (fd);
// 	return (0);
// }