`timescale 1ns/1ns
`include "twoBMult.v"

module twoBMult_tb();
reg x0,x1,y0,y1;
wire s0,s1,s2,cout;

twoBMult fbas(x0,x1,y0,y1,s0,s1,s2,cout);
initial 
begin 
	$dumpfile("twoBMult_tb.vcd");
	$dumpvars(0,twoBMult_tb);
	
	x0=0;x1=1;y0=0;y1=1;#20;
	x0=1;x1=1;y0=1;y1=0;#20;
	
	$display("Test Complete");
	
end 
endmodule
