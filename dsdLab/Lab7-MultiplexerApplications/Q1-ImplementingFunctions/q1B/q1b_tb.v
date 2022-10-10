`timescale 1ns/1ns
`include "q1b.v"

module q1b_tb();
reg a,b,c,d;
wire f;

q1b q(a,b,c,d,f);
initial 
begin 

    $dumpfile("q1b_tb.vcd");
    $dumpvars(0,q1b_tb);

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
    