//SOOL-ADC-INCLUDES-BEGIN
#include "RCC.h"
//SOOL-ADC-INCLUDES-END
//SOOL-ADC-DECLARATION-BEGIN
private:
static constexpr uint32_t get_clock_enable_bit(const uint32_t addr);

static constexpr volatile Reg32_t& get_clock_enable_reg(const uint32_t addr);

public:
void enable_clock() volatile;

void disable_clock() volatile;

bool is_clock_enabled() const volatile;

#ifdef ADC_SQR1
void set_acquisition_sequence_length(const unsigned int length) volatile;
#endif

void set_sequence_value(const unsigned int position, const unsigned int channel) volatile;
//SOOL-ADC-DECLARATION-END

//SOOL-ADC-DEFINITION-BEGIN


inline constexpr uint32_t ADC::get_clock_enable_bit(const uint32_t addr)
{
	switch (addr) {
#ifdef ADC1_BASE_ADDR
		case ADC1_BASE_ADDR :
#if defined(STM32F1) || defined(STM32L1) || defined(STM32F0) || defined(STM32L0) || defined(STM32F373xC) || defined(STM32F378xx)
					return 1 << 9;
#elif defined(STM32F2) || defined(STM32F4) || defined(STM32F7)
					return 1 << 8;
#elif defined(STM32L4) || defined(STM32L4P)
					return 1 << 13;
#elif defined(STM32H7)
					return 1 << 5;
#else //F3
					return 1 << 28;
#endif
#endif
#ifdef ADC2_BASE_ADDR
		case ADC2_BASE_ADDR :
#if defined(STM32F1)
					return 1 << 10;
#elif defined(STM32F2) || defined(STM32F4) || defined(STM32F7)
					return 1 << 9;
#elif defined(STM32L4) || defined(STM32L4P)
					return 1 << 13;
#elif defined(STM32H7)
					return 1 << 5;
#else //F3
					return 1 << 28;
#endif
#endif
#ifdef ADC3_BASE_ADDR
		case ADC3_BASE_ADDR :
#if defined(STM32F1)
					return 1 << 15;
#elif defined(STM32F2) || defined(STM32F4) || defined(STM32F7)
					return 1 << 10;
#elif defined(STM32L4) || defined(STM32L4P)
					return 1 << 13;
#elif defined(STM32H7)
					return 1 << 24;
#else //F3
					return 1 << 29;
#endif
#endif
#ifdef ADC4_BASE_ADDR
		case ADC4_BASE_ADDR :
				return 1 << 29;
#endif
		default :
			return 0;


	}
}

inline constexpr volatile Reg32_t &ADC::get_clock_enable_reg(const uint32_t addr)
{
	switch (addr) {
#ifdef ADC1_BASE_ADDR
		case ADC1_BASE_ADDR :
#if defined(STM32L4) || defined(STM32L4P)
					return RCC->AHB2ENR;
#elif 	defined(STM32F3) && !(defined(STM32F373xC) || defined(STM32F378xx))
					return RCC->AHBENR;
#elif defined(STM32H7)
					return RCC->AHB1ENR
#else
					return RCC->APB2ENR;
#endif
#endif
#ifdef ADC2_BASE_ADDR
		case ADC2_BASE_ADDR :
#if defined(STM32L4) || defined(STM32L4P)
					return RCC->AHB2ENR;
#elif 	defined(STM32F3)
					return RCC->AHBENR;
#elif defined(STM32H7)
					return RCC->AHB1ENR
#else
					return RCC->APB2ENR;
#endif
#endif
#ifdef ADC3_BASE_ADDR
		case ADC3_BASE_ADDR :
#if defined(STM32L4) || defined(STM32L4P)
					return RCC->AHB2ENR;
#elif 	defined(STM32F3)
					return RCC->AHBENR;
#elif defined(STM32H7)
					return RCC->AHB4ENR
#else
					return RCC->APB2ENR;
#endif
#endif
#ifdef ADC4_BASE_ADDR
		case ADC4_BASE_ADDR :
				return RCC->AHBENR;
#endif
		default :
			return *reinterpret_cast<volatile Reg32_t *>(0);
	}
}

inline void ADC::enable_clock() volatile
{
	get_clock_enable_reg(reinterpret_cast<const uint32_t>(this))
			|= get_clock_enable_bit(reinterpret_cast<const uint32_t>(this));
}

inline void ADC::disable_clock() volatile
{
	get_clock_enable_reg(reinterpret_cast<const uint32_t>(this))
			&= ~get_clock_enable_bit(reinterpret_cast<const uint32_t>(this));
}

inline bool ADC::is_clock_enabled() const volatile
{
	return (get_clock_enable_reg(reinterpret_cast<const uint32_t>(this))
			& get_clock_enable_bit(reinterpret_cast<const uint32_t>(this)))
		   == get_clock_enable_bit(reinterpret_cast<const uint32_t>(this));
}

#ifdef ADC_SQR1
inline void ADC::set_acquisition_sequence_length(const unsigned int length) volatile
{
	SQR1.L = length;
};
#endif




//SOOL-ADC-DEFINITION-END
