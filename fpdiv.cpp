#include<stdio.h>
#include<iostream>

using namespace std;
#define ll long long
// function to perform division of two integers using bit manipulation upto maximum decimal places precision of 7 that float type can have
float division(ll dend,ll dsor){
    string ans;
    int flag=0,c=0;
    while(c<7){
        ll x=0,qtent=0;
        for(int i=31;i>=0;i--){
            if(x+ (dsor<<i)<=dend){
                x+=dsor<<i;
                qtent+=1<<i;
            } 
        }
        if(c!=0 || qtent!=0) 
            c+=to_string(qtent).size();
        ans+=to_string(qtent);
        if(c==7) 
            break;
        dend=dend-x;
        if(dend==0)
            break;
        if(flag==0){
            ans+=".";
            flag=1;
        }
        dend=(dend<<3) + (dend<<1);
        while(dend<dsor){
            ans+="0";
            dend=(dend<<3) + (dend<<1);
            if(c!=0)
                c++;
            if(c==7) break;
        }
    }
    return stof(ans);
}
int main(){
	float a,b;
	cin>>a>>b;
	
	if(b==0) {
		cout<<"invalid\n";
		return 0;
	}
	int sign=1;
	if((a<0 && b>0) || (a>0 && b<0)) 
	    sign=-1;
	// calculating integer values with same bit representation as that of the original floating point numbers
	int x=*(int*)&a;  
	int y=*(int*)&b;
	
	// converting the integers into bit form such that bit[0] gives sign bit as in ieee 754 single precision representation
	int bit1[32],bit2[32];
	
	for(int i=0;i<32;i++){
		if(x & 1<<i) 
		    bit1[31-i]=1;
		else 
		    bit1[31-i]=0;
	}
	
	for(int i=0;i<32;i++){
		if(y & 1<<i)
		    bit2[31-i]=1;
		else 
		    bit2[31-i]=0;
 	}
 	
 	//converting a/b into form (x/y)*2^z where x and y has been converted to integers dend and dsor using their bit representation
	ll dend=0,dsor=0;
	int f1=8,f2=8;
	
	for(int i=31;i>=9;i--){
		if(bit1[i]){
			f1=i;
			break;
		}
	}
	for(int i=31;i>=9;i--){
		if(bit2[i]){
			f2=i;
			break;
		}
	}
	f1-=8;
	f2-=8;
	dend+=1<<(f1);
	dsor+=1<<(f2);
	
	for(int i=9;i<32;i++){
		if(bit1[i])
		    dend+=1<<(f1-i+8);
	}
	
	for(int i=9;i<32;i++){
		if(bit2[i])
		    dsor+=1<<(f2-i+8);
	}
	int e1=0,e2=0;
	
	for(int i=1;i<9;i++){
		if(bit1[i])
		    e1+=1LL<<(8-i);
	}
	
	for(int i=1;i<9;i++){
		if(bit2[i])
		    e2+=1LL<<(8-i);
	}
	
	int z=e1-e2-f1+f2;
	
    //calculating value of x/y by calling function for division of two integers
    float val=division(dend,dsor);
    
    //calculating bit represention bit3 for float val
    int p=*(int*)&val;
	int bit3[32];
	
	for(int i=0;i<32;i++){
		if(p & 1<<i) 
		    bit3[31-i]=1;
		else 
		    bit3[31-i]=0;
	}
	//converting bit3 into final ans of a/b by setting sign bit with resultant sign of a/b and adding previously calculated exponent z to exponent of val as |a/b|=(x/y)*(2^z)=(1.mantissa)*2^e3*2^z
	if(sign==-1) bit3[0]=1;
	else bit3[0]=0;
	int e3=0;
	for(int i=1;i<9;i++){
		if(bit3[i])
		    e3+=1LL<<(8-i);
	}
	e3+=z;
	for(int i=1;i<9;i++){
		if(1<<(i-1) & e3) 
		    bit3[9-i]=1;
		else 
		    bit3[9-i]=0;
	}
	//calculating integer equivalent of bit3 and converting it to float using pointer
	int sum_res=0;
	for(int i=0;i<32;i++){
		if(bit3[31-i]) 
		    sum_res+=1<<i;
	}
	float final_ans=*(float*)&sum_res;
    cout<<final_ans<<"\n";
	
