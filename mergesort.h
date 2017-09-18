

 void mergesort(long a[],int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    long L[n1] ;
    long R[n2] ;
    for(int i = 0; i < n1 ; i++){
        L[i] = a[l+i];
    }
    for(int i = 0; i < n1 ; i++){
        R[i] = a[m+1+i];
    }
    int i=0,j=0;
    int k=l;
    while(i<n1 && j <n2){
        if (L[i]<=R[j]){
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
                j++;
        }
        k++;
    }
    while (i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while (j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void merge(long a[],int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        merge(a,l,m);
        merge(a,m+1,r);
        mergesort(a,l,m,r);
    }
}
