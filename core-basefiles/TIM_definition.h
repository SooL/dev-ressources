//SOOL-TIM-INCLUDES-BEGIN
#include "RCC.h"

//SOOL-TIM-INCLUDES-END
template<typename plugin>
class TIM
{
//SOOL-TIM_PARENT-DECLARATIONS-BEGIN
private:
	static constexpr uint32_t get_clock_enable_bit(const uintptr_t addr);
	static constexpr volatile Reg32_t& get_clock_enable_reg(const uintptr_t addr);

public:
	inline void enable_clock() volatile;
	inline void disable_clock() volatile;
	inline bool is_clock_enabled() const volatile;
//SOOL-TIM_PARENT-DECLARATIONS-END
};

//SOOL-TIM-DEFINITIONS-BEGIN
inline constexpr volatile Reg32_t& TIM_PARENT::get_clock_enable_reg(const uintptr_t addr)
{
	switch (addr)
	{
		//Output for TIM1EN
#ifdef TIM1_BASE_ADDR
		case TIM1_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32G4      ) || \
			    defined(STM32GB      ) || defined(STM32H7      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB2ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR2;
			#endif
#endif
		//Output for TIM8EN
#ifdef TIM8_BASE_ADDR
		case TIM8_BASE_ADDR :
			return RCC->APB2ENR;
#endif
		//Output for TIM20EN
#ifdef TIM20_BASE_ADDR
		case TIM20_BASE_ADDR :
			return RCC->APB2ENR;
#endif
		//Output for TIM2EN
#ifdef TIM2_BASE_ADDR
		case TIM2_BASE_ADDR :
			#if defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->APB1ENR1;
			#elif defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			      defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR1;
			#endif
#endif
		//Output for TIM3EN
#ifdef TIM3_BASE_ADDR
		case TIM3_BASE_ADDR :
			#if defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      )
				return RCC->APB1ENR1;
			#elif defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			      defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR1;
			#endif
#endif
		//Output for TIM4EN
#ifdef TIM4_BASE_ADDR
		case TIM4_BASE_ADDR :
			#if defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      )
				return RCC->APB1ENR1;
			#elif defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#endif
#endif
		//Output for TIM5EN
#ifdef TIM5_BASE_ADDR
		case TIM5_BASE_ADDR :
			#if defined(STM32G4      ) || defined(STM32L4      )
				return RCC->APB1ENR1;
			#elif defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#endif
#endif
		//Output for TIM6EN
#ifdef TIM6_BASE_ADDR
		case TIM6_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      )
				return RCC->APB1ENR1;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			      defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR1;
			#endif
#endif
		//Output for TIM7EN
#ifdef TIM7_BASE_ADDR
		case TIM7_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      )
				return RCC->APB1ENR1;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			      defined(STM32L0      ) || defined(STM32L1      )
				return RCC->APB1ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR1;
			#endif
#endif
		//Output for TIM18EN
#ifdef TIM18_BASE_ADDR
		case TIM18_BASE_ADDR :
			return RCC->APB1ENR;
#endif
		//Output for TIM12EN
#ifdef TIM12_BASE_ADDR
		case TIM12_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      )
				return RCC->APB1ENR;
			#endif
#endif
		//Output for TIM13EN
#ifdef TIM13_BASE_ADDR
		case TIM13_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      )
				return RCC->APB1ENR;
			#endif
#endif
		//Output for TIM14EN
#ifdef TIM14_BASE_ADDR
		case TIM14_BASE_ADDR :
			#if defined(STM32H7      )
				return RCC->APB1LENR;
			#elif defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      )
				return RCC->APB1ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR2;
			#endif
#endif
		//Output for TIM19EN
#ifdef TIM19_BASE_ADDR
		case TIM19_BASE_ADDR :
			return RCC->APB2ENR;
#endif
		//Output for TIM15EN
#ifdef TIM15_BASE_ADDR
		case TIM15_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F3      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      )
				return RCC->APB2ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR2;
			#endif
#endif
		//Output for TIM16EN
#ifdef TIM16_BASE_ADDR
		case TIM16_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F3      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || \
			    defined(STM32WB      )
				return RCC->APB2ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR2;
			#endif
#endif
		//Output for TIM17EN
#ifdef TIM17_BASE_ADDR
		case TIM17_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F3      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || \
			    defined(STM32WB      )
				return RCC->APB2ENR;
			#elif defined(STM32G0      )
				return RCC->APBENR2;
			#endif
#endif
		//Output for TIM9EN
#ifdef TIM9_BASE_ADDR
		case TIM9_BASE_ADDR :
			return RCC->APB2ENR;
#endif
		//Output for TIM21EN
#ifdef TIM21_BASE_ADDR
		case TIM21_BASE_ADDR :
			return RCC->APB2ENR;
#endif
		//Output for TIM22EN
#ifdef TIM22_BASE_ADDR
		case TIM22_BASE_ADDR :
			return RCC->APB2ENR;
#endif
		//Output for TIM10EN
#ifdef TIM10_BASE_ADDR
		case TIM10_BASE_ADDR :
			return RCC->APB2ENR;
#endif
		//Output for TIM11EN
#ifdef TIM11_BASE_ADDR
		case TIM11_BASE_ADDR :
			return RCC->APB2ENR;
#endif
	}
}
inline constexpr uint32_t TIM_PARENT::get_clock_enable_bit(const uintptr_t addr)
{
	switch (addr)
	{
		//Output for TIM1EN
#ifdef TIM1_BASE_ADDR
		case TIM1_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32H7      )
				return 1 << 0;
			#elif defined(STM32F0      ) || defined(STM32G0      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      ) || \
			      defined(STM32WB      )
				return 1 << 11;
			#endif
#endif
		//Output for TIM8EN
#ifdef TIM8_BASE_ADDR
		case TIM8_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32H7      )
				return 1 << 1;
			#elif defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32L4      )
				return 1 << 13;
			#endif
#endif
		//Output for TIM20EN
#ifdef TIM20_BASE_ADDR
		case TIM20_BASE_ADDR :
				return 1 << 20;
#endif
		//Output for TIM2EN
#ifdef TIM2_BASE_ADDR
		case TIM2_BASE_ADDR :
				return 1 << 0;
#endif
		//Output for TIM3EN
#ifdef TIM3_BASE_ADDR
		case TIM3_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32G0      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32H7      ) || defined(STM32L1      ) || \
			    defined(STM32L4      )
				return 1 << 1;
			#elif defined(STM32L0      )
				return 1 << 2;
			#endif
#endif
		//Output for TIM4EN
#ifdef TIM4_BASE_ADDR
		case TIM4_BASE_ADDR :
				return 1 << 2;
#endif
		//Output for TIM5EN
#ifdef TIM5_BASE_ADDR
		case TIM5_BASE_ADDR :
				return 1 << 3;
#endif
		//Output for TIM6EN
#ifdef TIM6_BASE_ADDR
		case TIM6_BASE_ADDR :
				return 1 << 4;
#endif
		//Output for TIM7EN
#ifdef TIM7_BASE_ADDR
		case TIM7_BASE_ADDR :
				return 1 << 5;
#endif
		//Output for TIM18EN
#ifdef TIM18_BASE_ADDR
		case TIM18_BASE_ADDR :
				return 1 << 9;
#endif
		//Output for TIM12EN
#ifdef TIM12_BASE_ADDR
		case TIM12_BASE_ADDR :
				return 1 << 6;
#endif
		//Output for TIM13EN
#ifdef TIM13_BASE_ADDR
		case TIM13_BASE_ADDR :
				return 1 << 7;
#endif
		//Output for TIM14EN
#ifdef TIM14_BASE_ADDR
		case TIM14_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F2      ) || defined(STM32F3      ) || defined(STM32F4      ) || defined(STM32F7      ) || \
			    defined(STM32H7      )
				return 1 << 8;
			#elif defined(STM32G0      )
				return 1 << 15;
			#endif
#endif
		//Output for TIM19EN
#ifdef TIM19_BASE_ADDR
		case TIM19_BASE_ADDR :
				return 1 << 19;
#endif
		//Output for TIM15EN
#ifdef TIM15_BASE_ADDR
		case TIM15_BASE_ADDR :
				return 1 << 16;
#endif
		//Output for TIM16EN
#ifdef TIM16_BASE_ADDR
		case TIM16_BASE_ADDR :
				return 1 << 17;
#endif
		//Output for TIM17EN
#ifdef TIM17_BASE_ADDR
		case TIM17_BASE_ADDR :
				return 1 << 18;
#endif
		//Output for TIM9EN
#ifdef TIM9_BASE_ADDR
		case TIM9_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      )
				return 1 << 16;
			#elif defined(STM32L1      )
				return 1 << 2;
			#endif
#endif
		//Output for TIM21EN
#ifdef TIM21_BASE_ADDR
		case TIM21_BASE_ADDR :
				return 1 << 2;
#endif
		//Output for TIM22EN
#ifdef TIM22_BASE_ADDR
		case TIM22_BASE_ADDR :
				return 1 << 5;
#endif
		//Output for TIM10EN
#ifdef TIM10_BASE_ADDR
		case TIM10_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      )
				return 1 << 17;
			#elif defined(STM32L1      )
				return 1 << 3;
			#endif
#endif
		//Output for TIM11EN
#ifdef TIM11_BASE_ADDR
		case TIM11_BASE_ADDR :
			#if defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      )
				return 1 << 18;
			#elif defined(STM32L1      )
				return 1 << 4;
			#endif
#endif
	}
}


void TIM_PARENT::enable_clock() volatile
{
	get_clock_enable_reg(get_addr())
			|= get_clock_enable_bit(get_addr());
}

void TIM_PARENT::disable_clock() volatile
{
	get_clock_enable_reg(get_addr())
			&= ~get_clock_enable_bit(get_addr());
}

bool TIM_PARENT::is_clock_enabled() const volatile
{
	return (get_clock_enable_reg(get_addr())
			& get_clock_enable_bit(get_addr()))
		   == get_clock_enable_bit(get_addr());
}
//SOOL-TIM-DEFINITIONS-END
