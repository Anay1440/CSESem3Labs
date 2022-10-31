module implementF(a,b,c,d,f);
    input a,b,c,d;
    output f;

    wire [3:0] w;
    assign w = {a,b,c,d};

    wire [0:15] y;

    fourTo16Decoder stage0(w,1'b1,y);

    or(f,y[1],y[3],y[6],y[7],y[9],y[14],y[15]);

endmodule

module fourTo16Decoder(w,En,y);
    input [3:0] w;
    input En;
    output reg [0:15] y;

    integer k;

    always @(w or En)
        for(k = 0; k <= 15; k=k+1)
        if ((w == k) && (En == 1))
            y[k] = 1;
        else 
            y[k] = 0;

endmodule