module MUX4To1(w,s,f);
	input [3:0] w;
	input [1:0] s;
	output f;
	wire t1,t2;
	
	function MUX2To1;
		input [1:0] w;
		input s;
		case(s)
			0:MUX2To1 = w[0];
			1:MUX2To1 = w[1];
		endcase
	endfunction
	
	assign t1 = MUX2To1(w[1:0],s[0]);
	assign t2 = MUX2To1(w[3:2],s[0]);
	assign f = MUX2To1({t2,t1},s[1]);
endmodule
