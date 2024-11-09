 #include <stdio.h>
 int findOptimalIndex(int pages[], int currentPage, int frames[], int frameCount, int pageCount) {
 int maxDistance =-1, index =-1;
 for (int i = 0; i < frameCount; i++) {
 int j;
 for (j = currentPage + 1; j < pageCount; j++) {
 if (frames[i] == pages[j]) {
 if (j > maxDistance) {
 maxDistance = j;
 index = i;
 }
 break;
 }
 }
 if (j == pageCount) return i; // If page is not found in future references, use this frame
 }
 return (index ==-1) ? 0 : index;
 }
 int main() {
 int frameCount, pageCount;
 printf("Enter the number of frames: ");
scanf("%d", &frameCount);
 printf("Enter the number of pages: ");
 scanf("%d", &pageCount);
 int frames[frameCount], pages[pageCount];
 int pageFaults = 0, nextPage = 0;
 printf("Enter the page reference sequence: ");
 for (int i = 0; i < pageCount; i++) {
 scanf("%d", &pages[i]);
 }
 for (int i = 0; i < frameCount; i++) frames[i] =-1; // Initialize frames
 for (int i = 0; i < pageCount; i++) {
 int found = 0;
 // Check if page is already in frame
 for (int j = 0; j < frameCount; j++) {
 if (frames[j] == pages[i]) {
 found = 1;
 break;
 }
 }
 if (!found) {
 // If page is not in frame, find optimal frame to replace
 if (nextPage < frameCount) {
 frames[nextPage++] = pages[i];
 } else {
 int optimalIndex = findOptimalIndex(pages, i, frames, frameCount, pageCount);
 frames[optimalIndex] = pages[i];
 }
 pageFaults++;
 }
 }
 printf("Total Page Faults: %d\n", pageFaults);
 return 0;
 }