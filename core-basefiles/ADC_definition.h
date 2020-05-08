//SOOL-ADC-INCLUDES-BEGIN
#include "RCC.h"
//SOOL-ADC-INCLUDES-END
//SOOL-ADC-DECLARATIONS-BEGIN
private:
static constexpr uint32_t get_clock_enable_bit(const uintptr_t addr);
static constexpr volatile Reg32_t& get_clock_enable_reg(const uintptr_t addr);

public:
void enable_clock() volatile;

void disable_clock() volatile;

bool is_clock_enabled() const volatile;

#ifdef ADC_SQR1
void set_acquisition_sequence_length(const unsigned int length) volatile;
#endif

void set_sequence_value(const unsigned int position, const unsigned int channel) volatile;
//SOOL-ADC-DECLARATIONS-END

//SOOL-ADC-DEFINITIONS-BEGIN


template<typename T>
inline constexpr volatile Reg32_t& ADC<T>::get_clock_enable_reg(const uintptr_t addr)
{
	switch (addr)
	{
		//Output for ADC3EN
#ifdef ADC3_BASE_ADDR
		case ADC3_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->AHB4ENR;
			#elif defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      )
				return RCC->APB2ENR;
			#endif
#endif
		//Output for ADCEN
#ifdef ADC_BASE_ADDR
		case ADC_BASE_ADDR :
			#if defined(STM32L4      ) || defined(STM32WB      )
				return RCC->AHB2ENR;
			#elif defined(STM32F0      ) || defined(STM32F3      ) || defined(STM32L0      )
				return RCC->APB2ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR2;
			#endif
#endif
		//Output for ADC1EN
#ifdef ADC1_BASE_ADDR
		case ADC1_BASE_ADDR :
			#if 1
				return RCC->APB2ENR;
			#endif
#endif
		//Output for ADC2EN
#ifdef ADC2_BASE_ADDR
		case ADC2_BASE_ADDR :
			#if 1
				return RCC->APB2ENR;
			#endif
#endif
	}
}
template<typename T>
inline constexpr uint32_t ADC<T>::get_clock_enable_bit(const uintptr_t addr)
{
	switch (addr)
	{
		//Output for ADC3EN
#ifdef ADC3_BASE_ADDR
		case ADC3_BASE_ADDR :
			#if defined(STM32H7      )
				return 1 << 24;
			#elif defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      )
				return 1 << 10;
			#endif
#endif
		//Output for ADCEN
#ifdef ADC_BASE_ADDR
		case ADC_BASE_ADDR :
			#if defined(STM32L4      ) || defined(STM32WB      )
				return 1 << 13;
			#elif defined(STM32F0      ) || defined(STM32F3      ) || defined(STM32L0      )
				return 1 << 9;
			#elif defined(STM32G0      )
				return 1 << 20;
			#endif
#endif
		//Output for ADC1EN
#ifdef ADC1_BASE_ADDR
		case ADC1_BASE_ADDR :
			#if 1
				return 1 << 8;
			#endif
#endif
		//Output for ADC2EN
#ifdef ADC2_BASE_ADDR
		case ADC2_BASE_ADDR :
			#if 1
				return 1 << 9;
			#endif
#endif
	}
}

template<typename T>
inline void ADC<T>::enable_clock() volatile
{
	get_clock_enable_reg(get_addr())
			|= get_clock_enable_bit(get_addr());
}
template<typename T>
inline void ADC<T>::disable_clock() volatile
{
	get_clock_enable_reg(get_addr())
			&= ~get_clock_enable_bit(get_addr());
}
template<typename T>
inline bool ADC<T>::is_clock_enabled() const volatile
{
	return (get_clock_enable_reg(reinterpret_cast<const uint32_t>(this))
			& get_clock_enable_bit(reinterpret_cast<const uint32_t>(this)))
		   == get_clock_enable_bit(reinterpret_cast<const uint32_t>(this));
}

#ifdef ADC_SQR1
template<typename T>
inline void ADC<T>::set_acquisition_sequence_length(const unsigned int length) volatile
{
	SQR1.L = length;
};
#endif




//SOOL-ADC-DEFINITIONS-END
