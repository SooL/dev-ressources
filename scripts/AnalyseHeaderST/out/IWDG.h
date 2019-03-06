#ifndef __SOOL_IWDG_H
#define __SOOL_IWDG_H

#include "peripheral_include.h"
//SOOL-IWDG-INCLUDES
//region defines

#define IWDG_KR
#define IWDG_PR
#define IWDG_RLR
#define IWDG_SR

#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32F7     ) || defined(STM32H7     ) ||\
    defined(STM32L0     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define IWDG_SR_WVU          WVU                  // 1 bits @ 2
#define IWDG_WINR
#define IWDG_MAP0_WINR       WINR_TypeDef WINR
#else
#define IWDG_SR_WVU
#define IWDG_MAP0_WINR __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class IWDG
		{
			//SOOL-IWDG-ENUMS
			
			public :
			
			#ifdef IWDG_KR
			struct KR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t KEY                  :16;
					uint32_t                      :16;
			
				//SOOL-IWDG_KR-DECLARATION
			};
			#endif
			
			#ifdef IWDG_PR
			struct PR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t PR                   :3;
						uint32_t                      :29;
					};
					struct
					{
						uint32_t P0                   :1;
						uint32_t P1                   :1;
						uint32_t P2                   :1;
						uint32_t                      :29;
					};
				};
				//SOOL-IWDG_PR-DECLARATION
			};
			#endif
			
			#ifdef IWDG_RLR
			struct RLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RL                   :12;
					uint32_t                      :20;
			
				//SOOL-IWDG_RLR-DECLARATION
			};
			#endif
			
			#ifdef IWDG_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PVU                  :1;
					uint32_t RVU                  :1;
					uint32_t IWDG_SR_WVU          :1;
					uint32_t                      :29;
			
				//SOOL-IWDG_SR-DECLARATION
			};
			#endif
			
			#ifdef IWDG_WINR
			struct WINR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t WIN                  :12;
					uint32_t                      :20;
			
				//SOOL-IWDG_WINR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					KR_TypeDef KR;       // @0x000
					PR_TypeDef PR;       // @0x004
					RLR_TypeDef RLR;     // @0x008
					SR_TypeDef SR;       // @0x00c
					IWDG_MAP0_WINR;      // @0x010
				};
			};
			private:
			IWDG() = delete;
			//SOOL-IWDG-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define IWDG_BASE_ADDR ((uint32_t)0x40003000U)
#endif

#if defined(STM32H7     ) 
#define IWDG1_BASE_ADDR ((uint32_t)0x58004800U)
#endif

#ifdef IWDG_BASE_ADDR
volatile class IWDG * const IWDG = reinterpret_cast<class IWDG* const>(IWDG_BASE_ADDR);
#endif
#ifdef IWDG1_BASE_ADDR
volatile class IWDG * const IWDG1 = reinterpret_cast<class IWDG* const>(IWDG1_BASE_ADDR);
#endif
//endregion

//SOOL-IWDG-DEFINES
//SOOL-IWDG-DEFINITION
	};
};//region undef
#undef IWDG_SR_WVU
#undef IWDG_MAP0_WINR
//endregion
#endif
