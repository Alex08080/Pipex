/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/12/04 23:47:51 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_flags
{
	int	zero;
	int	dot;
	int	hashtag;
	int	space;
	int	plus;
	int	minus;
	int	width;
	int	precision;
}	t_flags;

typedef struct s_data
{
	char	*str;
	int		is_neg;
	int		is_zero;
	int		len;
	int		is_null;
	int		is_char_null;
}	t_data;

int		ft_conversion_manag(char const *format, int *i, va_list list);
int		ft_printf(const char *format, ...);
int		check_flags(char c, t_flags *flag);
int		ft_free_conversion(t_flags *flag, t_data *data, char *res, int len);
void	priority_flags(t_flags *flag);
int		data_fail(t_flags *flag, char c);
void	parse_flag(t_flags *flag, char const *str, int *j, va_list list);
void	parse_width(t_flags *flag, char const *str, int *j, va_list list);
void	parse_precision(t_flags *flag, char const *str, int *j, va_list list);
void	ft_su(char *s, int size, unsigned int n);
void	ft_sh(char *s, int size, unsigned int n);
void	ft_sp(char *s, int size, unsigned long long n);
void	new_str_nb(int nb, t_data *data);
void	final_print(t_flags *flag, t_data *data, char *res, int *len);
t_flags	*new_flag(void);
t_data	*type_conversion(va_list list, char c);
t_data	*conversion_int(va_list list);
t_data	*conversion_string(va_list list);
t_data	*conversion_char(va_list list);
t_data	*conversion_hex(va_list list, int c);
t_data	*conversion_point(va_list list);
t_data	*conversion_percent(void);
t_data	*conversion_unsigned(va_list list);
t_data	*new_data(void);
char	*manag_precision(t_data *data, t_flags *flag, char c);
char	*manag_precision_nb(t_data *data, t_flags *flag);
char	*manag_precision_str(t_data *data, t_flags *flag);
char	*manag_prefix(char *str, t_data *data, t_flags *flag, char c);
char	*manag_prefix_int(char *str, t_flags *flag, t_data *data);
char	*manag_prefix_hex(char *str, char c);
char	*manag_width(char *str, t_flags *flag);
char	*manag_width_left(char *str, int nb_fill, char fill);
char	*manag_width_right(char *str, int nb_fill, char fill);
char	*conversion_final(t_data *data, t_flags *flag, char c);
char	*conversion_precision(t_data *data, t_flags *flag, char c);
char	*str_int(t_data *data, int nb);
char	*str_unsigned(t_data *data, unsigned int nb);
char	*str_hex(t_data *data, unsigned int nb);
char	*str_point(t_data *data, unsigned long long nb);
char	*ft_utoa(unsigned int n);
char	*ft_htoa(unsigned int n);
char	*ft_ptoa(unsigned long long n);
#endif
