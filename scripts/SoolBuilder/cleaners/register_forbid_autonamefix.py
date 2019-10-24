from structure import PeripheralMapping


def setup():
	# Peripheral : CAN
	# PeripheralMapping.forbid_fix("CAN_BTR", "BTR")
	# PeripheralMapping.forbid_fix("CAN_ESR", "ESR")
	# PeripheralMapping.forbid_fix("CAN_FA1R", "FA1R")
	# PeripheralMapping.forbid_fix("CAN_FFA1R", "FFA1R")
	# PeripheralMapping.forbid_fix("CAN_FM1R", "FM1R")
	# PeripheralMapping.forbid_fix("CAN_FMR", "FMR")
	# PeripheralMapping.forbid_fix("CAN_FS1R", "FS1R")
	# PeripheralMapping.forbid_fix("CAN_IER", "IER")
	# PeripheralMapping.forbid_fix("CAN_MCR", "MCR")
	# PeripheralMapping.forbid_fix("CAN_MSR", "MSR")
	# PeripheralMapping.forbid_fix("CAN_RDH0R", "RDH0R")
	# PeripheralMapping.forbid_fix("CAN_RDH1R", "RDH1R")
	# PeripheralMapping.forbid_fix("CAN_RDL0R", "RDL0R")
	# PeripheralMapping.forbid_fix("CAN_RDL1R", "RDL1R")
	# PeripheralMapping.forbid_fix("CAN_RDT0R", "RDT0R")
	# PeripheralMapping.forbid_fix("CAN_RDT1R", "RDT1R")
	# PeripheralMapping.forbid_fix("CAN_RF0R", "RF0R")
	# PeripheralMapping.forbid_fix("CAN_RF1R", "RF1R")
	# PeripheralMapping.forbid_fix("CAN_RI0R", "RI0R")
	# PeripheralMapping.forbid_fix("CAN_RI1R", "RI1R")
	# PeripheralMapping.forbid_fix("CAN_TDH0R", "TDH0R")
	# PeripheralMapping.forbid_fix("CAN_TDH1R", "TDH1R")
	# PeripheralMapping.forbid_fix("CAN_TDH2R", "TDH2R")
	# PeripheralMapping.forbid_fix("CAN_TDL0R", "TDL0R")
	# PeripheralMapping.forbid_fix("CAN_TDL1R", "TDL1R")
	# PeripheralMapping.forbid_fix("CAN_TDL2R", "TDL2R")
	# PeripheralMapping.forbid_fix("CAN_TDT0R", "TDT0R")
	# PeripheralMapping.forbid_fix("CAN_TDT1R", "TDT1R")
	# PeripheralMapping.forbid_fix("CAN_TDT2R", "TDT2R")
	# PeripheralMapping.forbid_fix("CAN_TI0R", "TI0R")
	# PeripheralMapping.forbid_fix("CAN_TI1R", "TI1R")
	# PeripheralMapping.forbid_fix("CAN_TI2R", "TI2R")
	# PeripheralMapping.forbid_fix("CAN_TSR", "TSR")
	
	# Peripheral : CEC
	# PeripheralMapping.forbid_fix("CR", "CEC_CR")
	
	# Peripheral : DBG
	# PeripheralMapping.forbid_fix("CR", "DBGMCU_CR")
	# PeripheralMapping.forbid_fix("IDCODE", "DBGMCU_IDCODE")
	
	# Peripheral : DBGMCU
	# PeripheralMapping.forbid_fix("APB1L_FZ", "APB1_FZ")
	
	# Peripheral : DFSDM
	# PeripheralMapping.forbid_fix("DFSDM_CHCFG0R1", "CHCFG0R1")
	
	# Peripheral : DMAMUX
	# PeripheralMapping.forbid_fix("C0CR", "DMAMUX_C0CR")
	# PeripheralMapping.forbid_fix("C1CR", "DMAMUX_C1CR")
	# PeripheralMapping.forbid_fix("C2CR", "DMAMUX_C2CR")
	# PeripheralMapping.forbid_fix("C3CR", "DMAMUX_C3CR")
	# PeripheralMapping.forbid_fix("C4CR", "DMAMUX_C4CR")
	# PeripheralMapping.forbid_fix("C5CR", "DMAMUX_C5CR")
	# PeripheralMapping.forbid_fix("C6CR", "DMAMUX_C6CR")
	# PeripheralMapping.forbid_fix("RG0CR", "DMAMUX_RG0CR")
	# PeripheralMapping.forbid_fix("RG1CR", "DMAMUX_RG1CR")
	# PeripheralMapping.forbid_fix("RG2CR", "DMAMUX_RG2CR")
	# PeripheralMapping.forbid_fix("RG3CR", "DMAMUX_RG3CR")
	# PeripheralMapping.forbid_fix("RGCFR", "DMAMUX_RGCFR")
	# PeripheralMapping.forbid_fix("RGSR", "DMAMUX_RGSR")
	
	# Peripheral : FIREWALL
	# PeripheralMapping.forbid_fix("FIREWALL_CR", "CR")
	# PeripheralMapping.forbid_fix("FIREWALL_CSL", "CSL")
	# PeripheralMapping.forbid_fix("FIREWALL_CSSA", "CSSA")
	# PeripheralMapping.forbid_fix("FIREWALL_NVDSL", "NVDSL")
	# PeripheralMapping.forbid_fix("FIREWALL_NVDSSA", "NVDSSA")
	# PeripheralMapping.forbid_fix("FIREWALL_VDSL", "VDSL")
	# PeripheralMapping.forbid_fix("FIREWALL_VDSSA", "VDSSA")
	
	# Peripheral : FSMC
	# PeripheralMapping.forbid_fix("ECCR3", "ECCR")
	# PeripheralMapping.forbid_fix("PATT3", "PATT")
	# PeripheralMapping.forbid_fix("PCR3", "PCR")
	# PeripheralMapping.forbid_fix("PMEM3", "PMEM")
	# PeripheralMapping.forbid_fix("SR3", "SR")
	
	# Peripheral : GPIO
	# PeripheralMapping.forbid_fix("OSPEEDR", "GPIOB_OSPEEDR")
	# PeripheralMapping.forbid_fix("OSPEEDR", "OSPEEDER")
	
	# Peripheral : HRTIM_Master
	# PeripheralMapping.forbid_fix("MDIER4", "MDIER")
	
	# Peripheral : HRTIM_TIMA
	# PeripheralMapping.forbid_fix("TIMADIER5", "TIMADIER")
	
	# Peripheral : HRTIM_TIMB
	# PeripheralMapping.forbid_fix("TIMBDIER5", "TIMBDIER")
	
	# Peripheral : HRTIM_TIMC
	# PeripheralMapping.forbid_fix("TIMCDIER5", "TIMCDIER")
	
	# Peripheral : HRTIM_TIMD
	# PeripheralMapping.forbid_fix("TIMDDIER5", "TIMDDIER")
	
	# Peripheral : HRTIM_TIME
	# PeripheralMapping.forbid_fix("TIMEDIER5", "TIMEDIER")
	
	# Peripheral : LCD
	# PeripheralMapping.forbid_fix("RAM_COM0", "RAM_COM00")
	# PeripheralMapping.forbid_fix("RAM_COM1", "RAM_COM10")
	# PeripheralMapping.forbid_fix("RAM_COM2", "RAM_COM20")
	# PeripheralMapping.forbid_fix("RAM_COM3", "RAM_COM30")
	# PeripheralMapping.forbid_fix("RAM_COM4", "RAM_COM40")
	# PeripheralMapping.forbid_fix("RAM_COM5", "RAM_COM50")
	# PeripheralMapping.forbid_fix("RAM_COM6", "RAM_COM60")
	# PeripheralMapping.forbid_fix("RAM_COM7", "RAM_COM70")
	
	# Peripheral : MPU
	# PeripheralMapping.forbid_fix("CTRL", "MPU_CTRL")
	# PeripheralMapping.forbid_fix("MPU_CTRL", "CTRL")
	# PeripheralMapping.forbid_fix("MPU_RASR", "RASR")
	# PeripheralMapping.forbid_fix("MPU_RBAR", "RBAR")
	# PeripheralMapping.forbid_fix("MPU_RNR", "RNR")
	# PeripheralMapping.forbid_fix("MPU_TYPER", "TYPER")
	# PeripheralMapping.forbid_fix("RASR", "MPU_RASR")
	# PeripheralMapping.forbid_fix("RBAR", "MPU_RBAR")
	# PeripheralMapping.forbid_fix("RNR", "MPU_RNR")
	# PeripheralMapping.forbid_fix("TYPER", "MPU_TYPER")
	
	# Peripheral : NVIC
	# PeripheralMapping.forbid_fix("ICER", "ICER0")
	# PeripheralMapping.forbid_fix("ICPR", "ICPR0")
	# PeripheralMapping.forbid_fix("ISER", "ISER0")
	# PeripheralMapping.forbid_fix("ISPR", "ISPR0")
	
	# Peripheral : OTG_FS_DEVICE
	# PeripheralMapping.forbid_fix("DIEPCTL1", "OTG_FS_DIEPCTL1")
	# PeripheralMapping.forbid_fix("DIEPCTL2", "OTG_FS_DIEPCTL2")
	# PeripheralMapping.forbid_fix("DIEPCTL3", "OTG_FS_DIEPCTL3")
	# PeripheralMapping.forbid_fix("DIEPEMPMSK", "OTG_FS_DIEPEMPMSK")
	# PeripheralMapping.forbid_fix("DIEPINT0", "OTG_FS_DIEPINT0")
	# PeripheralMapping.forbid_fix("DIEPINT1", "OTG_FS_DIEPINT1")
	# PeripheralMapping.forbid_fix("DIEPINT2", "OTG_FS_DIEPINT2")
	# PeripheralMapping.forbid_fix("DIEPINT3", "OTG_FS_DIEPINT3")
	# PeripheralMapping.forbid_fix("DIEPTSIZ0", "OTG_FS_DIEPTSIZ0")
	# PeripheralMapping.forbid_fix("DIEPTSIZ1", "OTG_FS_DIEPTSIZ1")
	# PeripheralMapping.forbid_fix("DIEPTSIZ2", "OTG_FS_DIEPTSIZ2")
	# PeripheralMapping.forbid_fix("DIEPTSIZ3", "OTG_FS_DIEPTSIZ3")
	# PeripheralMapping.forbid_fix("DOEPCTL0", "OTG_FS_DOEPCTL0")
	# PeripheralMapping.forbid_fix("DOEPCTL1", "OTG_FS_DOEPCTL1")
	# PeripheralMapping.forbid_fix("DOEPCTL2", "OTG_FS_DOEPCTL2")
	# PeripheralMapping.forbid_fix("DOEPCTL3", "OTG_FS_DOEPCTL3")
	# PeripheralMapping.forbid_fix("DOEPINT0", "OTG_FS_DOEPINT0")
	# PeripheralMapping.forbid_fix("DOEPINT1", "OTG_FS_DOEPINT1")
	# PeripheralMapping.forbid_fix("DOEPINT2", "OTG_FS_DOEPINT2")
	# PeripheralMapping.forbid_fix("DOEPINT3", "OTG_FS_DOEPINT3")
	# PeripheralMapping.forbid_fix("DOEPTSIZ0", "OTG_FS_DOEPTSIZ0")
	# PeripheralMapping.forbid_fix("DOEPTSIZ1", "OTG_FS_DOEPTSIZ1")
	# PeripheralMapping.forbid_fix("DOEPTSIZ2", "OTG_FS_DOEPTSIZ2")
	# PeripheralMapping.forbid_fix("DOEPTSIZ3", "OTG_FS_DOEPTSIZ3")
	# PeripheralMapping.forbid_fix("DTXFSTS0", "OTG_FS_DTXFSTS0")
	# PeripheralMapping.forbid_fix("DTXFSTS1", "OTG_FS_DTXFSTS1")
	# PeripheralMapping.forbid_fix("DTXFSTS2", "OTG_FS_DTXFSTS2")
	# PeripheralMapping.forbid_fix("DTXFSTS3", "OTG_FS_DTXFSTS3")
	# PeripheralMapping.forbid_fix("DVBUSDIS", "OTG_FS_DVBUSDIS")
	# PeripheralMapping.forbid_fix("DVBUSPULSE", "OTG_FS_DVBUSPULSE")
	# PeripheralMapping.forbid_fix("FS_DAINT", "OTG_FS_DAINT")
	# PeripheralMapping.forbid_fix("FS_DAINTMSK", "OTG_FS_DAINTMSK")
	# PeripheralMapping.forbid_fix("FS_DCFG", "OTG_FS_DCFG")
	# PeripheralMapping.forbid_fix("FS_DCTL", "OTG_FS_DCTL")
	# PeripheralMapping.forbid_fix("FS_DIEPCTL0", "OTG_FS_DIEPCTL0")
	# PeripheralMapping.forbid_fix("FS_DIEPMSK", "OTG_FS_DIEPMSK")
	# PeripheralMapping.forbid_fix("FS_DOEPMSK", "OTG_FS_DOEPMSK")
	# PeripheralMapping.forbid_fix("FS_DSTS", "OTG_FS_DSTS")
	# PeripheralMapping.forbid_fix("OTG_FS_DIEPTSIZ5", "OTG_FS_DIEPTSIZ55")
	# PeripheralMapping.forbid_fix("OTG_FS_DTXFSTS5", "OTG_FS_DTXFSTS55")
	
	# Peripheral : OTG_FS_GLOBAL
	# PeripheralMapping.forbid_fix("FS_GRXSTSR_Device", "FS_GRXSTSR_Host")
	# PeripheralMapping.forbid_fix("FS_GRXSTSR_Host", "FS_GRXSTSR_Device")
	# PeripheralMapping.forbid_fix("FS_GRXSTSR_Host", "OTG_FS_GRXSTSR_Device")
	
	# Peripheral : OTG_FS_HOST
	# PeripheralMapping.forbid_fix("FS_HCCHAR0", "OTG_FS_HCCHAR0")
	# PeripheralMapping.forbid_fix("FS_HCCHAR1", "OTG_FS_HCCHAR1")
	# PeripheralMapping.forbid_fix("FS_HCCHAR2", "OTG_FS_HCCHAR2")
	# PeripheralMapping.forbid_fix("FS_HCCHAR3", "OTG_FS_HCCHAR3")
	# PeripheralMapping.forbid_fix("FS_HCCHAR4", "OTG_FS_HCCHAR4")
	# PeripheralMapping.forbid_fix("FS_HCCHAR5", "OTG_FS_HCCHAR5")
	# PeripheralMapping.forbid_fix("FS_HCCHAR6", "OTG_FS_HCCHAR6")
	# PeripheralMapping.forbid_fix("FS_HCCHAR7", "OTG_FS_HCCHAR7")
	# PeripheralMapping.forbid_fix("FS_HCFG", "OTG_FS_HCFG")
	# PeripheralMapping.forbid_fix("FS_HCINT0", "OTG_FS_HCINT0")
	# PeripheralMapping.forbid_fix("FS_HCINT1", "OTG_FS_HCINT1")
	# PeripheralMapping.forbid_fix("FS_HCINT2", "OTG_FS_HCINT2")
	# PeripheralMapping.forbid_fix("FS_HCINT3", "OTG_FS_HCINT3")
	# PeripheralMapping.forbid_fix("FS_HCINT4", "OTG_FS_HCINT4")
	# PeripheralMapping.forbid_fix("FS_HCINT5", "OTG_FS_HCINT5")
	# PeripheralMapping.forbid_fix("FS_HCINT6", "OTG_FS_HCINT6")
	# PeripheralMapping.forbid_fix("FS_HCINT7", "OTG_FS_HCINT7")
	# PeripheralMapping.forbid_fix("FS_HCINTMSK0", "OTG_FS_HCINTMSK0")
	# PeripheralMapping.forbid_fix("FS_HCINTMSK1", "OTG_FS_HCINTMSK1")
	# PeripheralMapping.forbid_fix("FS_HCINTMSK2", "OTG_FS_HCINTMSK2")
	# PeripheralMapping.forbid_fix("FS_HCINTMSK3", "OTG_FS_HCINTMSK3")
	# PeripheralMapping.forbid_fix("FS_HCINTMSK4", "OTG_FS_HCINTMSK4")
	# PeripheralMapping.forbid_fix("FS_HCINTMSK5", "OTG_FS_HCINTMSK5")
	# PeripheralMapping.forbid_fix("FS_HCINTMSK6", "OTG_FS_HCINTMSK6")
	# PeripheralMapping.forbid_fix("FS_HCINTMSK7", "OTG_FS_HCINTMSK7")
	# PeripheralMapping.forbid_fix("FS_HCTSIZ0", "OTG_FS_HCTSIZ0")
	# PeripheralMapping.forbid_fix("FS_HCTSIZ1", "OTG_FS_HCTSIZ1")
	# PeripheralMapping.forbid_fix("FS_HCTSIZ2", "OTG_FS_HCTSIZ2")
	# PeripheralMapping.forbid_fix("FS_HCTSIZ3", "OTG_FS_HCTSIZ3")
	# PeripheralMapping.forbid_fix("FS_HCTSIZ4", "OTG_FS_HCTSIZ4")
	# PeripheralMapping.forbid_fix("FS_HCTSIZ5", "OTG_FS_HCTSIZ5")
	# PeripheralMapping.forbid_fix("FS_HCTSIZ6", "OTG_FS_HCTSIZ6")
	# PeripheralMapping.forbid_fix("FS_HCTSIZ7", "OTG_FS_HCTSIZ7")
	# PeripheralMapping.forbid_fix("FS_HFNUM", "OTG_FS_HFNUM")
	# PeripheralMapping.forbid_fix("FS_HPRT", "OTG_FS_HPRT")
	# PeripheralMapping.forbid_fix("FS_HPTXSTS", "OTG_FS_HPTXSTS")
	# PeripheralMapping.forbid_fix("HAINT", "OTG_FS_HAINT")
	# PeripheralMapping.forbid_fix("HAINTMSK", "OTG_FS_HAINTMSK")
	# PeripheralMapping.forbid_fix("HFIR", "OTG_FS_HFIR")
	
	# Peripheral : OTG_FS_PWRCLK
	# PeripheralMapping.forbid_fix("FS_PCGCCTL", "OTG_FS_PCGCCTL")
	
	# Peripheral : OTG_HS_DEVICE
	# PeripheralMapping.forbid_fix("OTG_HS_DIEPDMA1", "OTG_HS_DIEPDMA0")
	# PeripheralMapping.forbid_fix("OTG_HS_DIEPDMA2", "OTG_HS_DIEPDMA1")
	# PeripheralMapping.forbid_fix("OTG_HS_DIEPDMA3", "OTG_HS_DIEPDMA2")
	# PeripheralMapping.forbid_fix("OTG_HS_DIEPDMA4", "OTG_HS_DIEPDMA3")
	# PeripheralMapping.forbid_fix("OTG_HS_DIEPDMA5", "OTG_HS_DIEPDMA4")
	
	# Peripheral : OTG_HS_GLOBAL
	# PeripheralMapping.forbid_fix("OTG_HS_DIEPTXF3", "OTG_HS_DIEPTXF7")
	# PeripheralMapping.forbid_fix("OTG_HS_GNPTXFSIZ_Host", "OTG_HS_HNPTXFSIZ_Host")
	# PeripheralMapping.forbid_fix("OTG_HS_GNPTXSTS", "OTG_HS_HNPTXSTS")
	# PeripheralMapping.forbid_fix("OTG_HS_GRXSTSP_Peripheral", "OTG_HS_GRXSTSP_Device")
	# PeripheralMapping.forbid_fix("OTG_HS_GRXSTSR_Peripheral", "OTG_HS_GRXSTSR_Device")
	# PeripheralMapping.forbid_fix("OTG_HS_TX0FSIZ_Peripheral", "OTG_HS_DIEPTXF0_Device")
	
	# Peripheral : RCC
	# PeripheralMapping.forbid_fix("PLLSYSCFGR", "PLLCFGR")
	
	# Peripheral : RTC
	# PeripheralMapping.forbid_fix("BK0R", "BKP19R")
	# PeripheralMapping.forbid_fix("BKP19R", "BK0R")
	
	# Peripheral : SDIO
	# PeripheralMapping.forbid_fix("RESPI1", "RESP1")
	
	# Peripheral : STK
	# PeripheralMapping.forbid_fix("CSR", "CTRL")
	# PeripheralMapping.forbid_fix("CVR", "VAL")
	# PeripheralMapping.forbid_fix("RVR", "LOAD")
	
	# Peripheral : SYSCFG
	# PeripheralMapping.forbid_fix("CFGR1", "MEMRM")
	# PeripheralMapping.forbid_fix("CFGR1", "MEMRMP")
	# PeripheralMapping.forbid_fix("MEMRM", "MEMRMP")
	# PeripheralMapping.forbid_fix("MEMRMP", "MEMRM")
	
	# Peripheral : TIM_ADVANCED
	# PeripheralMapping.forbid_fix("CCMR1_Input", "CCMR1_Output")
	# PeripheralMapping.forbid_fix("CCMR1_Output", "CCMR1_Input")
	# PeripheralMapping.forbid_fix("CCMR2_Input", "CCMR2_Output")
	# PeripheralMapping.forbid_fix("CCMR2_Output", "CCMR2_Input")
	# PeripheralMapping.forbid_fix("CCR6", "CRR6")
	
	# Peripheral : TIM_GENERAL_15
	#PeripheralMapping.forbid_fix("AF1", "OR2")
	
	# Peripheral : USB
	# PeripheralMapping.forbid_fix("CNTR", "USB_CNTR")
	# PeripheralMapping.forbid_fix("EP0R", "USB_EP0R")
	# PeripheralMapping.forbid_fix("EP1R", "USB_EP1R")
	# PeripheralMapping.forbid_fix("EP2R", "USB_EP2R")
	# PeripheralMapping.forbid_fix("EP3R", "USB_EP3R")
	# PeripheralMapping.forbid_fix("EP4R", "USB_EP4R")
	# PeripheralMapping.forbid_fix("EP5R", "USB_EP5R")
	# PeripheralMapping.forbid_fix("EP6R", "USB_EP6R")
	# PeripheralMapping.forbid_fix("EP7R", "USB_EP7R")
	
	# Peripheral : USB_GENERIC
	# PeripheralMapping.forbid_fix("USB_EP0R", "EP0R")
	# PeripheralMapping.forbid_fix("USB_EP1R", "EP1R")
	# PeripheralMapping.forbid_fix("USB_EP2R", "EP2R")
	# PeripheralMapping.forbid_fix("USB_EP3R", "EP3R")
	# PeripheralMapping.forbid_fix("USB_EP4R", "EP4R")
	# PeripheralMapping.forbid_fix("USB_EP5R", "EP5R")
	# PeripheralMapping.forbid_fix("USB_EP6R", "EP6R")
	# PeripheralMapping.forbid_fix("USB_EP7R", "EP7R")
	
	# Peripheral : USB_OTG_GLOBAL
	# PeripheralMapping.forbid_fix("FS_GRXSTSR_Device", "FS_GRXSTSR_Host")
	
	pass