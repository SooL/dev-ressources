import re

def CAN_periph_advanced_cleaner(periph: "Peripheral") :
	from structure import Peripheral, MappingElement
	for m in periph.mappings :
		if "F0R1" in m and not "sFilterRegister" in periph :
			F0R1 = m["F0R1"]; F0R2 = m["F0R2"]
			FRx = F0R1.component
			FRx.name = "FRx"

			array_size = len(list(filter(lambda elmt : re.match("^F\d+R1", elmt.name), m.elements)))
			if len(list(filter(lambda elmt : elmt.component is FRx, m.elements))) != (array_size * 2) :
				raise AssertionError("different registers for CAN filters")

			address = F0R1.address
			filter_register_sub_periph = Peripheral(FRx.chips, "FilterRegister", "CAN Filter Register")
			filter_register_sub_periph.add_register(FRx)
			placement_FR1 = MappingElement(F0R1.chips, "FR1", component = FRx, address = 0)
			placement_FR2 = MappingElement(F0R2.chips, "FR2", component = FRx, address = F0R2.address - F0R1.address)
			filter_register_sub_periph.add_placement(placement_FR1)
			filter_register_sub_periph.add_placement(placement_FR2)
			filter_placement = MappingElement(F0R1.chips, "sFilterRegister",
			                                 component = filter_register_sub_periph, address = address,
			                                 array_size = array_size, array_space = 0)
			m.remove_elements_for(FRx)
			periph.add_register(filter_register_sub_periph)
			periph.add_placement(filter_placement)

		if "TI0R" in m and not "TxMailBox" in periph :
			TI0R = m["TI0R"]; TDT0R = m["TDT0R"]; TDL0R = m["TDL0R"]; TDH0R = m["TDH0R"]
			TIR = TI0R.component; TDTR = TDT0R.component; TDLR = TDL0R.component; TDHR = TDH0R.component
			TIR.name = "TIR"; TDTR.name = "TDTR"; TDLR.name = "TDLR"; TDHR.name = "TDHR"
			array_size = len(list(filter(lambda elmt : re.match("^TI\d*R", elmt.name), m.elements)))
			address = TI0R.address
			mailbox_sub_periph = Peripheral(TIR.chips, "TxMailBox", "CAN Tx MailBox")
			mailbox_sub_periph.add_register(TIR)
			mailbox_sub_periph.add_register(TDTR)
			mailbox_sub_periph.add_register(TDLR)
			mailbox_sub_periph.add_register(TDHR)
			placement_TIR  = MappingElement(TI0R.chips , "TIR" , component=TIR , address=0)
			placement_TDTR = MappingElement(TDT0R.chips, "TDTR", component=TDTR, address=TDT0R.address-TI0R.address)
			placement_TDLR = MappingElement(TDL0R.chips, "TDLR", component=TDLR, address=TDL0R.address-TI0R.address)
			placement_TDHR = MappingElement(TDH0R.chips, "TDHR", component=TDHR, address=TDH0R.address-TI0R.address)
			mailbox_sub_periph.add_placement(placement_TIR)
			mailbox_sub_periph.add_placement(placement_TDTR)
			mailbox_sub_periph.add_placement(placement_TDLR)
			mailbox_sub_periph.add_placement(placement_TDHR)
			mailbox_placement = MappingElement(TI0R.chips, "sTxMailBox", component=mailbox_sub_periph,
			                                   address=TI0R.address, array_size=array_size, array_space=0)

			i = 0
			while i < len(m.elements) :
				if re.match("^T(I|D[TLH])\d*R", m.elements[i].name) :
					m.remove_element(m.elements[i])
				else : i += 1

			periph.add_register(mailbox_sub_periph)
			periph.add_placement(mailbox_placement)

		if "RI0R" in m and not "RxMailBox" in periph :
			RI0R = m["RI0R"]; RDT0R = m["RDT0R"]; RDL0R = m["RDL0R"]; RDH0R = m["RDH0R"]
			RIR = RI0R.component; RDTR = RDT0R.component; RDLR = RDL0R.component; RDHR = RDH0R.component
			RIR.name = "RIR"; RDTR.name = "RDTR"; RDLR.name = "RDLR"; RDHR.name = "RDHR"

			array_size = len(list(filter(lambda elmt : re.match("^RI\d*R", elmt.name), m.elements)))
			address = RI0R.address
			mailbox_sub_periph = Peripheral(RIR.chips, "FIFOMailBox", "CAN Rx MailBox")
			mailbox_sub_periph.add_register(RIR)
			mailbox_sub_periph.add_register(RDTR)
			mailbox_sub_periph.add_register(RDLR)
			mailbox_sub_periph.add_register(RDHR)
			placement_RIR = MappingElement(RI0R.chips, "RIR", component=RIR, address=0)
			placement_RDTR = MappingElement(RDT0R.chips, "RDTR", component=RDTR, address=RDT0R.address - RI0R.address)
			placement_RDLR = MappingElement(RDL0R.chips, "RDLR", component=RDLR, address=RDL0R.address - RI0R.address)
			placement_RDHR = MappingElement(RDH0R.chips, "RDHR", component=RDHR, address=RDH0R.address - RI0R.address)
			mailbox_sub_periph.add_placement(placement_RIR)
			mailbox_sub_periph.add_placement(placement_RDTR)
			mailbox_sub_periph.add_placement(placement_RDLR)
			mailbox_sub_periph.add_placement(placement_RDHR)
			mailbox_placement = MappingElement(RI0R.chips, "sFIFOMailBox", component=mailbox_sub_periph,
			                                   address=RI0R.address, array_size=array_size, array_space=0)

			i = 0
			while i < len(m.elements) :
				if re.match("^R(I|D[TLH])\d*R", m.elements[i].name) :
					m.remove_element(m.elements[i])
				else : i += 1

			periph.add_register(mailbox_sub_periph)
			periph.add_placement(mailbox_placement)