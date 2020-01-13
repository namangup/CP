int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    arrin(arr,n);

    int l[2*n+1];
    l[0]=0;
    l[1]=1;

    int cenp=1;
    int cenrp=2;
    int curp;
    int culp;
    int expand=-1;
    int diff=-1;

    //cout<<l[1]<<" ";
    for(curp=2;curp<2*n+1;curp++)
    {
        culp=2*cenp-curp;
        expand=0;
        diff= cenrp-curp;
        if(diff>0)
        {
            if(l[culp]<diff)
            l[curp]=l[culp];
            else if(l[culp]==diff && curp==2*n)
            l[curp]=l[culp];
            else if(l[culp]==diff && curp < 2*n)
            {
                l[curp]=diff;
                expand=1;
            }
            else if(l[culp]>diff)
            {
                l[curp]=diff;
                expand=1;
            }
        }
        else
        {
            l[curp]=0;
            expand=1;
        }

        if(expand)
        {
            while(((curp+l[curp]<2*n+1)&&(curp-l[curp]>0))&& (((curp+l[curp]+1)%2==0)||(arr[(curp+l[curp]+1)/2]==arr[(curp-l[curp]-1)/2])))
            l[curp]++;
        }
        if(curp+l[curp]>cenrp)
        {
            cenp=curp;
            cenrp=curp+l[curp];
        }
        /*if(curp%2==1)
        cout<<l[curp]<<" ";*/
    }
}