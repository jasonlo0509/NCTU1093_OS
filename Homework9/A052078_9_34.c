#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,a[50],frame[10],window,k,hit,count_FIFO=0, count_LRU=0;
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d",&n);
    printf("\n Auto Generated Sequences :\n");
    for(i=1;i<=n;i++){
        a[i] = rand() % 10;
        printf( "%d\n", a[i]);
    }
    printf("\n ENTER THE NUMBER OF FRAMES :");
        scanf("%d",&window);
    // initialization!
    for(i=0;i<window;i++){
        frame[i]= -1;
    }
    j=0;
    printf("FIFO Algorithm!\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t",a[i]);
        hit=0;
        for(k=0;k<window;k++)
            if(frame[k]==a[i])
                hit=1;
            if (hit==0)
            {
                frame[j]=a[i];
                j=(j+1)%window;
                count_FIFO++;
                for(k=0;k<window;k++)
                    printf("%d\t",frame[k]);
            }
            /*else{
                for(k=0;k<window;k++)
                    printf("%d\t",frame[k]);
            }*/
            printf("\r\n");
    }


    printf("LRU Algorithm!\n");
    j=0;
    int freq[window];
    int min=100;
    for(i=0;i<window;i++){
        frame[i]= -1;
        freq[i] = 0;
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t",a[i]);
        hit=0;
        int max;
        for(k=0;k<window;k++){
            if(frame[k]==a[i]){
                hit=1;
                freq[k]=max;
            }
            if(frame[k]!=-1)
                freq[k]--;
        }
            if (hit==0)
            {   
                int full=0;
                max = -3000;
                for(k=0; k<window; k++){
                    if(max < freq[k]){
                        max = freq[k];
                    }
                }
                for(k=0; k<window; k++){
                    if(frame[k]==-1){
                        full =0;
                    }
                    else{
                        full =1;
                    }
                }
                if(full == 0 ){
                    frame[j]=a[i];
                    j=(j+1)%window;
                    count_LRU++;
                    for(k=0;k<window;k++)
                        printf("%d\t",frame[k]);
                    freq[j]--;
                }
                else{
                    min = 100;
                    for(k=0; k<window; k++){
                        if(min > freq[k]){
                            min = freq[k];
                        }
                    }
                    for(k=0; k<window; k++){
                        if(min == freq[k]){
                            frame[k] = a[i];
                            freq[k]=max+1;
                        }
                        
                    }
                    count_LRU++;
                    for(k=0;k<window;k++)
                        printf("%d \t",frame[k]);
                }
            }
            else{
                //count_LRU--;
                for(k=0; k<window; k++){
                    if(frame[k] == a[i]){
                        freq[k] = max+1;
                    }
                }
            }
            printf("\r\n");
    }
    printf("Number of Page Fault using FIFO Is %d\r\n",count_FIFO);
    printf("Number of Page Fault using LRU Is %d\r\n",count_LRU);
    return 0;
}
