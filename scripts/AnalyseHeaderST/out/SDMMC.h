#ifndef __SOOL_SDMMC_H
#define __SOOL_SDMMC_H

#include "peripheral_include.h"
//SOOL-SDMMC-INCLUDES
#if defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L431xx ) || defined(STM32L433xx ) ||\
    defined(STM32L443xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) ||\
    defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
//region defines

#if defined(STM32H7     ) || defined(STM32L4P    ) 
#define SDMMC_ACKTIME
#define SDMMC_CLKCR_0_DDR    DDR                  // 1 bits @ 18
#define SDMMC_CLKCR_0_BUSSPEED BUSSPEED             // 1 bits @ 19
#define SDMMC_CLKCR_0_SELCLKRX SELCLKRX             // 2 bits @ 20
#define SDMMC_CLKCR_1
#define SDMMC_CMD_0_DTHOLD   DTHOLD               // 1 bits @ 13
#define SDMMC_CMD_0_BOOTMODE BOOTMODE             // 1 bits @ 14
#define SDMMC_CMD_0_BOOTEN   BOOTEN               // 1 bits @ 15
#define SDMMC_CMD_0_CMDSUSPEND CMDSUSPEND           // 1 bits @ 16
#define SDMMC_CMD_1
#define SDMMC_DCTRL_0_BOOTACKEN BOOTACKEN            // 1 bits @ 12
#define SDMMC_DCTRL_0_FIFORST FIFORST              // 1 bits @ 13
#define SDMMC_DCTRL_1
#define SDMMC_ICR_0_DHOLDC   DHOLDC               // 1 bits @ 9
#define SDMMC_ICR_0_DABORTC  DABORTC              // 1 bits @ 11
#define SDMMC_ICR_0_BUSYD0ENDC BUSYD0ENDC           // 1 bits @ 21
#define SDMMC_ICR_0_ACKFAILC ACKFAILC             // 1 bits @ 23
#define SDMMC_ICR_0_ACKTIMEOUTC ACKTIMEOUTC          // 1 bits @ 24
#define SDMMC_ICR_0_VSWENDC  VSWENDC              // 1 bits @ 25
#define SDMMC_ICR_0_CKSTOPC  CKSTOPC              // 1 bits @ 26
#define SDMMC_ICR_0_IDMATEC  IDMATEC              // 1 bits @ 27
#define SDMMC_ICR_0_IDMABTCC IDMABTCC             // 1 bits @ 28
#define SDMMC_IDMABASE0
#define SDMMC_IDMABASE1
#define SDMMC_IDMABSIZE
#define SDMMC_IDMACTRL
#define SDMMC_MASK_0_DHOLDIE DHOLDIE              // 1 bits @ 9
#define SDMMC_MASK_0_ACKFAILIE ACKFAILIE            // 1 bits @ 23
#define SDMMC_MASK_0_ACKTIMEOUTIE ACKTIMEOUTIE         // 1 bits @ 24
#define SDMMC_MASK_0_VSWENDIE VSWENDIE             // 1 bits @ 25
#define SDMMC_MASK_0_CKSTOPIE CKSTOPIE             // 1 bits @ 26
#define SDMMC_MASK_0_IDMABTCIE IDMABTCIE            // 1 bits @ 28
#define SDMMC_MASK_1
#define SDMMC_POWER_VSWITCH  VSWITCH              // 1 bits @ 2
#define SDMMC_POWER_VSWITCHEN VSWITCHEN            // 1 bits @ 3
#define SDMMC_POWER_DIRPOL   DIRPOL               // 1 bits @ 4
#define SDMMC_STA_0_DHOLD    DHOLD                // 1 bits @ 9
#define SDMMC_STA_0_ACKFAIL  ACKFAIL              // 1 bits @ 23
#define SDMMC_STA_0_ACKTIMEOUT ACKTIMEOUT           // 1 bits @ 24
#define SDMMC_STA_0_VSWEND   VSWEND               // 1 bits @ 25
#define SDMMC_STA_0_CKSTOP   CKSTOP               // 1 bits @ 26
#define SDMMC_STA_0_IDMATE   IDMATE               // 1 bits @ 27
#define SDMMC_STA_0_IDMABTC  IDMABTC              // 1 bits @ 28
#define SDMMC_STA_1_DABORT   DABORT               // 1 bits @ 11
#define SDMMC_STA_1_BUSYD0   BUSYD0               // 1 bits @ 20
#define SDMMC_STA_1_BUSYD0END BUSYD0END            // 1 bits @ 21
#define SDMMC_MAP0_ACKTIME   ACKTIME_TypeDef ACKTIME
#define SDMMC_MAP0_IDMACTRL  IDMACTRL_TypeDef IDMACTRL
#define SDMMC_MAP0_IDMABSIZE IDMABSIZE_TypeDef IDMABSIZE
#define SDMMC_MAP0_IDMABASE0 IDMABASE0_TypeDef IDMABASE0
#define SDMMC_MAP0_IDMABASE1 IDMABASE1_TypeDef IDMABASE1
#else
#define SDMMC_CLKCR_0_DDR
#define SDMMC_CLKCR_0_BUSSPEED
#define SDMMC_CLKCR_0_SELCLKRX
#define SDMMC_CMD_0_DTHOLD
#define SDMMC_CMD_0_BOOTMODE
#define SDMMC_CMD_0_BOOTEN
#define SDMMC_CMD_0_CMDSUSPEND
#define SDMMC_DCTRL_0_BOOTACKEN
#define SDMMC_DCTRL_0_FIFORST
#define SDMMC_ICR_0_DHOLDC
#define SDMMC_ICR_0_DABORTC
#define SDMMC_ICR_0_BUSYD0ENDC
#define SDMMC_ICR_0_ACKFAILC
#define SDMMC_ICR_0_ACKTIMEOUTC
#define SDMMC_ICR_0_VSWENDC
#define SDMMC_ICR_0_CKSTOPC
#define SDMMC_ICR_0_IDMATEC
#define SDMMC_ICR_0_IDMABTCC
#define SDMMC_MASK_0_DHOLDIE
#define SDMMC_MASK_0_ACKFAILIE
#define SDMMC_MASK_0_ACKTIMEOUTIE
#define SDMMC_MASK_0_VSWENDIE
#define SDMMC_MASK_0_CKSTOPIE
#define SDMMC_MASK_0_IDMABTCIE
#define SDMMC_POWER_VSWITCH
#define SDMMC_POWER_VSWITCHEN
#define SDMMC_POWER_DIRPOL
#define SDMMC_STA_0_DHOLD
#define SDMMC_STA_0_ACKFAIL
#define SDMMC_STA_0_ACKTIMEOUT
#define SDMMC_STA_0_VSWEND
#define SDMMC_STA_0_CKSTOP
#define SDMMC_STA_0_IDMATE
#define SDMMC_STA_0_IDMABTC
#define SDMMC_STA_1_DABORT
#define SDMMC_STA_1_BUSYD0
#define SDMMC_STA_1_BUSYD0END
#define SDMMC_MAP0_ACKTIME __SOOL_PERIPH_PADDING_4
#define SDMMC_MAP0_IDMACTRL __SOOL_PERIPH_PADDING_4
#define SDMMC_MAP0_IDMABSIZE __SOOL_PERIPH_PADDING_4
#define SDMMC_MAP0_IDMABASE0 __SOOL_PERIPH_PADDING_4
#define SDMMC_MAP0_IDMABASE1 __SOOL_PERIPH_PADDING_4
#endif

#define SDMMC_ARG
#define SDMMC_CLKCR
#define SDMMC_CMD
#define SDMMC_DCOUNT
#define SDMMC_DCTRL
#define SDMMC_DLEN
#define SDMMC_DTIMER
#define SDMMC_FIFO
#define SDMMC_ICR
#define SDMMC_MASK
#define SDMMC_POWER
#define SDMMC_RESP
#define SDMMC_RESPCMD
#define SDMMC_STA

#if defined(STM32F7     ) || defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define SDMMC_CLKCR_0_CLKDIV CLKDIV               // 8 bits @ 0
#define SDMMC_CLKCR_0_CLKEN  CLKEN                // 1 bits @ 8
#define SDMMC_CLKCR_0_PWRSAV PWRSAV               // 1 bits @ 9
#define SDMMC_CLKCR_0_BYPASS BYPASS               // 1 bits @ 10
#define SDMMC_CLKCR_0_WIDBUS WIDBUS               // 2 bits @ 11
#define SDMMC_CLKCR_0_NEGEDGE NEGEDGE              // 1 bits @ 13
#define SDMMC_CLKCR_0_HWFC_EN HWFC_EN              // 1 bits @ 14
#define SDMMC_CMD_0_WAITRESP WAITRESP             // 2 bits @ 6
#define SDMMC_CMD_0_WAITINT  WAITINT              // 1 bits @ 8
#define SDMMC_CMD_0_WAITPEND WAITPEND             // 1 bits @ 9
#define SDMMC_CMD_0_CPSMEN   CPSMEN               // 1 bits @ 10
#define SDMMC_CMD_0_SDIOSUSPEND SDIOSUSPEND          // 1 bits @ 11
#define SDMMC_DCTRL_0_DTMODE DTMODE               // 1 bits @ 2
#define SDMMC_DCTRL_0_DMAEN  DMAEN                // 1 bits @ 3
#define SDMMC_FIFOCNT
#define SDMMC_MASK_0_CMDACTIE CMDACTIE             // 1 bits @ 11
#define SDMMC_MASK_0_TXACTIE TXACTIE              // 1 bits @ 12
#define SDMMC_MASK_0_RXACTIE RXACTIE              // 1 bits @ 13
#define SDMMC_MASK_0_TXFIFOFIE TXFIFOFIE            // 1 bits @ 16
#define SDMMC_MASK_0_RXFIFOEIE RXFIFOEIE            // 1 bits @ 19
#define SDMMC_MASK_0_TXDAVLIE TXDAVLIE             // 1 bits @ 20
#define SDMMC_MASK_0_RXDAVLIE RXDAVLIE             // 1 bits @ 21
#define SDMMC_STA_0_CMDACT   CMDACT               // 1 bits @ 11
#define SDMMC_STA_0_TXACT    TXACT                // 1 bits @ 12
#define SDMMC_STA_0_RXACT    RXACT                // 1 bits @ 13
#define SDMMC_STA_0_TXDAVL   TXDAVL               // 1 bits @ 20
#define SDMMC_STA_0_RXDAVL   RXDAVL               // 1 bits @ 21
#define SDMMC_MAP0_FIFOCNT   FIFOCNT_TypeDef FIFOCNT
#else
#define SDMMC_CLKCR_0_CLKDIV
#define SDMMC_CLKCR_0_CLKEN
#define SDMMC_CLKCR_0_PWRSAV
#define SDMMC_CLKCR_0_BYPASS
#define SDMMC_CLKCR_0_WIDBUS
#define SDMMC_CLKCR_0_NEGEDGE
#define SDMMC_CLKCR_0_HWFC_EN
#define SDMMC_CMD_0_WAITRESP
#define SDMMC_CMD_0_WAITINT
#define SDMMC_CMD_0_WAITPEND
#define SDMMC_CMD_0_CPSMEN
#define SDMMC_CMD_0_SDIOSUSPEND
#define SDMMC_DCTRL_0_DTMODE
#define SDMMC_DCTRL_0_DMAEN
#define SDMMC_MASK_0_CMDACTIE
#define SDMMC_MASK_0_TXACTIE
#define SDMMC_MASK_0_RXACTIE
#define SDMMC_MASK_0_TXFIFOFIE
#define SDMMC_MASK_0_RXFIFOEIE
#define SDMMC_MASK_0_TXDAVLIE
#define SDMMC_MASK_0_RXDAVLIE
#define SDMMC_STA_0_CMDACT
#define SDMMC_STA_0_TXACT
#define SDMMC_STA_0_RXACT
#define SDMMC_STA_0_TXDAVL
#define SDMMC_STA_0_RXDAVL
#define SDMMC_MAP0_FIFOCNT __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) 
#define SDMMC_ICR_1
#define SDMMC_STA_1_STBITERR STBITERR             // 1 bits @ 9
#else
#define SDMMC_STA_1_STBITERR
#endif

#if defined(STM32H7     ) 
#define SDMMC_IPVR
#define SDMMC_MASK_1_SDIOTIE SDIOTIE              // 1 bits @ 22
#define SDMMC_STA_1_CPSMACT  CPSMACT              // 1 bits @ 12
#define SDMMC_STA_1_DPSMACT  DPSMACT              // 1 bits @ 13
#define SDMMC_MAP0_IPVR      uint32_t IPVR
#else
#define SDMMC_MASK_1_SDIOTIE
#define SDMMC_STA_1_CPSMACT
#define SDMMC_STA_1_DPSMACT
#define SDMMC_MAP0_IPVR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F7     ) || defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define SDMMC_MASK_0_SDIOITIE SDIOITIE             // 1 bits @ 22
#else
#define SDMMC_MASK_0_SDIOITIE
#endif

#if defined(STM32F7     ) || defined(STM32H7     ) 
#define SDMMC_RESPCMD_1
#endif

#if defined(STM32H7     ) || defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define SDMMC_STA_1
#endif

#if defined(STM32L4P    ) 
#define SDMMC_STA_2
#define SDMMC_VERR
#define SDMMC_MAP0_VERR      VERR_TypeDef VERR
#else
#define SDMMC_MAP0_VERR __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class SDMMC
		{
			//SOOL-SDMMC-ENUMS
			
			public :
			
			#ifdef SDMMC_ACKTIME
			struct ACKTIME_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ACKTIME              :25;
					uint32_t                      :7;
			
				//SOOL-SDMMC_ACKTIME-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_ARG
			struct ARG_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMDARG               :32;
			
				//SOOL-SDMMC_ARG-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_CLKCR
			struct CLKCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t SDMMC_CLKCR_0_CLKDIV :8;
						uint32_t SDMMC_CLKCR_0_CLKEN  :1;
						uint32_t SDMMC_CLKCR_0_PWRSAV :1;
						uint32_t SDMMC_CLKCR_0_BYPASS :1;
						uint32_t SDMMC_CLKCR_0_WIDBUS :2;
						uint32_t SDMMC_CLKCR_0_NEGEDGE :1;
						uint32_t SDMMC_CLKCR_0_HWFC_EN :1;
						uint32_t                      :3;
						uint32_t SDMMC_CLKCR_0_DDR    :1;
						uint32_t SDMMC_CLKCR_0_BUSSPEED :1;
						uint32_t SDMMC_CLKCR_0_SELCLKRX :2;
						uint32_t                      :10;
					};
					#ifdef SDMMC_CLKCR_1
					struct
					{
						uint32_t CLKDIV               :10;
						uint32_t                      :2;
						uint32_t PWRSAV               :1;
						uint32_t                      :1;
						uint32_t WIDBUS               :2;
						uint32_t NEGEDGE              :1;
						uint32_t HWFC_EN              :1;
						uint32_t                      :14;
					};
					#endif
				};
				//SOOL-SDMMC_CLKCR-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_CMD
			struct CMD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t CMDINDEX             :6;
						uint32_t SDMMC_CMD_0_WAITRESP :2;
						uint32_t SDMMC_CMD_0_WAITINT  :1;
						uint32_t SDMMC_CMD_0_WAITPEND :1;
						uint32_t SDMMC_CMD_0_CPSMEN   :1;
						uint32_t SDMMC_CMD_0_SDIOSUSPEND :1;
						uint32_t                      :1;
						uint32_t SDMMC_CMD_0_DTHOLD   :1;
						uint32_t SDMMC_CMD_0_BOOTMODE :1;
						uint32_t SDMMC_CMD_0_BOOTEN   :1;
						uint32_t SDMMC_CMD_0_CMDSUSPEND :1;
						uint32_t                      :15;
					};
					#ifdef SDMMC_CMD_1
					struct
					{
						uint32_t                      :6;
						uint32_t CMDTRANS             :1;
						uint32_t CMDSTOP              :1;
						uint32_t WAITRESP             :2;
						uint32_t WAITINT              :1;
						uint32_t WAITPEND             :1;
						uint32_t CPSMEN               :1;
						uint32_t                      :19;
					};
					#endif
				};
				//SOOL-SDMMC_CMD-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_DCOUNT
			struct DCOUNT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATACOUNT            :25;
					uint32_t                      :7;
			
				//SOOL-SDMMC_DCOUNT-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_DCTRL
			struct DCTRL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t DTEN                 :1;
						uint32_t DTDIR                :1;
						uint32_t SDMMC_DCTRL_0_DTMODE :1;
						uint32_t SDMMC_DCTRL_0_DMAEN  :1;
						uint32_t DBLOCKSIZE           :4;
						uint32_t RWSTART              :1;
						uint32_t RWSTOP               :1;
						uint32_t RWMOD                :1;
						uint32_t SDIOEN               :1;
						uint32_t SDMMC_DCTRL_0_BOOTACKEN :1;
						uint32_t SDMMC_DCTRL_0_FIFORST :1;
						uint32_t                      :18;
					};
					#ifdef SDMMC_DCTRL_1
					struct
					{
						uint32_t                      :2;
						uint32_t DTMODE               :2;
						uint32_t                      :28;
					};
					#endif
				};
				//SOOL-SDMMC_DCTRL-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_DLEN
			struct DLEN_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATALENGTH           :25;
					uint32_t                      :7;
			
				//SOOL-SDMMC_DLEN-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_DTIMER
			struct DTIMER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATATIME             :32;
			
				//SOOL-SDMMC_DTIMER-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_FIFO
			struct FIFO_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FIFODATA             :32;
			
				//SOOL-SDMMC_FIFO-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_FIFOCNT
			struct FIFOCNT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FIFOCOUNT            :24;
					uint32_t                      :8;
			
				//SOOL-SDMMC_FIFOCNT-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t CCRCFAILC            :1;
						uint32_t DCRCFAILC            :1;
						uint32_t CTIMEOUTC            :1;
						uint32_t DTIMEOUTC            :1;
						uint32_t TXUNDERRC            :1;
						uint32_t RXOVERRC             :1;
						uint32_t CMDRENDC             :1;
						uint32_t CMDSENTC             :1;
						uint32_t DATAENDC             :1;
						uint32_t SDMMC_ICR_0_DHOLDC   :1;
						uint32_t DBCKENDC             :1;
						uint32_t SDMMC_ICR_0_DABORTC  :1;
						uint32_t                      :9;
						uint32_t SDMMC_ICR_0_BUSYD0ENDC :1;
						uint32_t SDIOITC              :1;
						uint32_t SDMMC_ICR_0_ACKFAILC :1;
						uint32_t SDMMC_ICR_0_ACKTIMEOUTC :1;
						uint32_t SDMMC_ICR_0_VSWENDC  :1;
						uint32_t SDMMC_ICR_0_CKSTOPC  :1;
						uint32_t SDMMC_ICR_0_IDMATEC  :1;
						uint32_t SDMMC_ICR_0_IDMABTCC :1;
						uint32_t                      :3;
					};
					#ifdef SDMMC_ICR_1
					struct
					{
						uint32_t                      :9;
						uint32_t STBITERRC            :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-SDMMC_ICR-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_IDMABASE0
			struct IDMABASE0_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IDMABASE0            :32;
			
				//SOOL-SDMMC_IDMABASE0-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_IDMABASE1
			struct IDMABASE1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IDMABASE1            :32;
			
				//SOOL-SDMMC_IDMABASE1-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_IDMABSIZE
			struct IDMABSIZE_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :5;
					uint32_t IDMABNDT             :8;
					uint32_t                      :19;
			
				//SOOL-SDMMC_IDMABSIZE-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_IDMACTRL
			struct IDMACTRL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IDMAEN               :1;
					uint32_t IDMABMODE            :1;
					uint32_t IDMABACT             :1;
					uint32_t                      :29;
			
				//SOOL-SDMMC_IDMACTRL-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_MASK
			struct MASK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t CCRCFAILIE           :1;
						uint32_t DCRCFAILIE           :1;
						uint32_t CTIMEOUTIE           :1;
						uint32_t DTIMEOUTIE           :1;
						uint32_t TXUNDERRIE           :1;
						uint32_t RXOVERRIE            :1;
						uint32_t CMDRENDIE            :1;
						uint32_t CMDSENTIE            :1;
						uint32_t DATAENDIE            :1;
						uint32_t SDMMC_MASK_0_DHOLDIE :1;
						uint32_t DBCKENDIE            :1;
						uint32_t SDMMC_MASK_0_CMDACTIE :1;
						uint32_t SDMMC_MASK_0_TXACTIE :1;
						uint32_t SDMMC_MASK_0_RXACTIE :1;
						uint32_t TXFIFOHEIE           :1;
						uint32_t RXFIFOHFIE           :1;
						uint32_t SDMMC_MASK_0_TXFIFOFIE :1;
						uint32_t RXFIFOFIE            :1;
						uint32_t TXFIFOEIE            :1;
						uint32_t SDMMC_MASK_0_RXFIFOEIE :1;
						uint32_t SDMMC_MASK_0_TXDAVLIE :1;
						uint32_t SDMMC_MASK_0_RXDAVLIE :1;
						uint32_t SDMMC_MASK_0_SDIOITIE :1;
						uint32_t SDMMC_MASK_0_ACKFAILIE :1;
						uint32_t SDMMC_MASK_0_ACKTIMEOUTIE :1;
						uint32_t SDMMC_MASK_0_VSWENDIE :1;
						uint32_t SDMMC_MASK_0_CKSTOPIE :1;
						uint32_t                      :1;
						uint32_t SDMMC_MASK_0_IDMABTCIE :1;
						uint32_t                      :3;
					};
					#ifdef SDMMC_MASK_1
					struct
					{
						uint32_t                      :11;
						uint32_t DABORTIE             :1;
						uint32_t                      :9;
						uint32_t BUSYD0ENDIE          :1;
						uint32_t SDMMC_MASK_1_SDIOTIE :1;
						uint32_t                      :9;
					};
					#endif
				};
				//SOOL-SDMMC_MASK-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_POWER
			struct POWER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PWRCTRL              :2;
					uint32_t SDMMC_POWER_VSWITCH  :1;
					uint32_t SDMMC_POWER_VSWITCHEN :1;
					uint32_t SDMMC_POWER_DIRPOL   :1;
					uint32_t                      :27;
			
				//SOOL-SDMMC_POWER-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_RESP
			struct RESP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CARDSTATUS           :32;
			
				//SOOL-SDMMC_RESP-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_RESPCMD
			struct RESPCMD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t RESPCMD              :6;
						uint32_t                      :26;
					};
					#ifdef SDMMC_RESPCMD_1
					struct
					{
						uint32_t CARDSTATUS0          :32;
					};
					#endif
				};
				//SOOL-SDMMC_RESPCMD-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_STA
			struct STA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t CCRCFAIL             :1;
						uint32_t DCRCFAIL             :1;
						uint32_t CTIMEOUT             :1;
						uint32_t DTIMEOUT             :1;
						uint32_t TXUNDERR             :1;
						uint32_t RXOVERR              :1;
						uint32_t CMDREND              :1;
						uint32_t CMDSENT              :1;
						uint32_t DATAEND              :1;
						uint32_t SDMMC_STA_0_DHOLD    :1;
						uint32_t DBCKEND              :1;
						uint32_t SDMMC_STA_0_CMDACT   :1;
						uint32_t SDMMC_STA_0_TXACT    :1;
						uint32_t SDMMC_STA_0_RXACT    :1;
						uint32_t TXFIFOHE             :1;
						uint32_t RXFIFOHF             :1;
						uint32_t TXFIFOF              :1;
						uint32_t RXFIFOF              :1;
						uint32_t TXFIFOE              :1;
						uint32_t RXFIFOE              :1;
						uint32_t SDMMC_STA_0_TXDAVL   :1;
						uint32_t SDMMC_STA_0_RXDAVL   :1;
						uint32_t SDIOIT               :1;
						uint32_t SDMMC_STA_0_ACKFAIL  :1;
						uint32_t SDMMC_STA_0_ACKTIMEOUT :1;
						uint32_t SDMMC_STA_0_VSWEND   :1;
						uint32_t SDMMC_STA_0_CKSTOP   :1;
						uint32_t SDMMC_STA_0_IDMATE   :1;
						uint32_t SDMMC_STA_0_IDMABTC  :1;
						uint32_t                      :3;
					};
					#ifdef SDMMC_STA_1
					struct
					{
						uint32_t                      :9;
						uint32_t SDMMC_STA_1_STBITERR :1;
						uint32_t                      :1;
						uint32_t SDMMC_STA_1_DABORT   :1;
						uint32_t SDMMC_STA_1_CPSMACT  :1;
						uint32_t SDMMC_STA_1_DPSMACT  :1;
						uint32_t                      :6;
						uint32_t SDMMC_STA_1_BUSYD0   :1;
						uint32_t SDMMC_STA_1_BUSYD0END :1;
						uint32_t                      :10;
					};
					#endif
					#ifdef SDMMC_STA_2
					struct
					{
						uint32_t                      :12;
						uint32_t DPSMACT              :1;
						uint32_t CPSMACT              :1;
						uint32_t                      :18;
					};
					#endif
				};
				//SOOL-SDMMC_STA-DECLARATION
			};
			#endif
			
			#ifdef SDMMC_VERR
			struct VERR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MINREV               :4;
					uint32_t MAJREV               :4;
					uint32_t                      :24;
			
				//SOOL-SDMMC_VERR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					POWER_TypeDef POWER; // @0x000
					CLKCR_TypeDef CLKCR; // @0x004
					ARG_TypeDef ARG;     // @0x008
					CMD_TypeDef CMD;     // @0x00c
					RESPCMD_TypeDef RESPCMD; // @0x010
					RESP_TypeDef RESP1;  // @0x014
					RESP_TypeDef RESP2;  // @0x018
					RESP_TypeDef RESP3;  // @0x01c
					RESP_TypeDef RESP4;  // @0x020
					DTIMER_TypeDef DTIMER; // @0x024
					DLEN_TypeDef DLEN;   // @0x028
					DCTRL_TypeDef DCTRL; // @0x02c
					DCOUNT_TypeDef DCOUNT; // @0x030
					STA_TypeDef STA;     // @0x034
					ICR_TypeDef ICR;     // @0x038
					MASK_TypeDef MASK;   // @0x03c
					SDMMC_MAP0_ACKTIME;  // @0x040
					__SOOL_PERIPH_PADDING_4;
					SDMMC_MAP0_FIFOCNT;  // @0x048
					__SOOL_PERIPH_PADDING_4;
					SDMMC_MAP0_IDMACTRL; // @0x050
					SDMMC_MAP0_IDMABSIZE; // @0x054
					SDMMC_MAP0_IDMABASE0; // @0x058
					SDMMC_MAP0_IDMABASE1; // @0x05c
					__SOOL_PERIPH_PADDING_32;
					FIFO_TypeDef FIFO;   // @0x080
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					SDMMC_MAP0_VERR;     // @0x3f4
					__SOOL_PERIPH_PADDING_4;
					SDMMC_MAP0_IPVR;     // @0x3fc
				};
			};
			private:
			SDMMC() = delete;
			//SOOL-SDMMC-DECLARATION
		};
		
		//region instances
#if defined(STM32F7     ) 
#define SDMMC1_BASE_ADDR ((uint32_t)0x40012C00U)
#endif

#if defined(STM32H7     ) 
#define SDMMC1_BASE_ADDR ((uint32_t)0x52007000U)
#define SDMMC2_BASE_ADDR ((uint32_t)0x48022400U)
#endif

#if defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) 
#define SDMMC1_BASE_ADDR ((uint32_t)0x40012800U)
#endif

#if defined(STM32L4P    ) 
#define SDMMC1_BASE_ADDR ((uint32_t)0x50062400U)
#endif

#if defined(STM32F722xx ) || defined(STM32F723xx ) || defined(STM32F732xx ) || defined(STM32F733xx ) ||\
    defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) 
#define SDMMC2_BASE_ADDR ((uint32_t)0x40011C00U)
#endif

#ifdef SDMMC1_BASE_ADDR
volatile class SDMMC * const SDMMC1 = reinterpret_cast<class SDMMC* const>(SDMMC1_BASE_ADDR);
#endif
#ifdef SDMMC2_BASE_ADDR
volatile class SDMMC * const SDMMC2 = reinterpret_cast<class SDMMC* const>(SDMMC2_BASE_ADDR);
#endif
//endregion

//SOOL-SDMMC-DEFINES
//SOOL-SDMMC-DEFINITION
	};
};//region undef
#undef SDMMC_CLKCR_0_DDR
#undef SDMMC_CLKCR_0_BUSSPEED
#undef SDMMC_CLKCR_0_SELCLKRX
#undef SDMMC_CMD_0_DTHOLD
#undef SDMMC_CMD_0_BOOTMODE
#undef SDMMC_CMD_0_BOOTEN
#undef SDMMC_CMD_0_CMDSUSPEND
#undef SDMMC_DCTRL_0_BOOTACKEN
#undef SDMMC_DCTRL_0_FIFORST
#undef SDMMC_ICR_0_DHOLDC
#undef SDMMC_ICR_0_DABORTC
#undef SDMMC_ICR_0_BUSYD0ENDC
#undef SDMMC_ICR_0_ACKFAILC
#undef SDMMC_ICR_0_ACKTIMEOUTC
#undef SDMMC_ICR_0_VSWENDC
#undef SDMMC_ICR_0_CKSTOPC
#undef SDMMC_ICR_0_IDMATEC
#undef SDMMC_ICR_0_IDMABTCC
#undef SDMMC_MASK_0_DHOLDIE
#undef SDMMC_MASK_0_ACKFAILIE
#undef SDMMC_MASK_0_ACKTIMEOUTIE
#undef SDMMC_MASK_0_VSWENDIE
#undef SDMMC_MASK_0_CKSTOPIE
#undef SDMMC_MASK_0_IDMABTCIE
#undef SDMMC_POWER_VSWITCH
#undef SDMMC_POWER_VSWITCHEN
#undef SDMMC_POWER_DIRPOL
#undef SDMMC_STA_0_DHOLD
#undef SDMMC_STA_0_ACKFAIL
#undef SDMMC_STA_0_ACKTIMEOUT
#undef SDMMC_STA_0_VSWEND
#undef SDMMC_STA_0_CKSTOP
#undef SDMMC_STA_0_IDMATE
#undef SDMMC_STA_0_IDMABTC
#undef SDMMC_STA_1_DABORT
#undef SDMMC_STA_1_BUSYD0
#undef SDMMC_STA_1_BUSYD0END
#undef SDMMC_MAP0_ACKTIME
#undef SDMMC_MAP0_IDMACTRL
#undef SDMMC_MAP0_IDMABSIZE
#undef SDMMC_MAP0_IDMABASE0
#undef SDMMC_MAP0_IDMABASE1
#undef SDMMC_CLKCR_0_CLKDIV
#undef SDMMC_CLKCR_0_CLKEN
#undef SDMMC_CLKCR_0_PWRSAV
#undef SDMMC_CLKCR_0_BYPASS
#undef SDMMC_CLKCR_0_WIDBUS
#undef SDMMC_CLKCR_0_NEGEDGE
#undef SDMMC_CLKCR_0_HWFC_EN
#undef SDMMC_CMD_0_WAITRESP
#undef SDMMC_CMD_0_WAITINT
#undef SDMMC_CMD_0_WAITPEND
#undef SDMMC_CMD_0_CPSMEN
#undef SDMMC_CMD_0_SDIOSUSPEND
#undef SDMMC_DCTRL_0_DTMODE
#undef SDMMC_DCTRL_0_DMAEN
#undef SDMMC_MASK_0_CMDACTIE
#undef SDMMC_MASK_0_TXACTIE
#undef SDMMC_MASK_0_RXACTIE
#undef SDMMC_MASK_0_TXFIFOFIE
#undef SDMMC_MASK_0_RXFIFOEIE
#undef SDMMC_MASK_0_TXDAVLIE
#undef SDMMC_MASK_0_RXDAVLIE
#undef SDMMC_STA_0_CMDACT
#undef SDMMC_STA_0_TXACT
#undef SDMMC_STA_0_RXACT
#undef SDMMC_STA_0_TXDAVL
#undef SDMMC_STA_0_RXDAVL
#undef SDMMC_MAP0_FIFOCNT
#undef SDMMC_STA_1_STBITERR
#undef SDMMC_MASK_1_SDIOTIE
#undef SDMMC_STA_1_CPSMACT
#undef SDMMC_STA_1_DPSMACT
#undef SDMMC_MAP0_IPVR
#undef SDMMC_MASK_0_SDIOITIE
#undef SDMMC_MAP0_VERR
//endregion
#endif
#endif
