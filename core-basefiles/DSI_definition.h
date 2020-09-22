#include "lib_utils/peripheral_include.h"
//SOOL-DSI-INCLUDES-BEGIN
#include "RCC.h"
//SOOL-DSI-INCLUDES-END
namespace sool { namespace core {
	class DSI {
		//SOOL-DSI-SUB-TYPES-BEGIN
		enum class ShortWriteType : uint32_t {
			Generic_NoParam  = 0x03,
			Generic_OneParam = 0x13,
			Generic_TwoParam = 0x23,
			DCS_NoParam = 0x05,
			DCS_OneParam = 0x15
		};
		
		enum class LongWriteType : uint32_t {
			Generic = 0x29,
			DCS  = 0x39
		};
		//SOOL-DSI-SUB-TYPES-END

		//SOOL-DSI-DECLARATIONS-BEGIN
		constexpr volatile Reg32_t &get_clock_enable_reg(const uintptr_t addr);
		constexpr uint32_t get_clock_enable_bit(const uintptr_t addr);
		
		void write_short(const int channel_id, const ShortWriteType mode, const uint8_t param1, const uint8_t  param2) volatile;
		
		/**
		 * In DCS mode, the first parameter is the location to write to.
		 * @param channel_id
		 * @param mode
		 * @param payload_length
		 * @param payload
		 */
		void write_long(const int channel_id, const DSI::LongWriteType mode, const unsigned int payload_length, const uint8_t *payload) volatile;
		//SOOL-DSI-DECLARATIONS-END
	};
	//SOOL-DSI-DEFINITIONS-BEGIN
	constexpr volatile Reg32_t &DSI::get_clock_enable_reg(const uintptr_t addr)
	{
	switch (addr)
	{
	//Output for DSIEN
	#ifdef DSI_BASE_ADDR
	case DSI_BASE_ADDR :
	return RCC->APB2ENR;
	#endif
	}
	}
	
	constexpr uint32_t DSI::get_clock_enable_bit(const uintptr_t addr)
	{
	switch (addr)
	{
	//Output for DSIEN
	#ifdef DSI_BASE_ADDR
	case DSI_BASE_ADDR :
	return 1 << 27;
	#endif
	}
	}
	//SOOL-DSI-DEFINITIONS-END
} };
