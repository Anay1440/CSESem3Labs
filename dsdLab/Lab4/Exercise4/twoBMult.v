module twoBMult(x0,x1,y0,y1,s0,s1,s2,cout);
	input x0,x1,y0,y1;
	output s0,s1,s2,cout;
	
	and (s0,x0,y0);
	and (i1,x1,y0);
	and (i2,x0,y1);
	and (i3,x1,y1);
	
	
	fa stage01(i1,i2,1'b0,s1,c1);
	fa stage02(i3,c1,1'b0,s2,cout);
	
endmodule

module twoBAdd(x0,x1,y0,y1,cin,s0,s1,cout);
	input x0,x1,y0,y1,cin;
	output s0,s1,cout;
	
	fa stage0(x0,y0,cin,s0,c1);
	fa stage1(x1,y1,c1,s1,cout);
	
endmodule

module fa(a,b,cin,s,cout);
	input a,b,cin;
	output s,cout;
	
	assign s = a ^ b ^ cin;
	assign cout = (a & b) | (a & cin) | (b & cin);

endmodule
