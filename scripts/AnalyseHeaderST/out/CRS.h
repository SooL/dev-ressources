#ifndef __SOOL_CRS_H
#define __SOOL_CRS_H

#include "peripheral_include.h"
//SOOL-CRS-INCLUDES
#if defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
//region defines

#define CRS_CFGR
#define CRS_CR
#define CRS_ICR
#define CRS_ISR

//endregion

namespace sool
{
	namespace core
	{
		class CRS
		{
			//SOOL-CRS-ENUMS
			
			public :
			
			#ifdef CRS_CFGR
			struct CFGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RELOAD               :16;
					uint32_t FELIM                :8;
					uint32_t SYNCDIV              :3;
					uint32_t                      :1;
					uint32_t SYNCSRC              :2;
					uint32_t                      :1;
					uint32_t SYNCPOL              :1;
			
				//SOOL-CRS_CFGR-DECLARATION
			};
			#endif
			
			#ifdef CRS_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SYNCOKIE             :1;
					uint32_t SYNCWARNIE           :1;
					uint32_t ERRIE                :1;
					uint32_t ESYNCIE              :1;
					uint32_t                      :1;
					uint32_t CEN                  :1;
					uint32_t AUTOTRIMEN           :1;
					uint32_t SWSYNC               :1;
					uint32_t TRIM                 :6;
					uint32_t                      :18;
			
				//SOOL-CRS_CR-DECLARATION
			};
			#endif
			
			#ifdef CRS_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SYNCOKC              :1;
					uint32_t SYNCWARNC            :1;
					uint32_t ERRC                 :1;
					uint32_t ESYNCC               :1;
					uint32_t                      :28;
			
				//SOOL-CRS_ICR-DECLARATION
			};
			#endif
			
			#ifdef CRS_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SYNCOKF              :1;
					uint32_t SYNCWARNF            :1;
					uint32_t ERRF                 :1;
					uint32_t ESYNCF               :1;
					uint32_t                      :4;
					uint32_t SYNCERR              :1;
					uint32_t SYNCMISS             :1;
					uint32_t TRIMOVF              :1;
					uint32_t                      :4;
					uint32_t FEDIR                :1;
					uint32_t FECAP                :16;
			
				//SOOL-CRS_ISR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					CFGR_TypeDef CFGR;   // @0x004
					ISR_TypeDef ISR;     // @0x008
					ICR_TypeDef ICR;     // @0x00c
				};
			};
			private:
			CRS() = delete;
			//SOOL-CRS-DECLARATION
		};
		
		//region instances
#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32L052xx ) ||\
    defined(STM32L053xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) 
#define CRS_BASE_ADDR ((uint32_t)0x40006C00U)
#endif

#if defined(STM32H7     ) 
#define CRS_BASE_ADDR ((uint32_t)0x40008400U)
#endif

#define CRS_BASE_ADDR ((uint32_t)0x40006000U)
#ifdef CRS_BASE_ADDR
volatile class CRS * const CRS = reinterpret_cast<class CRS* const>(CRS_BASE_ADDR);
#endif
//endregion

//SOOL-CRS-DEFINES
//SOOL-CRS-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
