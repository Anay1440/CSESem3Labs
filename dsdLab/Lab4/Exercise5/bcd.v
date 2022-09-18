//module bcd(x0,x1,x2,x3,y0,y1,y2,y3,cin,s0,s1,s2,s3);
module bcd(x,y,cin,s);
	//input x0,x1,x2,x3,y0,y1,y2,y3,cin;
	input [3:0] x,y;
	input cin;
	output [3:0] s;
	wire [3:0] st;
	wire t1,t2,co;
	wire [3:0] k;
	//fbAdd stage0(x0,x1,x2,x3,y0,y1,y2,y3,cin,st0,st1,st2,st3,cout);
	fbAdd stage0(x,y,cin,st,cout);
	and (t1,st[3],st[2]);
	and (t2,st[3],st[1]);
	or (co,cout,t1,t2);
	assign k={1'b0,co,co,1'b0};
	//fbAdd stage1(st0,st1,st2,st3,1'b0,co,co,1'b0,1'b0,s0,s1,s2,s3,c);	
	fbAdd stage1(st,k,1'b0,s,c2);
endmodule

module fbAdd(x,y,cin,s,cout);
	//input x0,x1,x2,x3,y0,y1,y2,y3,cin;
	input [3:0] x,y;
	input cin;
	output [3:0] s;
	output cout;
	wire [3:1] c;
	
	fa stage0(x[0],y[0],cin,s[0],c[1]);
	fa stage1(x[1],y[1],c[1],s[1],c[2]);
	fa stage2(x[2],y[2],c[2],s[2],c[3]);
	fa stage3(x[3],y[3],c[3],s[3],cout);
	
endmodule

module fa(a,b,cin,s,cout);
	input a,b,cin;
	output s,cout;
	
	assign s = a ^ b ^ cin;
	assign cout = (a & b) | (a & cin) | (b & cin);

endmodule
