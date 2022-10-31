`timescale 1ns/1ns
`include "fgh.v"

module fgh_tb();
reg a,b,c,d;
wire f,g,h;

fgh q(a,b,c,d,f,g,h);
initial 
begin 
    $dumpfile("fgh_tb.vcd");
    $dumpvars(0,fgh_tb);

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