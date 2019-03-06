#ifndef __SOOL_GPIO_H
#define __SOOL_GPIO_H

#include "lib_utils/peripheral_include.h"
//SOOL-GPIO-INCLUDES
//region defines

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define GPIO_AFR
#define GPIO_AFRH
#define GPIO_AFRL
#define GPIO_MODER
#define GPIO_OSPEEDR
#define GPIO_OTYPER
#define GPIO_PUPDR
#define GPIO_MAP0_MODER      MODER_TypeDef MODER
#define GPIO_MAP0_OTYPER     OTYPER_TypeDef OTYPER
#define GPIO_MAP0_OSPEEDR    OSPEEDR_TypeDef OSPEEDR
#define GPIO_MAP0_PUPDR      PUPDR_TypeDef PUPDR
#define GPIO_MAP0_IDR        IDR_TypeDef IDR
#define GPIO_MAP0_ODR        ODR_TypeDef ODR
#define GPIO_MAP0_LCKR       LCKR_TypeDef LCKR
#define GPIO_MAP0_AFR        AFR_TypeDef AFR
#define GPIO_MAP1_AFRL       AFRL_TypeDef AFRL
#define GPIO_MAP1_AFRH       AFRH_TypeDef AFRH
#else
#define GPIO_MAP0_MODER __SOOL_PERIPH_PADDING_4
#define GPIO_MAP0_OTYPER __SOOL_PERIPH_PADDING_4
#define GPIO_MAP0_OSPEEDR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP0_PUPDR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP0_IDR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP0_ODR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP0_LCKR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP0_AFR __SOOL_PERIPH_PADDING_8
#define GPIO_MAP1_AFRL __SOOL_PERIPH_PADDING_4
#define GPIO_MAP1_AFRH __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define GPIO_AFR_0
#define GPIO_AFRH_0
#define GPIO_AFRL_0
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define GPIO_AFR_1
#define GPIO_AFRH_1
#define GPIO_AFRL_1
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) 
#define GPIO_ASCR
#define GPIO_MAP0_ASCR       ASCR_TypeDef ASCR
#else
#define GPIO_MAP0_ASCR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) || defined(STM32L0     ) ||\
    defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define GPIO_BRR
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define GPIO_BSRR
#endif

#if defined(STM32H7     ) 
#define GPIO_BSRRH
#define GPIO_BSRRL
#define GPIO_MAP2_BSRRL      BSRRL_TypeDef BSRRL
#define GPIO_MAP2_BSRRH      BSRRH_TypeDef BSRRH
#else
#define GPIO_MAP2_BSRRL __SOOL_PERIPH_PADDING_2
#define GPIO_MAP2_BSRRH __SOOL_PERIPH_PADDING_2
#endif

#if defined(STM32F1     ) 
#define GPIO_CRH
#define GPIO_CRL
#define GPIO_MAP1_CRL        CRL_TypeDef CRL
#define GPIO_MAP1_CRH        CRH_TypeDef CRH
#define GPIO_MAP1_IDR        IDR_TypeDef IDR
#define GPIO_MAP1_ODR        ODR_TypeDef ODR
#define GPIO_MAP1_BSRR       BSRR_TypeDef BSRR
#define GPIO_MAP1_BRR        BRR_TypeDef BRR
#define GPIO_MAP1_LCKR       LCKR_TypeDef LCKR
#else
#define GPIO_MAP1_CRL __SOOL_PERIPH_PADDING_4
#define GPIO_MAP1_CRH __SOOL_PERIPH_PADDING_4
#define GPIO_MAP1_IDR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP1_ODR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP1_BSRR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP1_BRR __SOOL_PERIPH_PADDING_4
#define GPIO_MAP1_LCKR __SOOL_PERIPH_PADDING_4
#endif

#define GPIO_IDR
#define GPIO_LCKR
#define GPIO_ODR

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) ||\
    defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) ||\
    defined(STM32F410Tx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32L0     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define GPIO_OSPEEDR_0
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L1     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define GPIO_OSPEEDR_1
#endif

#if defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define GPIO_OSPEEDR_1_OSPEEDR0 OSPEEDR0             // 2 bits @ 0
#else
#define GPIO_OSPEEDR_1_OSPEEDR0
#endif

#if defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define GPIO_OTYPER_1
#define GPIO_OTYPER_2
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define GPIO_MAP0_BSRR       BSRR_TypeDef BSRR
#else
#define GPIO_MAP0_BSRR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32L0     ) || defined(STM32L100xC ) ||\
    defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define GPIO_MAP0_BRR        BRR_TypeDef BRR
#else
#define GPIO_MAP0_BRR __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class GPIO
		{
			//SOOL-GPIO-ENUMS
			
			public :
			
			#ifdef GPIO_AFR
			struct AFR_TypeDef : public ArrayRegBase_t<uint64_t, uint32_t>
			{
				using ArrayRegBase_t<uint64_t, uint32_t>::operator=;
			
				union
				{
					#ifdef GPIO_AFR_0
					struct
					{
						uint32_t AFSEL0               :4;
						uint32_t AFSEL1               :4;
						uint32_t AFSEL2               :4;
						uint32_t AFSEL3               :4;
						uint32_t AFSEL4               :4;
						uint32_t AFSEL5               :4;
						uint32_t AFSEL6               :4;
						uint32_t AFSEL7               :4;
						uint32_t AFSEL8               :4;
						uint32_t AFSEL9               :4;
						uint32_t AFSEL10              :4;
						uint32_t AFSEL11              :4;
						uint32_t AFSEL12              :4;
						uint32_t AFSEL13              :4;
						uint32_t AFSEL14              :4;
						uint32_t AFSEL15              :4;
					};
					#endif
					#ifdef GPIO_AFR_1
					struct
					{
						uint32_t AFRL0                :4;
						uint32_t AFRL1                :4;
						uint32_t AFRL2                :4;
						uint32_t AFRL3                :4;
						uint32_t AFRL4                :4;
						uint32_t AFRL5                :4;
						uint32_t AFRL6                :4;
						uint32_t AFRL7                :4;
						uint32_t AFRH0                :4;
						uint32_t AFRH1                :4;
						uint32_t AFRH2                :4;
						uint32_t AFRH3                :4;
						uint32_t AFRH4                :4;
						uint32_t AFRH5                :4;
						uint32_t AFRH6                :4;
						uint32_t AFRH7                :4;
					};
					#endif
				};
				//SOOL-GPIO_AFR-DECLARATION
			};
			#endif
			
			#ifdef GPIO_AFRH
			struct AFRH_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef GPIO_AFRH_0
					struct
					{
						uint32_t AFSEL8               :4;
						uint32_t AFSEL9               :4;
						uint32_t AFSEL10              :4;
						uint32_t AFSEL11              :4;
						uint32_t AFSEL12              :4;
						uint32_t AFSEL13              :4;
						uint32_t AFSEL14              :4;
						uint32_t AFSEL15              :4;
					};
					#endif
					#ifdef GPIO_AFRH_1
					struct
					{
						uint32_t AFRH0                :4;
						uint32_t AFRH1                :4;
						uint32_t AFRH2                :4;
						uint32_t AFRH3                :4;
						uint32_t AFRH4                :4;
						uint32_t AFRH5                :4;
						uint32_t AFRH6                :4;
						uint32_t AFRH7                :4;
					};
					#endif
				};
				//SOOL-GPIO_AFRH-DECLARATION
			};
			#endif
			
			#ifdef GPIO_AFRL
			struct AFRL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef GPIO_AFRL_0
					struct
					{
						uint32_t AFSEL0               :4;
						uint32_t AFSEL1               :4;
						uint32_t AFSEL2               :4;
						uint32_t AFSEL3               :4;
						uint32_t AFSEL4               :4;
						uint32_t AFSEL5               :4;
						uint32_t AFSEL6               :4;
						uint32_t AFSEL7               :4;
					};
					#endif
					#ifdef GPIO_AFRL_1
					struct
					{
						uint32_t AFRL0                :4;
						uint32_t AFRL1                :4;
						uint32_t AFRL2                :4;
						uint32_t AFRL3                :4;
						uint32_t AFRL4                :4;
						uint32_t AFRL5                :4;
						uint32_t AFRL6                :4;
						uint32_t AFRL7                :4;
					};
					#endif
				};
				//SOOL-GPIO_AFRL-DECLARATION
			};
			#endif
			
			#ifdef GPIO_ASCR
			struct ASCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t ASC0                 :1;
						uint32_t ASC1                 :1;
						uint32_t ASC2                 :1;
						uint32_t ASC3                 :1;
						uint32_t ASC4                 :1;
						uint32_t ASC5                 :1;
						uint32_t ASC6                 :1;
						uint32_t ASC7                 :1;
						uint32_t ASC8                 :1;
						uint32_t ASC9                 :1;
						uint32_t ASC10                :1;
						uint32_t ASC11                :1;
						uint32_t ASC12                :1;
						uint32_t ASC13                :1;
						uint32_t ASC14                :1;
						uint32_t ASC15                :1;
						uint32_t                      :16;
					};
					struct
					{
						uint32_t EN0                  :1;
						uint32_t EN1                  :1;
						uint32_t EN2                  :1;
						uint32_t EN3                  :1;
						uint32_t EN4                  :1;
						uint32_t EN5                  :1;
						uint32_t EN6                  :1;
						uint32_t EN7                  :1;
						uint32_t EN8                  :1;
						uint32_t EN9                  :1;
						uint32_t EN10                 :1;
						uint32_t EN11                 :1;
						uint32_t EN12                 :1;
						uint32_t EN13                 :1;
						uint32_t EN14                 :1;
						uint32_t EN15                 :1;
						uint32_t                      :16;
					};
				};
				//SOOL-GPIO_ASCR-DECLARATION
			};
			#endif
			
			#ifdef GPIO_BRR
			struct BRR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BR0                  :1;
					uint32_t BR1                  :1;
					uint32_t BR2                  :1;
					uint32_t BR3                  :1;
					uint32_t BR4                  :1;
					uint32_t BR5                  :1;
					uint32_t BR6                  :1;
					uint32_t BR7                  :1;
					uint32_t BR8                  :1;
					uint32_t BR9                  :1;
					uint32_t BR10                 :1;
					uint32_t BR11                 :1;
					uint32_t BR12                 :1;
					uint32_t BR13                 :1;
					uint32_t BR14                 :1;
					uint32_t BR15                 :1;
					uint32_t                      :16;
			
				//SOOL-GPIO_BRR-DECLARATION
			};
			#endif
			
			#ifdef GPIO_BSRR
			struct BSRR_TypeDef : public ArrayRegBase_t<uint32_t, uint16_t>
			{
				using ArrayRegBase_t<uint32_t, uint16_t>::operator=;
				
					uint32_t BS0                  :1;
					uint32_t BS1                  :1;
					uint32_t BS2                  :1;
					uint32_t BS3                  :1;
					uint32_t BS4                  :1;
					uint32_t BS5                  :1;
					uint32_t BS6                  :1;
					uint32_t BS7                  :1;
					uint32_t BS8                  :1;
					uint32_t BS9                  :1;
					uint32_t BS10                 :1;
					uint32_t BS11                 :1;
					uint32_t BS12                 :1;
					uint32_t BS13                 :1;
					uint32_t BS14                 :1;
					uint32_t BS15                 :1;
					uint32_t BR0                  :1;
					uint32_t BR1                  :1;
					uint32_t BR2                  :1;
					uint32_t BR3                  :1;
					uint32_t BR4                  :1;
					uint32_t BR5                  :1;
					uint32_t BR6                  :1;
					uint32_t BR7                  :1;
					uint32_t BR8                  :1;
					uint32_t BR9                  :1;
					uint32_t BR10                 :1;
					uint32_t BR11                 :1;
					uint32_t BR12                 :1;
					uint32_t BR13                 :1;
					uint32_t BR14                 :1;
					uint32_t BR15                 :1;
			
				//SOOL-GPIO_BSRR-DECLARATION
			};
			#endif
			
			#ifdef GPIO_BSRRH
			struct BSRRH_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t BR0                  :1;
					uint16_t BR1                  :1;
					uint16_t BR2                  :1;
					uint16_t BR3                  :1;
					uint16_t BR4                  :1;
					uint16_t BR5                  :1;
					uint16_t BR6                  :1;
					uint16_t BR7                  :1;
					uint16_t BR8                  :1;
					uint16_t BR9                  :1;
					uint16_t BR10                 :1;
					uint16_t BR11                 :1;
					uint16_t BR12                 :1;
					uint16_t BR13                 :1;
					uint16_t BR14                 :1;
					uint16_t BR15                 :1;
			
				//SOOL-GPIO_BSRRH-DECLARATION
			};
			#endif
			
			#ifdef GPIO_BSRRL
			struct BSRRL_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t BS0                  :1;
					uint16_t BS1                  :1;
					uint16_t BS2                  :1;
					uint16_t BS3                  :1;
					uint16_t BS4                  :1;
					uint16_t BS5                  :1;
					uint16_t BS6                  :1;
					uint16_t BS7                  :1;
					uint16_t BS8                  :1;
					uint16_t BS9                  :1;
					uint16_t BS10                 :1;
					uint16_t BS11                 :1;
					uint16_t BS12                 :1;
					uint16_t BS13                 :1;
					uint16_t BS14                 :1;
					uint16_t BS15                 :1;
			
				//SOOL-GPIO_BSRRL-DECLARATION
			};
			#endif
			
			#ifdef GPIO_CRH
			struct CRH_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MODE8                :2;
					uint32_t CNF8                 :2;
					uint32_t MODE9                :2;
					uint32_t CNF9                 :2;
					uint32_t MODE10               :2;
					uint32_t CNF10                :2;
					uint32_t MODE11               :2;
					uint32_t CNF11                :2;
					uint32_t MODE12               :2;
					uint32_t CNF12                :2;
					uint32_t MODE13               :2;
					uint32_t CNF13                :2;
					uint32_t MODE14               :2;
					uint32_t CNF14                :2;
					uint32_t MODE15               :2;
					uint32_t CNF15                :2;
			
				//SOOL-GPIO_CRH-DECLARATION
			};
			#endif
			
			#ifdef GPIO_CRL
			struct CRL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MODE0                :2;
					uint32_t CNF0                 :2;
					uint32_t MODE1                :2;
					uint32_t CNF1                 :2;
					uint32_t MODE2                :2;
					uint32_t CNF2                 :2;
					uint32_t MODE3                :2;
					uint32_t CNF3                 :2;
					uint32_t MODE4                :2;
					uint32_t CNF4                 :2;
					uint32_t MODE5                :2;
					uint32_t CNF5                 :2;
					uint32_t MODE6                :2;
					uint32_t CNF6                 :2;
					uint32_t MODE7                :2;
					uint32_t CNF7                 :2;
			
				//SOOL-GPIO_CRL-DECLARATION
			};
			#endif
			
			#ifdef GPIO_IDR
			struct IDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ID0                  :1;
					uint32_t ID1                  :1;
					uint32_t ID2                  :1;
					uint32_t ID3                  :1;
					uint32_t ID4                  :1;
					uint32_t ID5                  :1;
					uint32_t ID6                  :1;
					uint32_t ID7                  :1;
					uint32_t ID8                  :1;
					uint32_t ID9                  :1;
					uint32_t ID10                 :1;
					uint32_t ID11                 :1;
					uint32_t ID12                 :1;
					uint32_t ID13                 :1;
					uint32_t ID14                 :1;
					uint32_t ID15                 :1;
					uint32_t                      :16;
			
				//SOOL-GPIO_IDR-DECLARATION
			};
			#endif
			
			#ifdef GPIO_LCKR
			struct LCKR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LCK0                 :1;
					uint32_t LCK1                 :1;
					uint32_t LCK2                 :1;
					uint32_t LCK3                 :1;
					uint32_t LCK4                 :1;
					uint32_t LCK5                 :1;
					uint32_t LCK6                 :1;
					uint32_t LCK7                 :1;
					uint32_t LCK8                 :1;
					uint32_t LCK9                 :1;
					uint32_t LCK10                :1;
					uint32_t LCK11                :1;
					uint32_t LCK12                :1;
					uint32_t LCK13                :1;
					uint32_t LCK14                :1;
					uint32_t LCK15                :1;
					uint32_t LCKK                 :1;
					uint32_t                      :15;
			
				//SOOL-GPIO_LCKR-DECLARATION
			};
			#endif
			
			#ifdef GPIO_MODER
			struct MODER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MODE0                :2;
					uint32_t MODE1                :2;
					uint32_t MODE2                :2;
					uint32_t MODE3                :2;
					uint32_t MODE4                :2;
					uint32_t MODE5                :2;
					uint32_t MODE6                :2;
					uint32_t MODE7                :2;
					uint32_t MODE8                :2;
					uint32_t MODE9                :2;
					uint32_t MODE10               :2;
					uint32_t MODE11               :2;
					uint32_t MODE12               :2;
					uint32_t MODE13               :2;
					uint32_t MODE14               :2;
					uint32_t MODE15               :2;
			
				//SOOL-GPIO_MODER-DECLARATION
			};
			#endif
			
			#ifdef GPIO_ODR
			struct ODR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OD0                  :1;
					uint32_t OD1                  :1;
					uint32_t OD2                  :1;
					uint32_t OD3                  :1;
					uint32_t OD4                  :1;
					uint32_t OD5                  :1;
					uint32_t OD6                  :1;
					uint32_t OD7                  :1;
					uint32_t OD8                  :1;
					uint32_t OD9                  :1;
					uint32_t OD10                 :1;
					uint32_t OD11                 :1;
					uint32_t OD12                 :1;
					uint32_t OD13                 :1;
					uint32_t OD14                 :1;
					uint32_t OD15                 :1;
					uint32_t                      :16;
			
				//SOOL-GPIO_ODR-DECLARATION
			};
			#endif
			
			#ifdef GPIO_OSPEEDR
			struct OSPEEDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef GPIO_OSPEEDR_0
					struct
					{
						uint32_t OSPEED0              :2;
						uint32_t OSPEED1              :2;
						uint32_t OSPEED2              :2;
						uint32_t OSPEED3              :2;
						uint32_t OSPEED4              :2;
						uint32_t OSPEED5              :2;
						uint32_t OSPEED6              :2;
						uint32_t OSPEED7              :2;
						uint32_t OSPEED8              :2;
						uint32_t OSPEED9              :2;
						uint32_t OSPEED10             :2;
						uint32_t OSPEED11             :2;
						uint32_t OSPEED12             :2;
						uint32_t OSPEED13             :2;
						uint32_t OSPEED14             :2;
						uint32_t OSPEED15             :2;
					};
					#endif
					#ifdef GPIO_OSPEEDR_1
					struct
					{
						uint32_t GPIO_OSPEEDR_1_OSPEEDR0 :2;
						uint32_t OSPEEDR1             :2;
						uint32_t OSPEEDR2             :2;
						uint32_t OSPEEDR3             :2;
						uint32_t OSPEEDR4             :2;
						uint32_t OSPEEDR5             :2;
						uint32_t OSPEEDR6             :2;
						uint32_t OSPEEDR7             :2;
						uint32_t OSPEEDR8             :2;
						uint32_t OSPEEDR9             :2;
						uint32_t OSPEEDR10            :2;
						uint32_t OSPEEDR11            :2;
						uint32_t OSPEEDR12            :2;
						uint32_t OSPEEDR13            :2;
						uint32_t OSPEEDR14            :2;
						uint32_t OSPEEDR15            :2;
					};
					#endif
				};
				//SOOL-GPIO_OSPEEDR-DECLARATION
			};
			#endif
			
			#ifdef GPIO_OTYPER
			struct OTYPER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t OT0                  :1;
						uint32_t OT1                  :1;
						uint32_t OT2                  :1;
						uint32_t OT3                  :1;
						uint32_t OT4                  :1;
						uint32_t OT5                  :1;
						uint32_t OT6                  :1;
						uint32_t OT7                  :1;
						uint32_t OT8                  :1;
						uint32_t OT9                  :1;
						uint32_t OT10                 :1;
						uint32_t OT11                 :1;
						uint32_t OT12                 :1;
						uint32_t OT13                 :1;
						uint32_t OT14                 :1;
						uint32_t OT15                 :1;
						uint32_t                      :16;
					};
					#ifdef GPIO_OTYPER_1
					struct
					{
						uint32_t                      :1;
						uint32_t IDR1                 :1;
						uint32_t IDR2                 :1;
						uint32_t IDR3                 :1;
						uint32_t IDR4                 :1;
						uint32_t IDR5                 :1;
						uint32_t IDR6                 :1;
						uint32_t IDR7                 :1;
						uint32_t IDR8                 :1;
						uint32_t IDR9                 :1;
						uint32_t IDR10                :1;
						uint32_t IDR11                :1;
						uint32_t IDR12                :1;
						uint32_t IDR13                :1;
						uint32_t IDR14                :1;
						uint32_t IDR15                :1;
						uint32_t                      :16;
					};
					#endif
					#ifdef GPIO_OTYPER_2
					struct
					{
						uint32_t                      :1;
						uint32_t ODR1                 :1;
						uint32_t ODR2                 :1;
						uint32_t ODR3                 :1;
						uint32_t ODR4                 :1;
						uint32_t ODR5                 :1;
						uint32_t ODR6                 :1;
						uint32_t ODR7                 :1;
						uint32_t ODR8                 :1;
						uint32_t ODR9                 :1;
						uint32_t ODR10                :1;
						uint32_t ODR11                :1;
						uint32_t ODR12                :1;
						uint32_t ODR13                :1;
						uint32_t ODR14                :1;
						uint32_t ODR15                :1;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-GPIO_OTYPER-DECLARATION
			};
			#endif
			
			#ifdef GPIO_PUPDR
			struct PUPDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PUPD0                :2;
					uint32_t PUPD1                :2;
					uint32_t PUPD2                :2;
					uint32_t PUPD3                :2;
					uint32_t PUPD4                :2;
					uint32_t PUPD5                :2;
					uint32_t PUPD6                :2;
					uint32_t PUPD7                :2;
					uint32_t PUPD8                :2;
					uint32_t PUPD9                :2;
					uint32_t PUPD10               :2;
					uint32_t PUPD11               :2;
					uint32_t PUPD12               :2;
					uint32_t PUPD13               :2;
					uint32_t PUPD14               :2;
					uint32_t PUPD15               :2;
			
				//SOOL-GPIO_PUPDR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					GPIO_MAP0_MODER;     // @0x000
					GPIO_MAP0_OTYPER;    // @0x004
					GPIO_MAP0_OSPEEDR;   // @0x008
					GPIO_MAP0_PUPDR;     // @0x00c
					GPIO_MAP0_IDR;       // @0x010
					GPIO_MAP0_ODR;       // @0x014
					GPIO_MAP0_BSRR;      // @0x018
					GPIO_MAP0_LCKR;      // @0x01c
					GPIO_MAP0_AFR;       // @0x020
					GPIO_MAP0_BRR;       // @0x028
					GPIO_MAP0_ASCR;      // @0x02c
				};
				struct
				{
					GPIO_MAP1_CRL;       // @0x000
					GPIO_MAP1_CRH;       // @0x004
					GPIO_MAP1_IDR;       // @0x008
					GPIO_MAP1_ODR;       // @0x00c
					GPIO_MAP1_BSRR;      // @0x010
					GPIO_MAP1_BRR;       // @0x014
					GPIO_MAP1_LCKR;      // @0x018
					__SOOL_PERIPH_PADDING_4;
					GPIO_MAP1_AFRL;      // @0x020
					GPIO_MAP1_AFRH;      // @0x024
					__SOOL_PERIPH_PADDING_8;
				};
				struct
				{
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					GPIO_MAP2_BSRRL;     // @0x018
					GPIO_MAP2_BSRRH;     // @0x01a
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			GPIO() = delete;
			//SOOL-GPIO-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define GPIOA_BASE_ADDR ((uint32_t)0x48000000U)
#define GPIOB_BASE_ADDR ((uint32_t)0x48000400U)
#define GPIOC_BASE_ADDR ((uint32_t)0x48000800U)
#endif

#if defined(STM32F1     ) 
#define GPIOA_BASE_ADDR ((uint32_t)0x40010800U)
#define GPIOB_BASE_ADDR ((uint32_t)0x40010C00U)
#define GPIOC_BASE_ADDR ((uint32_t)0x40011000U)
#define GPIOD_BASE_ADDR ((uint32_t)0x40011400U)
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define GPIOA_BASE_ADDR ((uint32_t)0x40020000U)
#define GPIOB_BASE_ADDR ((uint32_t)0x40020400U)
#define GPIOC_BASE_ADDR ((uint32_t)0x40020800U)
#endif

#if defined(STM32H7     ) 
#define GPIOA_BASE_ADDR ((uint32_t)0x58020000U)
#define GPIOB_BASE_ADDR ((uint32_t)0x58020400U)
#define GPIOC_BASE_ADDR ((uint32_t)0x58020800U)
#define GPIOD_BASE_ADDR ((uint32_t)0x58020C00U)
#define GPIOF_BASE_ADDR ((uint32_t)0x58021400U)
#define GPIOE_BASE_ADDR ((uint32_t)0x58021000U)
#define GPIOG_BASE_ADDR ((uint32_t)0x58021800U)
#define GPIOH_BASE_ADDR ((uint32_t)0x58021C00U)
#define GPIOI_BASE_ADDR ((uint32_t)0x58022000U)
#define GPIOJ_BASE_ADDR ((uint32_t)0x58022400U)
#define GPIOK_BASE_ADDR ((uint32_t)0x58022800U)
#endif

#if defined(STM32L0     ) 
#define GPIOA_BASE_ADDR ((uint32_t)0x50000000U)
#define GPIOB_BASE_ADDR ((uint32_t)0x50000400U)
#define GPIOC_BASE_ADDR ((uint32_t)0x50000800U)
#endif

#if defined(STM32F030x6 ) || defined(STM32F030x8 ) || defined(STM32F030xC ) || defined(STM32F051x8 ) ||\
    defined(STM32F058xx ) || defined(STM32F070x6 ) || defined(STM32F070xB ) || defined(STM32F071xB ) ||\
    defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) ||\
    defined(STM32F3     ) || defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define GPIOD_BASE_ADDR ((uint32_t)0x48000C00U)
#endif

#if defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define GPIOD_BASE_ADDR ((uint32_t)0x40020C00U)
#endif

#if defined(STM32L051xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) 
#define GPIOD_BASE_ADDR ((uint32_t)0x50000C00U)
#endif

#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define GPIOF_BASE_ADDR ((uint32_t)0x48001400U)
#endif

#if defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) 
#define GPIOF_BASE_ADDR ((uint32_t)0x40011C00U)
#define GPIOG_BASE_ADDR ((uint32_t)0x40012000U)
#endif

#if defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F412Cx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) 
#define GPIOF_BASE_ADDR ((uint32_t)0x40021400U)
#define GPIOG_BASE_ADDR ((uint32_t)0x40021800U)
#endif

#if defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define GPIOF_BASE_ADDR ((uint32_t)0x40021800U)
#define GPIOG_BASE_ADDR ((uint32_t)0x40021C00U)
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define GPIOE_BASE_ADDR ((uint32_t)0x48001000U)
#endif

#if defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xB ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F105xC ) || defined(STM32F107xC ) 
#define GPIOE_BASE_ADDR ((uint32_t)0x40011800U)
#endif

#if defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L151xB ) || defined(STM32L151xBA) ||\
    defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xB ) || defined(STM32L152xBA) || defined(STM32L152xC ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) ||\
    defined(STM32L162xE ) 
#define GPIOE_BASE_ADDR ((uint32_t)0x40021000U)
#endif

#if defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) 
#define GPIOE_BASE_ADDR ((uint32_t)0x50001000U)
#endif

#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define GPIOG_BASE_ADDR ((uint32_t)0x48001800U)
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     ) 
#define GPIOH_BASE_ADDR ((uint32_t)0x40021C00U)
#endif

#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define GPIOH_BASE_ADDR ((uint32_t)0x48001C00U)
#endif

#if defined(STM32L031xx ) || defined(STM32L041xx ) || defined(STM32L051xx ) || defined(STM32L052xx ) ||\
    defined(STM32L053xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) ||\
    defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) 
#define GPIOH_BASE_ADDR ((uint32_t)0x50001C00U)
#endif

#if defined(STM32L1     ) 
#define GPIOH_BASE_ADDR ((uint32_t)0x40021400U)
#endif

#if defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) ||\
    defined(STM32F439xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) 
#define GPIOI_BASE_ADDR ((uint32_t)0x40022000U)
#endif

#if defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define GPIOI_BASE_ADDR ((uint32_t)0x48002000U)
#endif

#if defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) ||\
    defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) 
#define GPIOJ_BASE_ADDR ((uint32_t)0x40022400U)
#define GPIOK_BASE_ADDR ((uint32_t)0x40022800U)
#endif

#ifdef GPIOA_BASE_ADDR
volatile class GPIO * const GPIOA = reinterpret_cast<class GPIO* const>(GPIOA_BASE_ADDR);
#endif
#ifdef GPIOB_BASE_ADDR
volatile class GPIO * const GPIOB = reinterpret_cast<class GPIO* const>(GPIOB_BASE_ADDR);
#endif
#ifdef GPIOC_BASE_ADDR
volatile class GPIO * const GPIOC = reinterpret_cast<class GPIO* const>(GPIOC_BASE_ADDR);
#endif
#ifdef GPIOD_BASE_ADDR
volatile class GPIO * const GPIOD = reinterpret_cast<class GPIO* const>(GPIOD_BASE_ADDR);
#endif
#ifdef GPIOF_BASE_ADDR
volatile class GPIO * const GPIOF = reinterpret_cast<class GPIO* const>(GPIOF_BASE_ADDR);
#endif
#ifdef GPIOE_BASE_ADDR
volatile class GPIO * const GPIOE = reinterpret_cast<class GPIO* const>(GPIOE_BASE_ADDR);
#endif
#ifdef GPIOG_BASE_ADDR
volatile class GPIO * const GPIOG = reinterpret_cast<class GPIO* const>(GPIOG_BASE_ADDR);
#endif
#ifdef GPIOH_BASE_ADDR
volatile class GPIO * const GPIOH = reinterpret_cast<class GPIO* const>(GPIOH_BASE_ADDR);
#endif
#ifdef GPIOI_BASE_ADDR
volatile class GPIO * const GPIOI = reinterpret_cast<class GPIO* const>(GPIOI_BASE_ADDR);
#endif
#ifdef GPIOJ_BASE_ADDR
volatile class GPIO * const GPIOJ = reinterpret_cast<class GPIO* const>(GPIOJ_BASE_ADDR);
#endif
#ifdef GPIOK_BASE_ADDR
volatile class GPIO * const GPIOK = reinterpret_cast<class GPIO* const>(GPIOK_BASE_ADDR);
#endif
//endregion

//SOOL-GPIO-DEFINES
//SOOL-GPIO-DEFINITION
	};
};//region undef
#undef GPIO_MAP0_MODER
#undef GPIO_MAP0_OTYPER
#undef GPIO_MAP0_OSPEEDR
#undef GPIO_MAP0_PUPDR
#undef GPIO_MAP0_IDR
#undef GPIO_MAP0_ODR
#undef GPIO_MAP0_LCKR
#undef GPIO_MAP0_AFR
#undef GPIO_MAP1_AFRL
#undef GPIO_MAP1_AFRH
#undef GPIO_MAP0_ASCR
#undef GPIO_MAP2_BSRRL
#undef GPIO_MAP2_BSRRH
#undef GPIO_MAP1_CRL
#undef GPIO_MAP1_CRH
#undef GPIO_MAP1_IDR
#undef GPIO_MAP1_ODR
#undef GPIO_MAP1_BSRR
#undef GPIO_MAP1_BRR
#undef GPIO_MAP1_LCKR
#undef GPIO_OSPEEDR_1_OSPEEDR0
#undef GPIO_MAP0_BSRR
#undef GPIO_MAP0_BRR
//endregion
#endif
