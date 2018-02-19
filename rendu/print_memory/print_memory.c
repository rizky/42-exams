#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_hex(int number, int rem)
{
	const char *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(number / 16, rem - 1);
	write(1, &(base[number % 16]), 1);
}

void	ft_putchar(unsigned char const c)
{
	if (c >= ' ' && c <= '~')
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;
	size_t	col;
	const unsigned char *ptr = addr;
	
	i = 0;
	while (i < size)
	{
		col = 0;
		while (col < 16 && col + i < size)
		{
			ft_putnbr_hex(*(ptr + i + col), 2);
			if (col % 2)
				write(1, " ", 1);
			col++;
		}
		while (col < 16)
		{
			write(1, "  ", 2);
			if (col % 2 == 0)
				write(1, " ", 1);
			col++;
		}
		col = 0;
		while (col < 16 && col + i < size)
		{
			ft_putchar(*(ptr + i + col));
			col++;
		}
		write(1, "\n", 1);
		i = i + 16;
	}
}