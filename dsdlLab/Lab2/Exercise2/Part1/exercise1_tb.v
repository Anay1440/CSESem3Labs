`timescale 1ns/1ns
`include "exercise1.v" 

module exercise1_tb();
reg b,c,d;
wire f;

exercise1 ex1(b,c,d,f);
initial 
begin

	$dumpfile("exercise1_tb.vcd");
	$dumpvars(0,exercise1_tb);
	
	 b=1'b0; c=1'b0; d=1'b0;
	#20;
	
	 b=1'b0; c=1'b0; d=1'b1;
	#20;
	
	 b=1'b0; c=1'b1; d=1'b0;
	#20;
	
	 b=1'b0; c=1'b1; d=1'b1;
	#20;
	
	 b=1'b1; c=1'b0; d=1'b0;
	#20;
	
	 b=1'b1; c=1'b0; d=1'b1;
	#20;
	
	 b=1'b1; c=1'b1; d=1'b0;
	#20;
	
	 b=1'b1; c=1'b1; d=1'b1;
	#20;
	
	 b=1'b0; c=1'b0; d=1'b0;
	#20;
	
	 b=1'b0; c=1'b0; d=1'b1;
	#20;
	
	 b=1'b0; c=1'b1; d=1'b0;
	#20;
	
	 b=1'b0; c=1'b1; d=1'b1;
	#20;
	
	 b=1'b1; c=1'b0; d=1'b0;
	#20;
	
	 b=1'b1; c=1'b0; d=1'b1;
	#20;
	
	 b=1'b1; c=1'b1; d=1'b0;
	#20;
	
	 b=1'b1; c=1'b1; d=1'b1;
	#20;
	$display("Test Complete");
end

endmodule
