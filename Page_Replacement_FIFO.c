#include<stdio.h>
int main(){
    int i,j,frames,pages,pageFaults=0,current=0;
    printf("Enter the no. of Frames: ");
    scanf("%d",&frames);
    printf("Enter the no. of Pages: ");
    scanf("%d",&pages);
    printf("Enter the reference string to pages: ");
    int pageString[pages];
    for(i=0;i<pages;i++){
        scanf("%d",&pageString[i]);
    }
    
    int frame[frames];
    for(i=0;i<frames;i++){
        frame[i] = -1;
    }
    
    for(i=0;i<pages;i++){
        int found = 0;
        for(j=0;j<frames;j++){
            if(frame[j] == pageString[i]){
                found = 1;
                break;
            }
        }
        
        if(!found){
            frame[current] = pageString[i];
            current = (current+1)%frames;
            pageFaults++;
            
            printf("Page %d: ", pageString[i]);
            
            for(j=0;j<frames;j++){
                if(frame[j] != -1){
                   printf("%d ",frame[j]);
                }
                else{
                    printf("-");
                }
            }
            printf("\n");
        }
        else{
            printf("Page %d: No page Fault \n", pageString[i]);
        
        }
    }
    printf("Total page faults: %d",pageFaults);
    return 0;
}