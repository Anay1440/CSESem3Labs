`timescale 1ns/1ns
`include "decompFA.v"

module decompFA_tb();
reg a,b,cin;
wire s,cout;

decompFA dfa(a,b,cin,s,cout);
initial 
begin 
	$dumpfile("decompFA_tb.vcd");
	$dumpvars(0,decompFA_tb);
	
	a=0;b=0;cin=0;#20;
	a=0;b=0;cin=1;#20;
	a=0;b=1;cin=0;#20;
	a=0;b=1;cin=1;#20;
	a=1;b=0;cin=0;#20;
	a=1;b=0;cin=1;#20;
	a=1;b=1;cin=0;#20;
	a=1;b=1;cin=1;#20;
	
	$display("Test Complete");
	
end 
endmodule
