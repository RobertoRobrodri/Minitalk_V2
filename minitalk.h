/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:41:52 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/06 15:36:02 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_signal
{
	char		msg;
	int			pos;
	int			pid;
	int			flag;
}	t_signal;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(long n);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif
