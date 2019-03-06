#ifndef __SOOL_BKP_H
#define __SOOL_BKP_H

#include "peripheral_include.h"
//SOOL-BKP-INCLUDES
#if defined(STM32F1     ) 
//region defines

#define BKP_CR
#define BKP_CSR
#define BKP_DR1
#define BKP_DR10
#define BKP_DR2
#define BKP_DR3
#define BKP_DR4
#define BKP_DR5
#define BKP_DR6
#define BKP_DR7
#define BKP_DR8
#define BKP_DR9
#define BKP_RTCCR

#if defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) 
#define BKP_DR11
#define BKP_DR12
#define BKP_DR13
#define BKP_DR14
#define BKP_DR15
#define BKP_DR16
#define BKP_DR17
#define BKP_DR18
#define BKP_DR19
#define BKP_DR20
#define BKP_DR21
#define BKP_DR22
#define BKP_DR23
#define BKP_DR24
#define BKP_DR25
#define BKP_DR26
#define BKP_DR27
#define BKP_DR28
#define BKP_DR29
#define BKP_DR30
#define BKP_DR31
#define BKP_DR32
#define BKP_DR33
#define BKP_DR34
#define BKP_DR35
#define BKP_DR36
#define BKP_DR37
#define BKP_DR38
#define BKP_DR39
#define BKP_DR40
#define BKP_DR41
#define BKP_DR42
#define BKP_MAP0_DR11        DR11_TypeDef DR11
#define BKP_MAP0_DR12        DR12_TypeDef DR12
#define BKP_MAP0_DR13        DR13_TypeDef DR13
#define BKP_MAP0_DR14        DR14_TypeDef DR14
#define BKP_MAP0_DR15        DR15_TypeDef DR15
#define BKP_MAP0_DR16        DR16_TypeDef DR16
#define BKP_MAP0_DR17        DR17_TypeDef DR17
#define BKP_MAP0_DR18        DR18_TypeDef DR18
#define BKP_MAP0_DR19        DR19_TypeDef DR19
#define BKP_MAP0_DR20        DR20_TypeDef DR20
#define BKP_MAP0_DR21        DR21_TypeDef DR21
#define BKP_MAP0_DR22        DR22_TypeDef DR22
#define BKP_MAP0_DR23        DR23_TypeDef DR23
#define BKP_MAP0_DR24        DR24_TypeDef DR24
#define BKP_MAP0_DR25        DR25_TypeDef DR25
#define BKP_MAP0_DR26        DR26_TypeDef DR26
#define BKP_MAP0_DR27        DR27_TypeDef DR27
#define BKP_MAP0_DR28        DR28_TypeDef DR28
#define BKP_MAP0_DR29        DR29_TypeDef DR29
#define BKP_MAP0_DR30        DR30_TypeDef DR30
#define BKP_MAP0_DR31        DR31_TypeDef DR31
#define BKP_MAP0_DR32        DR32_TypeDef DR32
#define BKP_MAP0_DR33        DR33_TypeDef DR33
#define BKP_MAP0_DR34        DR34_TypeDef DR34
#define BKP_MAP0_DR35        DR35_TypeDef DR35
#define BKP_MAP0_DR36        DR36_TypeDef DR36
#define BKP_MAP0_DR37        DR37_TypeDef DR37
#define BKP_MAP0_DR38        DR38_TypeDef DR38
#define BKP_MAP0_DR39        DR39_TypeDef DR39
#define BKP_MAP0_DR40        DR40_TypeDef DR40
#define BKP_MAP0_DR41        DR41_TypeDef DR41
#define BKP_MAP0_DR42        DR42_TypeDef DR42
#else
#define BKP_MAP0_DR11 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR12 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR13 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR14 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR15 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR16 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR17 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR18 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR19 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR20 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR21 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR22 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR23 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR24 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR25 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR26 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR27 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR28 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR29 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR30 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR31 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR32 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR33 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR34 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR35 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR36 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR37 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR38 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR39 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR40 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR41 __SOOL_PERIPH_PADDING_4
#define BKP_MAP0_DR42 __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class BKP
		{
			//SOOL-BKP-ENUMS
			
			public :
			
			#ifdef BKP_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TPE                  :1;
					uint32_t TPAL                 :1;
					uint32_t                      :30;
			
				//SOOL-BKP_CR-DECLARATION
			};
			#endif
			
			#ifdef BKP_CSR
			struct CSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CTE                  :1;
					uint32_t CTI                  :1;
					uint32_t TPIE                 :1;
					uint32_t                      :5;
					uint32_t TEF                  :1;
					uint32_t TIF                  :1;
					uint32_t                      :22;
			
				//SOOL-BKP_CSR-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR1
			struct DR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR1-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR10
			struct DR10_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR10-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR11
			struct DR11_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR11-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR12
			struct DR12_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR12-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR13
			struct DR13_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR13-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR14
			struct DR14_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR14-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR15
			struct DR15_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR15-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR16
			struct DR16_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR16-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR17
			struct DR17_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR17-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR18
			struct DR18_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR18-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR19
			struct DR19_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR19-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR2
			struct DR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR2-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR20
			struct DR20_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR20-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR21
			struct DR21_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR21-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR22
			struct DR22_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR22-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR23
			struct DR23_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR23-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR24
			struct DR24_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR24-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR25
			struct DR25_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR25-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR26
			struct DR26_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR26-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR27
			struct DR27_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR27-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR28
			struct DR28_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR28-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR29
			struct DR29_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR29-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR3
			struct DR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR3-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR30
			struct DR30_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR30-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR31
			struct DR31_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR31-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR32
			struct DR32_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR32-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR33
			struct DR33_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR33-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR34
			struct DR34_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR34-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR35
			struct DR35_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR35-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR36
			struct DR36_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR36-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR37
			struct DR37_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR37-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR38
			struct DR38_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR38-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR39
			struct DR39_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR39-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR4
			struct DR4_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR4-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR40
			struct DR40_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR40-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR41
			struct DR41_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR41-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR42
			struct DR42_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR42-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR5
			struct DR5_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR5-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR6
			struct DR6_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR6-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR7
			struct DR7_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR7-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR8
			struct DR8_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR8-DECLARATION
			};
			#endif
			
			#ifdef BKP_DR9
			struct DR9_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :16;
					uint32_t                      :16;
			
				//SOOL-BKP_DR9-DECLARATION
			};
			#endif
			
			#ifdef BKP_RTCCR
			struct RTCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CAL                  :7;
					uint32_t CCO                  :1;
					uint32_t ASOE                 :1;
					uint32_t ASOS                 :1;
					uint32_t                      :22;
			
				//SOOL-BKP_RTCCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					__SOOL_PERIPH_PADDING_4;
					DR1_TypeDef DR1;     // @0x004
					DR2_TypeDef DR2;     // @0x008
					DR3_TypeDef DR3;     // @0x00c
					DR4_TypeDef DR4;     // @0x010
					DR5_TypeDef DR5;     // @0x014
					DR6_TypeDef DR6;     // @0x018
					DR7_TypeDef DR7;     // @0x01c
					DR8_TypeDef DR8;     // @0x020
					DR9_TypeDef DR9;     // @0x024
					DR10_TypeDef DR10;   // @0x028
					RTCCR_TypeDef RTCCR; // @0x02c
					CR_TypeDef CR;       // @0x030
					CSR_TypeDef CSR;     // @0x034
					__SOOL_PERIPH_PADDING_8;
					BKP_MAP0_DR11;       // @0x040
					BKP_MAP0_DR12;       // @0x044
					BKP_MAP0_DR13;       // @0x048
					BKP_MAP0_DR14;       // @0x04c
					BKP_MAP0_DR15;       // @0x050
					BKP_MAP0_DR16;       // @0x054
					BKP_MAP0_DR17;       // @0x058
					BKP_MAP0_DR18;       // @0x05c
					BKP_MAP0_DR19;       // @0x060
					BKP_MAP0_DR20;       // @0x064
					BKP_MAP0_DR21;       // @0x068
					BKP_MAP0_DR22;       // @0x06c
					BKP_MAP0_DR23;       // @0x070
					BKP_MAP0_DR24;       // @0x074
					BKP_MAP0_DR25;       // @0x078
					BKP_MAP0_DR26;       // @0x07c
					BKP_MAP0_DR27;       // @0x080
					BKP_MAP0_DR28;       // @0x084
					BKP_MAP0_DR29;       // @0x088
					BKP_MAP0_DR30;       // @0x08c
					BKP_MAP0_DR31;       // @0x090
					BKP_MAP0_DR32;       // @0x094
					BKP_MAP0_DR33;       // @0x098
					BKP_MAP0_DR34;       // @0x09c
					BKP_MAP0_DR35;       // @0x0a0
					BKP_MAP0_DR36;       // @0x0a4
					BKP_MAP0_DR37;       // @0x0a8
					BKP_MAP0_DR38;       // @0x0ac
					BKP_MAP0_DR39;       // @0x0b0
					BKP_MAP0_DR40;       // @0x0b4
					BKP_MAP0_DR41;       // @0x0b8
					BKP_MAP0_DR42;       // @0x0bc
				};
			};
			private:
			BKP() = delete;
			//SOOL-BKP-DECLARATION
		};
		
		//region instances
#define BKP_BASE_ADDR ((uint32_t)0x40006C00U)
#ifdef BKP_BASE_ADDR
volatile class BKP * const BKP = reinterpret_cast<class BKP* const>(BKP_BASE_ADDR);
#endif
//endregion

//SOOL-BKP-DEFINES
//SOOL-BKP-DEFINITION
	};
};//region undef
#undef BKP_MAP0_DR11
#undef BKP_MAP0_DR12
#undef BKP_MAP0_DR13
#undef BKP_MAP0_DR14
#undef BKP_MAP0_DR15
#undef BKP_MAP0_DR16
#undef BKP_MAP0_DR17
#undef BKP_MAP0_DR18
#undef BKP_MAP0_DR19
#undef BKP_MAP0_DR20
#undef BKP_MAP0_DR21
#undef BKP_MAP0_DR22
#undef BKP_MAP0_DR23
#undef BKP_MAP0_DR24
#undef BKP_MAP0_DR25
#undef BKP_MAP0_DR26
#undef BKP_MAP0_DR27
#undef BKP_MAP0_DR28
#undef BKP_MAP0_DR29
#undef BKP_MAP0_DR30
#undef BKP_MAP0_DR31
#undef BKP_MAP0_DR32
#undef BKP_MAP0_DR33
#undef BKP_MAP0_DR34
#undef BKP_MAP0_DR35
#undef BKP_MAP0_DR36
#undef BKP_MAP0_DR37
#undef BKP_MAP0_DR38
#undef BKP_MAP0_DR39
#undef BKP_MAP0_DR40
#undef BKP_MAP0_DR41
#undef BKP_MAP0_DR42
//endregion
#endif
#endif
