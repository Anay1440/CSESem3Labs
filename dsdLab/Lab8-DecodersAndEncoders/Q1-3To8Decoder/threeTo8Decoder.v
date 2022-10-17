// 3 to 8 decoder using 2 to 4 decoder
// 2 to 4 decoder is using if else 

module threeTo8Decoder(w,En,y);
    input [2:0] w;
    input En;
    output [0:7] y;

    wire t1,t2;
    assign t1 = ~w[2] & En;
    assign t2 = w[2] & En;

    TwoToFourDecoder stage0(w[1:0],t1,y[0:3]);
    TwoToFourDecoder stage1(w[1:0],t2,y[4:7]);

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
            
            if (w == 0)
                y[0] = 1;
            if (w == 1)
                y[1] = 1;
            if (w == 2)
                y[2] = 1;
            if (w == 3)
                y[3] = 1; 
        end
    end
endmodule

/*
module TwoToFourDecoder(w,En,y);
    input [1:0] w;
    input En;
    output reg [0:3] y;
    integer k;

    always @(w or En)
    for (k = 0; k <= 3; k=k+1)
        if ((w==k) && (En == 1))
            y[k] = 1;
        else
            y[k] = 0;

endmodule */



