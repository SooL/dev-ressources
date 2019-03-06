#ifndef __SOOL_HSEM_H
#define __SOOL_HSEM_H

#include "peripheral_include.h"
//SOOL-HSEM-INCLUDES
#if defined(STM32H7     ) 
//region defines

#define HSEM_CR
#define HSEM_ICR
#define HSEM_IER
#define HSEM_ISR
#define HSEM_KEYR
#define HSEM_MISR
#define HSEM_R
#define HSEM_RLR

//endregion

namespace sool
{
	namespace core
	{
		class HSEM
		{
			//SOOL-HSEM-ENUMS
			
			public :
			
			#ifdef HSEM_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :8;
					uint32_t MASTERID             :8;
					uint32_t KEY                  :16;
			
				//SOOL-HSEM_CR-DECLARATION
			};
			#endif
			
			#ifdef HSEM_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ISEM0                :1;
					uint32_t ISEM1                :1;
					uint32_t ISEM2                :1;
					uint32_t ISEM3                :1;
					uint32_t ISEM4                :1;
					uint32_t ISEM5                :1;
					uint32_t ISEM6                :1;
					uint32_t ISEM7                :1;
					uint32_t ISEM8                :1;
					uint32_t ISEM9                :1;
					uint32_t ISEM10               :1;
					uint32_t ISEM11               :1;
					uint32_t ISEM12               :1;
					uint32_t ISEM13               :1;
					uint32_t ISEM14               :1;
					uint32_t ISEM15               :1;
					uint32_t ISEM16               :1;
					uint32_t ISEM17               :1;
					uint32_t ISEM18               :1;
					uint32_t ISEM19               :1;
					uint32_t ISEM20               :1;
					uint32_t ISEM21               :1;
					uint32_t ISEM22               :1;
					uint32_t ISEM23               :1;
					uint32_t ISEM24               :1;
					uint32_t ISEM25               :1;
					uint32_t ISEM26               :1;
					uint32_t ISEM27               :1;
					uint32_t ISEM28               :1;
					uint32_t ISEM29               :1;
					uint32_t ISEM30               :1;
					uint32_t ISEM31               :1;
			
				//SOOL-HSEM_ICR-DECLARATION
			};
			#endif
			
			#ifdef HSEM_IER
			struct IER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ISEM0                :1;
					uint32_t ISEM1                :1;
					uint32_t ISEM2                :1;
					uint32_t ISEM3                :1;
					uint32_t ISEM4                :1;
					uint32_t ISEM5                :1;
					uint32_t ISEM6                :1;
					uint32_t ISEM7                :1;
					uint32_t ISEM8                :1;
					uint32_t ISEM9                :1;
					uint32_t ISEM10               :1;
					uint32_t ISEM11               :1;
					uint32_t ISEM12               :1;
					uint32_t ISEM13               :1;
					uint32_t ISEM14               :1;
					uint32_t ISEM15               :1;
					uint32_t ISEM16               :1;
					uint32_t ISEM17               :1;
					uint32_t ISEM18               :1;
					uint32_t ISEM19               :1;
					uint32_t ISEM20               :1;
					uint32_t ISEM21               :1;
					uint32_t ISEM22               :1;
					uint32_t ISEM23               :1;
					uint32_t ISEM24               :1;
					uint32_t ISEM25               :1;
					uint32_t ISEM26               :1;
					uint32_t ISEM27               :1;
					uint32_t ISEM28               :1;
					uint32_t ISEM29               :1;
					uint32_t ISEM30               :1;
					uint32_t ISEM31               :1;
			
				//SOOL-HSEM_IER-DECLARATION
			};
			#endif
			
			#ifdef HSEM_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ISEM0                :1;
					uint32_t ISEM1                :1;
					uint32_t ISEM2                :1;
					uint32_t ISEM3                :1;
					uint32_t ISEM4                :1;
					uint32_t ISEM5                :1;
					uint32_t ISEM6                :1;
					uint32_t ISEM7                :1;
					uint32_t ISEM8                :1;
					uint32_t ISEM9                :1;
					uint32_t ISEM10               :1;
					uint32_t ISEM11               :1;
					uint32_t ISEM12               :1;
					uint32_t ISEM13               :1;
					uint32_t ISEM14               :1;
					uint32_t ISEM15               :1;
					uint32_t ISEM16               :1;
					uint32_t ISEM17               :1;
					uint32_t ISEM18               :1;
					uint32_t ISEM19               :1;
					uint32_t ISEM20               :1;
					uint32_t ISEM21               :1;
					uint32_t ISEM22               :1;
					uint32_t ISEM23               :1;
					uint32_t ISEM24               :1;
					uint32_t ISEM25               :1;
					uint32_t ISEM26               :1;
					uint32_t ISEM27               :1;
					uint32_t ISEM28               :1;
					uint32_t ISEM29               :1;
					uint32_t ISEM30               :1;
					uint32_t ISEM31               :1;
			
				//SOOL-HSEM_ISR-DECLARATION
			};
			#endif
			
			#ifdef HSEM_KEYR
			struct KEYR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :16;
					uint32_t KEY                  :16;
			
				//SOOL-HSEM_KEYR-DECLARATION
			};
			#endif
			
			#ifdef HSEM_MISR
			struct MISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ISEM0                :1;
					uint32_t ISEM1                :1;
					uint32_t ISEM2                :1;
					uint32_t ISEM3                :1;
					uint32_t ISEM4                :1;
					uint32_t ISEM5                :1;
					uint32_t ISEM6                :1;
					uint32_t ISEM7                :1;
					uint32_t ISEM8                :1;
					uint32_t ISEM9                :1;
					uint32_t ISEM10               :1;
					uint32_t ISEM11               :1;
					uint32_t ISEM12               :1;
					uint32_t ISEM13               :1;
					uint32_t ISEM14               :1;
					uint32_t ISEM15               :1;
					uint32_t ISEM16               :1;
					uint32_t ISEM17               :1;
					uint32_t ISEM18               :1;
					uint32_t ISEM19               :1;
					uint32_t ISEM20               :1;
					uint32_t ISEM21               :1;
					uint32_t ISEM22               :1;
					uint32_t ISEM23               :1;
					uint32_t ISEM24               :1;
					uint32_t ISEM25               :1;
					uint32_t ISEM26               :1;
					uint32_t ISEM27               :1;
					uint32_t ISEM28               :1;
					uint32_t ISEM29               :1;
					uint32_t ISEM30               :1;
					uint32_t ISEM31               :1;
			
				//SOOL-HSEM_MISR-DECLARATION
			};
			#endif
			
			#ifdef HSEM_R
			struct R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PROCID               :8;
					uint32_t MASTERID             :8;
					uint32_t                      :15;
					uint32_t LOCK                 :1;
			
				//SOOL-HSEM_R-DECLARATION
			};
			#endif
			
			#ifdef HSEM_RLR
			struct RLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PROCID               :8;
					uint32_t MASTERID             :8;
					uint32_t                      :15;
					uint32_t LOCK                 :1;
			
				//SOOL-HSEM_RLR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					R_TypeDef R[32];     // @0x000
					RLR_TypeDef RLR[32]; // @0x080
					IER_TypeDef IER;     // @0x100
					ICR_TypeDef ICR;     // @0x104
					ISR_TypeDef ISR;     // @0x108
					MISR_TypeDef MISR;   // @0x10c
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					CR_TypeDef CR;       // @0x140
					KEYR_TypeDef KEYR;   // @0x144
				};
			};
			private:
			HSEM() = delete;
			//SOOL-HSEM-DECLARATION
		};
		
		//region instances
#define HSEM_BASE_ADDR ((uint32_t)0x58026400U)
#ifdef HSEM_BASE_ADDR
volatile class HSEM * const HSEM = reinterpret_cast<class HSEM* const>(HSEM_BASE_ADDR);
#endif
//endregion

//SOOL-HSEM-DEFINES
//SOOL-HSEM-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
