
//SOOL-USART-INCLUDES-BEGIN
#include "RCC.h"

//SOOL-USART-INCLUDES-END
class USART
{
//SOOL-USART-DECLARATIONS-BEGIN
private:
	static constexpr uint32_t get_clock_enable_bit(const uintptr_t addr);

	static constexpr volatile Reg32_t& get_clock_enable_reg(const uintptr_t addr);

public:
	void enable_clock() volatile;

	void disable_clock() volatile;

	bool is_clock_enabled() const volatile;

	void init();

	const bool is_rx_not_empty() const;

	const bool is_tx_empty() const;

	const bool tx_sent() const;

	USART& operator<<(const uint8_t value);

	USART& operator<<(const uint16_t value);

	void send(char* value);

	USART& operator>>(uint8_t &variable);

	USART& operator>>(uint16_t &variable);
//SOOL-USART-DECLARATIONS-END
};

//SOOL-USART-DEFINITIONS-BEGIN
template<typename tmpl>
inline constexpr uint32_t USART<tmpl>::get_clock_enable_bit(const uintptr_t addr)
{
	switch (addr) {
#ifdef USART1_BASE_ADDR
		case USART1_BASE_ADDR :
#if defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)
				return 1 << 4;
#else
				return 1 << 14;
#endif
#endif
#ifdef USART2_BASE_ADDR
		case USART2_BASE_ADDR :
#ifdef RCC_APB1ENR1
				return 1 << 14;
#else
				return 1 << 17;
#endif
#endif
#ifdef USART3_BASE_ADDR
		case USART3_BASE_ADDR :
				return 1 << 18;
#endif
#ifdef USART4_BASE_ADDR
		case USART4_BASE_ADDR : return 1 << 19;
#endif
#ifdef USART5_BASE_ADDR
		case USART5_BASE_ADDR : return 1 << 20;
#endif
#ifdef USART6_BASE_ADDR
		case USART6_BASE_ADDR : return 1 << 5;
#endif
#ifdef USART7_BASE_ADDR
		case USART7_BASE_ADDR :
#ifdef STM32F0
				return 1 << 6;
#else
				return 1 << 30;
#endif
#endif
#ifdef USART8_BASE_ADDR
		case USART8_BASE_ADDR :
#ifdef STM32F0
				return 1 << 7;
#else
				return 1 << 31;
#endif
#endif
		default :
			return 0;
	}
}

template<typename tmpl>
inline constexpr volatile Reg32_t& USART<tmpl>::get_clock_enable_reg(const uintptr_t addr)
{
	switch (addr) {
#ifdef USART1_BASE_ADDR
		case USART1_BASE_ADDR : return RCC->APB2ENR;
#endif
#ifdef USART6_BASE_ADDR
		case USART6_BASE_ADDR : return RCC->APB2ENR;
#endif
		default:
#if defined(RCC_APB1ENR1)
			return RCC->APB1ENR1;
#elif defined(RCC_APB1LENR)
			return RCC->APB1LENR;
#elif defined(RCC_APB1ENR)
			return RCC->APB1ENR;
#else
			return *reinterpret_cast<volatile Reg32_t *>(0);
#endif
	}
}

template<typename tmpl>
inline void USART<tmpl>::enable_clock() volatile
{
	get_clock_enable_reg(get_addr()) |= get_clock_enable_bit(get_addr());
}

template<typename tmpl>
inline void USART<tmpl>::disable_clock() volatile
{
	get_clock_enable_reg(get_addr())
			&= ~get_clock_enable_bit(get_addr());
}

template<typename tmpl>
inline bool USART<tmpl>::is_clock_enabled() const volatile
{
	return (get_clock_enable_reg(get_addr()) & get_clock_enable_bit(get_addr()))
	== get_clock_enable_bit(get_addr());
}

template<typename tmpl>
inline const bool USART<tmpl>::is_rx_not_empty() const
{
#ifdef USART_ISR
	return ISR.RXNE == 1;
#elif defined(USART_SR)
	return SR.RXNE == 1;
#endif
}

template<typename tmpl>
inline const bool USART<tmpl>::is_tx_empty() const
{
#ifdef USART_ISR
	return ISR.TXE == 1;
#elif defined(USART_SR)
	return SR.TXE == 1;
#endif

}

template<typename tmpl>
inline const bool USART<tmpl>::tx_sent() const
{
#ifdef USART_ISR
	return ISR.TC == 1;
#elif defined(USART_SR)
	return SR.TC == 1;
#endif
}

template<typename tmpl>
inline USART<tmpl>& USART<tmpl>::operator<<(const uint8_t value)
{
#ifdef USART_DR
	DR = value;
#else
	TDR = value;
	//TODO send
#endif
	return *this;
}


template<typename tmpl>
inline USART<tmpl>& USART<tmpl>::operator<<(const uint16_t value)
{
#ifdef USART_DR
	DR = value;
#else
	TDR = value;
#endif
	return *this;
}


template<typename tmpl>
void USART<tmpl>::send(char* value)
{
	int pos = 0;
	while(value[pos])
	{
		while(! is_tx_empty())
				asm("nop");
#ifdef USART_DR
		DR = value[pos];
#else
		TDR = value[pos];
#endif
		pos ++;
	}

	return *this;
}

template<typename tmpl>
inline USART<tmpl>& USART<tmpl>::operator>>(uint8_t &variable)
{
#ifdef USART_DR
	variable = DR;
#else
	variable = RDR;
#endif
	return *this;
}



template<typename tmpl>
inline USART<tmpl>& USART<tmpl>::operator>>(uint16_t &variable)
{
#ifdef USART_DR
	variable = DR;
#else
	variable = RDR;
#endif
	return *this;
}
//SOOL-USART-DEFINITIONS-END

