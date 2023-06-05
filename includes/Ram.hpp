#ifndef	RAM_HPP
#define	RAM_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <fstream>

#define	TOTAL_RAM	0xFFFFF //65535
#define	VRAM_START	0x64010
#define	VRAM_END	0x672F0 - 128 * 16

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
		sf::RenderTexture	_tiles;

	private:
		uint8_t							_ram[TOTAL_RAM];
		sf::RectangleShape				_rect;

		void	loadTiles(void);
};

#endif	//RAM_HPP