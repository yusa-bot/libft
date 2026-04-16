/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:02:48 by ayusa             #+#    #+#             */
/*   Updated: 2026/04/16 18:03:00 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_until_nl(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*tmp;

	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);

	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		buf[bytes] = '\0';

		tmp = ft_strjoin(stash, buf);

		free(stash);

		stash = tmp;
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*extract_line(const char *stash)
{
	size_t	len;
	char	*nl;

	if (!stash || stash[0] == '\0')
		return (NULL);

	nl = ft_strchr(stash, '\n');
	if (nl)
		len = (size_t)(nl - stash) + 1;
	else
		len = ft_strlen(stash);

	return (ft_substr(stash, 0, len));
}

static char	*update_stash(char *stash)
{
	char	*nl;
	char	*new_stash;

	if (!stash)
		return (NULL);

	nl = ft_strchr(stash, '\n');
	if (!nl)
	{
		free(stash);
		return (NULL);
	}

	new_stash = ft_strdup(nl + 1);
	free(stash);

	if (!new_stash || new_stash[0] == '\0')
	{
		free(new_stash);
		return (NULL);
	}
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	stash = read_until_nl(fd, stash);
	if (!stash)
		return (NULL);

	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}

	stash = update_stash(stash);
	return (line);
}
