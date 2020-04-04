
//  Created by Tenzin monlam on 04/04/20.

#include<stdio.h>
#include<stdlib.h>

int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
 
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    
    return pos;
}
 
int main()
{
int i,j,n,no_frame,k,avail,count=0;
    int p[20],frame[10];
            printf("\n ENTER THE NUMBER OF PAGES:\n");
            scanf("%d",&n);  //input no. of page
            printf("\n PAGE NUMBER :\n");
            for(i=1;i<=n;i++)
            {
                p[i]=rand()%10; // random page /*scanf("%d",&a[i]); */ // manual
            }
    for(i=1;i<=n;i++)
              {
                  printf("a[%d] = %d \n",i,p[i]);
              }
            printf("\n ENTER THE NUMBER OF FRAMES :");
            scanf("%d",&no_frame);//no. of frames
for(i=0;i<n;i++)
            frame[i]= -1; //for empty space = -1
                      
    //FIRST IN FIRST OUT (FIFO) PAGE REPLACEMENT ALGO
    
    printf("\n--FIRST IN FIRST OUT(FIFO)--\n");
      j=0;
    printf("ref string\t\t page frames\n");
                        for(i=1;i<=n;i++)
                        {
                            printf("%d\t\t",p[i]);
                            avail=0;
                            
                            for(k=0;k<no_frame;k++)
                                if(frame[k]==p[i])
                                {
                                    avail=1;
                                    break;
                                }
                            
                            if (avail==0)
                            {
                                frame[j]=p[i];
                                j=(j+1)%no_frame;
                                count++;
                                
                                for(k=0;k<no_frame;k++)
                                printf("%d\t",frame[k]);
                            }
                            else
                            {
                                for(k=0;k<no_frame;k++)
                                  printf("%d\t",frame[k]);
                            }
                            printf("\n");
                         }
    printf("Page Fault Is %d\n",count);

    //LEAST RECENTLY USED (LRU) PAGE REPLACEMENT ALGO
    
    int flag1,flag2,counter=0,faults=0,time[10],pos;
    
     for(i=0;i<n;i++)
     frame[i]= -1;
    
    printf("\n\n--LEAST RECENTLY USED(LRU)--\n");
    printf("ref string\t\t page frames\n");
    for(i = 1; i <= n; ++i)
    {
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_frame; ++j)
        {
            if(frame[j] == p[i])
            {
                counter++;
                time[j] = counter;
                   flag1 = flag2 = 1;
                   break;
            }
        }
        
        if(flag1 == 0)
        {
            for(j = 0; j < no_frame; ++j)
            {
                if(frame[j] == -1)
                {
                    counter++;
                    faults++;
                    frame[j] = p[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
         }
        
        if(flag2 == 0)
        {
            pos = findLRU(time, no_frame);
            counter++;
            faults++;
            frame[pos] = p[i];
            time[pos] = counter;
        }
        
        printf("\n");
        
        printf("%d\t\t",p[i]);
        
        for(j = 0; j < no_frame; ++j)
        {
            printf("%d\t", frame[j]);
        }
    }
    
    printf("\n\n Page Faults is %d\n", faults);
 
    
    
    //OPTIMAL PAGE REPLACEMENT ALGO
    
    
    int temp[10],f1,f2,f3,max;
    faults=0;
    
    for(i=0;i<n;i++)
       frame[i]= -1;
    printf("\n\n--OPTIMAL PAGE REPLACEMENT --\n");
    printf("ref string\t\t page frames\n");
    
for(i = 1; i <= n; ++i)
{
        f1 = f2 = 0;
        
        for(j = 0; j < no_frame; ++j)
        {
            if(frame[j] == p[i])
            {
                   f1 = f2 = 1;
                   break;
            }
        }
        
        if(flag1 == 0)
        {
            for(j = 0; j < no_frame; ++j)
            {
                if(frame[j] == -1)
                {
                    faults++;
                    frame[j] = p[i];
                    f2 = 1;
                    break;
                }
            }
         }
        
        if(f2 == 0)
        {
            f3 =0;
            
            for(j = 0; j < no_frame; ++j)
            {
                temp[j] = -1;
                
                for(k = i + 1; k < n; ++k)
                {
                    if(frame[j] == p[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
             }
            
            for(j = 0; j < no_frame; ++j)
            {
                if(temp[j] == -1)
                {
                    pos = j;
                    f3 = 1;
                    break;
                }
            }
            
            if(f3 ==0)
            {
                max = temp[0];
                pos = 0;
                
                for(j = 1; j < no_frame; ++j)
                {
                    if(temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            
            frame[pos] = p[i];
            faults++;
        }
        
        printf("\n");
  
        printf("%d\t\t", p[i]);
        for(j = 0; j < no_frame; ++j)
        {
            printf("%d\t", frame[j]);
        }
}
    
    printf("\n\nTotal Page Faults = %d\n", faults);
    
    
     return 0;
}

