#include <stdio.h>
#include <stdlib.h>
#define text_file_name "text_file.txt"
void array_modify(int*, int);

int main()
{
    int N;
    do{
        printf("Enter N\n");
        scanf("%d", &N);
    }
    while (N<0);
    double sum=0;
    for(int n=0, power_of_2=1, factorial_of_n=1; n<=N; n++)
    {
        if (n>=2) {
            for(int i=2; i<=n; i++) {
                factorial_of_n*=i;
            }
            for(int i=1; i<n; i++)
                power_of_2*=2;
        }
        if(n==1)
            power_of_2=2;
        sum+=(double)(power_of_2/factorial_of_n);
    }

    sum++;
    do {
        printf("Enter N\n");
        scanf("%d", &N);
    }
    while(N<0);
    int A[N];
    for(int i=0; i<N; i++)
        A[i]=rand()%(N-(-N)+1)+(-N);
    printf("Sum = %lf\n", sum);
    printf("Matrix:\n");
    for(int i=0; i<N; i++)
        printf("%d ", A[i]);
    array_modify(&A[0], N);
    printf("\nMatrix:\n");
    for(int i=0; i<N; i++)
        printf("%d ", A[i]);
    int Numbers=10, d;
    int B[2][Numbers];
    for (int i=0; i<Numbers; i++)
        B[0][i] = i+48, B[1][i]=0;
    printf("\n");
    FILE* text_file = fopen(text_file_name, "r");
    if(text_file==NULL) {
        printf("No file. Create %s", text_file_name);
        exit(0);
    }
    else {
        while(d!=EOF)
        {
            d = getc(text_file);
            for(int i=0; i<Numbers; i++)
                if(d==B[0][i])
                    B[1][i]+=1;
        }
        for(int k=0; k<Numbers; k++)
            for(int i=1; i<Numbers; i++)
                if (B[1][i-1]<B[1][i])
                    d = B[0][i-1], B[0][i-1] = B[0][i], B[0][i] = d, d = B[1][i-1], B[1][i-1] = B[1][i], B[1][i] = d;
        printf("4 symbols:\n");
        for (int i=0; i<4; i++)
            printf("%c ", B[0][i]);
        printf("\nHow often they are in file:\n");
        for (int i=0; i<4; i++)
            printf("%d ", B[1][i]);
    }
    return 0;
}
void array_modify(int* A, int N) {
    for(int i=0; i<N; i++)
        if(A[i]<0)
            A[i]=-1;
        else if(A[i]>0)
            A[i]=1;
        else if(A[i]==0)
            A[i]=0;
}
