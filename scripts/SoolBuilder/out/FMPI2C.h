#ifndef __SOOL_FMPI2C_H
#define __SOOL_FMPI2C_H

#include "peripheral_include.h"
//SOOL-FMPI2C-INCLUDES
#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F412Cx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F446xx ) 
//region defines

#define FMPI2C_CR1
#define FMPI2C_CR2
#define FMPI2C_ICR
#define FMPI2C_ISR
#define FMPI2C_OAR1
#define FMPI2C_OAR2
#define FMPI2C_PECR
#define FMPI2C_RXDR
#define FMPI2C_TIMEOUTR
#define FMPI2C_TIMINGR
#define FMPI2C_TXDR

#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F423xx ) ||\
    defined(STM32F446xx ) 
#define FMPI2C_CR1_SMBHEN    SMBHEN               // 1 bits @ 20
#define FMPI2C_CR1_SMBDEN    SMBDEN               // 1 bits @ 21
#else
#define FMPI2C_CR1_SMBHEN
#define FMPI2C_CR1_SMBDEN
#endif

//endregion

namespace sool
{
	namespace core
	{
		class FMPI2C
		{
			//SOOL-FMPI2C-ENUMS
			
			public :
			
			#ifdef FMPI2C_CR1
			struct CR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PE                   :1;
					uint32_t TXIE                 :1;
					uint32_t RXIE                 :1;
					uint32_t ADDRIE               :1;
					uint32_t NACKIE               :1;
					uint32_t STOPIE               :1;
					uint32_t TCIE                 :1;
					uint32_t ERRIE                :1;
					uint32_t DFN                  :4;
					uint32_t ANFOFF               :1;
					uint32_t                      :1;
					uint32_t TXDMAEN              :1;
					uint32_t RXDMAEN              :1;
					uint32_t SBC                  :1;
					uint32_t NOSTRETCH            :1;
					uint32_t                      :1;
					uint32_t GCEN                 :1;
					uint32_t FMPI2C_CR1_SMBHEN    :1;
					uint32_t FMPI2C_CR1_SMBDEN    :1;
					uint32_t ALERTEN              :1;
					uint32_t PECEN                :1;
					uint32_t                      :8;
			
				//SOOL-FMPI2C_CR1-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_CR2
			struct CR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SADD                 :10;
					uint32_t RD_WRN               :1;
					uint32_t ADD10                :1;
					uint32_t HEAD10R              :1;
					uint32_t START                :1;
					uint32_t STOP                 :1;
					uint32_t NACK                 :1;
					uint32_t NBYTES               :8;
					uint32_t RELOAD               :1;
					uint32_t AUTOEND              :1;
					uint32_t PECBYTE              :1;
					uint32_t                      :5;
			
				//SOOL-FMPI2C_CR2-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :3;
					uint32_t ADDRCF               :1;
					uint32_t NACKCF               :1;
					uint32_t STOPCF               :1;
					uint32_t                      :2;
					uint32_t BERRCF               :1;
					uint32_t ARLOCF               :1;
					uint32_t OVRCF                :1;
					uint32_t PECCF                :1;
					uint32_t TIMOUTCF             :1;
					uint32_t ALERTCF              :1;
					uint32_t                      :18;
			
				//SOOL-FMPI2C_ICR-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TXE                  :1;
					uint32_t TXIS                 :1;
					uint32_t RXNE                 :1;
					uint32_t ADDR                 :1;
					uint32_t NACKF                :1;
					uint32_t STOPF                :1;
					uint32_t TC                   :1;
					uint32_t TCR                  :1;
					uint32_t BERR                 :1;
					uint32_t ARLO                 :1;
					uint32_t OVR                  :1;
					uint32_t PECERR               :1;
					uint32_t TIMEOUT              :1;
					uint32_t ALERT                :1;
					uint32_t                      :1;
					uint32_t BUSY                 :1;
					uint32_t DIR                  :1;
					uint32_t ADDCODE              :7;
					uint32_t                      :8;
			
				//SOOL-FMPI2C_ISR-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_OAR1
			struct OAR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OA1                  :10;
					uint32_t OA1MODE              :1;
					uint32_t                      :4;
					uint32_t OA1EN                :1;
					uint32_t                      :16;
			
				//SOOL-FMPI2C_OAR1-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_OAR2
			struct OAR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t OA2                  :7;
					uint32_t OA2MSK               :3;
					uint32_t                      :4;
					uint32_t OA2EN                :1;
					uint32_t                      :16;
			
				//SOOL-FMPI2C_OAR2-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_PECR
			struct PECR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PEC                  :8;
					uint32_t                      :24;
			
				//SOOL-FMPI2C_PECR-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_RXDR
			struct RXDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXDATA               :8;
					uint32_t                      :24;
			
				//SOOL-FMPI2C_RXDR-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_TIMEOUTR
			struct TIMEOUTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TIMEOUTA             :12;
					uint32_t TIDLE                :1;
					uint32_t                      :2;
					uint32_t TIMOUTEN             :1;
					uint32_t TIMEOUTB             :12;
					uint32_t                      :3;
					uint32_t TEXTEN               :1;
			
				//SOOL-FMPI2C_TIMEOUTR-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_TIMINGR
			struct TIMINGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SCLL                 :8;
					uint32_t SCLH                 :8;
					uint32_t SDADEL               :4;
					uint32_t SCLDEL               :4;
					uint32_t                      :4;
					uint32_t PRESC                :4;
			
				//SOOL-FMPI2C_TIMINGR-DECLARATION
			};
			#endif
			
			#ifdef FMPI2C_TXDR
			struct TXDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TXDATA               :8;
					uint32_t                      :24;
			
				//SOOL-FMPI2C_TXDR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR1_TypeDef CR1;     // @0x000
					CR2_TypeDef CR2;     // @0x004
					OAR1_TypeDef OAR1;   // @0x008
					OAR2_TypeDef OAR2;   // @0x00c
					TIMINGR_TypeDef TIMINGR; // @0x010
					TIMEOUTR_TypeDef TIMEOUTR; // @0x014
					ISR_TypeDef ISR;     // @0x018
					ICR_TypeDef ICR;     // @0x01c
					PECR_TypeDef PECR;   // @0x020
					RXDR_TypeDef RXDR;   // @0x024
					TXDR_TypeDef TXDR;   // @0x028
				};
			};
			private:
			FMPI2C() = delete;
			//SOOL-FMPI2C-DECLARATION
		};
		
		//region instances
#define FMPI2C1_BASE_ADDR ((uint32_t)0x40006000U)
#ifdef FMPI2C1_BASE_ADDR
volatile class FMPI2C * const FMPI2C1 = reinterpret_cast<class FMPI2C* const>(FMPI2C1_BASE_ADDR);
#endif
//endregion

//SOOL-FMPI2C-DEFINES
//SOOL-FMPI2C-DEFINITION
	};
};//region undef
#undef FMPI2C_CR1_SMBHEN
#undef FMPI2C_CR1_SMBDEN
//endregion
#endif
#endif
