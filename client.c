/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:48:35 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/06 15:29:13 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_new_line(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill (pid, SIGUSR1);
		i++;
		usleep(50);
	}
	ft_putstr("Message delivered!\n");
}

static void	ft_send_signal(int pid, char *str)
{
	int	shift;

	if (pid == 0)
	{
		ft_putstr("Invalid PID!\n");
		exit(-1);
	}
	while (*str)
	{
		shift = 7;
		while (shift >= 0)
		{
			if (((*str >> shift) & 1))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift--;
			usleep(50);
		}
		str++;
	}
	ft_send_new_line(pid);
}

static int	ft_valid_pid(char *pid)
{
	while (*pid)
	{
		if (!ft_isdigit(*pid))
			return (0);
		pid++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_valid_pid(argv[1]) == 0)
		{
			ft_putstr("Invalid PID!\n");
			exit(-1);
		}
		if (!*argv[2])
		{
			ft_putstr("Write something, don't be shy\n");
			exit(-1);
		}
		ft_send_signal(ft_atoi(argv[1]), argv[2]);
	}
	else if (argc > 3)
		ft_putstr("Format message: \"Your message\"\n");
	else
		ft_putstr("You must include server PID and a message\n");
	return (0);
}
