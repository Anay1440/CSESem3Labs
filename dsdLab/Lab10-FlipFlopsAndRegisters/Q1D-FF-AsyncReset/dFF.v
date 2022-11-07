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