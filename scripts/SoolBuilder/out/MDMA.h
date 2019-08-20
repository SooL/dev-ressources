#ifndef __SOOL_MDMA_H
#define __SOOL_MDMA_H

#include "peripheral_include.h"
//SOOL-MDMA-INCLUDES
#if defined(STM32H7     ) 
//region defines

#define MDMA_GISR0
#define MDMA_Channel_CBNDTR
#define MDMA_Channel_CBRUR
#define MDMA_Channel_CCR
#define MDMA_Channel_CDAR
#define MDMA_Channel_CESR
#define MDMA_Channel_CIFCR
#define MDMA_Channel_CISR
#define MDMA_Channel_CLAR
#define MDMA_Channel_CMAR
#define MDMA_Channel_CMDR
#define MDMA_Channel_CSAR
#define MDMA_Channel_CTBR
#define MDMA_Channel_CTCR

//endregion

namespace sool
{
	namespace core
	{
		class MDMA
		{
			//SOOL-MDMA-ENUMS
			
			public :
			
			#ifdef MDMA_GISR0
			struct GISR0_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t GIF0                 :1;
					uint32_t GIF1                 :1;
					uint32_t GIF2                 :1;
					uint32_t GIF3                 :1;
					uint32_t GIF4                 :1;
					uint32_t GIF5                 :1;
					uint32_t GIF6                 :1;
					uint32_t GIF7                 :1;
					uint32_t GIF8                 :1;
					uint32_t GIF9                 :1;
					uint32_t GIF10                :1;
					uint32_t GIF11                :1;
					uint32_t GIF12                :1;
					uint32_t GIF13                :1;
					uint32_t GIF14                :1;
					uint32_t GIF15                :1;
					uint32_t                      :16;
			
				//SOOL-MDMA_GISR0-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					GISR0_TypeDef GISR0; // @0x000
				};
			};
			private:
			MDMA() = delete;
			//SOOL-MDMA-DECLARATION
		};
		
		
		class MDMA_Channel
		{
			//SOOL-MDMA_Channel-ENUMS
			
			public :
			
			#ifdef MDMA_Channel_CBNDTR
			struct CBNDTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BNDT                 :17;
					uint32_t                      :1;
					uint32_t BRSUM                :1;
					uint32_t BRDUM                :1;
					uint32_t BRC                  :12;
			
				//SOOL-MDMA_Channel_CBNDTR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CBRUR
			struct CBRUR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SUV                  :16;
					uint32_t DUV                  :16;
			
				//SOOL-MDMA_Channel_CBRUR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CCR
			struct CCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t TEIE                 :1;
					uint32_t CTCIE                :1;
					uint32_t BRTIE                :1;
					uint32_t BTIE                 :1;
					uint32_t TCIE                 :1;
					uint32_t PL                   :2;
					uint32_t                      :4;
					uint32_t BEX                  :1;
					uint32_t HEX                  :1;
					uint32_t WEX                  :1;
					uint32_t                      :1;
					uint32_t SWRQ                 :1;
					uint32_t                      :15;
			
				//SOOL-MDMA_Channel_CCR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CDAR
			struct CDAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DAR                  :32;
			
				//SOOL-MDMA_Channel_CDAR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CESR
			struct CESR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TEA                  :7;
					uint32_t TED                  :1;
					uint32_t TELD                 :1;
					uint32_t TEMD                 :1;
					uint32_t ASE                  :1;
					uint32_t BSE                  :1;
					uint32_t                      :20;
			
				//SOOL-MDMA_Channel_CESR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CIFCR
			struct CIFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CTEIF                :1;
					uint32_t CCTCIF               :1;
					uint32_t CBRTIF               :1;
					uint32_t CBTIF                :1;
					uint32_t CLTCIF               :1;
					uint32_t                      :27;
			
				//SOOL-MDMA_Channel_CIFCR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CISR
			struct CISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TEIF                 :1;
					uint32_t CTCIF                :1;
					uint32_t BRTIF                :1;
					uint32_t BTIF                 :1;
					uint32_t TCIF                 :1;
					uint32_t                      :11;
					uint32_t CRQA                 :1;
					uint32_t                      :15;
			
				//SOOL-MDMA_Channel_CISR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CLAR
			struct CLAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LAR                  :32;
			
				//SOOL-MDMA_Channel_CLAR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CMAR
			struct CMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MAR                  :32;
			
				//SOOL-MDMA_Channel_CMAR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CMDR
			struct CMDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MDR                  :32;
			
				//SOOL-MDMA_Channel_CMDR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CSAR
			struct CSAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SAR                  :32;
			
				//SOOL-MDMA_Channel_CSAR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CTBR
			struct CTBR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSEL                 :8;
					uint32_t                      :8;
					uint32_t SBUS                 :1;
					uint32_t DBUS                 :1;
					uint32_t                      :14;
			
				//SOOL-MDMA_Channel_CTBR-DECLARATION
			};
			#endif
			
			#ifdef MDMA_Channel_CTCR
			struct CTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SINC                 :2;
					uint32_t DINC                 :2;
					uint32_t SSIZE                :2;
					uint32_t DSIZE                :2;
					uint32_t SINCOS               :2;
					uint32_t DINCOS               :2;
					uint32_t SBURST               :3;
					uint32_t DBURST               :3;
					uint32_t TLEN                 :7;
					uint32_t PKE                  :1;
					uint32_t PAM                  :2;
					uint32_t TRGM                 :2;
					uint32_t SWRM                 :1;
					uint32_t BWM                  :1;
			
				//SOOL-MDMA_Channel_CTCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CISR_TypeDef CISR;   // @0x000
					CIFCR_TypeDef CIFCR; // @0x004
					CESR_TypeDef CESR;   // @0x008
					CCR_TypeDef CCR;     // @0x00c
					CTCR_TypeDef CTCR;   // @0x010
					CBNDTR_TypeDef CBNDTR; // @0x014
					CSAR_TypeDef CSAR;   // @0x018
					CDAR_TypeDef CDAR;   // @0x01c
					CBRUR_TypeDef CBRUR; // @0x020
					CLAR_TypeDef CLAR;   // @0x024
					CTBR_TypeDef CTBR;   // @0x028
					__SOOL_PERIPH_PADDING_4;
					CMAR_TypeDef CMAR;   // @0x030
					CMDR_TypeDef CMDR;   // @0x034
				};
			};
			private:
			MDMA_Channel() = delete;
			//SOOL-MDMA_Channel-DECLARATION
		};
		
		//region instances
#define MDMA_BASE_ADDR ((uint32_t)0x52000000U)
#if defined(STM32H7     ) 
#define MDMA_Channel0_BASE_ADDR ((uint32_t)0x52000040U)
#define MDMA_Channel1_BASE_ADDR ((uint32_t)0x52000080U)
#define MDMA_Channel2_BASE_ADDR ((uint32_t)0x520000C0U)
#define MDMA_Channel3_BASE_ADDR ((uint32_t)0x52000100U)
#define MDMA_Channel4_BASE_ADDR ((uint32_t)0x52000140U)
#define MDMA_Channel5_BASE_ADDR ((uint32_t)0x52000180U)
#define MDMA_Channel6_BASE_ADDR ((uint32_t)0x520001C0U)
#define MDMA_Channel7_BASE_ADDR ((uint32_t)0x52000200U)
#define MDMA_Channel8_BASE_ADDR ((uint32_t)0x52000240U)
#define MDMA_Channel9_BASE_ADDR ((uint32_t)0x52000280U)
#define MDMA_Channel10_BASE_ADDR ((uint32_t)0x520002C0U)
#define MDMA_Channel11_BASE_ADDR ((uint32_t)0x52000300U)
#define MDMA_Channel12_BASE_ADDR ((uint32_t)0x52000340U)
#define MDMA_Channel13_BASE_ADDR ((uint32_t)0x52000380U)
#define MDMA_Channel14_BASE_ADDR ((uint32_t)0x520003C0U)
#define MDMA_Channel15_BASE_ADDR ((uint32_t)0x52000400U)
#endif

#ifdef MDMA_BASE_ADDR
volatile class MDMA * const MDMA = reinterpret_cast<class MDMA* const>(MDMA_BASE_ADDR);
#endif
#ifdef MDMA_Channel0_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel0 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel0_BASE_ADDR);
#endif
#ifdef MDMA_Channel1_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel1 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel1_BASE_ADDR);
#endif
#ifdef MDMA_Channel2_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel2 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel2_BASE_ADDR);
#endif
#ifdef MDMA_Channel3_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel3 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel3_BASE_ADDR);
#endif
#ifdef MDMA_Channel4_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel4 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel4_BASE_ADDR);
#endif
#ifdef MDMA_Channel5_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel5 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel5_BASE_ADDR);
#endif
#ifdef MDMA_Channel6_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel6 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel6_BASE_ADDR);
#endif
#ifdef MDMA_Channel7_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel7 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel7_BASE_ADDR);
#endif
#ifdef MDMA_Channel8_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel8 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel8_BASE_ADDR);
#endif
#ifdef MDMA_Channel9_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel9 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel9_BASE_ADDR);
#endif
#ifdef MDMA_Channel10_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel10 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel10_BASE_ADDR);
#endif
#ifdef MDMA_Channel11_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel11 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel11_BASE_ADDR);
#endif
#ifdef MDMA_Channel12_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel12 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel12_BASE_ADDR);
#endif
#ifdef MDMA_Channel13_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel13 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel13_BASE_ADDR);
#endif
#ifdef MDMA_Channel14_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel14 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel14_BASE_ADDR);
#endif
#ifdef MDMA_Channel15_BASE_ADDR
volatile class MDMA_Channel * const MDMA_Channel15 = reinterpret_cast<class MDMA_Channel* const>(MDMA_Channel15_BASE_ADDR);
#endif
//endregion

//SOOL-MDMA-DEFINES
//SOOL-MDMA-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
