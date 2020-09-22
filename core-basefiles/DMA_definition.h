//SOOL-DMA-DEFINITIONS-BEGIN
template<typename T>
inline constexpr volatile Reg32_t& DMA<T>::get_clock_enable_reg(const uintptr_t addr)
{
	switch (addr) 
	{
	//Output for DMA1EN
	#ifdef DMA1_BASE_ADDR
		case DMA1_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32L1      )
				return RCC->AHBENR;
			#elif defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32G4      ) || defined(STM32GB      ) || \
			      defined(STM32H7      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->AHB1ENR;
			#endif
	#endif
	//Output for DMA2EN
	#ifdef DMA2_BASE_ADDR
		case DMA2_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F3      ) || defined(STM32L1      )
				return RCC->AHBENR;
			#elif defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      ) || defined(STM32G4      ) || defined(STM32GB      ) || \
			      defined(STM32H7      ) || defined(STM32L4      ) || defined(STM32WB      )
				return RCC->AHB1ENR;
			#endif
	#endif
	//Output for DMAEN
	#ifdef DMA_BASE_ADDR
		case DMA_BASE_ADDR :
			return RCC->AHBENR;
		#endif
	}
}
template<typename T>
inline constexpr uint32_t DMA<T>::get_clock_enable_bit(const uintptr_t addr)
{
	switch (addr) 
	{
	//Output for DMA1EN
	#ifdef DMA1_BASE_ADDR
		case DMA1_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32H7      ) || defined(STM32L4      ) || \
			    defined(STM32WB      )
				return 1 << 0;
			#elif defined(STM32L1      )
				return 1 << 24;
			#elif defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      )
				return 1 << 21;
			#endif
	#endif
	//Output for DMA2EN
	#ifdef DMA2_BASE_ADDR
		case DMA2_BASE_ADDR :
			#if defined(STM32F0      ) || defined(STM32F3      ) || defined(STM32G4      ) || defined(STM32GB      ) || defined(STM32H7      ) || \
			    defined(STM32L4      ) || defined(STM32WB      )
				return 1 << 1;
			#elif defined(STM32L1      )
				return 1 << 25;
			#elif defined(STM32F2      ) || defined(STM32F4      ) || defined(STM32F7      )
				return 1 << 22;
			#endif
	#endif
	//Output for DMAEN
	#ifdef DMA_BASE_ADDR
		case DMA_BASE_ADDR :
			#if defined(STM32G0      )
				return 1 << 0;
			#elif defined(STM32L1      )
				return 1 << 24;
			#endif
	#endif
	}
}

//SOOL-DMA-DEFINITIONS-END
