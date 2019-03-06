#ifndef __SOOL_LPTIM_H
#define __SOOL_LPTIM_H

#include "peripheral_include.h"
//SOOL-LPTIM-INCLUDES
#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L0     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
//region defines

#define LPTIM_ARR
#define LPTIM_CFGR
#define LPTIM_CMP
#define LPTIM_CNT
#define LPTIM_CR
#define LPTIM_ICR
#define LPTIM_IER
#define LPTIM_ISR

#if defined(STM32H7     ) 
#define LPTIM_CFGR2
#define LPTIM_MAP1_CFGR2     CFGR2_TypeDef CFGR2
#else
#define LPTIM_MAP1_CFGR2 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define LPTIM_CR_SNGSTRT     SNGSTRT              // 1 bits @ 1
#else
#define LPTIM_CR_SNGSTRT
#endif

#if defined(STM32H7     ) || defined(STM32L4P    ) 
#define LPTIM_CR_COUNTRST    COUNTRST             // 1 bits @ 3
#define LPTIM_CR_RSTARE      RSTARE               // 1 bits @ 4
#else
#define LPTIM_CR_COUNTRST
#define LPTIM_CR_RSTARE
#endif

#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define LPTIM_OR
#define LPTIM_MAP0_OR        OR_TypeDef OR
#else
#define LPTIM_MAP0_OR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) 
#define LPTIM_OR_0
#endif

#if defined(STM32F413xx ) || defined(STM32F423xx ) 
#define LPTIM_OR_0_TIM1_ITR2_RMP TIM1_ITR2_RMP        // 1 bits @ 2
#define LPTIM_OR_0_TIM5_ITR1_RMP TIM5_ITR1_RMP        // 1 bits @ 3
#define LPTIM_OR_0_TIM9_ITR1_RMP TIM9_ITR1_RMP        // 1 bits @ 4
#else
#define LPTIM_OR_0_TIM1_ITR2_RMP
#define LPTIM_OR_0_TIM5_ITR1_RMP
#define LPTIM_OR_0_TIM9_ITR1_RMP
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define LPTIM_OR_1
#define LPTIM_OR_2
#endif

//endregion

namespace sool
{
	namespace core
	{
		class LPTIM
		{
			//SOOL-LPTIM-ENUMS
			
			public :
			
			#ifdef LPTIM_ARR
			struct ARR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ARR                  :16;
					uint32_t                      :16;
			
				//SOOL-LPTIM_ARR-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_CFGR
			struct CFGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CKSEL                :1;
					uint32_t CKPOL                :2;
					uint32_t CKFLT                :2;
					uint32_t                      :1;
					uint32_t TRGFLT               :2;
					uint32_t                      :1;
					uint32_t PRESC                :3;
					uint32_t                      :1;
					uint32_t TRIGSEL              :3;
					uint32_t                      :1;
					uint32_t TRIGEN               :2;
					uint32_t TIMOUT               :1;
					uint32_t WAVE                 :1;
					uint32_t WAVPOL               :1;
					uint32_t PRELOAD              :1;
					uint32_t COUNTMODE            :1;
					uint32_t ENC                  :1;
					uint32_t                      :7;
			
				//SOOL-LPTIM_CFGR-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_CFGR2
			struct CFGR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t CFGR2                :8;
						uint32_t                      :24;
					};
					struct
					{
						uint32_t IN1_SEL0             :1;
						uint32_t IN1_SEL1             :1;
						uint32_t                      :2;
						uint32_t IN2_SEL0             :1;
						uint32_t IN2_SEL1             :1;
						uint32_t                      :26;
					};
				};
				//SOOL-LPTIM_CFGR2-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_CMP
			struct CMP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMP                  :16;
					uint32_t                      :16;
			
				//SOOL-LPTIM_CMP-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_CNT
			struct CNT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CNT                  :16;
					uint32_t                      :16;
			
				//SOOL-LPTIM_CNT-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ENABLE               :1;
					uint32_t LPTIM_CR_SNGSTRT     :1;
					uint32_t CNTSTRT              :1;
					uint32_t LPTIM_CR_COUNTRST    :1;
					uint32_t LPTIM_CR_RSTARE      :1;
					uint32_t                      :27;
			
				//SOOL-LPTIM_CR-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMPMCF               :1;
					uint32_t ARRMCF               :1;
					uint32_t EXTTRIGCF            :1;
					uint32_t CMPOKCF              :1;
					uint32_t ARROKCF              :1;
					uint32_t UPCF                 :1;
					uint32_t DOWNCF               :1;
					uint32_t                      :25;
			
				//SOOL-LPTIM_ICR-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_IER
			struct IER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMPMIE               :1;
					uint32_t ARRMIE               :1;
					uint32_t EXTTRIGIE            :1;
					uint32_t CMPOKIE              :1;
					uint32_t ARROKIE              :1;
					uint32_t UPIE                 :1;
					uint32_t DOWNIE               :1;
					uint32_t                      :25;
			
				//SOOL-LPTIM_IER-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMPM                 :1;
					uint32_t ARRM                 :1;
					uint32_t EXTTRIG              :1;
					uint32_t CMPOK                :1;
					uint32_t ARROK                :1;
					uint32_t UP                   :1;
					uint32_t DOWN                 :1;
					uint32_t                      :25;
			
				//SOOL-LPTIM_ISR-DECLARATION
			};
			#endif
			
			#ifdef LPTIM_OR
			struct OR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef LPTIM_OR_0
					struct
					{
						uint32_t LPT_IN1_RMP          :2;
						uint32_t LPTIM_OR_0_TIM1_ITR2_RMP :1;
						uint32_t LPTIM_OR_0_TIM5_ITR1_RMP :1;
						uint32_t LPTIM_OR_0_TIM9_ITR1_RMP :1;
						uint32_t                      :27;
					};
					#endif
					#ifdef LPTIM_OR_1
					struct
					{
						uint32_t OR                   :2;
						uint32_t                      :30;
					};
					#endif
					#ifdef LPTIM_OR_2
					struct
					{
						uint32_t O0                   :1;
						uint32_t O1                   :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-LPTIM_OR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					ISR_TypeDef ISR;     // @0x000
					ICR_TypeDef ICR;     // @0x004
					IER_TypeDef IER;     // @0x008
					CFGR_TypeDef CFGR;   // @0x00c
					CR_TypeDef CR;       // @0x010
					CMP_TypeDef CMP;     // @0x014
					ARR_TypeDef ARR;     // @0x018
					CNT_TypeDef CNT;     // @0x01c
					LPTIM_MAP0_OR;       // @0x020
					__SOOL_PERIPH_PADDING_2;
				};
				struct
				{
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_2;
					LPTIM_MAP1_CFGR2;    // @0x022
				};
			};
			private:
			LPTIM() = delete;
			//SOOL-LPTIM-DECLARATION
		};
		
		//region instances
#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F7     ) || defined(STM32H7     ) 
#define LPTIM1_BASE_ADDR ((uint32_t)0x40002400U)
#endif

#if defined(STM32L0     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define LPTIM1_BASE_ADDR ((uint32_t)0x40007C00U)
#endif

#if defined(STM32H7     ) 
#define LPTIM2_BASE_ADDR ((uint32_t)0x58002400U)
#define LPTIM3_BASE_ADDR ((uint32_t)0x58002800U)
#define LPTIM4_BASE_ADDR ((uint32_t)0x58002C00U)
#define LPTIM5_BASE_ADDR ((uint32_t)0x58003000U)
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define LPTIM2_BASE_ADDR ((uint32_t)0x40009400U)
#endif

#ifdef LPTIM1_BASE_ADDR
volatile class LPTIM * const LPTIM1 = reinterpret_cast<class LPTIM* const>(LPTIM1_BASE_ADDR);
#endif
#ifdef LPTIM2_BASE_ADDR
volatile class LPTIM * const LPTIM2 = reinterpret_cast<class LPTIM* const>(LPTIM2_BASE_ADDR);
#endif
#ifdef LPTIM3_BASE_ADDR
volatile class LPTIM * const LPTIM3 = reinterpret_cast<class LPTIM* const>(LPTIM3_BASE_ADDR);
#endif
#ifdef LPTIM4_BASE_ADDR
volatile class LPTIM * const LPTIM4 = reinterpret_cast<class LPTIM* const>(LPTIM4_BASE_ADDR);
#endif
#ifdef LPTIM5_BASE_ADDR
volatile class LPTIM * const LPTIM5 = reinterpret_cast<class LPTIM* const>(LPTIM5_BASE_ADDR);
#endif
//endregion

//SOOL-LPTIM-DEFINES
//SOOL-LPTIM-DEFINITION
	};
};//region undef
#undef LPTIM_MAP1_CFGR2
#undef LPTIM_CR_SNGSTRT
#undef LPTIM_CR_COUNTRST
#undef LPTIM_CR_RSTARE
#undef LPTIM_MAP0_OR
#undef LPTIM_OR_0_TIM1_ITR2_RMP
#undef LPTIM_OR_0_TIM5_ITR1_RMP
#undef LPTIM_OR_0_TIM9_ITR1_RMP
//endregion
#endif
#endif
