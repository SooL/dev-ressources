-- List enable register names, and the associated chips.
-- You can select the peripheral to target in the subquery (alias :pname).
SELECT r.name as rname, f.name as fname, GROUP_CONCAT(DISTINCT c.name) as cname
FROM registers r
         INNER JOIN reg_placements rp ON r.id = rp.register_id
         INNER JOIN peripherals p ON rp.periph_id = p.id
         INNER JOIN field_reg_placement frp ON rp.id = frp.reg_placement_id
         INNER JOIN fields f ON frp.field_id = f.id
         INNER JOIN instances i ON p.id = i.periph_id
         INNER JOIN inst_chip ic ON i.id = ic.inst_id
         INNER JOIN chips c ON frp.chip_id = c.id
		 INNER JOIN inst_chip ic ON c.id = ic.chip_id
WHERE p.name == 'RCC' AND
 	f.name IN (
		SELECT (i.name || 'EN') as enfield FROM instances i
			INNER JOIN peripherals p ON i.periph_id = p.id
			INNER JOIN groups g ON p.grp_id = g.id
		WHERE p.name == :pname
	)
GROUP BY r.name, f.name;