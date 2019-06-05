class RCC
{
//SOOL-RCC-RELATED-TYPES-BEGIN
	enum class ClockDomain
	{
#if defined(STM32F0)
		HSI,
		HSE,
		LSI,
		LSE,
		HSI14,
		Cortex_System_Timer,
		PLLCLK,
		SYSCLK,
		HCLK,
		RTCCLKK,
		MCO,
		PCLK,
	#if defined(STM32F030x4) || defined(STM32F030x6) || defined(STM32F030x8)
			FHCLK,
	#else
			FCLK,
	#endif
	#if defined(STM32F04x) || defined(STM32F07x) || defined(STM32F09x)
			HSI48,
	#endif
	#if defined(STM32F0x0)
			FLITFCLK,
	#endif
#endif

	};
//SOOL-RCC-RELATED-TYPES-END

//SOOL-RCC-DECLARATION-BEGIN
public:
	uint32_t get_clock_frequency(ClockDomain domain) volatile;
//SOOL-RCC-DECLARATION-END
};
//SOOL-RCC-DEFINITION-BEGIN
//SOOL-RCC-DEFINITION-END