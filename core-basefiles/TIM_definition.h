//SOOL-TIM-INCLUDES-BEGIN
#include "RCC.h"

//SOOL-TIM-INCLUDES-END
template<typename plugin>
class TIM
{
//SOOL-TIM-DECLARATION-BEGIN
private:
	static constexpr uint32_t get_clock_enable_bit(const uint32_t addr);

	static constexpr volatile Reg32_t &get_clock_enable_reg(const uint32_t addr);

public:
	void enable_clock() volatile;

	void disable_clock() volatile;

	bool is_clock_enabled() const volatile;
//SOOL-TIM-DECLARATION-END
};

//SOOL-TIM-DEFINITION-BEGIN
template<typename plugin>
constexpr uint32_t TIM<plugin>::get_clock_enable_bit(const uint32_t addr)
{
	switch (addr) {
#ifdef TIM1_BASE_ADDR
		case TIM1_BASE_ADDR:
#if defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)
				return 1 << 0;
#else
				return 1 << 11;
#endif
#endif
#ifdef TIM2_BASE_ADDR
		case TIM2_BASE_ADDR: return 1 << 0;
#endif
#ifdef TIM3_BASE_ADDR
		case TIM3_BASE_ADDR: return 1 << 1;
#endif
#ifdef TIM4_BASE_ADDR
		case TIM4_BASE_ADDR: return 1 << 2;
#endif
#ifdef TIM5_BASE_ADDR
		case TIM5_BASE_ADDR: return 1 << 3;
#endif
#ifdef TIM6_BASE_ADDR
		case TIM6_BASE_ADDR: return 1 << 4;
#endif
#ifdef TIM7_BASE_ADDR
		case TIM7_BASE_ADDR: return 1 << 5;
#endif
#ifdef TIM8_BASE_ADDR
		case TIM8_BASE_ADDR:
#if defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)
				return 1 << 1;
#else
				return 1 << 13;
#endif
#endif
#ifdef TIM9_BASE_ADDR
		case TIM9_BASE_ADDR:
#if defined(STM32F0)
				return 1 << 19;
#elif defined(STM32L1)
				return 1 << 2;
#else
				return 1 << 16;
#endif
#endif
#ifdef TIM10_BASE_ADDR
		case TIM10_BASE_ADDR:
#if defined(STM32F0)
				return 1 << 20;
#elif defined(STM32L1)
				return 1 << 3;
#else
				return 1 << 17;
#endif
#endif
#ifdef TIM11_BASE_ADDR
		case TIM11_BASE_ADDR:
#if defined(STM32F0)
				return 1 << 21;
#elif defined(STM32L1)
				return 1 << 4;
#else
				return 1 << 18;
#endif
#endif
#ifdef TIM12_BASE_ADDR
		case TIM12_BASE_ADDR: return 1 << 6;
#endif
#ifdef TIM13_BASE_ADDR
		case TIM13_BASE_ADDR: return 1 << 7;
#endif
#ifdef TIM14_BASE_ADDR
		case TIM14_BASE_ADDR: return 1 << 8;
#endif
#ifdef TIM15_BASE_ADDR
		case TIM15_BASE_ADDR: return 1 << 16;
#endif
#ifdef TIM16_BASE_ADDR
		case TIM16_BASE_ADDR: return 1 << 17;
#endif
#ifdef TIM17_BASE_ADDR
		case TIM17_BASE_ADDR: return 1 << 18;
#endif
#ifdef TIM18_BASE_ADDR
		case TIM18_BASE_ADDR: return 1 << 9;
#endif
#ifdef TIM19_BASE_ADDR
		case TIM19_BASE_ADDR: return 1 << 19;
#endif
#ifdef TIM20_BASE_ADDR
		case TIM20_BASE_ADDR: return 1 << 20;
#endif
#ifdef TIM21_BASE_ADDR
		case TIM21_BASE_ADDR: return 1 << 2;
#endif
#ifdef TIM22_BASE_ADDR
		case TIM22_BASE_ADDR: return 1 << 5;
#endif
		default:
			return 0;
	}
}

template<typename plugin>
constexpr volatile Reg32_t &TIM<plugin>::get_clock_enable_reg(const uint32_t addr)
{
	switch (addr) {
#ifdef TIM1_BASE_ADDR
		case TIM1_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM8_BASE_ADDR
		case TIM8_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM9_BASE_ADDR
		case TIM9_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM10_BASE_ADDR
		case TIM10_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM11_BASE_ADDR
		case TIM11_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM15_BASE_ADDR
		case TIM15_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM16_BASE_ADDR
		case TIM16_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM17_BASE_ADDR
		case TIM17_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM19_BASE_ADDR
		case TIM19_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM20_BASE_ADDR
		case TIM20_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM21_BASE_ADDR
		case TIM21_BASE_ADDR: return RCC->APB2ENR;
#endif
#ifdef TIM22_BASE_ADDR
		case TIM22_BASE_ADDR: return RCC->APB2ENR;
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

template<typename plugin>
inline void TIM<plugin>::enable_clock() volatile
{
	TIM<plugin>::get_clock_enable_reg(reinterpret_cast<const uint32_t>(this))
			|= get_clock_enable_bit(reinterpret_cast<const uint32_t>(this));
}

template<typename plugin>
inline void TIM<plugin>::disable_clock() volatile
{
	TIM<plugin>::get_clock_enable_reg(reinterpret_cast<const uint32_t>(this))
			&= ~get_clock_enable_bit(reinterpret_cast<const uint32_t>(this));
}

template<typename plugin>
inline bool TIM<plugin>::is_clock_enabled() const volatile
{
	return (get_clock_enable_reg(reinterpret_cast<const uint32_t>(this))
			& get_clock_enable_bit(reinterpret_cast<const uint32_t>(this)))
		   == get_clock_enable_bit(reinterpret_cast<const uint32_t>(this));
}
//SOOL-TIM-DEFINITION-END
