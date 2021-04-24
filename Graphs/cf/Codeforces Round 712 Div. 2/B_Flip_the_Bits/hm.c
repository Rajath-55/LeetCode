#include <stdio.h>

void solve(){
    int n;
        scanf("%d",&n);
        char a[n+1],b[n+1];
        scanf("%s",&a);
        scanf("%s",&b);
        int count=0;
        int res[n];
        int azeroes=0,a1=0;
        for(int i=0;i<n;i++){
            if(a[i]=='0'){
                azeroes+=1;
            }
            if(a[i]=='1'){
                a1+=1;
            }
            if(azeroes==a1){
                res[i]=1;
            }
            if(azeroes!=a1){
                res[i]=0;
            }
        }
        int flag=0;
        for(int i=n-1;i>=0;i--){
            if(count%2==0){
                if(a[i]!=b[i]){
                    if(res[i]==1){
                        count+=1;
                        continue;
                    }
                    else {
                        printf("NO\n");
                        flag =1;
                        break;
                    }
                }
            }
            if(count%2==1){
                if(a[i]==b[i]){
                    if(res[i]==1){
                        count+=1;
                        continue;
                    }
                    else {
                        printf("NO\n");
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==0){
            printf("YES\n");
        }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}