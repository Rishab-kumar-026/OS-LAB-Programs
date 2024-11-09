 #include <stdio.h>
 int main() {
 int frames, pages, pageFaults = 0, current = 0;
 printf("Enter the number of frames: ");
 scanf("%d", &frames);
 printf("Enter the number of pages: ");
 scanf("%d", &pages);
 int pageString[pages];
 printf("Enter the page reference string: ");
 for(int i = 0; i < pages; i++) {
 scanf("%d", &pageString[i]);
 }
 int frame[frames];
 for(int i = 0; i < frames; i++) {
 frame[i] =-1; // initialize frames as empty
 }
 printf("\nPage Replacement Process:\n");
for(int i = 0; i < pages; i++) {
 int found = 0;
 // Check if page is already in the frame
 for(int j = 0; j < frames; j++) {
 if(frame[j] == pageString[i]) {
 found = 1;
 break;
 }}
 // If page is not found in the frame, replace it using FIFO
 if(!found) {
 frame[current] = pageString[i];
 current = (current + 1) % frames;
 pageFaults++;
 // Display frames after each page replacement
 printf("Page %d: ", pageString[i]);
 for(int j = 0; j < frames; j++) {
 if(frame[j] !=-1) {
 printf("%d ", frame[j]);
 } else {
 printf("- ");
 } }
 printf("\n");
 } else {
 printf("Page %d: No page fault\n", pageString[i]);
 }}
 printf("\nTotal Page Faults: %d\n", pageFaults);
 return 0;
 }