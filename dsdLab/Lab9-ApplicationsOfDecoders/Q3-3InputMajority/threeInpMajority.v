/* This is using one decoder
module threeInpMajority(w,f);
    input [2:0] w;
    output f;

    wire [0:3] y;

    TwoToFourDecoder stage0(w[2:1],1'b1,y);
    and(t1,w[0],y[1]);
    and(t2,y[1],y[2]);
    and(t3,w[0],y[2]);
    or(f,t1,t2,t3,y[3]);

endmodule */

//Using 2 decoders: 

module threeInpMajority(w,f);
    input [2:0] w;
    output f;

    wire [0:3] y1;
    wire [0:3] y2;

    TwoToFourDecoder stage0(w[1:0],1'b1,y1);
    TwoToFourDecoder stage1(w[2:1],1'b1,y2);
    and(t1,y1[1],y1[2]);
    and(t2,y1[1],y2[2]);
    and(t3,y2[1],y2[2]);
    or(f,t1,t2,t3,y1[3],y2[3]);

endmodule

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
endmodule 

