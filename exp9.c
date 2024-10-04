#include<stdio.h>

void firstfit(int p_size[], int n, int m_size[], int m) {
    printf("\tFIRST FIT \n");
    int i, j, flag, psize[100], msize[100];
    
    for(i = 0; i < n; i++)
        psize[i] = p_size[i];
    for(i = 0; i < m; i++)
        msize[i] = m_size[i];
    
    printf("PROCESS ID\tMEMORY BLOCK\tSPACE REMAIN\n"); 
    for(i = 0; i < n; i++) {
        flag = 0;
        for(j = 0; j < m; j++) {
            if(msize[j] >= psize[i]) {
                printf("\nP%d[%d]\t\tM[%d]\t\t", i + 1, psize[i], msize[j]);
                msize[j] = msize[j] - psize[i];
                printf("%d\n", msize[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            printf("\nP%d[%d]\tcannot allocate\n", i + 1, psize[i]);
    }
}

void worstfit(int p_size[], int n, int m_size[], int m) {
    printf("\tWORST FIT \n");
    int i, j, max, loc, psize[100], msize[100];
    
    for(i = 0; i < n; i++)
        psize[i] = p_size[i];
    
    for(i = 0; i < m; i++)
        msize[i] = m_size[i];
    
printf("PROCESS ID\tMEMORY BLOCK\tSPACE REMAIN\n"); 
    for(i = 0; i < n; i++) {
        max = msize[0];
        loc = 0;
        for(j = 0; j < m; j++) {
            if(msize[j] > max) {
                max = msize[j];
                loc = j;
            }
        }
        if(max >= psize[i]) {
            printf("\nP%d[%d]\t\tM[%d]\t\t", i + 1, psize[i], msize[loc]);
            msize[loc] = msize[loc] - psize[i];
            printf("%d\n", msize[loc]);
        } else {
            printf("\nP%d[%d]\tcannot allocate\n", i + 1, psize[i]);
        }
    }
}

void bestfit(int p_size[], int n, int m_size[], int m) {
    printf("\tBEST FIT \n");
    int i, j, loc, psize[100], msize[100];
    for(i = 0; i < n; i++)
        psize[i] = p_size[i];
    for(i = 0; i < m; i++)
        msize[i] = m_size[i];
   printf("PROCESS ID\tMEMORY BLOCK\tSPACE REMAIN\n"); 
    for(i = 0; i < n; i++) {
        loc = -1;
        for(j = 0; j < m; j++) {
            if(msize[j] >= psize[i]) {
                if(loc == -1)
                    loc = j;
                else if(msize[loc] > msize[j])
                    loc = j;
            }
        }
        if(loc != -1) {
            printf("\nP%d[%d]\t\tM[%d]\t\t", i + 1, psize[i], msize[loc]);
            msize[loc] = msize[loc] - psize[i];
            printf("%d\n", msize[loc]);
        } else {
            printf("\nP%d[%d]\tcannot allocate\n", i + 1, psize[i]);
        }
    }
}

void main() {
    int i, p_size[100], m_size[100], n, m;
    
    printf("Enter The No: Of Processes:\n ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter each process size %d: ", i + 1);
        scanf("%d", &p_size[i]);
    }
    
    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    
    for(i = 0; i < m; i++) {
        printf("Enter each block size %d: ", i + 1);
        scanf("%d", &m_size[i]);
    }
    
    firstfit(p_size, n, m_size, m);
    printf("\n\n");
    bestfit(p_size, n, m_size, m);
    printf("\n\n");
    worstfit(p_size, n, m_size, m);
}
