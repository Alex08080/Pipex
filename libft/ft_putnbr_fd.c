/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:43:54 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 16:54:23 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	else
		nb = n;
	if (nb / 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10 + 48), fd);
}
/*
#include <unistd.h>

int main(void)
{
    write(1, "=== Test ft_putnbr_fd ===\n\n", 28);

    ft_putnbr_fd(42, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-42, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(2147483647, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);

    return 0;
}
*/
