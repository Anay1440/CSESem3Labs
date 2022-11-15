module sixBitShiftReg(inp,clk,o);
    input inp;
    input clk;
    output o;

    wire [4:0] t;

    dFF ff1(inp,clk,t[4]);
    dFF ff2(t[4],clk,t[3]);
    dFF ff3(t[3],clk,t[2]);
    dFF ff4(t[2],clk,t[1]);
    dFF ff5(t[1],clk,t[0]);
    dFF ff6(t[0],clk,o);

endmodule

module dFF(d,clk,q);
    input d,clk;
    output reg q;

    always @(posedge clk)
        q <= d;

endmodule