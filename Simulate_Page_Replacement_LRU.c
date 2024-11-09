 #include <stdio.h>
 #define MAX_FRAMES 10 // Max number of frames, can be adjusted as needed
 #define MAX_PAGES 50 // Max number of pages in reference string
 int findLRU(int time[], int n) {
 int i, minimum = time[0], pos = 0;
 for (i = 1; i < n; ++i) {
 if (time[i] < minimum) {
 minimum = time[i];
 pos = i;
 } }
 return pos;
 }
 void LRU(int pages[], int n, int frames) {
int frame[MAX_FRAMES], time[MAX_FRAMES];
 int count = 0, faults = 0;
 int i, j, pos, flag1, flag2;
 for (i = 0; i < frames; ++i) {
 frame[i] =-1; // Initialize frames as empty
 }
 for (i = 0; i < n; ++i) {
 flag1 = flag2 = 0;
 // Check if the page is already in a frame
 for (j = 0; j < frames; ++j) {
 if (frame[j] == pages[i]) {
 count++;
 time[j] = count; // Update time for recently used page
 flag1 = flag2 = 1;
 break;
 } }
 if (!flag1) {
 // Check for an empty frame
 for (j = 0; j < frames; ++j) {
 if (frame[j] ==-1) {
 faults++;
 count++;
 frame[j] = pages[i];
 time[j] = count;
 flag2 = 1;
 break;
 }}}
 if (!flag2) {
 // Find LRU page to replace
 pos = findLRU(time, frames);
 faults++;
 count++;
 frame[pos] = pages[i];
 time[pos] = count;
 }
 // Display frames
 printf("\nFrames after accessing page %d: ", pages[i]);
 for (j = 0; j < frames; ++j) {
 if (frame[j] !=-1) {
 printf("%d ", frame[j]);
 } else {
 printf("- ");
 }}}
 printf("\n\nTotal Page Faults: %d\n", faults);
}
 int main() {
 int pages[MAX_PAGES];
 int n, frames;
 int i;
 printf("Enter the number of pages: ");
 scanf("%d", &n);
 printf("Enter the reference string (page numbers): ");
 for (i = 0; i < n; ++i) {
 scanf("%d", &pages[i]);
 }
 printf("Enter the number of frames: ");
 scanf("%d", &frames);
 LRU(pages, n, frames);
 return 0;
 }