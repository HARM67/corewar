.name "zork"
.comment "I'M ALIIIIVE"

<<<<<<< HEAD
l2:
		sti r10,%:live,%1
		and r1, %0, r1

live:	live %1
		zjmp %:live
=======
l2:		
		sti r1,%:live,%1
		and r1, 10, r1

		live %1_
		zjmp %live
live:
>>>>>>> bc9a6e1853052aee7657f27955ec610bac963038
