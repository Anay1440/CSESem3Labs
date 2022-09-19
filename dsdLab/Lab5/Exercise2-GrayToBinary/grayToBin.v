module grayToBin(g,b);
    parameter m=4;
    input [(m-1):0] g;
    output [(m-1):0] b;
    reg [(m-1):0] b;
    integer i = 0;
    
    always @(g)
    begin 
        b[(m-1)] = g[(m-1)];
        for(i=(m-2);i>-1;i=i-1)
            begin
                b[i] = b[(i+1)] ^ g[i];
            end
    end

endmodule

