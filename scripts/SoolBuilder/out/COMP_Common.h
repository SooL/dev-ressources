#ifndef __SOOL_COMP_Common_H
#define __SOOL_COMP_Common_H

#include "peripheral_include.h"
//SOOL-COMP_Common-INCLUDES
#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
//region defines

#if defined(STM32H7     ) 
#define COMP_Common_CFGR
#define COMP_Common_MAP1_CFGR uint32_t CFGR
#else
#define COMP_Common_MAP1_CFGR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define COMP_Common_CSR
#define COMP_Common_MAP0_CSR uint32_t CSR
#else
#define COMP_Common_MAP0_CSR __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class COMP_Common
		{
			//SOOL-COMP_Common-ENUMS
			
			public :
			
			union
			{
				
				struct
				{
					COMP_Common_MAP0_CSR; // @0x000
				};
				struct
				{
					COMP_Common_MAP1_CFGR; // @0x000
				};
			};
			private:
			COMP_Common() = delete;
			//SOOL-COMP_Common-DECLARATION
		};
		
		//region instances
#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) 
#define COMP12_COMMON_BASE_ADDR ((uint32_t)0x4001001CU)
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) 
#define COMP12_COMMON_BASE_ADDR ((uint32_t)0x40010020U)
#endif

#if defined(STM32H7     ) 
#define COMP12_COMMON_BASE_ADDR ((uint32_t)0x58003810U)
#endif

#if defined(STM32L1     ) 
#define COMP12_COMMON_BASE_ADDR ((uint32_t)0x40007C00U)
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define COMP12_COMMON_BASE_ADDR ((uint32_t)0x40010204U)
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define COMP34_COMMON_BASE_ADDR ((uint32_t)0x40010028U)
#define COMP56_COMMON_BASE_ADDR ((uint32_t)0x40010030U)
#endif

#ifdef COMP12_COMMON_BASE_ADDR
volatile class COMP_Common * const COMP12_COMMON = reinterpret_cast<class COMP_Common* const>(COMP12_COMMON_BASE_ADDR);
#endif
#ifdef COMP34_COMMON_BASE_ADDR
volatile class COMP_Common * const COMP34_COMMON = reinterpret_cast<class COMP_Common* const>(COMP34_COMMON_BASE_ADDR);
#endif
#ifdef COMP56_COMMON_BASE_ADDR
volatile class COMP_Common * const COMP56_COMMON = reinterpret_cast<class COMP_Common* const>(COMP56_COMMON_BASE_ADDR);
#endif
//endregion

//SOOL-COMP_Common-DEFINES
//SOOL-COMP_Common-DEFINITION
	};
};//region undef
#undef COMP_Common_MAP1_CFGR
#undef COMP_Common_MAP0_CSR
//endregion
#endif
#endif
