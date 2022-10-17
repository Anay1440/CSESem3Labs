module fourTo16Decoder(w,En,y);
    input [3:0] w;
    input En;
    output [0:15] y;

    wire t1,t2;
    assign t1 = ~w[3] & En;
    assign t2 = w[3] & En;

    threeTo8Decoder stage0(w[2:0],t1,y[0:7]);
    threeTo8Decoder stage1(w[2:0],t2,y[8:15]);

endmodule

module threeTo8Decoder(w,En,y);
    input [2:0] w;
    input En;
    output reg [0:7] y;

    integer k;

    always @(w or En)
        for(k = 0; k <= 7; k=k+1)
        if ((w == k) && (En == 1))
            y[k] = 1;
        else 
            y[k] = 0;

endmodule