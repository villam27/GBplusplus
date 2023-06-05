#include <Ram.hpp>
#include <Ram.hpp>
#include <string.h>
#include <defines.hpp>

Ram::Ram(void)
{
	memset(_ram, 0, TOTAL_RAM);
	_rect.setSize(sf::Vector2f(1, 1));
	_tiles.create(144, 144);
	_tiles.clear();
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
	size_t		i = VRAM_START;
	uint16_t	tmp = 0;
	size_t		x_off = 0;
	size_t		y_off = 0;

	while (i < VRAM_END)
	{
		int	j = 0;
		while (j < 8)
		{
			int	k = 0;
			uint8_t	t1 = _ram[i];
			uint8_t	t2 = _ram[i + 1];
			printf("%X %X ", _ram[i], _ram[i + 1]);
			//printf("%X ", tmp);
			while (k < 8)
			{
				//int px = (tmp & 0xC000) >> 14;
				uint8_t	px = ((t1 & 0x80) >> 6);
				px += (t2 >> 7);
				//printf ("%d\n", px);
				if (px == 1)
					_rect.setFillColor(sf::Color(C01));
				else if (px == 2)
					_rect.setFillColor(sf::Color(C10));
				else if (px == 3)
					_rect.setFillColor(sf::Color(C11));
				else if (px == 0)
					_rect.setFillColor(sf::Color(C00));
				tmp <<= 2;
				t1 <<= 1;
				t2 <<= 1;
				_rect.setPosition(k + x_off, j + y_off);
				//std::cout << _rect.getFillColor().toInteger() << " " 
				//		<< _rect.getPosition().x << " "
				//		<< _rect.getPosition().y << std::endl;
				_tiles.draw(_rect);
				k++;
			}
			j++;
			i += 2;
		}
		printf("\n");
		x_off += 9;
		if (x_off >= 128)
		{
			x_off = 0;
			y_off += 9;
		}
		//sf::Sprite	sp = sf::Sprite(_tiles[i - VRAM_B1_SART].getTexture());
		//sp.scale(10, 10);
	}
	_tiles.display();
}