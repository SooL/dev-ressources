#ifndef __SOOL_COMP1_2_H
#define __SOOL_COMP1_2_H

#include "peripheral_include.h"
//SOOL-COMP1_2-INCLUDES
#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) 
//region defines

#define COMP1_2_CSR

//endregion

namespace sool
{
	namespace core
	{
		class COMP1_2
		{
			//SOOL-COMP1_2-ENUMS
			
			public :
			
			union
			{
				
				struct
				{
					uint32_t CSR;        // @0x000
				};
			};
			private:
			COMP1_2() = delete;
			//SOOL-COMP1_2-DECLARATION
		};
		
		//region instances
#define COMP_BASE_ADDR ((uint32_t)0x4001001CU)
#ifdef COMP_BASE_ADDR
volatile class COMP1_2 * const COMP = reinterpret_cast<class COMP1_2* const>(COMP_BASE_ADDR);
#endif
//endregion

//SOOL-COMP1_2-DEFINES
//SOOL-COMP1_2-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
