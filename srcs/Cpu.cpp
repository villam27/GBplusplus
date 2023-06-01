#include <Cpu.hpp>

uint8_t	Cpu::GetRegisterA(void)
{
	return (_reg.A);
}

uint8_t	Cpu::GetRegisterB(void)
{
	return (_reg.B);
}

uint8_t	Cpu::GetRegisterC(void)
{
	return (_reg.C);
}

uint8_t	Cpu::GetRegisterD(void)
{
	return (_reg.D);
}

uint8_t	Cpu::GetRegisterE(void)
{
	return (_reg.E);
}

uint8_t	Cpu::GetRegisterF(void)
{
	return (_reg.F);
}

uint8_t	Cpu::GetRegisterH(void)
{
	return (_reg.H);
}

uint8_t	Cpu::GetRegisterL(void)
{
	return (_reg.L);
}

uint16_t	Cpu::GetRegisterBC(void)
{
	return TO_16BIT(_reg.B, _reg.C);
}

uint16_t	Cpu::GetRegisterDE(void)
{	
	return TO_16BIT(_reg.D, _reg.E);
}

uint16_t	Cpu::GetRegisterHL(void)
{
	return TO_16BIT(_reg.H, _reg.L);
}

void	Cpu::SetRegisterA(uint8_t value)
{
	_reg.A = value;
}

void	Cpu::SetRegisterB(uint8_t value)
{
	_reg.B = value;
}

void	Cpu::SetRegisterC(uint8_t value)
{
	_reg.C = value;
}

void	Cpu::SetRegisterD(uint8_t value)
{
	_reg.D = value;
}

void	Cpu::SetRegisterE(uint8_t value)
{
	_reg.E = value;
}

void	Cpu::SetRegisterF(uint8_t value)
{
	_reg.F = value;
}

void	Cpu::SetRegisterH(uint8_t value)
{
	_reg.H = value;
}

void	Cpu::SetRegisterL(uint8_t value)
{
	_reg.L = value;
}

void	Cpu::SetRegisterBC(uint16_t value)
{
	_reg.B = GET_FF(value);
	_reg.C = GET_00FF(value);
}
void	Cpu::SetRegisterDE(uint16_t value)
{
	_reg.D = GET_FF(value);
	_reg.E = GET_00FF(value);
}
void	Cpu::SetRegisterHL(uint16_t value)
{
	_reg.H = GET_FF(value);
	_reg.L = GET_00FF(value);
}