`timescale 1ns/1ns
`include "exercise1.v" 

module exercise1_tb();
reg a,b,c,d,e;
wire f;

exercise1 ex1(a,b,c,d,e,f);
initial 
begin

	$dumpfile("exercise1_tb.vcd");
	$dumpvars(0,exercise1_tb);
	
	a=0; b=0; c=0; d=0; e=0;
	#20;
	
	a=0; b=0; c=0; d=0; e=1;
	#20;
	
	a=0; b=0; c=0; d=1; e=0;
	#20;
	
	a=0; b=0; c=0; d=1; e=1;
	#20;
	
	a=0; b=0; c=1; d=0; e=0;
	#20;
	
	a=0; b=0; c=1; d=0; e=1;
	#20;
	
	a=0; b=0; c=1; d=1; e=0;
	#20;
	
	a=0; b=0; c=1; d=1; e=1;
	#20;
	
	a=0; b=1; c=0; d=0; e=0;
	#20;
	
	a=0; b=1; c=0; d=0; e=1;
	#20;
	
	a=0; b=1; c=0; d=1; e=0;
	#20;
	
	a=0; b=1; c=0; d=1; e=1;
	#20;
	
	a=0; b=1; c=1; d=0; e=0;
	#20;
	
	a=0; b=1; c=1; d=0; e=1;
	#20;
	
	a=0; b=1; c=1; d=1; e=0;
	#20;
	
	a=0; b=1; c=1; d=1; e=1;
	#20;
	
	a=1; b=0; c=0; d=0; e=0;
	#20;
	
	a=1; b=0; c=0; d=0; e=1;
	#20;
	
	a=1; b=0; c=0; d=1; e=0;
	#20;
	
	a=1; b=0; c=0; d=1; e=1;
	#20;
	
	a=1; b=0; c=1; d=0; e=0;
	#20;
	
	a=1; b=0; c=1; d=0; e=1;
	#20;
	
	a=1; b=0; c=1; d=1; e=0;
	#20;
	
	a=1; b=0; c=1; d=1; e=1;
	#20;
	
	a=1; b=1; c=0; d=0; e=0;
	#20;
	
	a=1; b=1; c=0; d=0; e=1;
	#20;
	
	a=1; b=1; c=0; d=1; e=0;
	#20;
	
	a=1; b=1; c=0; d=1; e=1;
	#20;
	
	a=1; b=1; c=1; d=0; e=0;
	#20;
	
	a=1; b=1; c=1; d=0; e=1;
	#20;
	
	a=1; b=1; c=1; d=1; e=0;
	#20;
	
	a=1; b=1; c=1; d=1; e=1;
	#20;
	
	$display("Test Complete");
end

endmodule
