/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:35:34 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 16:54:01 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
#include <unistd.h>

int main(void)
{
    write(1, "=== Test ft_putstr_fd ===\n\n", 28);

    ft_putstr_fd("Hello World!\n", 1);
    ft_putstr_fd("42 Network\n", 1);

    return 0;
}
*/
