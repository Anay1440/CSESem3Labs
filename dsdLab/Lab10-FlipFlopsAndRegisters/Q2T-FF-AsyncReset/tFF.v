module tFF(t,clk,reset,q);
    input t,clk,reset;
    output reg q;
    always @(negedge clk)
        if (reset)
            q <= ~q;

    always @(reset)
        if (!reset)
            q <= 0;

endmodule