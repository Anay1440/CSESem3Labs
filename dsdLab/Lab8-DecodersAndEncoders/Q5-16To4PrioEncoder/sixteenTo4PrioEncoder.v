module sixteenTo4PrioEncoder(w,y,z);
    input [15:0] w;
    output reg [3:0] y;
    output reg z;
    integer k;
    always @(w)
    begin 
        z = 1;
        if (w == 0)
            z = 0;
        else
        begin
            for(k = 15; k >= 0; k = k - 1)
            begin
                if (w[k] == 1)
                    y = k;
            end
        end
    end
endmodule