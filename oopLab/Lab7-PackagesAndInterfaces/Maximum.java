package myPackages.p1;

public class Maximum {
    public int max(int a,int b,int c) {
        if (a>b && a>c) 
            return a;
        else if (b>a && b>c)     
            return b;
        else
            return c;
    }
    public float max(float a,float b,float c) {
        if (a>b && a>c) 
            return a;
        else if (b>a && b>c)     
            return b;
        else
            return c;
    }
    public int max(int arr[]) {
        int m=arr[0];
        for(int i=0;i<arr.length;i++) {
            if (arr[i] > m)
                m = arr[i];
        }
        return m;
    }
    public int max(int arr[][]) {
        int m = arr[0][0];
        for(int i=0;i<arr.length;i++) {
            for (int j = 0;j<arr[0].length;j++) {
                if (arr[i][j] > m)  
                    m = arr[i][j];
            }
        }
        return m;
    }
}
