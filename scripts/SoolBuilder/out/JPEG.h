#ifndef __SOOL_JPEG_H
#define __SOOL_JPEG_H

#include "peripheral_include.h"
//SOOL-JPEG-INCLUDES
#if defined(STM32H7     ) 
//region defines

#define JPEG_CFR
#define JPEG_CONFR0
#define JPEG_CONFR1
#define JPEG_CONFR2
#define JPEG_CONFR3
#define JPEG_CONFR4
#define JPEG_CONFR5
#define JPEG_CONFR6
#define JPEG_CONFR7
#define JPEG_CR
#define JPEG_DHTMEM
#define JPEG_DIR
#define JPEG_DOR
#define JPEG_HUFFBASE
#define JPEG_HUFFENC_AC0
#define JPEG_HUFFENC_AC1
#define JPEG_HUFFENC_DC0
#define JPEG_HUFFENC_DC1
#define JPEG_HUFFMIN
#define JPEG_HUFFSYMB
#define JPEG_QMEM0
#define JPEG_QMEM1
#define JPEG_QMEM2
#define JPEG_QMEM3
#define JPEG_SR

#if defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) 
#define JPEG_CFR_0
#define JPEG_CONFR1_RE       RE                   // 1 bits @ 2
#define JPEG_CONFR3_NRST     NRST                 // 16 bits @ 0
#define JPEG_CR_IDMAEN       IDMAEN               // 1 bits @ 11
#define JPEG_CR_ODMAEN       ODMAEN               // 1 bits @ 12
#else
#define JPEG_CONFR1_RE
#define JPEG_CONFR3_NRST
#define JPEG_CR_IDMAEN
#define JPEG_CR_ODMAEN
#endif

//endregion

namespace sool
{
	namespace core
	{
		class JPEG
		{
			//SOOL-JPEG-ENUMS
			
			public :
			
			#ifdef JPEG_CFR
			struct CFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef JPEG_CFR_0
					struct
					{
						uint32_t                      :5;
						uint32_t CEOCF                :1;
						uint32_t CHPDF                :1;
						uint32_t                      :25;
					};
					#endif
					struct
					{
						uint32_t                      :4;
						uint32_t CEOCF                :1;
						uint32_t CHPDF                :1;
						uint32_t                      :26;
					};
				};
				//SOOL-JPEG_CFR-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CONFR0
			struct CONFR0_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t START                :1;
					uint32_t                      :31;
			
				//SOOL-JPEG_CONFR0-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CONFR1
			struct CONFR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NF                   :2;
					uint32_t JPEG_CONFR1_RE       :1;
					uint32_t DE                   :1;
					uint32_t COLORSPACE           :2;
					uint32_t NS                   :2;
					uint32_t HDR                  :1;
					uint32_t                      :7;
					uint32_t YSIZE                :16;
			
				//SOOL-JPEG_CONFR1-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CONFR2
			struct CONFR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NMCU                 :26;
					uint32_t                      :6;
			
				//SOOL-JPEG_CONFR2-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CONFR3
			struct CONFR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t JPEG_CONFR3_NRST     :16;
					uint32_t XSIZE                :16;
			
				//SOOL-JPEG_CONFR3-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CONFR4
			struct CONFR4_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HD                   :1;
					uint32_t HA                   :1;
					uint32_t QT                   :2;
					uint32_t NB                   :4;
					uint32_t VSF                  :4;
					uint32_t HSF                  :4;
					uint32_t                      :16;
			
				//SOOL-JPEG_CONFR4-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CONFR5
			struct CONFR5_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HD                   :1;
					uint32_t HA                   :1;
					uint32_t QT                   :2;
					uint32_t NB                   :4;
					uint32_t VSF                  :4;
					uint32_t HSF                  :4;
					uint32_t                      :16;
			
				//SOOL-JPEG_CONFR5-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CONFR6
			struct CONFR6_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HD                   :1;
					uint32_t HA                   :1;
					uint32_t QT                   :2;
					uint32_t NB                   :4;
					uint32_t VSF                  :4;
					uint32_t HSF                  :4;
					uint32_t                      :16;
			
				//SOOL-JPEG_CONFR6-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CONFR7
			struct CONFR7_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HD                   :1;
					uint32_t HA                   :1;
					uint32_t QT                   :2;
					uint32_t NB                   :4;
					uint32_t VSF                  :4;
					uint32_t HSF                  :4;
					uint32_t                      :16;
			
				//SOOL-JPEG_CONFR7-DECLARATION
			};
			#endif
			
			#ifdef JPEG_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t JCEN                 :1;
					uint32_t IFTIE                :1;
					uint32_t IFNFIE               :1;
					uint32_t OFTIE                :1;
					uint32_t OFNEIE               :1;
					uint32_t EOCIE                :1;
					uint32_t HPDIE                :1;
					uint32_t                      :4;
					uint32_t JPEG_CR_IDMAEN       :1;
					uint32_t JPEG_CR_ODMAEN       :1;
					uint32_t IFF                  :1;
					uint32_t OFF                  :1;
					uint32_t                      :17;
			
				//SOOL-JPEG_CR-DECLARATION
			};
			#endif
			
			#ifdef JPEG_DIR
			struct DIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATAIN               :32;
			
				//SOOL-JPEG_DIR-DECLARATION
			};
			#endif
			
			#ifdef JPEG_DOR
			struct DOR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATAOUT              :32;
			
				//SOOL-JPEG_DOR-DECLARATION
			};
			#endif
			
			#ifdef JPEG_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t IFTF                 :1;
					uint32_t IFNFF                :1;
					uint32_t OFTF                 :1;
					uint32_t OFNEF                :1;
					uint32_t EOCF                 :1;
					uint32_t HPDF                 :1;
					uint32_t COF                  :1;
					uint32_t                      :24;
			
				//SOOL-JPEG_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CONFR0_TypeDef CONFR0; // @0x000
					CONFR1_TypeDef CONFR1; // @0x004
					CONFR2_TypeDef CONFR2; // @0x008
					CONFR3_TypeDef CONFR3; // @0x00c
					CONFR4_TypeDef CONFR4; // @0x010
					CONFR5_TypeDef CONFR5; // @0x014
					CONFR6_TypeDef CONFR6; // @0x018
					CONFR7_TypeDef CONFR7; // @0x01c
					__SOOL_PERIPH_PADDING_16;
					CR_TypeDef CR;       // @0x030
					SR_TypeDef SR;       // @0x034
					CFR_TypeDef CFR;     // @0x038
					__SOOL_PERIPH_PADDING_4;
					DIR_TypeDef DIR;     // @0x040
					DOR_TypeDef DOR;     // @0x044
					__SOOL_PERIPH_PADDING_8;
					uint32_t QMEM0[16];  // @0x050
					uint32_t QMEM1[16];  // @0x090
					uint32_t QMEM2[16];  // @0x0d0
					uint32_t QMEM3[16];  // @0x110
					uint32_t HUFFMIN[16]; // @0x150
					uint32_t HUFFBASE[32]; // @0x190
					uint32_t HUFFSYMB[84]; // @0x210
					uint32_t DHTMEM[103]; // @0x360
					__SOOL_PERIPH_PADDING_4;
					uint32_t HUFFENC_AC0[88]; // @0x500
					uint32_t HUFFENC_AC1[88]; // @0x660
					uint32_t HUFFENC_DC0[8]; // @0x7c0
					uint32_t HUFFENC_DC1[8]; // @0x7e0
				};
			};
			private:
			JPEG() = delete;
			//SOOL-JPEG-DECLARATION
		};
		
		//region instances
#if defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) 
#define JPEG_BASE_ADDR ((uint32_t)0x50051000U)
#endif

#define JPEG_BASE_ADDR ((uint32_t)0x52003000U)
#ifdef JPEG_BASE_ADDR
volatile class JPEG * const JPEG = reinterpret_cast<class JPEG* const>(JPEG_BASE_ADDR);
#endif
//endregion

//SOOL-JPEG-DEFINES
//SOOL-JPEG-DEFINITION
	};
};//region undef
#undef JPEG_CONFR1_RE
#undef JPEG_CONFR3_NRST
#undef JPEG_CR_IDMAEN
#undef JPEG_CR_ODMAEN
//endregion
#endif
#endif
