#ifndef __SOOL_WWDG_H
#define __SOOL_WWDG_H

#include "peripheral_include.h"
//SOOL-WWDG-INCLUDES
//region defines

#define WWDG_CFR
#define WWDG_CR
#define WWDG_SR

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define WWDG_CFR_0_WDGTB     WDGTB                // 2 bits @ 7
#else
#define WWDG_CFR_0_WDGTB
#endif

#if defined(STM32H7     ) 
#define WWDG_CFR_0_WDGTB0    WDGTB0               // 1 bits @ 11
#define WWDG_CFR_0_WDGTB1    WDGTB1               // 1 bits @ 12
#define WWDG_CFR_0_WDGTB2    WDGTB2               // 1 bits @ 13
#define WWDG_CFR_1
#define WWDG_CR_1
#else
#define WWDG_CFR_0_WDGTB0
#define WWDG_CFR_0_WDGTB1
#define WWDG_CFR_0_WDGTB2
#endif

//endregion

namespace sool
{
	namespace core
	{
		class WWDG
		{
			//SOOL-WWDG-ENUMS
			
			public :
			
			#ifdef WWDG_CFR
			struct CFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t W                    :7;
						uint32_t WWDG_CFR_0_WDGTB     :2;
						uint32_t EWI                  :1;
						uint32_t                      :1;
						uint32_t WWDG_CFR_0_WDGTB0    :1;
						uint32_t WWDG_CFR_0_WDGTB1    :1;
						uint32_t WWDG_CFR_0_WDGTB2    :1;
						uint32_t                      :18;
					};
					#ifdef WWDG_CFR_1
					struct
					{
						uint32_t W0                   :1;
						uint32_t W1                   :1;
						uint32_t W2                   :1;
						uint32_t W3                   :1;
						uint32_t W4                   :1;
						uint32_t W5                   :1;
						uint32_t W6                   :1;
						uint32_t                      :4;
						uint32_t WDGTB                :3;
						uint32_t                      :18;
					};
					#endif
				};
				//SOOL-WWDG_CFR-DECLARATION
			};
			#endif
			
			#ifdef WWDG_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t T                    :7;
						uint32_t WDGA                 :1;
						uint32_t                      :24;
					};
					#ifdef WWDG_CR_1
					struct
					{
						uint32_t T0                   :1;
						uint32_t T1                   :1;
						uint32_t T2                   :1;
						uint32_t T3                   :1;
						uint32_t T4                   :1;
						uint32_t T5                   :1;
						uint32_t T6                   :1;
						uint32_t                      :25;
					};
					#endif
				};
				//SOOL-WWDG_CR-DECLARATION
			};
			#endif
			
			#ifdef WWDG_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EWIF                 :1;
					uint32_t                      :31;
			
				//SOOL-WWDG_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					CFR_TypeDef CFR;     // @0x004
					SR_TypeDef SR;       // @0x008
				};
			};
			private:
			WWDG() = delete;
			//SOOL-WWDG-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define WWDG_BASE_ADDR ((uint32_t)0x40002C00U)
#endif

#if defined(STM32H7     ) 
#define WWDG1_BASE_ADDR ((uint32_t)0x50003000U)
#endif

#ifdef WWDG_BASE_ADDR
volatile class WWDG * const WWDG = reinterpret_cast<class WWDG* const>(WWDG_BASE_ADDR);
#endif
#ifdef WWDG1_BASE_ADDR
volatile class WWDG * const WWDG1 = reinterpret_cast<class WWDG* const>(WWDG1_BASE_ADDR);
#endif
//endregion

//SOOL-WWDG-DEFINES
//SOOL-WWDG-DEFINITION
	};
};//region undef
#undef WWDG_CFR_0_WDGTB
#undef WWDG_CFR_0_WDGTB0
#undef WWDG_CFR_0_WDGTB1
#undef WWDG_CFR_0_WDGTB2
//endregion
#endif
