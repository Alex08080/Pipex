/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:41:17 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 16:53:55 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include <unistd.h>

int main(void)
{
    write(1, "=== Test ft_putendl_fd ===\n\n", 29);

    ft_putendl_fd("Hello", 1);
    ft_putendl_fd("World", 1);
    ft_putendl_fd("42", 1);

    return 0;
}
*/
