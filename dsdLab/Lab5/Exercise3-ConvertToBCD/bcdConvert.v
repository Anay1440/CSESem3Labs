module bcdConvert(x,y);
    input [3:0] x;
    output [3:0] y;
    reg b;
    wire [3:0] nine;
    assign nine = {1'b1,1'b0,1'b0,1'b1};
    always @x
    begin
        assign b = 1'b0;
        if (x > nine)
            assign b = 1'b1;
    end
    wire [3:0] c;
    assign c = {1'b0,b,b,1'b0};
    fbAdd ad(x,c,1'b0,y,c3);

endmodule

/*
module compareToNine(x,f);
    input [3:0] x;
    output reg f;
    wire [3:0] nine;
    assign nine = {1'b1,1'b0,1'b0,1'b1};
    always @(x)
    begin 
        f = 0;
        if (x > nine)
            f = 1;
    end
endmodule
*/

module fbAdd(x,y,cin,s,cout);
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
