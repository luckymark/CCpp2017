# include<stdio.h>
# include<stdbool.h>
int main()
{
	bool flagA = 0;
	int index = 1;
	int Primer[27] = {1, 0};
	bool flag = 0;
	for(int k=2; k<101; k++){	
		for(int i=2; i*i<=k; i++){
		if(k%i==0){
			flag = 1;
			break;
		}
		}
		if(flag) flag = 0;
		else{
			Primer[index] = k;
			index += 1;
		};
	}

	for(int i=4; i<101; i+=2){
		if(i%2==0){
			for(int j=1; j<26; j++){
				for(int k=1; k<26; k++){
					if(i==(Primer[j]+Primer[k])){
						//cout<<i<<'='<<Primer[j]<<'+'<<Primer[k]<<endl;
						printf("%d=%d+%d\n", i, Primer[j], Primer[k]);
						flagA =1;
						break;
					}
				}
				if(flagA){
					flagA = 0;
					break;
				}
			}
		}
	}
	return 0;
}

