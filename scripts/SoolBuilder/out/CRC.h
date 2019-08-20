#ifndef __SOOL_CRC_H
#define __SOOL_CRC_H

#include "peripheral_include.h"
//SOOL-CRC-INCLUDES
//region defines

#define CRC_CR
#define CRC_DR
#define CRC_IDR

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F3     ) || defined(STM32F7     ) || defined(STM32H7     ) ||\
    defined(STM32L0     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define CRC_CR_POLYSIZE      POLYSIZE             // 2 bits @ 3
#define CRC_POL
#define CRC_MAP0_POL         POL_TypeDef POL
#else
#define CRC_CR_POLYSIZE
#define CRC_MAP0_POL __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32F7     ) || defined(STM32H7     ) ||\
    defined(STM32L0     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define CRC_CR_REV_IN        REV_IN               // 2 bits @ 5
#define CRC_CR_REV_OUT       REV_OUT              // 1 bits @ 7
#define CRC_INIT
#define CRC_MAP0_INIT        INIT_TypeDef INIT
#else
#define CRC_CR_REV_IN
#define CRC_CR_REV_OUT
#define CRC_MAP0_INIT __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define CRC_IDR_0
#endif

#if defined(STM32H7     ) 
#define CRC_IDR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class CRC
		{
			//SOOL-CRC-ENUMS
			
			public :
			
			#ifdef CRC_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RESET                :1;
					uint32_t                      :2;
					uint32_t CRC_CR_POLYSIZE      :2;
					uint32_t CRC_CR_REV_IN        :2;
					uint32_t CRC_CR_REV_OUT       :1;
					uint32_t                      :24;
			
				//SOOL-CRC_CR-DECLARATION
			};
			#endif
			
			#ifdef CRC_DR
			struct DR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DR                   :32;
			
				//SOOL-CRC_DR-DECLARATION
			};
			#endif
			
			#ifdef CRC_IDR
			struct IDR_TypeDef : public Reg8_t
			{
				using Reg8_t::operator=;
			
				union
				{
					#ifdef CRC_IDR_0
					struct
					{
						uint32_t IDR                  :8;
						uint32_t                      :24;
					};
					#endif
					#ifdef CRC_IDR_1
					struct
					{
						uint32_t IDR                  :32;
					};
					#endif
				};
				//SOOL-CRC_IDR-DECLARATION
			};
			#endif
			
			#ifdef CRC_INIT
			struct INIT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INIT                 :32;
			
				//SOOL-CRC_INIT-DECLARATION
			};
			#endif
			
			#ifdef CRC_POL
			struct POL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t POL                  :32;
			
				//SOOL-CRC_POL-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					DR_TypeDef DR;       // @0x000
					IDR_TypeDef IDR;     // @0x004
					CR_TypeDef CR;       // @0x008
					__SOOL_PERIPH_PADDING_4;
					CRC_MAP0_INIT;       // @0x010
					CRC_MAP0_POL;        // @0x014
				};
			};
			private:
			CRC() = delete;
			//SOOL-CRC-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define CRC_BASE_ADDR ((uint32_t)0x40023000U)
#endif

#if defined(STM32H7     ) 
#define CRC_BASE_ADDR ((uint32_t)0x58024C00U)
#endif

#ifdef CRC_BASE_ADDR
volatile class CRC * const CRC = reinterpret_cast<class CRC* const>(CRC_BASE_ADDR);
#endif
//endregion

//SOOL-CRC-DEFINES
//SOOL-CRC-DEFINITION
	};
};//region undef
#undef CRC_CR_POLYSIZE
#undef CRC_MAP0_POL
#undef CRC_CR_REV_IN
#undef CRC_CR_REV_OUT
#undef CRC_MAP0_INIT
//endregion
#endif
