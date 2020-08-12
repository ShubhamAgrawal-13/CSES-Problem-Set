
a = b + reverse(b)

while(a.length() == 1){
	if(a[n-1]!=1){
		if(a[n-1]!=0){
			print "not possible"
			break
		}
		else{
			a[n-1]=0
			a[0]=0
			a=a/10
		}
	}
	else{
		a = a - (10 + a[0]) - (10^(n-2))*(10 + a[0])
		a = a/10
	}
}

