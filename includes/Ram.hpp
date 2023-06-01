#ifndef	RAM_HPP
#define	RAM_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <fstream>

#define	TOTAL_RAM	0xFFFF //65535
#define	VRAM_START	0x8000
#define	VRAM_END	0xA000

/*	First block of tile data, 128 8x8 16bytes sprites	*/
#define	VRAM_B1_SART	0x8000
#define	VRAM_B1_END		0x87FF

class Ram
{
	public:
		Ram(void);
		~Ram(void);

		void	loadData(std::ifstream &file);
		uint8_t	*getData(const uint16_t &start_addr);

	private:
		uint8_t							_ram[TOTAL_RAM];
		std::vector<sf::RenderTexture>	_tiles;
		sf::RectangleShape				_rect;

		void	loadTiles(void);
};

#endif	//RAM_HPP