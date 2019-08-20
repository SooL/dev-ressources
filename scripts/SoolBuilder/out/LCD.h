#ifndef __SOOL_LCD_H
#define __SOOL_LCD_H

#include "peripheral_include.h"
//SOOL-LCD-INCLUDES
#if defined(STM32L053xx ) || defined(STM32L063xx ) || defined(STM32L073xx ) || defined(STM32L083xx ) ||\
    defined(STM32L100xB ) || defined(STM32L100xBA) || defined(STM32L100xC ) || defined(STM32L152xB ) ||\
    defined(STM32L152xBA) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) || defined(STM32L433xx ) ||\
    defined(STM32L443xx ) || defined(STM32L476xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) 
//region defines

#define LCD_CLR
#define LCD_CR
#define LCD_FCR
#define LCD_RAM
#define LCD_SR

#if defined(STM32L053xx ) || defined(STM32L063xx ) || defined(STM32L073xx ) || defined(STM32L083xx ) ||\
    defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L476xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define LCD_CR_BUFEN         BUFEN                // 1 bits @ 8
#else
#define LCD_CR_BUFEN
#endif

//endregion

namespace sool
{
	namespace core
	{
		class LCD
		{
			//SOOL-LCD-ENUMS
			
			public :
			
			#ifdef LCD_CLR
			struct CLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t SOFC                 :1;
					uint32_t                      :1;
					uint32_t UDDC                 :1;
					uint32_t                      :28;
			
				//SOOL-LCD_CLR-DECLARATION
			};
			#endif
			
			#ifdef LCD_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LCDEN                :1;
					uint32_t VSEL                 :1;
					uint32_t DUTY                 :3;
					uint32_t BIAS                 :2;
					uint32_t MUX_SEG              :1;
					uint32_t LCD_CR_BUFEN         :1;
					uint32_t                      :23;
			
				//SOOL-LCD_CR-DECLARATION
			};
			#endif
			
			#ifdef LCD_FCR
			struct FCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HD                   :1;
					uint32_t SOFIE                :1;
					uint32_t                      :1;
					uint32_t UDDIE                :1;
					uint32_t PON                  :3;
					uint32_t DEAD                 :3;
					uint32_t CC                   :3;
					uint32_t BLINKF               :3;
					uint32_t BLINK                :2;
					uint32_t DIV                  :4;
					uint32_t PS                   :4;
					uint32_t                      :6;
			
				//SOOL-LCD_FCR-DECLARATION
			};
			#endif
			
			#ifdef LCD_RAM
			struct RAM_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SEGMENT_DATA         :32;
			
				//SOOL-LCD_RAM-DECLARATION
			};
			#endif
			
			#ifdef LCD_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ENS                  :1;
					uint32_t SOF                  :1;
					uint32_t UDR                  :1;
					uint32_t UDD                  :1;
					uint32_t RDY                  :1;
					uint32_t FCRSR                :1;
					uint32_t                      :26;
			
				//SOOL-LCD_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					FCR_TypeDef FCR;     // @0x004
					SR_TypeDef SR;       // @0x008
					CLR_TypeDef CLR;     // @0x00c
					__SOOL_PERIPH_PADDING_4;
					RAM_TypeDef RAM[16]; // @0x014
				};
			};
			private:
			LCD() = delete;
			//SOOL-LCD-DECLARATION
		};
		
		//region instances
#define LCD_BASE_ADDR ((uint32_t)0x40002400U)
#ifdef LCD_BASE_ADDR
volatile class LCD * const LCD = reinterpret_cast<class LCD* const>(LCD_BASE_ADDR);
#endif
//endregion

//SOOL-LCD-DEFINES
//SOOL-LCD-DEFINITION
	};
};//region undef
#undef LCD_CR_BUFEN
//endregion
#endif
#endif
