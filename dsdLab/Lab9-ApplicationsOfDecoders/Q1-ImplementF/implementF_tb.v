`timescale 1ns/1ns
`include "implementF.v"

module implementF_tb();
reg a,b,c,d;
wire f;

implementF q(a,b,c,d,f);
initial 
begin 
    $dumpfile("implementF_tb.vcd");
    $dumpvars(0,implementF_tb);

	a=0; b=0; c=0; d=0;#20;
	a=0; b=0; c=0; d=1;#20;
	a=0; b=0; c=1; d=0;#20;
	a=0; b=0; c=1; d=1;#20;
	a=0; b=1; c=0; d=0;#20;
	a=0; b=1; c=0; d=1;#20;
	a=0; b=1; c=1; d=0;#20;
	a=0; b=1; c=1; d=1;#20;
	a=1; b=0; c=0; d=0;#20;
	a=1; b=0; c=0; d=1;#20;
	a=1; b=0; c=1; d=0;#20;
	a=1; b=0; c=1; d=1;#20;
	a=1; b=1; c=0; d=0;#20;
	a=1; b=1; c=0; d=1;#20;
	a=1; b=1; c=1; d=0;#20;
	a=1; b=1; c=1; d=1;#20;
    
	$display("Test Complete");

end
endmodule