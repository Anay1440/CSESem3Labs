// 4 To 16 Decoder using 2 To 4 Decoder
// 2 to 4 Decoder is using case statement
module fourTo16Decoder(w,En,y);
    input [3:0] w;
    input En;
    output [0:15] y;
    wire [0:3] y2;
    
    TwoToFourDecoder stage0(w[3:2],En,y2);
    TwoToFourDecoder stage1(w[1:0],y2[0],y[0:3]);
    TwoToFourDecoder stage2(w[1:0],y2[1],y[4:7]);
    TwoToFourDecoder stage3(w[1:0],y2[2],y[8:11]);
    TwoToFourDecoder stage4(w[1:0],y2[3],y[12:15]);

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