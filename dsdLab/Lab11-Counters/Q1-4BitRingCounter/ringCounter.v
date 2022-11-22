module ringCounter(clk,reset,Q);
    input clk,reset;
    output [0:3] Q;
    wire [1:0] t;
    
    twoBitCounter c(clk,reset,t);
    TwoToFourDecoder d(t,1'b1,Q);

endmodule

module TwoToFourDecoder(w,En,y);
    input [1:0] w;
    input En;
    output reg [0:3] y;
    always @(w or En)
    begin
            y=4'b0000;
        if (En == 1)
        begin
            case(w)
            0:  y[0] = 1;
            1:  y[1] = 1;
            2:  y[2] = 1;
            3:  y[3] = 1; 
            endcase
        end
    end
endmodule

module twoBitCounter(clk,reset,o);
    input clk,reset;
    output [0:1] o;

    dFF ff1(~o[1],clk,reset,o[1]);
    dFF ff2(~o[0],~o[1],reset,o[0]);

endmodule

module dFF(d,clk,reset,q);
    input d,clk,reset;
    output reg q;

    always @(posedge clk)
        if (!reset)
            q <= d;

    always @(reset)
        if (reset)
            q <= 0;

endmodule