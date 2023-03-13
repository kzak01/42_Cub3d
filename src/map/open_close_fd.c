/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:12:09 by kzak              #+#    #+#             */
/*   Updated: 2023/03/13 15:22:43 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	open_file(const char *file_path)
{
	int fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error("Failed to open file");
	return (fd);
}

int	close_file(int fd)
{
	if (close(fd) == -1)
		return (error("Failed to close file"));
	return (0);
}
