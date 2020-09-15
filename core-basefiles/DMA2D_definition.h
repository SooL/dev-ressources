//SOOL-DMA2D-INCLUDES-BEGIN
#include "RCC.h"
//SOOL-DMA2D-INCLUDES-END
template<typename plugin>
class DMA2D {
//SOOL-DMA2D-DECLARATIONS-BEGIN
#if __SOOL_DEBUG_NOPHY
	DMA2D(uintptr_t addr) : myaddr(addr){};
	const uintptr_t myaddr;
	inline const uintptr_t get_addr() const volatile {return myaddr;};
#else
	inline const uintptr_t get_addr() const volatile {return reinterpret_cast<uintptr_t>(this);};
private:
	DMA2D() = delete;
#endif
private:
	static constexpr uint32_t get_clock_enable_bit(const uintptr_t addr);
	static constexpr volatile Reg32_t& get_clock_enable_reg(const uintptr_t addr);
public:
	void enable_clock() volatile;
//SOOL-DMA2D-DECLARATIONS-END
};

//SOOL-DMA2D-DEFINITIONS-BEGIN
inline void DMA2D::enable_clock() volatile
{
	get_clock_enable_reg(get_addr()) |= get_clock_enable_bit(get_addr());
}

inline constexpr volatile Reg32_t& DMA2D::get_clock_enable_reg(const uintptr_t addr)
{
	switch (addr)
	{
//Output for DMA2DEN
#ifdef DMA2D_BASE_ADDR
case DMA2D_BASE_ADDR :
	#if defined(STM32H7A3xx  ) || defined(STM32H7A3xxQ ) || defined(STM32H7B0xx  ) || defined(STM32H7B0xxQ ) || defined(STM32H7B3xx  ) || \
	    defined(STM32H7B3xxQ )
return RCC->C1_AHB3ENR;
	#elif defined(STM32H742xx  ) || defined(STM32H743xx  ) || defined(STM32H745xx_CORE_CM4) || defined(STM32H745xx_CORE_CM7) || defined(STM32H747xx_CORE_CM4) || \
	      defined(STM32H747xx_CORE_CM7) || defined(STM32H750xx  ) || defined(STM32H753xx  ) || defined(STM32H755xx_CORE_CM4) || defined(STM32H755xx_CORE_CM7) || \
	      defined(STM32H757xx_CORE_CM4) || defined(STM32H757xx_CORE_CM7)
return RCC->AHB3ENR;
	#elif defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32L4      )
return RCC->AHB1ENR;
	#endif
#endif
	}
}
inline constexpr uint32_t DMA2D::get_clock_enable_bit(const uintptr_t addr)
{
	switch (addr)
	{
//Output for DMA2DEN
#ifdef DMA2D_BASE_ADDR
case DMA2D_BASE_ADDR :
	#if defined(STM32H7      )
return 1 << 4;
	#elif defined(STM32F4      ) || defined(STM32F7      )
return 1 << 23;
	#elif defined(STM32L4      )
return 1 << 17;
	#endif
#endif
	}
}

//SOOL-DMA2D-DEFINITIONS-END