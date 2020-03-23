
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

	bool is_rx_not_empty() const volatile;

	bool is_tx_empty() const volatile;

	bool tx_sent() const volatile;

	volatile USART& operator<<(const uint8_t value) volatile;

	volatile USART& operator<<(const uint16_t value) volatile;

	void send(char* value) volatile;

	volatile USART& operator>>(uint8_t &variable) volatile;

	volatile USART& operator>>(uint16_t &variable) volatile;
//SOOL-USART-DECLARATIONS-END
};

//SOOL-USART-DEFINITIONS-BEGIN
template<typename T>
inline constexpr volatile Reg32_t& USART<T>::get_clock_enable_reg(const uintptr_t addr)
{
	switch (addr)
	{
		//Output for USART1EN
#ifdef USART1_BASE_ADDR
		case USART1_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32H7      ) || defined(STM32L0      ) || defined(STM32L1      ) || \
			    defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB2ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR2;
		#endif
#endif
		//Output for USART2EN
#ifdef USART2_BASE_ADDR
		case USART2_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB1ENR1;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			      defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR1;
		#endif
#endif
		//Output for UART5EN
#ifdef UART5_BASE_ADDR
		case UART5_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB1ENR1;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			      defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
		#endif
#endif
		//Output for USART6EN
#ifdef USART6_BASE_ADDR
		case USART6_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32H7      ) || defined(STM32L0      ) || defined(STM32L1      ) || \
			    defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB2ENR;
		#endif
#endif
		//Output for UART7EN
#ifdef UART7_BASE_ADDR
		case UART7_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
		#endif
#endif
		//Output for UART8EN
#ifdef UART8_BASE_ADDR
		case UART8_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
		#endif
#endif
		//Output for USART3EN
#ifdef USART3_BASE_ADDR
		case USART3_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB1ENR1;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			      defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR1;
		#endif
#endif
		//Output for UART4EN
#ifdef UART4_BASE_ADDR
		case UART4_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB1ENR1;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			      defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
		#endif
#endif
		//Output for LPUART1EN
#ifdef LPUART1_BASE_ADDR
		case LPUART1_BASE_ADDR :
			#if defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB1ENR2;
		#endif
#endif
		//Output for USART4EN
#ifdef USART4_BASE_ADDR
		case USART4_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR1;
		#endif
#endif
		//Output for USART5EN
#ifdef USART5_BASE_ADDR
		case USART5_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
		#endif
#endif
	}
}
template<typename T>
inline constexpr uint32_t USART<T>::get_clock_enable_bit(const uintptr_t addr)
{
	switch (addr)
	{
		//Output for USART1EN
#ifdef USART1_BASE_ADDR
		case USART1_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32H7      )
				return 1 << 4;
			#elif defined(STM32F0      ) || defined(STM32F3      ) || defined(STM32G0      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L1      ) || defined(STM32L4      ) || defined(STM32WB      ) || defined(STM32L011xx  ) || defined(STM32L021xx  ) || defined(STM32L031xx  ) || defined(STM32L041xx  ) || defined(STM32L051xx  ) || defined(STM32L052xx  ) || defined(STM32L053xx  ) || defined(STM32L062xx  ) || defined(STM32L063xx  ) || defined(STM32L071xx  ) || defined(STM32L072xx  ) || defined(STM32L073xx  ) || defined(STM32L081xx  ) || defined(STM32L082xx  ) || defined(STM32L083xx  )
				return 1 << 14;
		#endif
#endif
		//Output for USART2EN
#ifdef USART2_BASE_ADDR
		case USART2_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32G0      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32H7      ) || defined(STM32L0      ) || \
			    defined(STM32L1      ) || defined(STM32L4      )
				return 1 << 17;
		#endif
#endif
		//Output for UART5EN
#ifdef UART5_BASE_ADDR
		case UART5_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F7      ) || defined(STM32H7      ) || defined(STM32F302xE  ) || defined(STM32F303xE  ) || \
			    defined(STM32F405xx  ) || defined(STM32F407xx  ) || defined(STM32F413xx  ) || defined(STM32F415xx  ) || defined(STM32F417xx  ) || \
			    defined(STM32F423xx  ) || defined(STM32F427xx  ) || defined(STM32F429xx  ) || defined(STM32F437xx  ) || defined(STM32F439xx  ) || \
			    defined(STM32F446xx  ) || defined(STM32F469xx  ) || defined(STM32F479xx  ) || defined(STM32G471xx  ) || defined(STM32G473xx  ) || \
			    defined(STM32G474xx  ) || defined(STM32G484xx  ) || defined(STM32L475xx  ) || defined(STM32L476xx  ) || defined(STM32L485xx  ) || \
			    defined(STM32L486xx  ) || defined(STM32L496xx  ) || defined(STM32L4A6xx  ) || defined(STM32L4P5xx  ) || defined(STM32L4Q5xx  ) || \
			    defined(STM32L4R5xx  ) || defined(STM32L4R7xx  ) || defined(STM32L4R9xx  ) || defined(STM32L4S5xx  ) || defined(STM32L4S7xx  ) || \
			    defined(STM32L4S9xx  )
				return 1 << 20;
		#endif
#endif
		//Output for USART6EN
#ifdef USART6_BASE_ADDR
		case USART6_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32H7      )
				return 1 << 5;
		#endif
#endif
		//Output for UART7EN
#ifdef UART7_BASE_ADDR
		case UART7_BASE_ADDR :
			#if defined(STM32F413xx  ) || defined(STM32F423xx  ) || defined(STM32F722xx  ) || defined(STM32F723xx  ) || defined(STM32F730xx  ) || \
			    defined(STM32F732xx  ) || defined(STM32F733xx  )
				return 1 << 30;
		#endif
#endif
		//Output for UART8EN
#ifdef UART8_BASE_ADDR
		case UART8_BASE_ADDR :
			#if defined(STM32F413xx  ) || defined(STM32F423xx  ) || defined(STM32F722xx  ) || defined(STM32F723xx  ) || defined(STM32F730xx  ) || \
			    defined(STM32F732xx  ) || defined(STM32F733xx  )
				return 1 << 31;
		#endif
#endif
		//Output for USART3EN
#ifdef USART3_BASE_ADDR
		case USART3_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F7      ) || defined(STM32G4      ) || defined(STM32GB      ) || \
			    defined(STM32H7      ) || defined(STM32L1      ) || defined(STM32F301x8  ) || defined(STM32F302x8  ) || defined(STM32F302xE  ) || \
			    defined(STM32F303x8  ) || defined(STM32F303xE  ) || defined(STM32F318xx  ) || defined(STM32F328xx  ) || defined(STM32F334x8  ) || \
			    defined(STM32F373xC  ) || defined(STM32F378xx  ) || defined(STM32F398xx  ) || defined(STM32F405xx  ) || defined(STM32F407xx  ) || \
			    defined(STM32F412Cx  ) || defined(STM32F412Rx  ) || defined(STM32F412Vx  ) || defined(STM32F412Zx  ) || defined(STM32F413xx  ) || \
			    defined(STM32F415xx  ) || defined(STM32F417xx  ) || defined(STM32F423xx  ) || defined(STM32F427xx  ) || defined(STM32F429xx  ) || \
			    defined(STM32F437xx  ) || defined(STM32F439xx  ) || defined(STM32F446xx  ) || defined(STM32F469xx  ) || defined(STM32F479xx  ) || \
			    defined(STM32G070xx  ) || defined(STM32G071xx  ) || defined(STM32G081xx  ) || defined(STM32L412xx  ) || defined(STM32L422xx  ) || \
			    defined(STM32L433xx  ) || defined(STM32L443xx  ) || defined(STM32L475xx  ) || defined(STM32L476xx  ) || defined(STM32L485xx  ) || \
			    defined(STM32L486xx  ) || defined(STM32L496xx  ) || defined(STM32L4A6xx  ) || defined(STM32L4P5xx  ) || defined(STM32L4Q5xx  ) || \
			    defined(STM32L4R5xx  ) || defined(STM32L4R7xx  ) || defined(STM32L4R9xx  ) || defined(STM32L4S5xx  ) || defined(STM32L4S7xx  ) || \
			    defined(STM32L4S9xx  )
				return 1 << 18;
		#endif
#endif
		//Output for UART4EN
#ifdef UART4_BASE_ADDR
		case UART4_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F7      ) || defined(STM32G4      ) || defined(STM32H7      ) || defined(STM32F302xE  ) || \
			    defined(STM32F303xE  ) || defined(STM32F405xx  ) || defined(STM32F407xx  ) || defined(STM32F413xx  ) || defined(STM32F415xx  ) || \
			    defined(STM32F417xx  ) || defined(STM32F423xx  ) || defined(STM32F427xx  ) || defined(STM32F429xx  ) || defined(STM32F437xx  ) || \
			    defined(STM32F439xx  ) || defined(STM32F446xx  ) || defined(STM32F469xx  ) || defined(STM32F479xx  ) || defined(STM32L431xx  ) || \
			    defined(STM32L432xx  ) || defined(STM32L442xx  ) || defined(STM32L451xx  ) || defined(STM32L452xx  ) || defined(STM32L462xx  ) || \
			    defined(STM32L471xx  ) || defined(STM32L475xx  ) || defined(STM32L476xx  ) || defined(STM32L485xx  ) || defined(STM32L486xx  ) || \
			    defined(STM32L496xx  ) || defined(STM32L4A6xx  ) || defined(STM32L4P5xx  ) || defined(STM32L4Q5xx  ) || defined(STM32L4R5xx  ) || \
			    defined(STM32L4R7xx  ) || defined(STM32L4R9xx  ) || defined(STM32L4S5xx  ) || defined(STM32L4S7xx  ) || defined(STM32L4S9xx  )
				return 1 << 19;
		#endif
#endif
		//Output for LPUART1EN
#ifdef LPUART1_BASE_ADDR
		case LPUART1_BASE_ADDR :
			#if defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || defined(STM32WB      )
				return 1 << 0;
		#endif
#endif
		//Output for USART4EN
#ifdef USART4_BASE_ADDR
		case USART4_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32G070xx  ) || defined(STM32G071xx  ) || defined(STM32G081xx  ) || defined(STM32L011xx  ) || \
			    defined(STM32L021xx  ) || defined(STM32L031xx  ) || defined(STM32L041xx  ) || defined(STM32L071xx  ) || defined(STM32L081xx  )
				return 1 << 19;
		#endif
#endif
		//Output for USART5EN
#ifdef USART5_BASE_ADDR
		case USART5_BASE_ADDR :
			#if defined(STM32F030x6  ) || defined(STM32F030x8  ) || defined(STM32F030xC  ) || defined(STM32F031x6  ) || defined(STM32F038xx  ) || \
			    defined(STM32F048xx  ) || defined(STM32F051x8  ) || defined(STM32F058xx  ) || defined(STM32F070x6  ) || defined(STM32F070xB  ) || \
			    defined(STM32F071xB  ) || defined(STM32F078xx  ) || defined(STM32F091xC  ) || defined(STM32F098xx  ) || defined(STM32L011xx  ) || \
			    defined(STM32L021xx  ) || defined(STM32L031xx  ) || defined(STM32L041xx  ) || defined(STM32L071xx  ) || defined(STM32L081xx  )
				return 1 << 20;
		#endif
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
inline bool USART<tmpl>::is_rx_not_empty() const volatile
{
#ifdef USART_ISR
	return ISR.RXNE == 1;
#elif defined(USART_SR)
	return SR.RXNE == 1;
#endif
}

template<typename tmpl>
inline bool USART<tmpl>::is_tx_empty() const volatile
{
#ifdef USART_ISR
	return ISR.TXE == 1;
#elif defined(USART_SR)
	return SR.TXE == 1;
#endif

}

template<typename tmpl>
inline bool USART<tmpl>::tx_sent() const volatile
{
#ifdef USART_ISR
	return ISR.TC == 1;
#elif defined(USART_SR)
	return SR.TC == 1;
#endif
}

template<typename tmpl>
inline volatile USART<tmpl>& USART<tmpl>::operator<<(const uint8_t value) volatile
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
inline volatile USART<tmpl>& USART<tmpl>::operator<<(const uint16_t value) volatile
{
#ifdef USART_DR
	DR = value;
#else
	TDR = value;
#endif
	return *this;
}


template<typename tmpl>
void USART<tmpl>::send(char* value) volatile
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
inline volatile USART<tmpl>& USART<tmpl>::operator>>(uint8_t &variable)  volatile
{
#ifdef USART_DR
	variable = DR;
#else
	variable = RDR;
#endif
	return *this;
}



template<typename tmpl>
inline volatile USART<tmpl>& USART<tmpl>::operator>>(uint16_t &variable) volatile
{
#ifdef USART_DR
	variable = DR;
#else
	variable = RDR;
#endif
	return *this;
}
//SOOL-USART-DEFINITIONS-END

