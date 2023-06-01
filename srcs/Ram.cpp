#include <Ram.hpp>
#include <Ram.hpp>
#include <string.h>
#include <defines.hpp>

Ram::Ram(void)
{
	memset(_ram, 0, TOTAL_RAM);
	_rect.setSize(sf::Vector2f(1, 1));
}

Ram::~Ram(void)
{

}

void	Ram::loadData(std::ifstream &file)
{
    file.read(reinterpret_cast<char *>(_ram), TOTAL_RAM);
	loadTiles();
}

uint8_t	*Ram::getData(const uint16_t &start_addr)
{
	return (_ram + start_addr);
}

void	Ram::loadTiles(void)
{
	size_t		i = VRAM_B1_SART;
	uint16_t	tmp = 0;

	while (i < VRAM_B1_END)
	{
		int	j = 0;
		while (j < 8)
		{
			//sf::RenderTexture	tmp_tex;
			//tmp_tex.create(8, 8);
			tmp = 0;
			tmp = TO_16BIT(_ram[i], _ram[i + 1]);
			//int	k = 0;
			while (tmp)
			{
				int px = (tmp & 0xC000) >> 14;
				if (px == 1)
					printf("\e[0;44m  ");
				else if (px == 2)
					printf("\e[0;104m  ");
				else if (px == 3)
					printf("\e[0;46m  ");
				else
					printf("\e[0;106m  ");
				tmp <<= 2;
				printf("\e[0m");
			}
			j++;
			i += 2;
			printf("\n");
		}
		printf("===\n");
	}
}