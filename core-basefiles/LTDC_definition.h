#include "lib_utils/peripheral_include.h"
//SOOL-LTDC-INCLUDES-BEGIN
#include "RCC.h"
//SOOL-LTDC-INCLUDES-END
namespace sool { namespace core {
class LTDC {
	//SOOL-LTDC-SUB-TYPES-BEGIN
	enum class Layer
	{
	Layer1,
	Layer2
	};
	
	enum class PixelFormat
	{
	ARGB8888 = 0,
	RGB888,
	RGB565,
	ARGB1555,
	ARGB4444,
	L8, //8bit luminance
	AL44,//4bit alpha, 4bit luminance
	AL88 //8bit alpha, 8bit luminance
	};
	//SOOL-LTDC-SUB-TYPES-END

	//SOOL-LTDC-DECLARATIONS-BEGIN
	constexpr volatile Reg32_t &get_clock_enable_reg(const uintptr_t addr) volatile;
	constexpr uint32_t get_clock_enable_bit(const uintptr_t addr) volatile;
	
	inline void enable_clock() volatile;
	inline void clut_write(Layer l,uint8_t address, uint32_t color) volatile;
	inline void clut_write(Layer l,uint8_t address, uint8_t r, uint8_t g, uint8_t b) volatile;
	
	void clut_write(const Layer l,const uint32_t table[],const int table_length) volatile;
	
	inline void enable_clut(Layer l) volatile;
	inline void enable_color_keying(Layer l,uint32_t color) volatile;
	
	inline void enable() volatile {GCR.LTDCEN = 1;};
	inline void disable() volatile{GCR.LTDCEN = 0;};
	
	inline void update_shadow_registers(bool immediate = false) volatile
	{
	if(immediate)
	SRCR.IMR = 1;
	else
	SRCR.VBR = 1;
	};
	//SOOL-LTDC-DECLARATIONS-END
};
//SOOL-LTDC-DEFINITIONS-BEGIN
constexpr volatile Reg32_t& LTDC::get_clock_enable_reg(const uintptr_t addr) volatile
{
	switch (addr)
	{
//Output for LTDCEN
#ifdef LTDC_BASE_ADDR
case LTDC_BASE_ADDR :
	#if defined(STM32H7      )
return RCC->APB3ENR;
	#elif defined(STM32F4      ) || defined(STM32F7      )
return RCC->APB2ENR;
	#endif
#endif
	}
}
constexpr uint32_t LTDC::get_clock_enable_bit(const uintptr_t addr) volatile
{
	switch (addr)
	{
//Output for LTDCEN
#ifdef LTDC_BASE_ADDR
case LTDC_BASE_ADDR :
	#if defined(STM32H7      )
return 1 << 3;
	#elif defined(STM32F4      ) || defined(STM32F7      )
return 1 << 26;
	#endif
#endif
	}
	return 0;
}

inline void LTDC::enable_clock() volatile
{
	get_clock_enable_reg(get_addr()) |= get_clock_enable_bit(get_addr());
}

inline void LTDC::clut_write(LTDC::Layer l,uint8_t address, uint32_t color) volatile
{
	switch (l)
	{
case Layer::Layer1:
	L1CLUTWR = address << 24 | (color & 0xFFFFFF);
	return;
case Layer::Layer2:
	L2CLUTWR = address << 24 | (color & 0xFFFFFF);
	return;
	}

}
inline void LTDC::clut_write(LTDC::Layer l,uint8_t address, uint8_t r, uint8_t g, uint8_t b) volatile
{
	switch (l)
	{
case Layer::Layer1:
	L1CLUTWR = address << 24 | (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return;
case Layer::Layer2:
	L2CLUTWR = address << 24 | (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return;
	}
}

inline void LTDC::enable_clut(LTDC::Layer l) volatile
{
	if(l == Layer::Layer1)
L1CR.CLUTEN = 1;
	else
L2CR.CLUTEN = 1;
	update_shadow_registers(true);
}

inline void LTDC::enable_color_keying(LTDC::Layer l,uint32_t color) volatile
{
	if(l == Layer::Layer1)
	{
L1CKCR = color & 0xFFFFFF;
L1CR.COLKEN = 1;
	}
	else
	{
L2CKCR = color & 0xFFFFFF;
L2CR.COLKEN = 1;
	}
	update_shadow_registers(true);
}

//SOOL-LTDC-DEFINITIONS-END
} };
