#include "minitalk.h"

	t_signal	holder;

static void	ft_init_struct()
{
	holder.msg = 0;
	holder.pos = 0;
}

static void	final_message()
{
	holder.msg = '\n';
	ft_putchar(holder.msg);
	ft_putstr("Message received!\n");
}

static void	sig_handler(int signal)
{
	if (signal == SIGUSR2)
		holder.msg |= 1;
	holder.pos++;
	if (holder.pos < 8)
		holder.msg <<= 1;
	else if (holder.pos == 8)
	{
		if (holder.msg == 0)
			final_message();
		else
			ft_putchar(holder.msg);
		ft_init_struct();
	}
}

int main (void)
{
	ft_putstr("Your PID is: ");
	ft_putnbr(getpid());
	ft_putstr("\nWaiting for a message\n");
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_init_struct();
	while (1)
	{
		pause();
	}
}
