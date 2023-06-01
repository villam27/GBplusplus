#ifndef	CPU_HPP
#define	CPU_HPP

#include <stdint.h>
#include <defines.hpp>

#define	GET_FF(VALUE)		(uint8_t)(((VALUE) & 0xFF00) >> 8)
#define	GET_00FF(VALUE)		(uint8_t)(((VALUE) & 0xFF))

struct Register
{
	uint8_t A;
	uint8_t B;
	uint8_t C;
	uint8_t D;
	uint8_t E;
	uint8_t F;
	uint8_t H;
	uint8_t L;
};

class Cpu
{
	public:
		Cpu();
		~Cpu();
	
		uint8_t		GetRegisterA(void);
		uint8_t		GetRegisterB(void);
		uint8_t		GetRegisterC(void);
		uint8_t		GetRegisterD(void);
		uint8_t		GetRegisterE(void);
		uint8_t		GetRegisterF(void);
		uint8_t		GetRegisterH(void);
		uint8_t		GetRegisterL(void);
		uint16_t	GetRegisterBC(void);
		uint16_t	GetRegisterDE(void);
		uint16_t	GetRegisterHL(void);
		void		SetRegisterA(uint8_t value);
		void		SetRegisterB(uint8_t value);
		void		SetRegisterC(uint8_t value);
		void		SetRegisterD(uint8_t value);
		void		SetRegisterE(uint8_t value);
		void		SetRegisterF(uint8_t value);
		void		SetRegisterH(uint8_t value);
		void		SetRegisterL(uint8_t value);
		void		SetRegisterBC(uint16_t value);
		void		SetRegisterDE(uint16_t value);
		void		SetRegisterHL(uint16_t value);

	private:
		Register	_reg;
};

#endif	//CPU_HPP