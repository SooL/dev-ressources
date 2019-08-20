#ifndef __SOOL_RNG_H
#define __SOOL_RNG_H

#include "peripheral_include.h"
//SOOL-RNG-INCLUDES
#if defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
//region defines

#define RNG_CR
#define RNG_DR
#define RNG_SR

#if defined(STM32H7     ) || defined(STM32L4P    ) 
#define RNG_CR_CED           CED                  // 1 bits @ 5
#else
#define RNG_CR_CED
#endif

//endregion

namespace sool
{
	namespace core
	{
		class RNG
		{
			//SOOL-RNG-ENUMS
			
			public :
			
			#ifdef RNG_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t RNGEN                :1;
					uint32_t IE                   :1;
					uint32_t                      :1;
					uint32_t RNG_CR_CED           :1;
					uint32_t                      :26;
			
				//SOOL-RNG_CR-DECLARATION
			};
			#endif
			
			#ifdef RNG_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DRDY                 :1;
					uint32_t CECS                 :1;
					uint32_t SECS                 :1;
					uint32_t                      :2;
					uint32_t CEIS                 :1;
					uint32_t SEIS                 :1;
					uint32_t                      :25;
			
				//SOOL-RNG_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					SR_TypeDef SR;       // @0x004
					uint32_t DR;         // @0x008
				};
			};
			private:
			RNG() = delete;
			//SOOL-RNG-DECLARATION
		};
		
		//region instances
#if defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F412Cx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RNG_BASE_ADDR ((uint32_t)0x50060800U)
#endif

#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) 
#define RNG_BASE_ADDR ((uint32_t)0x40080000U)
#endif

#if defined(STM32H7     ) 
#define RNG_BASE_ADDR ((uint32_t)0x48021800U)
#endif

#if defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) ||\
    defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) 
#define RNG_BASE_ADDR ((uint32_t)0x40025000U)
#endif

#ifdef RNG_BASE_ADDR
volatile class RNG * const RNG = reinterpret_cast<class RNG* const>(RNG_BASE_ADDR);
#endif
//endregion

//SOOL-RNG-DEFINES
//SOOL-RNG-DEFINITION
	};
};//region undef
#undef RNG_CR_CED
//endregion
#endif
#endif
