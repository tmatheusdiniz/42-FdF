/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:56:46 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/18 14:13:55 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../../include/libft.h"

# define HEXBASE "0123456789abcdef"
# define HEXBASEUP "0123456789ABCDEF"
# define FLAGS "-0.# +"

# define TRUE 1
# define FALSE 0

typedef struct s_flags
{
	int	sign_plus;
	int	left_aligment;
	int	zero;
	int	width;
	int	dot;
	int	precision;
	int	hashtag;
	int	space;
}		t_flags;

// The main
int		ft_printf(const char *string, ...);
int		formats(const char *string, size_t *i, va_list args, t_flags *flags);

// to_conversions
int		string_handler(va_list args, t_flags *flags);
int		char_handler(va_list args, t_flags *flags);
int		integer_handler(long int number, t_flags *flags);
int		unsignedint_handler(va_list args, t_flags *flags);
int		pointer_handler(va_list args, t_flags *flags);
int		percentage_handler(void);
int		hexdecimal_handler(long unsigned int number,
			t_flags *flags, char token);

// Flags
t_flags	*initialization_flags(void);
void	tratament_flags(const char *string, size_t *i, t_flags *flags);
t_flags	*flags_handler(const char *string, size_t *i, t_flags *flags);

// Aux String function
int		print_w_p(char *string, int width, int precision, int left_aligment);
int		print_p(char *string, int precision);
int		print_w(char *sring, int width, int left_aligment);

// Aux Integer function
int		print_int_left_pp(long number, t_flags *flags, int precision);
int		print_int_p(long number, int precision, int space, int sign_plus);
int		print_zero(long number, int size_number, t_flags *flags);
int		p_w_i(long number, int size_number, t_flags *flags, int precision);

//Aux Unsigned Int function
int		unsignedint_leftalig(long int number, int numbersize,
			t_flags *flags, int precision);
int		unsignedint_prec(long int number, int precision);
int		unsignedint_w(long int number, int numbersize,
			t_flags *flags, int precision);
int		unsignedint_w_l(long int number, t_flags *flags, int precision);

//Aux Pointer function
int		print_width(int width, int left_aligment,
			int size_address, size_t number);
int		print_null(int left_aligment, int width);

//Aux Hexdecimal function
int		print_hex_leftalig(t_flags *flags, int precision,
			long unsigned number, char token);
int		print_h_p(long unsigned number, t_flags *flags,
			int precision, char token);
int		print_hex_width(t_flags *flags, long number, char flag, char token);
int		print_hashtag(long unsigned number, int hashtag, char token);

// Utils general
int		ft_numsize(long long n);
int		ft_hexsize(size_t n);
int		ft_putnbr(long long n);
int		ft_putnbr_base(unsigned long long n, char *base);

// Utils int
int		print_aux_w(long number, t_flags *flags,
			int precision, int size_number);
int		aux_zero(long number, t_flags *flags);
int		aux_z_plus(long number, int width, int sign_plus);
int		aux_z_space(long number, int width, int space);
int		aux_left(t_flags *flags);
int		aux_prec_zero(t_flags *flags);
int		int_wid(t_flags *flags);

// Utils Unsigned int
int		ft_numsize_unsig(unsigned int n);
int		ft_putnbr_unsig(unsigned int n);
int		aux_unsigned(t_flags *flags);

#endif
