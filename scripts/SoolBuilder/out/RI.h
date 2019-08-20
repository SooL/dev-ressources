#ifndef __SOOL_RI_H
#define __SOOL_RI_H

#include "peripheral_include.h"
//SOOL-RI-INCLUDES
#if defined(STM32L1     ) 
//region defines

#define RI_ASCR1
#define RI_ASCR2
#define RI_HYSCR1
#define RI_HYSCR2
#define RI_ICR

#if defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define RI_ASCR1_CH31        CH31                 // 1 bits @ 16
#define RI_ASCR1_CH27        CH27                 // 1 bits @ 27
#define RI_ASCR1_CH28        CH28                 // 1 bits @ 28
#define RI_ASCR1_CH29        CH29                 // 1 bits @ 29
#define RI_ASCR1_CH30        CH30                 // 1 bits @ 30
#define RI_ASCR2_CH0b        CH0b                 // 1 bits @ 16
#define RI_ASMR1
#define RI_ASMR2
#define RI_ASMR3
#define RI_CICR1
#define RI_CICR2
#define RI_CICR3
#define RI_CMR1
#define RI_CMR2
#define RI_CMR3
#else
#define RI_ASCR1_CH31
#define RI_ASCR1_CH27
#define RI_ASCR1_CH28
#define RI_ASCR1_CH29
#define RI_ASCR1_CH30
#define RI_ASCR2_CH0b
#endif

#if defined(STM32L100xB ) || defined(STM32L100xBA) || defined(STM32L151xB ) || defined(STM32L151xBA) ||\
    defined(STM32L152xB ) || defined(STM32L152xBA) 
#define RI_ASCR2_GR6         GR6                  // 2 bits @ 4
#else
#define RI_ASCR2_GR6
#endif

#if defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define RI_ASCR2_CH1b        CH1b                 // 1 bits @ 17
#define RI_ASCR2_CH2b        CH2b                 // 1 bits @ 18
#define RI_ASCR2_CH3b        CH3b                 // 1 bits @ 19
#define RI_ASCR2_CH6b        CH6b                 // 1 bits @ 20
#define RI_ASCR2_CH7b        CH7b                 // 1 bits @ 21
#define RI_ASCR2_CH8b        CH8b                 // 1 bits @ 22
#define RI_ASCR2_CH9b        CH9b                 // 1 bits @ 23
#define RI_ASCR2_CH10b       CH10b                // 1 bits @ 24
#define RI_ASCR2_CH11b       CH11b                // 1 bits @ 25
#define RI_ASCR2_CH12b       CH12b                // 1 bits @ 26
#define RI_ASMR4
#define RI_ASMR5
#define RI_CICR4
#define RI_CICR5
#define RI_CMR4
#define RI_CMR5
#define RI_HYSCR3_PF         PF                   // 16 bits @ 16
#define RI_HYSCR4
#define RI_MAP1_HYSCR4       HYSCR4_TypeDef HYSCR4
#define RI_MAP0_ASMR4        ASMR4_TypeDef ASMR4
#define RI_MAP0_CMR4         CMR4_TypeDef CMR4
#define RI_MAP0_CICR4        CICR4_TypeDef CICR4
#define RI_MAP0_ASMR5        ASMR5_TypeDef ASMR5
#define RI_MAP0_CMR5         CMR5_TypeDef CMR5
#define RI_MAP0_CICR5        CICR5_TypeDef CICR5
#else
#define RI_ASCR2_CH1b
#define RI_ASCR2_CH2b
#define RI_ASCR2_CH3b
#define RI_ASCR2_CH6b
#define RI_ASCR2_CH7b
#define RI_ASCR2_CH8b
#define RI_ASCR2_CH9b
#define RI_ASCR2_CH10b
#define RI_ASCR2_CH11b
#define RI_ASCR2_CH12b
#define RI_HYSCR3_PF
#define RI_MAP1_HYSCR4 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_ASMR4 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CMR4 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CICR4 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_ASMR5 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CMR5 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CICR5 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L151xB ) || defined(STM32L151xBA) || defined(STM32L151xC ) || defined(STM32L151xCA) ||\
    defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xB ) ||\
    defined(STM32L152xBA) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define RI_HYSCR3
#define RI_MAP0_HYSCR3       HYSCR3_TypeDef HYSCR3
#else
#define RI_MAP0_HYSCR3 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L100xC ) 
#define RI_MAP0_ASMR1        ASMR1_TypeDef ASMR1
#define RI_MAP0_CMR1         CMR1_TypeDef CMR1
#define RI_MAP0_CICR1        CICR1_TypeDef CICR1
#define RI_MAP0_ASMR2        ASMR2_TypeDef ASMR2
#define RI_MAP0_CMR2         CMR2_TypeDef CMR2
#define RI_MAP0_CICR2        CICR2_TypeDef CICR2
#define RI_MAP0_ASMR3        ASMR3_TypeDef ASMR3
#define RI_MAP0_CMR3         CMR3_TypeDef CMR3
#define RI_MAP0_CICR3        CICR3_TypeDef CICR3
#else
#define RI_MAP0_ASMR1 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CMR1 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CICR1 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_ASMR2 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CMR2 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CICR2 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_ASMR3 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CMR3 __SOOL_PERIPH_PADDING_4
#define RI_MAP0_CICR3 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define RI_MAP1_ASMR1        ASMR1_TypeDef ASMR1
#define RI_MAP1_CMR1         CMR1_TypeDef CMR1
#define RI_MAP1_CICR1        CICR1_TypeDef CICR1
#define RI_MAP1_ASMR2        ASMR2_TypeDef ASMR2
#define RI_MAP1_CMR2         CMR2_TypeDef CMR2
#define RI_MAP1_CICR2        CICR2_TypeDef CICR2
#define RI_MAP1_ASMR3        ASMR3_TypeDef ASMR3
#define RI_MAP1_CMR3         CMR3_TypeDef CMR3
#define RI_MAP1_CICR3        CICR3_TypeDef CICR3
#else
#define RI_MAP1_ASMR1 __SOOL_PERIPH_PADDING_4
#define RI_MAP1_CMR1 __SOOL_PERIPH_PADDING_4
#define RI_MAP1_CICR1 __SOOL_PERIPH_PADDING_4
#define RI_MAP1_ASMR2 __SOOL_PERIPH_PADDING_4
#define RI_MAP1_CMR2 __SOOL_PERIPH_PADDING_4
#define RI_MAP1_CICR2 __SOOL_PERIPH_PADDING_4
#define RI_MAP1_ASMR3 __SOOL_PERIPH_PADDING_4
#define RI_MAP1_CMR3 __SOOL_PERIPH_PADDING_4
#define RI_MAP1_CICR3 __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class RI
		{
			//SOOL-RI-ENUMS
			
			public :
			
			#ifdef RI_ASCR1
			struct ASCR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CH0                  :1;
					uint32_t CH1                  :1;
					uint32_t CH2                  :1;
					uint32_t CH3                  :1;
					uint32_t CH4                  :1;
					uint32_t CH5                  :1;
					uint32_t CH6                  :1;
					uint32_t CH7                  :1;
					uint32_t CH8                  :1;
					uint32_t CH9                  :1;
					uint32_t CH10                 :1;
					uint32_t CH11                 :1;
					uint32_t CH12                 :1;
					uint32_t CH13                 :1;
					uint32_t CH14                 :1;
					uint32_t CH15                 :1;
					uint32_t RI_ASCR1_CH31        :1;
					uint32_t                      :1;
					uint32_t CH18                 :1;
					uint32_t CH19                 :1;
					uint32_t CH20                 :1;
					uint32_t CH21                 :1;
					uint32_t CH22                 :1;
					uint32_t CH23                 :1;
					uint32_t CH24                 :1;
					uint32_t CH25                 :1;
					uint32_t VCOMP                :1;
					uint32_t RI_ASCR1_CH27        :1;
					uint32_t RI_ASCR1_CH28        :1;
					uint32_t RI_ASCR1_CH29        :1;
					uint32_t RI_ASCR1_CH30        :1;
					uint32_t SCM                  :1;
			
				//SOOL-RI_ASCR1-DECLARATION
			};
			#endif
			
			#ifdef RI_ASCR2
			struct ASCR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t GR101                :1;
					uint32_t GR102                :1;
					uint32_t GR103                :1;
					uint32_t GR104                :1;
					uint32_t RI_ASCR2_GR6         :2;
					uint32_t GR51                 :1;
					uint32_t GR52                 :1;
					uint32_t GR53                 :1;
					uint32_t GR41                 :1;
					uint32_t GR42                 :1;
					uint32_t GR43                 :1;
					uint32_t                      :3;
					uint32_t GR44                 :1;
					uint32_t RI_ASCR2_CH0b        :1;
					uint32_t RI_ASCR2_CH1b        :1;
					uint32_t RI_ASCR2_CH2b        :1;
					uint32_t RI_ASCR2_CH3b        :1;
					uint32_t RI_ASCR2_CH6b        :1;
					uint32_t RI_ASCR2_CH7b        :1;
					uint32_t RI_ASCR2_CH8b        :1;
					uint32_t RI_ASCR2_CH9b        :1;
					uint32_t RI_ASCR2_CH10b       :1;
					uint32_t RI_ASCR2_CH11b       :1;
					uint32_t RI_ASCR2_CH12b       :1;
					uint32_t                      :5;
			
				//SOOL-RI_ASCR2-DECLARATION
			};
			#endif
			
			#ifdef RI_ASMR1
			struct ASMR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PA                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_ASMR1-DECLARATION
			};
			#endif
			
			#ifdef RI_ASMR2
			struct ASMR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PB                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_ASMR2-DECLARATION
			};
			#endif
			
			#ifdef RI_ASMR3
			struct ASMR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PC                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_ASMR3-DECLARATION
			};
			#endif
			
			#ifdef RI_ASMR4
			struct ASMR4_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PF                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_ASMR4-DECLARATION
			};
			#endif
			
			#ifdef RI_ASMR5
			struct ASMR5_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PG                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_ASMR5-DECLARATION
			};
			#endif
			
			#ifdef RI_CICR1
			struct CICR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PA                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CICR1-DECLARATION
			};
			#endif
			
			#ifdef RI_CICR2
			struct CICR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PB                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CICR2-DECLARATION
			};
			#endif
			
			#ifdef RI_CICR3
			struct CICR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PC                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CICR3-DECLARATION
			};
			#endif
			
			#ifdef RI_CICR4
			struct CICR4_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PF                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CICR4-DECLARATION
			};
			#endif
			
			#ifdef RI_CICR5
			struct CICR5_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PG                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CICR5-DECLARATION
			};
			#endif
			
			#ifdef RI_CMR1
			struct CMR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PA                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CMR1-DECLARATION
			};
			#endif
			
			#ifdef RI_CMR2
			struct CMR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PB                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CMR2-DECLARATION
			};
			#endif
			
			#ifdef RI_CMR3
			struct CMR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PC                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CMR3-DECLARATION
			};
			#endif
			
			#ifdef RI_CMR4
			struct CMR4_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PF                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CMR4-DECLARATION
			};
			#endif
			
			#ifdef RI_CMR5
			struct CMR5_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PG                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_CMR5-DECLARATION
			};
			#endif
			
			#ifdef RI_HYSCR1
			struct HYSCR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PA                   :16;
					uint32_t PB                   :16;
			
				//SOOL-RI_HYSCR1-DECLARATION
			};
			#endif
			
			#ifdef RI_HYSCR2
			struct HYSCR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PC                   :16;
					uint32_t PD                   :16;
			
				//SOOL-RI_HYSCR2-DECLARATION
			};
			#endif
			
			#ifdef RI_HYSCR3
			struct HYSCR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PE                   :16;
					uint32_t RI_HYSCR3_PF         :16;
			
				//SOOL-RI_HYSCR3-DECLARATION
			};
			#endif
			
			#ifdef RI_HYSCR4
			struct HYSCR4_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PG                   :16;
					uint32_t                      :16;
			
				//SOOL-RI_HYSCR4-DECLARATION
			};
			#endif
			
			#ifdef RI_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IC1OS                :4;
					uint32_t IC2OS                :4;
					uint32_t IC3OS                :4;
					uint32_t IC4OS                :4;
					uint32_t TIM                  :2;
					uint32_t IC1                  :1;
					uint32_t IC2                  :1;
					uint32_t IC3                  :1;
					uint32_t IC4                  :1;
					uint32_t                      :10;
			
				//SOOL-RI_ICR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					ICR_TypeDef ICR;     // @0x000
					ASCR1_TypeDef ASCR1; // @0x004
					ASCR2_TypeDef ASCR2; // @0x008
					HYSCR1_TypeDef HYSCR1; // @0x00c
					HYSCR2_TypeDef HYSCR2; // @0x010
					RI_MAP0_HYSCR3;      // @0x014
					RI_MAP0_ASMR1;       // @0x018
					RI_MAP0_CMR1;        // @0x01c
					RI_MAP0_CICR1;       // @0x020
					RI_MAP0_ASMR2;       // @0x024
					RI_MAP0_CMR2;        // @0x028
					RI_MAP0_CICR2;       // @0x02c
					RI_MAP0_ASMR3;       // @0x030
					RI_MAP0_CMR3;        // @0x034
					RI_MAP0_CICR3;       // @0x038
					__SOOL_PERIPH_PADDING_4;
					RI_MAP0_ASMR4;       // @0x040
					RI_MAP0_CMR4;        // @0x044
					RI_MAP0_CICR4;       // @0x048
					RI_MAP0_ASMR5;       // @0x04c
					RI_MAP0_CMR5;        // @0x050
					RI_MAP0_CICR5;       // @0x054
				};
				struct
				{
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					RI_MAP1_HYSCR4;      // @0x018
					RI_MAP1_ASMR1;       // @0x01c
					RI_MAP1_CMR1;        // @0x020
					RI_MAP1_CICR1;       // @0x024
					RI_MAP1_ASMR2;       // @0x028
					RI_MAP1_CMR2;        // @0x02c
					RI_MAP1_CICR2;       // @0x030
					RI_MAP1_ASMR3;       // @0x034
					RI_MAP1_CMR3;        // @0x038
					RI_MAP1_CICR3;       // @0x03c
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
				};
			};
			private:
			RI() = delete;
			//SOOL-RI-DECLARATION
		};
		
		//region instances
#define RI_BASE_ADDR ((uint32_t)0x40007C04U)
#ifdef RI_BASE_ADDR
volatile class RI * const RI = reinterpret_cast<class RI* const>(RI_BASE_ADDR);
#endif
//endregion

//SOOL-RI-DEFINES
//SOOL-RI-DEFINITION
	};
};//region undef
#undef RI_ASCR1_CH31
#undef RI_ASCR1_CH27
#undef RI_ASCR1_CH28
#undef RI_ASCR1_CH29
#undef RI_ASCR1_CH30
#undef RI_ASCR2_CH0b
#undef RI_ASCR2_GR6
#undef RI_ASCR2_CH1b
#undef RI_ASCR2_CH2b
#undef RI_ASCR2_CH3b
#undef RI_ASCR2_CH6b
#undef RI_ASCR2_CH7b
#undef RI_ASCR2_CH8b
#undef RI_ASCR2_CH9b
#undef RI_ASCR2_CH10b
#undef RI_ASCR2_CH11b
#undef RI_ASCR2_CH12b
#undef RI_HYSCR3_PF
#undef RI_MAP1_HYSCR4
#undef RI_MAP0_ASMR4
#undef RI_MAP0_CMR4
#undef RI_MAP0_CICR4
#undef RI_MAP0_ASMR5
#undef RI_MAP0_CMR5
#undef RI_MAP0_CICR5
#undef RI_MAP0_HYSCR3
#undef RI_MAP0_ASMR1
#undef RI_MAP0_CMR1
#undef RI_MAP0_CICR1
#undef RI_MAP0_ASMR2
#undef RI_MAP0_CMR2
#undef RI_MAP0_CICR2
#undef RI_MAP0_ASMR3
#undef RI_MAP0_CMR3
#undef RI_MAP0_CICR3
#undef RI_MAP1_ASMR1
#undef RI_MAP1_CMR1
#undef RI_MAP1_CICR1
#undef RI_MAP1_ASMR2
#undef RI_MAP1_CMR2
#undef RI_MAP1_CICR2
#undef RI_MAP1_ASMR3
#undef RI_MAP1_CMR3
#undef RI_MAP1_CICR3
//endregion
#endif
#endif
