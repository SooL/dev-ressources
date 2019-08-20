#ifndef __SOOL_FDCAN_H
#define __SOOL_FDCAN_H

#include "peripheral_include.h"
//SOOL-FDCAN-INCLUDES
#if defined(STM32H7     ) 
//region defines

#define FDCAN_ClockCalibrationUnit_CCFG
#define FDCAN_ClockCalibrationUnit_CREL
#define FDCAN_ClockCalibrationUnit_CSTAT
#define FDCAN_ClockCalibrationUnit_CWD
#define FDCAN_ClockCalibrationUnit_IE
#define FDCAN_ClockCalibrationUnit_IR
#define FDCAN_Global_CCCR
#define FDCAN_Global_CREL
#define FDCAN_Global_DBTP
#define FDCAN_Global_ECR
#define FDCAN_Global_ENDN
#define FDCAN_Global_GFC
#define FDCAN_Global_HPMS
#define FDCAN_Global_IE
#define FDCAN_Global_ILE
#define FDCAN_Global_ILS
#define FDCAN_Global_IR
#define FDCAN_Global_NBTP
#define FDCAN_Global_NDAT1
#define FDCAN_Global_NDAT2
#define FDCAN_Global_PSR
#define FDCAN_Global_RWD
#define FDCAN_Global_RXBC
#define FDCAN_Global_RXESC
#define FDCAN_Global_RXF0A
#define FDCAN_Global_RXF0C
#define FDCAN_Global_RXF0S
#define FDCAN_Global_RXF1A
#define FDCAN_Global_RXF1C
#define FDCAN_Global_RXF1S
#define FDCAN_Global_SIDFC
#define FDCAN_Global_TDCR
#define FDCAN_Global_TEST
#define FDCAN_Global_TOCC
#define FDCAN_Global_TOCV
#define FDCAN_Global_TSCC
#define FDCAN_Global_TSCV
#define FDCAN_Global_TXBAR
#define FDCAN_Global_TXBC
#define FDCAN_Global_TXBCF
#define FDCAN_Global_TXBCIE
#define FDCAN_Global_TXBCR
#define FDCAN_Global_TXBRP
#define FDCAN_Global_TXBTIE
#define FDCAN_Global_TXBTO
#define FDCAN_Global_TXEFA
#define FDCAN_Global_TXEFC
#define FDCAN_Global_TXEFS
#define FDCAN_Global_TXESC
#define FDCAN_Global_TXFQS
#define FDCAN_Global_XIDAM
#define FDCAN_Global_XIDFC
#define TTCAN_TTCPT
#define TTCAN_TTCSM
#define TTCAN_TTCTC
#define TTCAN_TTGTP
#define TTCAN_TTIE
#define TTCAN_TTILS
#define TTCAN_TTIR
#define TTCAN_TTLGT
#define TTCAN_TTMLM
#define TTCAN_TTOCF
#define TTCAN_TTOCN
#define TTCAN_TTOST
#define TTCAN_TTRMC
#define TTCAN_TTTMC
#define TTCAN_TTTMK
#define TTCAN_TTTS
#define TTCAN_TURCF
#define TTCAN_TURNA

//endregion

namespace sool
{
	namespace core
	{
		class FDCAN_ClockCalibrationUnit
		{
			//SOOL-FDCAN_ClockCalibrationUnit-ENUMS
			
			public :
			
			#ifdef FDCAN_ClockCalibrationUnit_CREL
			struct CREL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DAY                  :8;
					uint32_t MON                  :8;
					uint32_t YEAR                 :4;
					uint32_t SUBSTEP              :4;
					uint32_t STEP                 :4;
					uint32_t REL                  :4;
			
				//SOOL-FDCAN_ClockCalibrationUnit_CREL-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_ClockCalibrationUnit_IE
			struct IE_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RF0NE                :1;
					uint32_t RF0WE                :1;
					uint32_t RF0FE                :1;
					uint32_t RF0LE                :1;
					uint32_t RF1NE                :1;
					uint32_t RF1WE                :1;
					uint32_t RF1FE                :1;
					uint32_t RF1LE                :1;
					uint32_t HPME                 :1;
					uint32_t TCE                  :1;
					uint32_t TCFE                 :1;
					uint32_t TFEE                 :1;
					uint32_t TEFNE                :1;
					uint32_t TEFWE                :1;
					uint32_t TEFFE                :1;
					uint32_t TEFLE                :1;
					uint32_t TSWE                 :1;
					uint32_t MRAFE                :1;
					uint32_t TOOE                 :1;
					uint32_t DRXE                 :1;
					uint32_t BECE                 :1;
					uint32_t BEUE                 :1;
					uint32_t ELOE                 :1;
					uint32_t EPE                  :1;
					uint32_t EWE                  :1;
					uint32_t BOE                  :1;
					uint32_t WDIE                 :1;
					uint32_t PEAE                 :1;
					uint32_t PEDE                 :1;
					uint32_t ARAE                 :1;
					uint32_t                      :2;
			
				//SOOL-FDCAN_ClockCalibrationUnit_IE-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_ClockCalibrationUnit_IR
			struct IR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RF0N                 :1;
					uint32_t RF0W                 :1;
					uint32_t RF0F                 :1;
					uint32_t RF0L                 :1;
					uint32_t RF1N                 :1;
					uint32_t RF1W                 :1;
					uint32_t RF1F                 :1;
					uint32_t RF1L                 :1;
					uint32_t HPM                  :1;
					uint32_t TC                   :1;
					uint32_t TCF                  :1;
					uint32_t TFE                  :1;
					uint32_t TEFN                 :1;
					uint32_t TEFW                 :1;
					uint32_t TEFF                 :1;
					uint32_t TEFL                 :1;
					uint32_t TSW                  :1;
					uint32_t MRAF                 :1;
					uint32_t TOO                  :1;
					uint32_t DRX                  :1;
					uint32_t                      :2;
					uint32_t ELO                  :1;
					uint32_t EP                   :1;
					uint32_t EW                   :1;
					uint32_t BO                   :1;
					uint32_t WDI                  :1;
					uint32_t PEA                  :1;
					uint32_t PED                  :1;
					uint32_t ARA                  :1;
					uint32_t                      :2;
			
				//SOOL-FDCAN_ClockCalibrationUnit_IR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CREL_TypeDef CREL;   // @0x000
					uint32_t CCFG;       // @0x004
					uint32_t CSTAT;      // @0x008
					uint32_t CWD;        // @0x00c
					IR_TypeDef IR;       // @0x010
					IE_TypeDef IE;       // @0x014
				};
			};
			private:
			FDCAN_ClockCalibrationUnit() = delete;
			//SOOL-FDCAN_ClockCalibrationUnit-DECLARATION
		};
		
		
		class FDCAN_Global
		{
			//SOOL-FDCAN_Global-ENUMS
			
			public :
			
			#ifdef FDCAN_Global_CCCR
			struct CCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INIT                 :1;
					uint32_t CCE                  :1;
					uint32_t ASM                  :1;
					uint32_t CSA                  :1;
					uint32_t CSR                  :1;
					uint32_t MON                  :1;
					uint32_t DAR                  :1;
					uint32_t TEST                 :1;
					uint32_t FDOE                 :1;
					uint32_t BRSE                 :1;
					uint32_t                      :2;
					uint32_t PXHD                 :1;
					uint32_t EFBI                 :1;
					uint32_t TXP                  :1;
					uint32_t NISO                 :1;
					uint32_t                      :16;
			
				//SOOL-FDCAN_Global_CCCR-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_DBTP
			struct DBTP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DSJW                 :4;
					uint32_t DTSEG2               :4;
					uint32_t DTSEG1               :4;
					uint32_t                      :4;
					uint32_t DBRP                 :5;
					uint32_t                      :2;
					uint32_t TDC                  :1;
					uint32_t                      :8;
			
				//SOOL-FDCAN_Global_DBTP-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_ECR
			struct ECR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TEC                  :4;
					uint32_t                      :4;
					uint32_t REC                  :7;
					uint32_t RP                   :1;
					uint32_t CEL                  :8;
					uint32_t                      :8;
			
				//SOOL-FDCAN_Global_ECR-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_ENDN
			struct ENDN_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ETV                  :32;
			
				//SOOL-FDCAN_Global_ENDN-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_GFC
			struct GFC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RRFE                 :1;
					uint32_t RRFS                 :1;
					uint32_t ANFE                 :2;
					uint32_t ANFS                 :2;
					uint32_t                      :26;
			
				//SOOL-FDCAN_Global_GFC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_HPMS
			struct HPMS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BIDX                 :6;
					uint32_t MSI                  :2;
					uint32_t FIDX                 :7;
					uint32_t FLST                 :1;
					uint32_t                      :16;
			
				//SOOL-FDCAN_Global_HPMS-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_ILE
			struct ILE_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EINT0                :1;
					uint32_t EINT1                :1;
					uint32_t                      :30;
			
				//SOOL-FDCAN_Global_ILE-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_ILS
			struct ILS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RF0NL                :1;
					uint32_t RF0WL                :1;
					uint32_t RF0FL                :1;
					uint32_t RF0LL                :1;
					uint32_t RF1NL                :1;
					uint32_t RF1WL                :1;
					uint32_t RF1FL                :1;
					uint32_t RF1LL                :1;
					uint32_t HPML                 :1;
					uint32_t TCL                  :1;
					uint32_t TCFL                 :1;
					uint32_t TFEL                 :1;
					uint32_t TEFNL                :1;
					uint32_t TEFWL                :1;
					uint32_t TEFFL                :1;
					uint32_t TEFLL                :1;
					uint32_t TSWL                 :1;
					uint32_t MRAFE                :1;
					uint32_t TOOE                 :1;
					uint32_t DRXE                 :1;
					uint32_t BECE                 :1;
					uint32_t BEUE                 :1;
					uint32_t ELOE                 :1;
					uint32_t EPE                  :1;
					uint32_t EWE                  :1;
					uint32_t BOE                  :1;
					uint32_t WDIE                 :1;
					uint32_t PEAE                 :1;
					uint32_t PEDE                 :1;
					uint32_t ARAE                 :1;
					uint32_t                      :2;
			
				//SOOL-FDCAN_Global_ILS-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_NBTP
			struct NBTP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NTSEG2               :7;
					uint32_t                      :1;
					uint32_t NTSEG1               :8;
					uint32_t NBRP                 :9;
					uint32_t NSJW                 :7;
			
				//SOOL-FDCAN_Global_NBTP-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_NDAT1
			struct NDAT1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ND0                  :1;
					uint32_t ND1                  :1;
					uint32_t ND2                  :1;
					uint32_t ND3                  :1;
					uint32_t ND4                  :1;
					uint32_t ND5                  :1;
					uint32_t ND6                  :1;
					uint32_t ND7                  :1;
					uint32_t ND8                  :1;
					uint32_t ND9                  :1;
					uint32_t ND10                 :1;
					uint32_t ND11                 :1;
					uint32_t ND12                 :1;
					uint32_t ND13                 :1;
					uint32_t ND14                 :1;
					uint32_t ND15                 :1;
					uint32_t ND16                 :1;
					uint32_t ND17                 :1;
					uint32_t ND18                 :1;
					uint32_t ND19                 :1;
					uint32_t ND20                 :1;
					uint32_t ND21                 :1;
					uint32_t ND22                 :1;
					uint32_t ND23                 :1;
					uint32_t ND24                 :1;
					uint32_t ND25                 :1;
					uint32_t ND26                 :1;
					uint32_t ND27                 :1;
					uint32_t ND28                 :1;
					uint32_t ND29                 :1;
					uint32_t ND30                 :1;
					uint32_t ND31                 :1;
			
				//SOOL-FDCAN_Global_NDAT1-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_NDAT2
			struct NDAT2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ND32                 :1;
					uint32_t ND33                 :1;
					uint32_t ND34                 :1;
					uint32_t ND35                 :1;
					uint32_t ND36                 :1;
					uint32_t ND37                 :1;
					uint32_t ND38                 :1;
					uint32_t ND39                 :1;
					uint32_t ND40                 :1;
					uint32_t ND41                 :1;
					uint32_t ND42                 :1;
					uint32_t ND43                 :1;
					uint32_t ND44                 :1;
					uint32_t ND45                 :1;
					uint32_t ND46                 :1;
					uint32_t ND47                 :1;
					uint32_t ND48                 :1;
					uint32_t ND49                 :1;
					uint32_t ND50                 :1;
					uint32_t ND51                 :1;
					uint32_t ND52                 :1;
					uint32_t ND53                 :1;
					uint32_t ND54                 :1;
					uint32_t ND55                 :1;
					uint32_t ND56                 :1;
					uint32_t ND57                 :1;
					uint32_t ND58                 :1;
					uint32_t ND59                 :1;
					uint32_t ND60                 :1;
					uint32_t ND61                 :1;
					uint32_t ND62                 :1;
					uint32_t ND63                 :1;
			
				//SOOL-FDCAN_Global_NDAT2-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_PSR
			struct PSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LEC                  :3;
					uint32_t ACT                  :2;
					uint32_t EP                   :1;
					uint32_t EW                   :1;
					uint32_t BO                   :1;
					uint32_t DLEC                 :3;
					uint32_t RESI                 :1;
					uint32_t RBRS                 :1;
					uint32_t REDL                 :1;
					uint32_t PXE                  :1;
					uint32_t                      :1;
					uint32_t TDCV                 :7;
					uint32_t                      :9;
			
				//SOOL-FDCAN_Global_PSR-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RWD
			struct RWD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t WDC                  :4;
					uint32_t WDV                  :4;
					uint32_t                      :24;
			
				//SOOL-FDCAN_Global_RWD-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RXBC
			struct RXBC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t RBSA                 :6;
					uint32_t                      :24;
			
				//SOOL-FDCAN_Global_RXBC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RXESC
			struct RXESC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t F0DS                 :3;
					uint32_t                      :1;
					uint32_t F1DS                 :3;
					uint32_t                      :1;
					uint32_t RBDS                 :3;
					uint32_t                      :21;
			
				//SOOL-FDCAN_Global_RXESC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RXF0A
			struct RXF0A_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t F0AI                 :6;
					uint32_t                      :26;
			
				//SOOL-FDCAN_Global_RXF0A-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RXF0C
			struct RXF0C_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t F0SA                 :14;
					uint32_t F0S                  :7;
					uint32_t                      :1;
					uint32_t F0WM                 :7;
					uint32_t F0OM                 :1;
			
				//SOOL-FDCAN_Global_RXF0C-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RXF0S
			struct RXF0S_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t F0FL                 :7;
					uint32_t                      :1;
					uint32_t F0GI                 :6;
					uint32_t                      :2;
					uint32_t F0PI                 :6;
					uint32_t                      :2;
					uint32_t F0F                  :1;
					uint32_t RF0L                 :1;
					uint32_t                      :6;
			
				//SOOL-FDCAN_Global_RXF0S-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RXF1A
			struct RXF1A_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t F1AI                 :6;
					uint32_t                      :26;
			
				//SOOL-FDCAN_Global_RXF1A-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RXF1C
			struct RXF1C_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t F1SA                 :6;
					uint32_t                      :8;
					uint32_t F1S                  :7;
					uint32_t                      :1;
					uint32_t F1WM                 :7;
					uint32_t F1OM                 :1;
			
				//SOOL-FDCAN_Global_RXF1C-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_RXF1S
			struct RXF1S_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t F1FL                 :7;
					uint32_t                      :1;
					uint32_t F1GI                 :6;
					uint32_t                      :2;
					uint32_t F1PI                 :6;
					uint32_t                      :2;
					uint32_t F1F                  :1;
					uint32_t RF1L                 :1;
					uint32_t                      :6;
			
				//SOOL-FDCAN_Global_RXF1S-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_SIDFC
			struct SIDFC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t FLSSA                :14;
					uint32_t LSS                  :8;
					uint32_t                      :8;
			
				//SOOL-FDCAN_Global_SIDFC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TDCR
			struct TDCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TDCF                 :7;
					uint32_t                      :1;
					uint32_t TDCO                 :7;
					uint32_t                      :17;
			
				//SOOL-FDCAN_Global_TDCR-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TEST
			struct TEST_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t LBCK                 :1;
					uint32_t TX                   :2;
					uint32_t RX                   :1;
					uint32_t                      :24;
			
				//SOOL-FDCAN_Global_TEST-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TOCC
			struct TOCC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ETOC                 :1;
					uint32_t TOS                  :2;
					uint32_t                      :13;
					uint32_t TOP                  :16;
			
				//SOOL-FDCAN_Global_TOCC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TOCV
			struct TOCV_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TOC                  :16;
					uint32_t                      :16;
			
				//SOOL-FDCAN_Global_TOCV-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TSCC
			struct TSCC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSS                  :2;
					uint32_t                      :14;
					uint32_t TCP                  :4;
					uint32_t                      :12;
			
				//SOOL-FDCAN_Global_TSCC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TSCV
			struct TSCV_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSC                  :16;
					uint32_t                      :16;
			
				//SOOL-FDCAN_Global_TSCV-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXBAR
			struct TXBAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AR                   :32;
			
				//SOOL-FDCAN_Global_TXBAR-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXBC
			struct TXBC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t TBSA                 :6;
					uint32_t                      :8;
					uint32_t NDTB                 :6;
					uint32_t                      :2;
					uint32_t TFQS                 :6;
					uint32_t TFQM                 :1;
					uint32_t                      :1;
			
				//SOOL-FDCAN_Global_TXBC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXBCF
			struct TXBCF_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CF                   :32;
			
				//SOOL-FDCAN_Global_TXBCF-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXBCIE
			struct TXBCIE_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CF                   :32;
			
				//SOOL-FDCAN_Global_TXBCIE-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXBCR
			struct TXBCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CR                   :32;
			
				//SOOL-FDCAN_Global_TXBCR-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXBRP
			struct TXBRP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TRP                  :32;
			
				//SOOL-FDCAN_Global_TXBRP-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXBTIE
			struct TXBTIE_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TIE                  :32;
			
				//SOOL-FDCAN_Global_TXBTIE-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXBTO
			struct TXBTO_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TO                   :32;
			
				//SOOL-FDCAN_Global_TXBTO-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXEFA
			struct TXEFA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EFAI                 :5;
					uint32_t                      :27;
			
				//SOOL-FDCAN_Global_TXEFA-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXEFC
			struct TXEFC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t EFSA                 :14;
					uint32_t EFS                  :6;
					uint32_t                      :2;
					uint32_t EFWM                 :6;
					uint32_t                      :2;
			
				//SOOL-FDCAN_Global_TXEFC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXEFS
			struct TXEFS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EFFL                 :6;
					uint32_t                      :2;
					uint32_t EFGI                 :5;
					uint32_t                      :3;
					uint32_t EFPI                 :5;
					uint32_t                      :3;
					uint32_t EFF                  :1;
					uint32_t TEFL                 :1;
					uint32_t                      :6;
			
				//SOOL-FDCAN_Global_TXEFS-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXESC
			struct TXESC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TBDS                 :3;
					uint32_t                      :29;
			
				//SOOL-FDCAN_Global_TXESC-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_TXFQS
			struct TXFQS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TFFL                 :6;
					uint32_t                      :2;
					uint32_t TFGI                 :5;
					uint32_t                      :3;
					uint32_t TFQPI                :5;
					uint32_t TFQF                 :1;
					uint32_t                      :10;
			
				//SOOL-FDCAN_Global_TXFQS-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_XIDAM
			struct XIDAM_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EIDM                 :29;
					uint32_t                      :3;
			
				//SOOL-FDCAN_Global_XIDAM-DECLARATION
			};
			#endif
			
			#ifdef FDCAN_Global_XIDFC
			struct XIDFC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t FLESA                :14;
					uint32_t LSE                  :8;
					uint32_t                      :8;
			
				//SOOL-FDCAN_Global_XIDFC-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					uint32_t CREL;       // @0x000
					ENDN_TypeDef ENDN;   // @0x004
					__SOOL_PERIPH_PADDING_4;
					DBTP_TypeDef DBTP;   // @0x00c
					TEST_TypeDef TEST;   // @0x010
					RWD_TypeDef RWD;     // @0x014
					CCCR_TypeDef CCCR;   // @0x018
					NBTP_TypeDef NBTP;   // @0x01c
					TSCC_TypeDef TSCC;   // @0x020
					TSCV_TypeDef TSCV;   // @0x024
					TOCC_TypeDef TOCC;   // @0x028
					TOCV_TypeDef TOCV;   // @0x02c
					__SOOL_PERIPH_PADDING_16;
					ECR_TypeDef ECR;     // @0x040
					PSR_TypeDef PSR;     // @0x044
					TDCR_TypeDef TDCR;   // @0x048
					__SOOL_PERIPH_PADDING_4;
					uint32_t IR;         // @0x050
					uint32_t IE;         // @0x054
					ILS_TypeDef ILS;     // @0x058
					ILE_TypeDef ILE;     // @0x05c
					__SOOL_PERIPH_PADDING_32;
					GFC_TypeDef GFC;     // @0x080
					SIDFC_TypeDef SIDFC; // @0x084
					XIDFC_TypeDef XIDFC; // @0x088
					__SOOL_PERIPH_PADDING_4;
					XIDAM_TypeDef XIDAM; // @0x090
					HPMS_TypeDef HPMS;   // @0x094
					NDAT1_TypeDef NDAT1; // @0x098
					NDAT2_TypeDef NDAT2; // @0x09c
					RXF0C_TypeDef RXF0C; // @0x0a0
					RXF0S_TypeDef RXF0S; // @0x0a4
					RXF0A_TypeDef RXF0A; // @0x0a8
					RXBC_TypeDef RXBC;   // @0x0ac
					RXF1C_TypeDef RXF1C; // @0x0b0
					RXF1S_TypeDef RXF1S; // @0x0b4
					RXF1A_TypeDef RXF1A; // @0x0b8
					RXESC_TypeDef RXESC; // @0x0bc
					TXBC_TypeDef TXBC;   // @0x0c0
					TXFQS_TypeDef TXFQS; // @0x0c4
					TXESC_TypeDef TXESC; // @0x0c8
					TXBRP_TypeDef TXBRP; // @0x0cc
					TXBAR_TypeDef TXBAR; // @0x0d0
					TXBCR_TypeDef TXBCR; // @0x0d4
					TXBTO_TypeDef TXBTO; // @0x0d8
					TXBCF_TypeDef TXBCF; // @0x0dc
					TXBTIE_TypeDef TXBTIE; // @0x0e0
					TXBCIE_TypeDef TXBCIE; // @0x0e4
					__SOOL_PERIPH_PADDING_8;
					TXEFC_TypeDef TXEFC; // @0x0f0
					TXEFS_TypeDef TXEFS; // @0x0f4
					TXEFA_TypeDef TXEFA; // @0x0f8
				};
			};
			private:
			FDCAN_Global() = delete;
			//SOOL-FDCAN_Global-DECLARATION
		};
		
		
		class TTCAN
		{
			//SOOL-TTCAN-ENUMS
			
			public :
			
			#ifdef TTCAN_TTCPT
			struct TTCPT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CCV                  :6;
					uint32_t                      :10;
					uint32_t SWV                  :16;
			
				//SOOL-TTCAN_TTCPT-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTCSM
			struct TTCSM_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CSM                  :16;
					uint32_t                      :16;
			
				//SOOL-TTCAN_TTCSM-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTCTC
			struct TTCTC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CT                   :16;
					uint32_t CC                   :6;
					uint32_t                      :10;
			
				//SOOL-TTCAN_TTCTC-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTGTP
			struct TTGTP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TP                   :16;
					uint32_t CTP                  :16;
			
				//SOOL-TTCAN_TTGTP-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTIE
			struct TTIE_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SBCE                 :1;
					uint32_t SMCE                 :1;
					uint32_t CSME                 :1;
					uint32_t SOGE                 :1;
					uint32_t RTMIE                :1;
					uint32_t TTMIE                :1;
					uint32_t SWEE                 :1;
					uint32_t GTWE                 :1;
					uint32_t GTDE                 :1;
					uint32_t GTEE                 :1;
					uint32_t TXUE                 :1;
					uint32_t TXOE                 :1;
					uint32_t SE1E                 :1;
					uint32_t SE2E                 :1;
					uint32_t ELCE                 :1;
					uint32_t IWTE                 :1;
					uint32_t WTE                  :1;
					uint32_t AWE                  :1;
					uint32_t CERE                 :1;
					uint32_t                      :13;
			
				//SOOL-TTCAN_TTIE-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTILS
			struct TTILS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SBCS                 :1;
					uint32_t SMCS                 :1;
					uint32_t CSMS                 :1;
					uint32_t SOGS                 :1;
					uint32_t RTMIS                :1;
					uint32_t TTMIS                :1;
					uint32_t SWES                 :1;
					uint32_t GTWS                 :1;
					uint32_t GTDS                 :1;
					uint32_t GTES                 :1;
					uint32_t TXUS                 :1;
					uint32_t TXOS                 :1;
					uint32_t SE1S                 :1;
					uint32_t SE2S                 :1;
					uint32_t ELCS                 :1;
					uint32_t IWTS                 :1;
					uint32_t WTS                  :1;
					uint32_t AWS                  :1;
					uint32_t CERS                 :1;
					uint32_t                      :13;
			
				//SOOL-TTCAN_TTILS-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTIR
			struct TTIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SBC                  :1;
					uint32_t SMC                  :1;
					uint32_t CSM                  :1;
					uint32_t SOG                  :1;
					uint32_t RTMI                 :1;
					uint32_t TTMI                 :1;
					uint32_t SWE                  :1;
					uint32_t GTW                  :1;
					uint32_t GTD                  :1;
					uint32_t GTE                  :1;
					uint32_t TXU                  :1;
					uint32_t TXO                  :1;
					uint32_t SE1                  :1;
					uint32_t SE2                  :1;
					uint32_t ELC                  :1;
					uint32_t IWT                  :1;
					uint32_t WT                   :1;
					uint32_t AW                   :1;
					uint32_t CER                  :1;
					uint32_t                      :13;
			
				//SOOL-TTCAN_TTIR-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTLGT
			struct TTLGT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LT                   :16;
					uint32_t GT                   :16;
			
				//SOOL-TTCAN_TTLGT-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTMLM
			struct TTMLM_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CCM                  :6;
					uint32_t CSS                  :2;
					uint32_t TXEW                 :4;
					uint32_t                      :4;
					uint32_t ENTT                 :12;
					uint32_t                      :4;
			
				//SOOL-TTCAN_TTMLM-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTOCF
			struct TTOCF_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OM                   :2;
					uint32_t                      :1;
					uint32_t GEN                  :1;
					uint32_t TM                   :1;
					uint32_t LDSDL                :3;
					uint32_t IRTO                 :7;
					uint32_t EECS                 :1;
					uint32_t AWL                  :8;
					uint32_t EGTF                 :1;
					uint32_t ECC                  :1;
					uint32_t EVTP                 :1;
					uint32_t                      :5;
			
				//SOOL-TTCAN_TTOCF-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTOCN
			struct TTOCN_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SGT                  :1;
					uint32_t ECS                  :1;
					uint32_t SWP                  :1;
					uint32_t SWS                  :2;
					uint32_t RTIE                 :1;
					uint32_t TMC                  :2;
					uint32_t TTIE                 :1;
					uint32_t GCS                  :1;
					uint32_t FGP                  :1;
					uint32_t TMG                  :1;
					uint32_t NIG                  :1;
					uint32_t ESCN                 :1;
					uint32_t                      :1;
					uint32_t LCKC                 :1;
					uint32_t                      :16;
			
				//SOOL-TTCAN_TTOCN-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTOST
			struct TTOST_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EL                   :2;
					uint32_t MS                   :2;
					uint32_t SYS                  :2;
					uint32_t QGTP                 :1;
					uint32_t QCS                  :1;
					uint32_t RTO                  :8;
					uint32_t                      :6;
					uint32_t WGTD                 :1;
					uint32_t GFI                  :1;
					uint32_t TMP                  :3;
					uint32_t GSI                  :1;
					uint32_t WFE                  :1;
					uint32_t AWE                  :1;
					uint32_t WECS                 :1;
					uint32_t SPL                  :1;
			
				//SOOL-TTCAN_TTOST-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTRMC
			struct TTRMC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RID                  :29;
					uint32_t                      :1;
					uint32_t XTD                  :1;
					uint32_t RMPS                 :1;
			
				//SOOL-TTCAN_TTRMC-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTTMC
			struct TTTMC_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t TMSA                 :14;
					uint32_t TME                  :7;
					uint32_t                      :9;
			
				//SOOL-TTCAN_TTTMC-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTTMK
			struct TTTMK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TM                   :16;
					uint32_t TICC                 :7;
					uint32_t                      :8;
					uint32_t LCKM                 :1;
			
				//SOOL-TTCAN_TTTMK-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TTTS
			struct TTTS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SWTSEL               :2;
					uint32_t                      :2;
					uint32_t EVTSEL               :2;
					uint32_t                      :26;
			
				//SOOL-TTCAN_TTTS-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TURCF
			struct TURCF_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NCL                  :16;
					uint32_t DC                   :14;
					uint32_t                      :1;
					uint32_t ELT                  :1;
			
				//SOOL-TTCAN_TURCF-DECLARATION
			};
			#endif
			
			#ifdef TTCAN_TURNA
			struct TURNA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NAV                  :18;
					uint32_t                      :14;
			
				//SOOL-TTCAN_TURNA-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					TTTMC_TypeDef TTTMC; // @0x000
					TTRMC_TypeDef TTRMC; // @0x004
					TTOCF_TypeDef TTOCF; // @0x008
					TTMLM_TypeDef TTMLM; // @0x00c
					TURCF_TypeDef TURCF; // @0x010
					TTOCN_TypeDef TTOCN; // @0x014
					TTGTP_TypeDef TTGTP; // @0x018
					TTTMK_TypeDef TTTMK; // @0x01c
					TTIR_TypeDef TTIR;   // @0x020
					TTIE_TypeDef TTIE;   // @0x024
					TTILS_TypeDef TTILS; // @0x028
					TTOST_TypeDef TTOST; // @0x02c
					TURNA_TypeDef TURNA; // @0x030
					TTLGT_TypeDef TTLGT; // @0x034
					TTCTC_TypeDef TTCTC; // @0x038
					TTCPT_TypeDef TTCPT; // @0x03c
					TTCSM_TypeDef TTCSM; // @0x040
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					TTTS_TypeDef TTTS;   // @0x200
				};
			};
			private:
			TTCAN() = delete;
			//SOOL-TTCAN-DECLARATION
		};
		
		//region instances
#if defined(STM32H7     ) 
#define FDCAN_CCU_BASE_ADDR ((uint32_t)0x4000A800U)
#define FDCAN1_BASE_ADDR ((uint32_t)0x4000A000U)
#define FDCAN2_BASE_ADDR ((uint32_t)0x4000A400U)
#endif

#ifdef FDCAN_CCU_BASE_ADDR
volatile class FDCAN_ClockCalibrationUnit * const FDCAN_CCU = reinterpret_cast<class FDCAN_ClockCalibrationUnit* const>(FDCAN_CCU_BASE_ADDR);
#endif
#ifdef FDCAN1_BASE_ADDR
volatile class FDCAN_Global * const FDCAN1 = reinterpret_cast<class FDCAN_Global* const>(FDCAN1_BASE_ADDR);
#endif
#ifdef FDCAN2_BASE_ADDR
volatile class FDCAN_Global * const FDCAN2 = reinterpret_cast<class FDCAN_Global* const>(FDCAN2_BASE_ADDR);
#endif
//endregion

//SOOL-FDCAN-DEFINES
//SOOL-FDCAN-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
