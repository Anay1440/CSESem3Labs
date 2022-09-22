//module twoBMult(x0,x1,y0,y1,s0,s1,s2,cout);
module twoBMult(x,y,m);
	input [1:0] x,y;
	output [3:0] m;
	wire [1:0] a,b;
	wire c2;
	
	and (m[0],x[0],y[0]);
	and (b[0],x[1],y[0]);
	and (a[0],x[0],y[1]);
	and (a[1],x[1],y[1]);
	
	assign b[1] = 1'b0;
	/*
	fa stage01(i1,i2,1'b0,s1,c1);
	fa stage02(i3,c1,1'b0,s2,cout);
	*/
	twoBAdd stage0(a,b,1'b0,m[2:1],m[3]);
	
endmodule

//module twoBAdd(x0,x1,y0,y1,cin,s0,s1,cout);
module twoBAdd(x,y,cin,s,cout);
	input [1:0] x,y;
	input cin;
	output [1:0] s;
	output cout;
	wire c1;
	
	fa stage0(x[0],y[0],cin,s[0],c1);
	fa stage1(x[1],y[1],c1,s[1],cout);
	
endmodule

module fa(a,b,cin,s,cout);
	input a,b,cin;
	output s,cout;
	
	assign s = a ^ b ^ cin;
	assign cout = (a & b) | (a & cin) | (b & cin);

endmodule
