`timescale 1ns/1ns
`include "exercise1.v" 

module exercise1_tb();
reg x1,x2,x3,x4;
wire f;

exercise1 ex1(x1,x2,x3,x4,f);
initial 
begin

	$dumpfile("exercise1_tb.vcd");
	$dumpvars(0,exercise1_tb);
	
	x1=1'b0; x2=1'b0; x3=1'b0; x4=1'b0;
	#20;
	
	x1=1'b0; x2=1'b0; x3=1'b0; x4=1'b1;
	#20;
	
	x1=1'b0; x2=1'b0; x3=1'b1; x4=1'b0;
	#20;
	
	x1=1'b0; x2=1'b0; x3=1'b1; x4=1'b1;
	#20;
	
	x1=1'b0; x2=1'b1; x3=1'b0; x4=1'b0;
	#20;
	
	x1=1'b0; x2=1'b1; x3=1'b0; x4=1'b1;
	#20;
	
	x1=1'b0; x2=1'b1; x3=1'b1; x4=1'b0;
	#20;
	
	x1=1'b0; x2=1'b1; x3=1'b1; x4=1'b1;
	#20;
	
	x1=1'b1; x2=1'b0; x3=1'b0; x4=1'b0;
	#20;
	
	x1=1'b1; x2=1'b0; x3=1'b0; x4=1'b1;
	#20;
	
	x1=1'b1; x2=1'b0; x3=1'b1; x4=1'b0;
	#20;
	
	x1=1'b1; x2=1'b0; x3=1'b1; x4=1'b1;
	#20;
	
	x1=1'b1; x2=1'b1; x3=1'b0; x4=1'b0;
	#20;
	
	x1=1'b1; x2=1'b1; x3=1'b0; x4=1'b1;
	#20;
	
	x1=1'b1; x2=1'b1; x3=1'b1; x4=1'b0;
	#20;
	
	x1=1'b1; x2=1'b1; x3=1'b1; x4=1'b1;
	#20;
	$display("Test Complete");
end

endmodule
