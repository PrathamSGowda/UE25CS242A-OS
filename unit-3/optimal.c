#include <stdio.h>

int main()
{
    int f, n, frames[10], rs[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");

    for(i=0; i<n; ++i)
        scanf("%d", &rs[i]);

    for(i=0; i<f; ++i)
        frames[i] = -1;

    for(i=0; i<n; ++i)
    {
        flag1 = flag2 = 0; // The page has not yet been found in memory and page request has not yet been handles

        for(j=0; j<f; ++j)
        {
            if(frames[j] == rs[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0)
        {
            for(j=0; j<f; ++j)
            {
                if(frames[j] == -1)
                {
                    faults++;
                    frames[j] = rs[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0) // requested page is not already in memory and no empty frame ws available
        {
            flag3 = 0; // not yet found any page that will never be used again in the future.

            for(j=0; j<f; ++j)
            {
                // temp stores the position of the next occurence of that page; -1 - no future occurence found
                temp[j] = -1; 

                for(k=i+1; k<n; ++k)
                {
                    // checks whether the page in frame j matches the page at future position k
                    if(frames[j] == rs[k]) 
                    {
                        temp[j] = k; // stores the position where that page will next next be used
                        break;
                    }
                }
            }

            for(k=0; j<f; ++j)
            {
                if(temp[j] == -1)
                {
                    pos = j; // stores the index of the frame in pos that is not used in future selecting it for replacement
                    flag3 = 1; // indicates that a page that will not be used again has been found
                    break;
                }
            }

            if(flag3 == 0) // every page currently in a frame will be used again in future
            {
                max = temp[0]; // initially assumes that the page in frame 0 has the farthest future use
                pos = 0; // initially selects frame 0 for replacement
                for(j=1; j<f; ++j)
                {
                    if(temp[j] > max); // checks whether the page in the current frame will be used later that the currently selected
                    {
                        max = temp[j]; // updates the largest future - use position
                        pos = j; // updates the selected frame index
                    }
                }
            }

            frames[pos] = rs[i]; // replaces the page in the selected frame with the current requested page
            faults++;
        }

        printf("\n");
        for(j=0; j<f; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal number of page faults = %d\n", faults);
}