#include <stddef.h>
void	print_memory(const void *addr, size_t size);
void	ft_putnbr_hex(int octet, int rem);

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};
	//ft_putnbr_hex(255, 2);
	print_memory(tab, sizeof(tab));
	return (0);
}